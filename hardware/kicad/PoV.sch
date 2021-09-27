EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "PoV display"
Date "2021-09-27"
Rev "1"
Comp "Filippo Sallemi"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATtiny:ATtiny85-20PU U1
U 1 1 6151AF9F
P 6000 4000
F 0 "U1" H 5471 4046 50  0000 R CNN
F 1 "ATtiny85-20PU" H 5471 3955 50  0000 R CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 6000 4000 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf" H 6000 4000 50  0001 C CNN
	1    6000 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 6151B60E
P 7650 2500
F 0 "D1" H 7643 2245 50  0000 C CNN
F 1 "LED" H 7643 2336 50  0000 C CNN
F 2 "" H 7650 2500 50  0001 C CNN
F 3 "~" H 7650 2500 50  0001 C CNN
	1    7650 2500
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D6
U 1 1 6151B918
P 12350 -9750
F 0 "D6" H 12343 -9534 50  0000 C CNN
F 1 "LED" H 12343 -9625 50  0000 C CNN
F 2 "" H 12350 -9750 50  0001 C CNN
F 3 "~" H 12350 -9750 50  0001 C CNN
	1    12350 -9750
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 6151C9C4
P 7650 2900
F 0 "D2" H 7643 2645 50  0000 C CNN
F 1 "LED" H 7643 2736 50  0000 C CNN
F 2 "" H 7650 2900 50  0001 C CNN
F 3 "~" H 7650 2900 50  0001 C CNN
	1    7650 2900
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D3
U 1 1 6151CCE4
P 7650 3300
F 0 "D3" H 7643 3045 50  0000 C CNN
F 1 "LED" H 7643 3136 50  0000 C CNN
F 2 "" H 7650 3300 50  0001 C CNN
F 3 "~" H 7650 3300 50  0001 C CNN
	1    7650 3300
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D4
U 1 1 6151D7C5
P 7650 3700
F 0 "D4" H 7643 3445 50  0000 C CNN
F 1 "LED" H 7643 3536 50  0000 C CNN
F 2 "" H 7650 3700 50  0001 C CNN
F 3 "~" H 7650 3700 50  0001 C CNN
	1    7650 3700
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D5
U 1 1 6151DAA8
P 7650 4100
F 0 "D5" H 7643 3845 50  0000 C CNN
F 1 "LED" H 7643 3936 50  0000 C CNN
F 2 "" H 7650 4100 50  0001 C CNN
F 3 "~" H 7650 4100 50  0001 C CNN
	1    7650 4100
	-1   0    0    1   
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 61526F5A
P 3650 4050
F 0 "BT1" H 3768 4146 50  0000 L CNN
F 1 "Battery_Cell" H 3768 4055 50  0000 L CNN
F 2 "" V 3650 4110 50  0001 C CNN
F 3 "~" V 3650 4110 50  0001 C CNN
	1    3650 4050
	1    0    0    -1  
$EndComp
$Comp
L pspice:C C1
U 1 1 6152772B
P 4500 4000
F 0 "C1" H 4678 4046 50  0000 L CNN
F 1 "C" H 4678 3955 50  0000 L CNN
F 2 "" H 4500 4000 50  0001 C CNN
F 3 "~" H 4500 4000 50  0001 C CNN
	1    4500 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3400 4500 3400
Wire Wire Line
	4500 3400 4500 3750
Wire Wire Line
	6000 4600 4500 4600
Wire Wire Line
	4500 4600 4500 4250
Wire Wire Line
	3650 4150 3650 4600
Wire Wire Line
	3650 4600 4500 4600
Connection ~ 4500 4600
Wire Wire Line
	6600 4100 7500 4100
Wire Wire Line
	6600 4000 7500 4000
Wire Wire Line
	7500 4000 7500 3700
Wire Wire Line
	6600 3900 7400 3900
Wire Wire Line
	7400 3900 7400 3300
Wire Wire Line
	7400 3300 7500 3300
Wire Wire Line
	6600 3800 7300 3800
Wire Wire Line
	7300 3800 7300 2900
Wire Wire Line
	7300 2900 7500 2900
Wire Wire Line
	7500 2500 7200 2500
Wire Wire Line
	7200 2500 7200 3700
Wire Wire Line
	7200 3700 6600 3700
Wire Wire Line
	6000 4600 7800 4600
Wire Wire Line
	7800 4600 7800 4100
Connection ~ 6000 4600
Wire Wire Line
	7800 4100 7800 3700
Connection ~ 7800 4100
Wire Wire Line
	7800 3700 7800 3300
Connection ~ 7800 3700
Wire Wire Line
	7800 3300 7800 2900
Connection ~ 7800 3300
Wire Wire Line
	7800 2900 7800 2500
Connection ~ 7800 2900
$Comp
L Switch:SW_DPDT_x2 SW1
U 1 1 6154A9DE
P 4050 3300
F 0 "SW1" H 4050 3585 50  0000 C CNN
F 1 "SW_DPDT_x2" H 4050 3494 50  0000 C CNN
F 2 "" H 4050 3300 50  0001 C CNN
F 3 "~" H 4050 3300 50  0001 C CNN
	1    4050 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3300 3650 3300
Wire Wire Line
	3650 3300 3650 3850
Wire Wire Line
	4250 3400 4500 3400
Connection ~ 4500 3400
$EndSCHEMATC