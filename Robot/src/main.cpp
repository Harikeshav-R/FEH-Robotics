#include <FEHLCD.h>
#include <FEHMotor.h>
#include <FEHIO.h>

#include "motor.h"

int main(void)
{
    robot::Motor motor_handler {FEHMotor::Motor3, FEHMotor::Motor0, FEHIO::P1_0, FEHIO::P2_7};
    
	return 0;
}