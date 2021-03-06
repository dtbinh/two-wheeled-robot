
// NXTServo.h
//
// This is a class for controlling the NXT Servo Controller, made by Mindsensors.
// See http://www.mindsensors.com/index.php?module=pagemaster&PAGE_user_op=view_page&PAGE_id=93 .

// Initial version: 2010-06-17 by Andrew Sylvester.
// Large parts of the code is ported from the NXC library for the device,
// written by Deepak Patil.

/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef NXTServo_H
#define NXTServo_H

#define Servo_Command				0x41
#define Servo_Voltage				0x41

#define Servo_1						1
#define Servo_2						2
#define Servo_3						3
#define Servo_4						4
#define Servo_5						5	
#define Servo_6						6	
#define Servo_7						7
#define Servo_8						8

#define Servo_Position_Default		1500
#define Servo_Speed_Full			0

#define Servo_Position_1			0x5A			
#define Servo_Position_2			0x5B	
#define Servo_Position_3			0x5C	
#define Servo_Position_4			0x5D	
#define Servo_Position_5			0x5E	
#define Servo_Position_6			0x5F	
#define Servo_Position_7			0x60	
#define Servo_Position_8			0x61

#define Servo_Speed_1				0x52			
#define Servo_Speed_2				0x53	
#define Servo_Speed_3				0x54	
#define Servo_Speed_4				0x55	
#define Servo_Speed_5				0x56	
#define Servo_Speed_6				0x57	
#define Servo_Speed_7				0x58	
#define Servo_Speed_8				0x59

#include "NXTI2CDevice.h"

class NXTServo : public NXTI2CDevice
{
public:
	NXTServo(uint8_t i2c_address = 0xb0);
	
	uint8_t issueCommand(char command);
    uint8_t getBatteryVoltage();
	bool storeInitial();
	bool reset();
	bool haltMacro();
	bool resumeMacro();
	bool gotoEEPROM();
	bool editMacro();
	bool pauseMacro();
	bool setSpeed(uint8_t number, uint8_t speed);
	bool setPosition(uint8_t number, uint8_t position);
	void runServo(uint8_t number, uint8_t position, uint8_t speed);

};

#endif
