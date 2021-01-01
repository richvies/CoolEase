import hid
import sys
import struct
import time
import argparse


class Device(hid.device):

    def __init__(self, vid=0x0483, pid=0x5750, manufacturer='CoolEase', product='CoolEase Hub'):
        # print('init device')
        self.path = None
        self.vid = vid
        self.pid = pid
        self.manufacturer = manufacturer
        self.product = product

    def __enter__(self):
        print('Searching for ', 'VID: ', self.vid, 'PID: ', self.pid)
        if self.find_device() is None:
            exit('Can\'t find automatically')
        else:
            self.open_path(self.path)
        return self

    def __exit__(self, *args):
        self.close()

    def test_command(self):
        cmd = TestCommand()
        self.write_command(cmd)

    def get_log(self):
        print('Getting Log')
        cmd = GetLogCommand()
        self.write_command(cmd)
        self.log = []
        for _ in range(10):
            self.log.append(self.read(max_length=64, timeout_ms=10))
        return self.log

    def write_command(self, command):
        data = b'\x00' + command.pack()  # prepend a zero since we don't use REPORT_ID
        res = self.write(data)
        if res < 0:
            raise ValueError(self.error())

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


class Command(object):
    """
    Basic command structure: 4 bytes of command followed by up to 60 bytes of data
    """

    def __init__(self, code, data_bytes):
        self.code = code
        self.data_bytes = data_bytes

    def pack(self):
        return struct.pack('<I60s', self.code, self.data_bytes)

class TestCommand(Command):
    COMMAND = 0

    def __init__(self):
        parts = bytes('Test Command', 'utf-8')
        super().__init__(self.COMMAND, parts)

class GetLogCommand(Command):
    COMMAND = 1

    def __init__(self):
        data = bytes('Get Log\0', 'utf-8')
        super().__init__(self.COMMAND, data)


def main():
    with Device() as dev:
        print(dev.vid)
        print(dev.get_log())
        # while True:
        #     print(dev.read(max_length=64, timeout_ms=10))


if __name__ == '__main__':
    main()
