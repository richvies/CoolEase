#   uint32_t dev_num;
# 	uint32_t boot_version;
# 	uint32_t vtor;
# 	uint8_t	 aes_key[16];
# 	char 	 pwd[33];
import struct


class bin_section(object):
    
    def __init__(self, name, size, data):
        self.name = name
        self.size = size
        self.data = data

def generate_hub_eeprom(dev_num, boot_version, vtor, aes_key, pwd, log_size):

    vtor = int(vtor, 16)
    aes_key = bytes.fromhex(aes_key)
    pwd = bytes(pwd, 'utf-8') + bytes(0)

    boot = bin_section('boot', 256, struct.pack('<III16s34s', dev_num, boot_version, vtor, aes_key, pwd))
    app = bin_section('app', 256, struct.pack('<I', 0))
    log = bin_section('log', 1024, struct.pack('<H', log_size))
    shared = bin_section('shared', 64, struct.pack('<I', 0))

    # Open blank bin file
    # filename = 'hub/bin/store/hub_' + '{0:08}'.format(dev_num) + '_eeprom_' + '{0:03}'.format(boot_version) + '.bin'
    filename = 'hub/hub_eeprom.bin'
    with open(filename, "wb+") as eeprom:
        
        for _ in range(2048):
            eeprom.write(b'\x00')

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

def main():

    generate_hub_eeprom(dev_num=1, 
                        boot_version=101, 
                        vtor='0x08008000', 
                        aes_key='0102030405060708090A0B0C0D0E0FFF', 
                        pwd='vAldoWDRaTHyrISmaTioNDERpormEntI', 
                        log_size=1020)
    print('Done')

if __name__ == '__main__':
    main()
