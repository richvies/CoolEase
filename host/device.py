from os import write
import hid
import sys
import struct
import time
import argparse
import zlib


class Device(hid.device):

    def __init__(self, vid=0x0483, pid=0x5750, manufacturer='CoolEase', product='CoolEase Hub'):
        # print('init device')
        self.path = None
        self.vid = vid
        self.pid = pid
        self.manufacturer = manufacturer
        self.product = product
        self.log = ""
        self.pagesize = 128

    def __enter__(self):
        print('Searching for ', 'VID: ', self.vid, 'PID: ', self.pid)
        if self.find_device() is None:
            exit('Can\'t find automatically')
        else:
            self.open_path(self.path)
        print()
        return self

    def __exit__(self, *args):
        self.close()

    def test_command(self):
        cmd = TestCommand()
        self.write_command(cmd)
        self.read_response()

    def get_log(self):
        if self.log == "":
            cmd = GetLogCommand()
            self.write_command(cmd)
            self.read_response()
            print('Getting Log\n' + '-' * 20)
            for _ in range(20):
                report = self.read(max_length=256, timeout_ms=100)
                string = "".join([chr(report[i]) for i in range(len(report))])
                if 'Callback' not in string:
                    self.log += string

        return self.log

    def program_bin(self, filename):
        print('Programming Bin', filename)
        with BinLoader(filename, self.pagesize) as bin:
            print()
            cmd = StartProgrammingCommand()
            self.write_command(cmd)
            self.read_response()
            for n in range(bin.num_pages):
                print('Page', n, 'start')

                page = bin.file.read(self.pagesize)
                writesize = int(self.pagesize/2)

                # Bin file is little endian but CRC on STM32 is big endian so reverse for zlib
                page_be = bytes()
                for i in range(int(self.pagesize / 4)):
                    page_be += page[(i*4)+3:None if i == 0 else (i*4)-1:-1]
                # print(page_be)

                crc_lower = zlib.crc32(page_be[:writesize])
                crc_upper = zlib.crc32(page_be[writesize:])

                cmd = ProgramPageCommand(n, crc_lower, crc_upper)
                lower = HalfPage(page[:writesize])
                upper = HalfPage(page[writesize:])

                # print('crc lower:', hex(crc_lower))
                # print('crc upper:', hex(crc_upper))
                # print(cmd)
                # print(lower.data)
                # print(upper.data)

                self.write_command(cmd)
                self.write_command(lower)
                self.write_command(upper)
                # self.write(b'\x00' + lower.data)
                # self.write(b'\x00' + upper.data)
                print('Page', n, 'done')

        print('Programming Done')

    def jump_to_app(self):
        print('Jumping to application')
        cmd = JumpToAppCommand()
        self.write_command(cmd)

    def write_command(self, command):
        # print('Writing Cmd:', command.code, 'Data:', command.data_bytes)
        data = b'\x00' + command.pack()  # prepend a zero since we don't use REPORT_ID
        res = self.write(data)
        if res < 0:
            raise ValueError(self.error())

    def read_response(self):
        report = self.read(max_length=256, timeout_ms=100)
        string = "".join([chr(report[i]) for i in range(len(report))])
        print('Response: ', string)

    def find_device(self):
        info = hid.enumerate(self.vid, self.pid)
        n = 0
        if len(info) == 0:
            print('No Hid Devices Found')
            return None
        else:
            print('Found HID Devices:')
            for i in info:
                n += 1
                print('Device', n)
                print('\t Manufacturer :\t', i['manufacturer_string'])
                print('\t Product :\t', i['product_string'])
                print()
                if i['manufacturer_string'] == self.manufacturer and i['product_string'] == self.product:
                    self.path = i['path']
                    print('Device found\nPath Set')
                    return i['path']
            return None
        print()


class Command(object):
    """
    Basic command structure: 4 bytes of command followed by up to 60 bytes of data
    """

    def __init__(self, code, data_bytes):
        self.code = code
        self.data_bytes = data_bytes

    def __str__(self):
        return " ".join(["0x{0:02x}".format(byte) for byte in self.pack()]) + "\n" + "".join([chr(byte) for byte in self.pack()])

    def pack(self):
        return struct.pack('<I60s', self.code, self.data_bytes)


class TestCommand(Command):
    COMMAND = 60

    def __init__(self):
        parts = bytes('Test Command', 'utf-8')
        super().__init__(self.COMMAND, parts)


class GetLogCommand(Command):
    COMMAND = 1

    def __init__(self):
        data = bytes('Get Log\0', 'utf-8')
        super().__init__(self.COMMAND, data)


