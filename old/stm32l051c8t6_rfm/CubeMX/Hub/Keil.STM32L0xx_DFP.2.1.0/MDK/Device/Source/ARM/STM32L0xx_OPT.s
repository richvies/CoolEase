;/*****************************************************************************/
;/* STM32L0xx_OPT.s: STM32L0xx Flash Option Bytes                             */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */
;/*****************************************************************************/
;/*  This file is part of the uVision/ARM development tools                   */
;/*  Copyright (c) 2015 - 2019 Keil - An ARM Company.                         */
;/*  All rights reserved.                                                     */
;/*****************************************************************************/

; Option byte organization
;-------------------------
;   Address     [31:24] [23:16] [15:8] [7:0]
; 0x1FF80000       -     nRDP      -    RDP	            (0xFF5500AA)
; 0x1FF80004     nUSER1  nUSER0  USER1  USER0           (0x7F8F8070)
; 0x1FF80008     nWRP1_1   nWRP1_0   WRP1_1   WRP1_0    (0xFFFF0000)
; 0x1FF8000C     nWRP1_3   nWRP1_2   WRP1_3   WRP1_2    (0xFFFF0000)
; 0x1FF80010     nWRP2_1   nWRP2_0   WRP2_1   WRP2_0    (0xFFFF0000)

;// <e> Flash Option Bytes
FLASH_OPT       EQU     1

;// <h> Flash Protection
;//     <i> Read protection is used to protect the software code stored in Flash memory
;//   <o0> Read Protection Level
;//     <i> Level 0: No Protection 
;//     <i> Level 1: Read Protection of Memories (memory read protection enabled!)
;//     <i> Level 2: Chip Protection (memory read protection enabled and all debug features disabled!)
;//     <i> Note: Mass Erase is performed when Level 1 is active and Level 0 is requested
;//          <0xAA=> Level 0 (No Protection) 
;//          <0x00=> Level 1 (Read Protection of Memories)
;//          <0xCC=> Level 2 (Chip Protection)
;//   <o1.0> WPRMOD <i> This bit selects between write and read protection of Flash program memory sectors.
;//          <0=> Write Protection enable <1=> Read Protection enable
;// </h>
RDP0             EQU     0xAA
RDP1             EQU     0x00
nRDP0            EQU     RDP0:EOR:0xFF
nRDP1            EQU     RDP1:EOR:0xFF

;// <h> Flash Write/Read Protection
;//   <h> WRP1_0..WRP1_3
;//     <o0.0> Sector 0
;//     <o0.1> Sector 1
;//     <o0.2> Sector 2
;//     <o0.3> Sector 3
;//     <o0.4> Sector 4
;//     <o0.5> Sector 5
;//     <o0.6> Sector 6
;//     <o0.7> Sector 7
;//     <o1.0> Sector 8
;//     <o1.1> Sector 9
;//     <o1.2> Sector 10
;//     <o1.3> Sector 11
;//     <o1.4> Sector 12
;//     <o1.5> Sector 13
;//     <o1.6> Sector 14
;//     <o1.7> Sector 15
;//     <o2.0> Sector 16
;//     <o2.1> Sector 17
;//     <o2.2> Sector 18
;//     <o2.3> Sector 19
;//     <o2.4> Sector 20
;//     <o2.5> Sector 21
;//     <o2.6> Sector 22
;//     <o2.7> Sector 23
;//     <o3.0> Sector 24
;//     <o3.1> Sector 25
;//     <o3.2> Sector 25
;//     <o3.3> Sector 27
;//     <o3.4> Sector 28
;//     <o3.5> Sector 29
;//     <o3.6> Sector 30
;//     <o3.7> Sector 31
;//   </h>
WRP1_00           EQU     0x00
WRP1_01           EQU     0x00
WRP1_02           EQU     0x00
WRP1_03           EQU     0x00
nWRP1_00          EQU     WRP1_00:EOR:0xFF
nWRP1_01          EQU     WRP1_01:EOR:0xFF
nWRP1_02          EQU     WRP1_02:EOR:0xFF
nWRP1_03          EQU     WRP1_03:EOR:0xFF
;
;//   <h> WRP2_0..WRP2_1
;//     <o0.0> Sector 32
;//     <o0.1> Sector 33
;//     <o0.2> Sector 34
;//     <o0.3> Sector 35
;//     <o0.4> Sector 36
;//     <o0.5> Sector 37
;//     <o0.6> Sector 38
;//     <o0.7> Sector 39
;//     <o1.0> Sector 40
;//     <o1.1> Sector 41
;//     <o1.2> Sector 42
;//     <o1.3> Sector 43
;//     <o1.4> Sector 44
;//     <o1.5> Sector 45
;//     <o1.6> Sector 46
;//     <o1.7> Sector 47
;//   </h>
WRP2_00           EQU     0x00
WRP2_01           EQU     0x00
nWRP2_00          EQU     WRP2_00:EOR:0xFF
nWRP2_01          EQU     WRP2_01:EOR:0xFF
;// </h>

