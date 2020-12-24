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

def main():
    dev = find_device()
    if dev is None:
        sys.exit('No hub found')
    with dev:
        print('Hub Found')
        cmd = TestCommand()
        dev.write_command(cmd)

if __name__ == '__main__':
    main()
