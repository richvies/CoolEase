"""
Basic methods and classes for interfacing with the hub
"""

import hid
import sys
import struct, time

VID = 0x0483
PID = 0x5750

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
    COMMAND = 1
    def __init__(self):
        parts = bytes('Test Command', 'utf-8')
        super().__init__(self.COMMAND, parts)

class Device(hid.device):
    MANUFACTURER='CoolEase'
    PRODUCT='CoolEase Hub'
    def __init__(self, path):
        self.path = path

    def __enter__(self):
        self.open_path(self.path)
        return self

    def __exit__(self, *args):
        self.close()

    def test_command(self):
        cmd = TestCommand()
        self.write_command(cmd)

    def write_command(self, command):
        data = b'\x00' + command.pack() #prepend a zero since we don't use REPORT_ID
        res = self.write(data)
        if res < 0:
            raise ValueError(self.error())

def find_device(cls=Device):
    info = hid.enumerate(VID, PID)
    n = 0
    for i in info:
        n += 1
        print('HID Device', n)
        print('\t Manufacturer :\t', i['manufacturer_string'])
        print('\t Product :\t', i['product_string'])
        print()
        if i['manufacturer_string'] == cls.MANUFACTURER and i['product_string'] == cls.PRODUCT:
            return cls(i['path'])
    return None

def open_bootloader(timeout=0):
    """
    Finds a bootloader device or places any found wristwatch devices into
    bootloader mode. Returns once a bootloader is found.

    timeout: Timeout in seconds
    """
    start = time.time()
    while True:
        now = time.time()
        if timeout and (now - start) > timeout:
            raise TimeoutError
        bootdev = bootloader.find_device()
        if bootdev is None:
            dev = wristwatch.find_device()
            if dev is None:
                continue
            with dev:
                print('Found wristwatch: Entering bootloader mode')
                dev.enter_bootloader()
        else:
            return bootdev

def program_device(filename):
    with bootloader.IntelHexLoader(filename) as l:
        print('Programming {} to attached device'.format(filename))
        pages = list(bootloader.ProgramPager(l))
        length = float(len(pages))
        start = time.perf_counter()
        for i, p in enumerate(pages):
            dev.program(p)
            sys.stdout.write('\rProgram/Verify: {:.1f}% '.format(((float(i)/length) * 100)))
            sys.stdout.flush()
        end = time.perf_counter()
        sys.stdout.write('\rProgram/Verify: 100% \r\n')
        sys.stdout.flush()
        speed = (length * 128) / (end-start) / 1024
        print('Programmed and verified {:.0f} pages in {:.2f} seconds ({:.2f} KB/s)'.format(length, end-start, speed))
    if not dev.exit(0x08002000):
        sys.exit('Failed to exit bootloader mode')

def main():
    dev = find_device()
    if dev is None:
        sys.exit('No hub found')
    with dev:
        print('Hub Found')
        cmd = TestCommand()
        dev.write_command(cmd)
    parser = argparse.ArgumentParser(description='Program the LED Wristwatch device')
    parser.add_argument('--timeout', type=int, help='Device find timeout', default=0)
    parser.add_argument('command', type=str, help='Bootloader command: "program" or "abort"')
    parser.add_argument('param', type=str, nargs='*')
    args = parser.parse_args()
    with open_bootloader(args.timeout) as dev:
        dev.reset()
        if args.command == 'program':
            if len(args.param) != 1:
                sys.exit('Invalid parameter count')
            program_device(args.param[0])
        elif args.command == 'abort':
            if not dev.abort():
                sys.exit('Failed to abort device programming. Perhaps programming already started?')
        else:
            sys.exit('Unknown command')
            
if __name__ == '__main__':
    main()
