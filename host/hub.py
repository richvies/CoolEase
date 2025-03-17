"""
Basic methods and classes for interfacing with the hub
"""

import argparse
import sys
import time

import bootloader
import device


class Hub(device.Device):
    def __init__(self):
        super().__init__()
        self.vid = 0x0483
        self.pid = 0x5750
        self.manufacturer = "CoolEase"
        self.product = "CoolEase Hub"
        print("init hub")

    def __enter__(self):
        return super().__enter__()


def main():
    with Hub() as hub:
        print(hub.vid)
    if hub.find_device() is None:
        sys.exit("No hub found")
    else:
        with hub as dev:
            dev.test_command()

    parser = argparse.ArgumentParser(description="Program the LED Wristwatch device")
    parser.add_argument("--timeout", type=int, help="Device find timeout", default=0)
    parser.add_argument(
        "command", type=str, help='Bootloader command: "program" or "abort"'
    )
    parser.add_argument("param", type=str, nargs="*")
    args = parser.parse_args()
    with bootloader.Bootloader() as dev:
        dev.reset()
        if args.command == "program":
            if len(args.param) != 1:
                sys.exit("Invalid parameter count")
            program_device(args.param[0])
        elif args.command == "abort":
            if not dev.abort():
                sys.exit(
                    "Failed to abort device programming. Perhaps programming already started?"
                )
        else:
            sys.exit("Unknown command")


if __name__ == "__main__":
    main()


def program_device(filename):
    with bootloader.IntelHexLoader(filename) as loader:
        print("Programming {} to attached device".format(filename))
        pages = list(bootloader.ProgramPager(loader))
        length = float(len(pages))
        start = time.perf_counter()
        for i, p in enumerate(pages):
            dev = bootloader.Bootloader()
            dev.program(p)
            sys.stdout.write(
                "\rProgram/Verify: {:.1f}% ".format(((float(i) / length) * 100))
            )
            sys.stdout.flush()
        end = time.perf_counter()
        sys.stdout.write("\rProgram/Verify: 100% \r\n")
        sys.stdout.flush()
        speed = (length * 128) / (end - start) / 1024
        print(
            "Programmed and verified {:.0f} pages in {:.2f} seconds ({:.2f} KB/s)".format(
                length, end - start, speed
            )
        )
    if not dev.exit(0x08002000):
        sys.exit("Failed to exit bootloader mode")
