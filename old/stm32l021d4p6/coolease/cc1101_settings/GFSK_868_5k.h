// Sync word qualifier mode = 30/32 sync word bits detected 
// CRC autoflush = false 
// Channel spacing = 199.813843 
// Data format = Normal mode 
// Data rate = 4.80223 
// RX filter BW = 210.937500 
// PA ramping = false 
// Preamble count = 4 
// Whitening = false 
// Address config = No address check 
// Carrier frequency = 867.999985 
// Device address = 0 
// TX power = 0 
// Manchester enable = false 
// CRC enable = true 
// Deviation = 197.753906 
// Packet length mode = Variable packet length mode. Packet length configured by the first byte after sync word 
// Packet length = 255 
// Modulation format = GFSK 
// Base frequency = 867.999985 
// Modulated = true 
// Channel number = 0 
//
// Rf settings for CC1101
write_reg_single(FIFOTHR,0x47); //RX FIFO and TX FIFO Thresholds
write_reg_single(SYNC1,0xD3);   //Sync Word, High Byte
write_reg_single(SYNC0,0x91);   //Sync Word, Low Byte
write_reg_single(PKTLEN,0xFF);  //Packet Length
write_reg_single(PKTCTRL1,0x04);//Packet Automation Control
write_reg_single(PKTCTRL0,0x05);//Packet Automation Control
write_reg_single(ADDR,0x00);    //Device Address
write_reg_single(CHANNR,0x00);  //Channel Number
write_reg_single(FSCTRL1,0x06); //Frequency Synthesizer Control
write_reg_single(FSCTRL0,0x00); //Frequency Synthesizer Control
write_reg_single(FREQ2,0x20);   //Frequency Control Word, High Byte
write_reg_single(FREQ1,0x25);   //Frequency Control Word, Middle Byte
write_reg_single(FREQ0,0xED);   //Frequency Control Word, Low Byte
write_reg_single(MDMCFG4,0x87); //Modem Configuration
write_reg_single(MDMCFG3,0x75); //Modem Configuration
write_reg_single(MDMCFG2,0x13); //Modem Configuration
write_reg_single(MDMCFG1,0x22); //Modem Configuration
write_reg_single(MDMCFG0,0xE5); //Modem Configuration
write_reg_single(DEVIATN,0x67); //Modem Deviation Setting
write_reg_single(MCSM2,0x07);   //Main Radio Control State Machine Configuration
write_reg_single(MCSM1,0x30);   //Main Radio Control State Machine Configuration
write_reg_single(MCSM0,0x18);   //Main Radio Control State Machine Configuration
write_reg_single(FOCCFG,0x16);  //Frequency Offset Compensation Configuration
write_reg_single(BSCFG,0x6C);   //Bit Synchronization Configuration
write_reg_single(AGCCTRL2,0x43);//AGC Control
write_reg_single(AGCCTRL1,0x40);//AGC Control
write_reg_single(AGCCTRL0,0x91);//AGC Control
write_reg_single(WOREVT1,0x87); //High Byte Event0 Timeout
write_reg_single(WOREVT0,0x6B); //Low Byte Event0 Timeout
write_reg_single(WORCTRL,0xFB); //Wake On Radio Control
write_reg_single(FREND1,0x56);  //Front End RX Configuration
write_reg_single(FREND0,0x10);  //Front End TX Configuration
write_reg_single(FSCAL3,0xE9);  //Frequency Synthesizer Calibration
write_reg_single(FSCAL2,0x2A);  //Frequency Synthesizer Calibration
write_reg_single(FSCAL1,0x00);  //Frequency Synthesizer Calibration
write_reg_single(FSCAL0,0x1F);  //Frequency Synthesizer Calibration
write_reg_single(RCCTRL1,0x41); //RC Oscillator Configuration
write_reg_single(RCCTRL0,0x00); //RC Oscillator Configuration
write_reg_single(FSTEST,0x59);  //Frequency Synthesizer Calibration Control
write_reg_single(PTEST,0x7F);   //Production Test
write_reg_single(AGCTEST,0x3F); //AGC Test
write_reg_single(TEST2,0x81);   //Various Test Settings
write_reg_single(TEST1,0x35);   //Various Test Settings
write_reg_single(TEST0,0x09);   //Various Test Settings