;// <h> User Configuration
;//   <o0.0..3> BOR_LEV     
;//          < 0=> BOR OFF:     Reset threshold level for 1.45V - 1.55V (power down only)
;//          < 1=> BOR OFF:     Reset threshold level for 1.45V - 1.55V (power down only)
;//          < 2=> BOR OFF:     Reset threshold level for 1.45V - 1.55V (power down only)
;//          < 3=> BOR OFF:     Reset threshold level for 1.45V - 1.55V (power down only)
;//          < 4=> BOR OFF:     Reset threshold level for 1.45V - 1.55V (power down only)
;//          < 5=> BOR OFF:     Reset threshold level for 1.45V - 1.55V (power down only)
;//          < 6=> BOR OFF:     Reset threshold level for 1.45V - 1.55V (power down only)
;//          < 7=> BOR OFF:     Reset threshold level for 1.45V - 1.55V (power down only)
;//          < 8=> BOR LEVEL 0: Reset threshold level for 1.69V - 1.80V (power on)
;//          < 9=> BOR LEVEL 1: Reset threshold level for 1.94V - 2.10V (power on)
;//          <10=> BOR LEVEL 2: Reset threshold level for 2.30V - 2.49V (power on)
;//          <11=> BOR LEVEL 3: Reset threshold level for 2.54V - 2.74V (power on)
;//          <12=> BOR LEVEL 4: Reset threshold level for 2.77V - 3.00V (power on)
;//   <o0.4> IWDG_SW     
;//          <0=> HW Watchdog <1=> SW Watchdog
;//   <o0.5> nRST_STOP  <i> Generate Reset when entering STOP Mode
;//          <0=> Enabled <1=> Disabled
;//   <o0.6> nRST_STDBY <i> Generate Reset when entering Standby Mode
;//          <0=> Enabled <1=> Disabled
;//   <o0.7> BFB2 <i> Boot from Bank 2
;//               <i> This bit is available in category 5 devices only!
;//          <0=> BOOT from Bank 1
;//          <1=> BOOT from System memory
;//   <o1.5> nBOOT_SEL <i> Select BOOT0 signal. 
;//                    <i> This bit is available on category 1 devices only!
;//          <0=> BOOT0 signal is defined by BOOT0 pin value
;//          <1=> BOOT0 signal is defined by nBOOT0 option bit
;//   <o1.6> nBOOT0 <i> When nBOOT_SEL is cleared, nBOOT0 bit defines the value of BOOT0 signal. 
;//                 <i> This bit is available on category 1 devices only!
;//          <0=> Reset <1=> Set
;//   <o1.7> nBOOT1 <i> This bit is used in conjunction with BOOT0 signal to configure the device boot mode
;//          <0=> Reset <1=> Set
;// </h>
USER0           EQU     0x70
USER1           EQU     0x80
nUSER0          EQU     USER0:EOR:0xFF
nUSER1          EQU     USER1:EOR:0xFF

;// </e>


                IF      FLASH_OPT <> 0
                AREA    |.ARM.__AT_0x1FF80000|, CODE, READONLY
                DCB     RDP0,  RDP1,  nRDP0,  nRDP1      
                DCB     USER0, USER1, nUSER0, nUSER1      
                DCB     WRP1_00, WRP1_01, nWRP1_00, nWRP1_01
                DCB     WRP1_02, WRP1_03, nWRP1_02, nWRP1_03
                DCB     WRP2_00, WRP2_01, nWRP2_00, nWRP2_01
                ENDIF


                END
