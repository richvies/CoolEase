import zlib

def main():
    print('hello')
    data = [84]
    print(data)
    print(bytes(data))
    print(hex(zlib.crc32(bytes(data))))

if __name__ == '__main__':
    main()