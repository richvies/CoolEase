# Currently works with test_boot_verify_checksum() arrangement

import zlib

def main():
    # data = ['0x12', '0x34', '0x56', '0x78', '0x24', '0x68', '0x13', '0x57']
    data = ['0x01', '0x02', '0x03', '0x04', '0x05', '0x06', '0x07', '0x01', ]
    
    result = bytes([int(x,0) for x in data])

    # for byt in result:
    #     print(byt)

    print(hex(zlib.crc32(result)))
    print(hex(zlib.crc32(result, 0x00000000)))
    print(hex(zlib.crc32(result, 0xFFFFFFFF)))

if __name__ == '__main__':
    main()