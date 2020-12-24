   
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X                                                                           X
X   Artwork and documentation done by: Texas Instrument                     X
X                                                                           X
X   Company: Texas Instrument Norway Gaustadalleen 21    0349 OSLO          X
X                                                                           X
X   Phone  : +47 22 95 85 44   Fax :  +47 22 95 85 46                       X
X                                                                           X
X                                                                           X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

PROJECT : 02552
PCB NAME : CC1101EM 868/915MHz
REVISION: 3.0.0 (schematic rev 3.0.0, PCB rev 3.0.0)
DATE: 2010-02-15


Manufacturers marking: Two letter + year + week
The two letter code shall identify the manufaturer and is decided by the manufacturer. 
No logos or other identifyers are allowed.
The marking shall be in silk screen print at secondary side of the PCB, or in solder 
resist if no silk print at secondary side.


FILE: CC1101EM_868_915MHz_3_0_0.ZIP PACKED WITH WinZIP 

PCB DESCRIPTION: 2 LAYER PCB 0.8 MM NOMINAL THICKNESS FR4
		Dimensions in mil (0.001 inch)
                            DOUBLE SIDE SOLDER MASK,
                            DOUBLE SIDE SILKSCREEN,
                            8 MIL MIN TRACE WIDTH AND 8 MIL MIN ISOLATION
		Dielectric constant for FR4 is 4.5
               
               
FILE NAME            		DESCRIPTION                               	FILE TYPE
-------------------------------------------------------------------------------------------
***PCB MANUFACTURING FILES:
l1.SPL                  LAYER 1 COMPONENT SIDE/POSITIV              EXT. GERBER
l2.SPL                  LAYER 2 Inner layer/POSITIV                 EXT. GERBER

STOPCOMP.SPL            SOLDER MASK COMPONENT SIDE/NEGATIVE         EXT. GERBER
STOPSOLD.SPL            SOLDER MASK SOLDER SIDE/NEGATIVE            EXT. GERBER

SILKCOMP.SPL            SILKSCREEN COMPONENT SIDE/POSITIVE          EXT. GERBER
SILKSOLD.SPL            SILKSCREEN SOLDER SIDE/POSITIVE             EXT. GERBER

PASTCOMP.SPL            SOLDER PAST COMPONENT SIDE/POSITIVE         EXT. GERBER
PATSOLD.SPL             SOLDER PAST SOLDER SIDE/POSITIVE            EXT. GERBER

ASSYCOMP.SPL            ASSEMBLY DRAWING COMPONENT SIDE					    EXT. GERBER
ASSYSOLD.SPL            ASSEMBLY DRAWING SOLDER SIDE				|       EXT. GERBER

NCDRILL.SPL             NC DRILL THROUGH HOLE                       EXCELLON
DRILL.SPL               DRILL/MECHANICAL DRAWING                    EXT. GERBER

GERBER.REP              DRILL/NC DRILL REPORT                       ASCII

P&PCOMP.REP             PICK AND PLACE FILE COMPONENT SIDE          ASCII
P&PSOLD.REP             PICK AND PLACE FILE SOLDER SIDE             ASCII

EXT_GERBER.USR          EXTENDED GERBER APERTURE TABLE              ASCII
CNC.USR                 NC DRILL DEVICE FILE                        ASCII

CC1100EM_868_915MHz_PARTLIST_3_0_0.xls		PART LIST									ASCII

***PDF FILES:
CC1101EM_868_915MHz_SCHEMATIC_3_0_0.PDF	Circuit Diagram
CC1101EM_868_915MHz_LAYOUT_3_0_0.PDF		Layout Diagram

***CADSTAR FILES:
CC1101EM_868_915MHz_3_0_0.SCM			Cadstar Schematic file
CC1101EM_868_915MHz_3_0_0.CSA			Cadstar Shematic archive
CC1101EM_868_915MHz_3_0_0.PCB			Cadstar Layout file
CC1101EM_868_915MHz_3_0_0.CPA			Cadstar PCB archive

README.TXT              THIS FILE                                   ASCII


***REVISION HISTORY

Changes from rev 1.0 to 2.2: 
	Added possibility for notch filter (C126 and L125). Notch filter is not mounted.
	Capacitor C125 changed to 12 pF.
	Inductors changed from multi-layer LQG15HS series to wire-wound LQW18 series.

Changes from rev 2.2 to 3.0.0: 
	Crystal X1 changed to size 3.2x2.5 mm (NX3225GA)
	Changed crystal loading capacitors C81 and C101 to 12 pF and 15 pF respectively
	Decoupling capacitors C181, C151, C141, C111, C91 changed to 100 nF

END.