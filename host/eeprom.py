#   uint32_t dev_id;
# 	uint32_t boot_version;
# 	uint32_t vtor;
# 	uint8_t	 aes_key[16];
# 	char 	 pwd[33];
import os.path as path
import struct
import sys
import zlib


class bin_section(object):
    def __init__(self, name, size, data):
        self.name = name
        self.size = size
        self.data = data


def generate_eeprom(dev_id, device_type, vtor, aes_key, pwd, log_size):
    vtor = int(vtor, 16)
    aes_key = bytes.fromhex(aes_key)
    pwd = bytes(pwd, "utf-8") + bytes(0)

    boot = bin_section(
        "boot",
        256,
        struct.pack(
            "<I8sI16s34s",
            dev_id,
            bytes(device_type, "utf-8") + bytes(0),
            vtor,
            aes_key,
            pwd,
        ),
    )
    app = bin_section("app", 256, struct.pack("<I", 0))
    log = bin_section("log", 1024, struct.pack("<HH", log_size, 0))
    shared = bin_section("shared", 64, struct.pack("<I", 0))

    # Special case, default eeprom file
    if dev_id == 0:
        filename = device_type + "/bin/" + device_type + "_eeprom.bin"
    else:
        filename = (
            device_type
            + "/bin/store/"
            + device_type
            + "_eeprom_"
            + "{0:08}".format(dev_id)
            + ".bin"
        )

    # Open blank bin file
    with open(filename, "wb+") as eeprom:
        for _ in range(2048):
            eeprom.write(b"\x00")

        locator = 0

        eeprom.seek(locator)
        eeprom.write(boot.data)
        locator += boot.size

        eeprom.seek(locator)
        eeprom.write(app.data)
        locator += app.size

        eeprom.seek(locator)
        eeprom.write(log.data)
        locator += log.size

        eeprom.seek(locator)
        eeprom.write(shared.data)
        locator += shared.size


# Append meta info to hub app binary
def generate_app(device_type, bin_type):
    # Check arguments
    device_types = {"hub", "sensor"}
    bin_types = {"app", "bootloader", "eeprom"}

    if device_type not in device_types:
        print("Error: Unknown device type '" + device_type + "'")
        print("\tShould be one of: ")
        for i in device_types:
            print("\t\t" + i)
        exit()

    if bin_type not in bin_types:
        print("Error: Unknown bin type '" + bin_type + "'")
        print("\tShould be one of: ")
        for i in bin_types:
            print("\t\t" + i)
        exit()

    if bin_type == "bootloader":
        dev_filename = device_type + "_bootloader"
    elif bin_type == "app":
        dev_filename = device_type

    # Get version number from corresponding src e.g. hub.c, and open new bin file e.g. hub_100.bin
    version = 0
    version_filename = device_type + "/src/" + dev_filename + ".c"
    if not path.isfile(version_filename):
        print("Error: Version file " + version_filename + " does not exist")
        exit()
    else:
        with open(version_filename, "r") as file:
            found = False

            for line in file:
                if "VERSION" in line:
                    found = True
                    version = int(line[15:])
                    break

            if not found:
                print("Error: Version could not be found in " + version_filename)
                exit()

    # Check original clean bin file (no header info, output of make)
    original_filename = device_type + "/bin/" + dev_filename + ".bin"
    if not path.isfile(original_filename):
        print("Error: " + original_filename + " does not exist")
        exit()

    # Generate app binary with header info
    with open(original_filename, "rb+") as original_bin:
        # make integer page number
        original_bin.seek(0)
        original_bin.read()
        len = original_bin.tell()
        while len % 64 != 0:
            original_bin.write(b"\x00")
            len += 1

        original_bin.seek(0)
        # print("Original\n" + str(original_bin.read(64)) + "\n\n")

        # calculate crc32
        num_u32 = int(len / 4)
        u32_list = bytearray()

        # bytes to int little endian for crc
        original_bin.seek(0)
        for _ in range(num_u32):
            u32 = int.from_bytes(original_bin.read(4), byteorder="little")
            u32_list.extend(u32.to_bytes(4, byteorder="big"))

        crc32 = zlib.crc32(u32_list)

        # print("LE")
        # print(u32_list[0:16])
        # print(str(hex(crc32)))

        # Append meta
        meta = bin_section("meta", 64, struct.pack("<II", version, crc32))

        new_filename = (
            device_type
            + "/bin/store/"
            + dev_filename
            + "_{0:03}".format(version)
            + ".bin"
        )

        with open(new_filename, "wb+") as new_bin:
            # Write meta data first, then program data
            new_bin.seek(0)
            for _ in range(meta.size):
                new_bin.write(b"\x00")

            new_bin.seek(0)
            new_bin.write(meta.data)

            new_bin.seek(meta.size)
            original_bin.seek(0)
            new_bin.write(original_bin.read())

        print(
            device_type
            + " "
            + bin_type
            + " version "
            + str(version)
            + " size "
            + str(path.getsize(new_filename))
        )

    # Generate eeprom bins
    dev_id_start = 0
    if device_type == "hub":
        dev_id_start = 20000000
    elif device_type == "sensor":
        dev_id_start = 30000000

    for i in range(1, 10):
        generate_eeprom(
            dev_id=dev_id_start + i,
            device_type=device_type,
            vtor="0x08008000",
            aes_key="0102030405060708090A0B0C0D0E0FFF",
            pwd="vAldoWDRaTHyrISmaTioNDERpormEntI",
            log_size=1020,
        )


if __name__ == "__main__":
    # boot or app, hub or sensor
    args = sys.argv

    if len(args) == 3:
        generate_app(str(args[1]), str(args[2]))
    else:
        print("Error: Expected two arguments, got " + str(len(args) - 1))
        exit()