class StartProgrammingCommand(Command):
    COMMAND = 2

    def __init__(self):
        data = bytes('Start Programming\0', 'utf-8')
        super().__init__(self.COMMAND, data)


class ProgramPageCommand(Command):
    COMMAND = 3

    def __init__(self, page_num, crc_lower, crc_upper):
        data = struct.pack('<III', page_num, crc_lower, crc_upper)
        super().__init__(self.COMMAND, data)


class HalfPage(object):

    def __init__(self, data):
        self.data = data

    def pack(self):
        return struct.pack('<64s', self.data)


class JumpToAppCommand(Command):
    COMMAND = 5

    def __init__(self):
        data = bytes('Jump to App\0', 'utf-8')
        super().__init__(self.COMMAND, data)


class BinLoader(object):

    def __init__(self, filename, pagesize):
        self.filename = filename
        self.file = None
        self.filesize = 0
        self.base_address = 0
        self.page_size = pagesize
        self.num_pages = 0

    def __enter__(self):
        self.file = open(self.filename, "ab+")

        # Get Size (pointer automatically reset when end reached)
        self.file.seek(0)
        byte = self.file.read(1)
        while byte:
            self.filesize += 1
            # print(self.file.tell() - 1, self.filesize, byte.hex())
            byte = self.file.read(1)
        print('File size:', self.filesize)

        # Pad file with 0s to fill final page
        print('Padding with 0\'s')
        self.file.seek(self.filesize)
        while self.filesize % self.page_size:
            self.file.write(b'\x00')
            self.filesize += 1

        print('New file size:', self.filesize)

        # Get Number of pages to write
        self.num_pages = int(self.filesize / self.page_size)
        print('Num pages:', self.num_pages)

        # Reset pointer
        self.file.seek(0)

        # Print lines lines end with 0A
        # print(self.file.readline().hex())

        return self

    def __exit__(self, *args):
        self.file.close()
        self.file = None

    def __iter__(self):
        return self

    def __next__(self):
        while False:
            print('hello')
        #     address = int(line[3:7], 16)
        #     record_type = int(line[7:9], 16)
        #     checksum = int(line[-2:], 16)
        #     data = bytes([int(line[9+2*i:9+2*(i+1)], 16) for i in range(0, length)])
        #     if record_type == 0:
        #         return ProgramBlock(self.base_address + address, data)
        #     elif record_type == 1:
        #         raise StopIteration
        #     elif record_type == 2:
        #         raise InvalidFileException('Record type 02 not supported in Intel Hex')
        #     elif record_type == 3:
        #         continue # ignore start segment addresses
        #     elif record_type == 4:
        #         self.base_address = struct.unpack('>H', data)[0] << 16
        #     elif record_type == 5:
        #         continue # ignore the start address for now, but it is convenient


class TestBin(object):

    def __init__(self):
        self.filename = 'test_bin.bin'
        self.generate_test_bin()

    def generate_test_bin(self):
        with open(self.filename, 'wb+') as bin:
            bin.write(bytes([i for i in range(240)]))
            bin.close()


def test_programming():
    print('Test Programming Bin\n-----------------------------\n')
    with Device() as dev:
        bin = TestBin()
        dev.program_bin(bin.filename)


def test_crc():
    print('Test Programming Bin\n-----------------------------\n')
    with Device() as dev:
        test_bin = TestBin()
        with BinLoader(test_bin.filename, 128) as bin:
            data = bin.file.read(8)
            # print(data[0:4])
            # print(data[4:8])
            # print(data[7:3:-1])
            # print(data[3:None:-1])

            # Bin file is little endian but CRC on STM32 is big endian so reverse for zlib
            data_be = bytes()
            for i in range(2):
                data_be += data[(i*4)+3:None if i == 0 else (i*4)-1:-1]
            print(data_be)

            crc = zlib.crc32(data_be)
            print(hex(crc))


def main():
    print('\nCoolEase Hub Usb Thing\n')

    # test_programming()
    # test_crc()

    # cmd = ProgramPageCommand(1, 0x12345678, 0x24681357)
    # cmd.print()
    # cmd = TestCommand()
    # print(cmd)
    # print([hex(byte) for byte in cmd.pack()])

    # with BinLoader('./hub/bin/hub.bin') as bin:
    #     print('someting')
    # print(next(bin))

    # with Device() as dev:
    #     dev.test_command()
    #     print(dev.get_log())

    with Device() as dev:
        dev.program_bin('hub/bin/hub.bin')
        dev.jump_to_app()


if __name__ == '__main__':
    main()
