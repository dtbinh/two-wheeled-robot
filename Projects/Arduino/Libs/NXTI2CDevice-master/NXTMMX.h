
// NXTMMX.h
//
// This is a class for controlling the Lego Motor Multiplexer, made by Mindsensors.
// See http://www.mindsensors.com/index.php?module=pagemaster&PAGE_user_op=view_page&PAGE_id=134 .

// Initial version: 2010-06-07 by Clinton Blackmore
// Large ports of the code is ported from the NXC library for the device,
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

#ifndef NXTMMX_H
#define NXTMMX_H

// THE FOLLOWING CONSTANTS ARE ALL FROM THE NXC SOURCE CODE

#define MMX_CONTROL_SPEED      0x01
#define MMX_CONTROL_RAMP       0x02
#define MMX_CONTROL_RELATIVE   0x04
#define MMX_CONTROL_TACHO      0x08
#define MMX_CONTROL_BRK        0x10
#define MMX_CONTROL_ON         0x20
#define MMX_CONTROL_TIME       0x40
#define MMX_CONTROL_GO         0x80

#define MMX_COMMAND		 0x41
#define MMX_VOLTAGE		 0x41

#define MMX_SETPT_M1     0x42
#define MMX_SPEED_M1     0x46
#define MMX_TIME_M1      0x47
#define MMX_CMD_B_M1     0x48
#define MMX_CMD_A_M1     0x49

#define MMX_SETPT_M2     0x4A
#define MMX_SPEED_M2     0x4E
#define MMX_TIME_M2      0x4F
#define MMX_CMD_B_M2     0x50
#define MMX_CMD_A_M2     0x51

/*
 * Read registers.
 */
#define MMX_POSITION_M1  0x62
#define MMX_POSITION_M2  0x66
#define MMX_STATUS_M1    0x72
#define MMX_STATUS_M2    0x73
#define MMX_TASKS_M1     0x76
#define MMX_TASKS_M2     0x77

#define MMX_ENCODER_PID	0x7A
#define MMX_SPEED_PID	0x80
#define MMX_PASS_COUNT	0x86
#define MMX_TOLERANCE	0x87

/* constants to be used by user programs */
/*
 * Motor selection related constants
 */
#define MMX_Motor_1                0x01
#define MMX_Motor_2                0x02
#define MMX_Motor_Both             0x03

/*
 * Next action related constants
 */
// stop and let the motor coast.
#define MMX_Next_Action_Float      0x00
// apply brakes, and resist change to tachometer
#define MMX_Next_Action_Brake      0x01
// apply brakes, and restore externally forced change to tachometer
#define MMX_Next_Action_BrakeHold  0x02

/*
 * Direction related constants
 */
#define MMX_Direction_Forward      0x01
#define MMX_Direction_Reverse      0x00

/*
 * Tachometer related constants
 */
#define MMX_Move_Relative 0x01
#define MMX_Move_Absolute 0x00

#define MMX_Completion_Wait_For    0x01
#define MMX_Completion_Dont_Wait   0x00

/*
 * Speed constants, these are just convenience constants,
 * You can use any value between 0 and 100.
 */
#define MMX_Speed_Full 90
#define MMX_Speed_Medium 60
#define MMX_Speed_Slow 25


#include "NXTI2CDevice.h"

class NXTMMX : public NXTI2CDevice
{
public:
	NXTMMX(uint8_t i2c_address = 0x06);

	uint8_t getBatteryVoltage();
	uint8_t issueCommand(char command);
	bool setEncoderTarget(uint8_t which_motor, long target);
	long getEncoderTarget(uint8_t which_motor);
	bool setSpeed(uint8_t which_motor, int speed);
	int8_t getSpeed(uint8_t which_motor);
	bool getTimeToRun(uint8_t which_motor, int seconds);
	uint8_t getTimeToRun(uint8_t which_motor);
	bool setCommandRegB(uint8_t which_motor, uint8_t value);
	uint8_t getCommandRegB(uint8_t which_motor);
	bool setCommandRegA(uint8_t which_motor, uint8_t value);
	uint8_t getCommandRegA(uint8_t which_motor);
	int32_t getEncoderPosition(uint8_t which_motor);
	uint8_t getMotorStatusByte(uint8_t which_motor);
	uint8_t getMotorTasksRunningByte(uint8_t which_motor);
	bool setEncoderPID(uint16_t Kp, uint16_t Ki, uint16_t Kd);
	bool setSpeedPID(uint16_t Kp, uint16_t Ki, uint16_t Kd);
	bool setPassCount(uint8_t pass_count);
	bool setTolerance(uint8_t tolerance);
	bool reset();
	bool startMotorsInSync();
	bool resetEncoder(uint8_t which_motor);
	bool setSpeedTimeAndControl(uint8_t which_motors, int speed, uint8_t duration, uint8_t control);
	bool setEncoderSpeedTimeAndControl(uint8_t which_motors, long encoder, int speed, uint8_t duration, uint8_t control);
	bool isTimeDone(uint8_t which_motors);
	void waitUntilTimeDone(uint8_t which_motors);
	bool isTachoDone(uint8_t which_motors);
	void waitUntilTachoDone(uint8_t which_motors);
	void runUnlimited(uint8_t which_motors, uint8_t direction, int speed);
	void runSeconds(uint8_t which_motors, uint8_t direction, int speed, uint8_t duration, uint8_t wait_for_completion, uint8_t next_action);
	void runTachometer(uint8_t which_motors, uint8_t direction, int speed, long tachometer, uint8_t relative, uint8_t wait_for_completion, uint8_t next_action);
	void runDegrees(uint8_t which_motors, uint8_t direction,int	speed, long degrees, uint8_t wait_for_completion, uint8_t next_action);
	void runRotations(	uint8_t which_motors, uint8_t direction, int speed, long rotations, uint8_t wait_for_completion, uint8_t next_action);
	bool stop(uint8_t which_motors, uint8_t next_action);
};

#endif