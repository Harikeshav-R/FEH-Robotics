#include <FEHLCD.h>
#include <FEHRCS.h>
#include <FEHIO.h>
#include "motor.h"


const char* RCS_IDENTIFYING_STRING = "0800A8DJX";
const int MOTOR_PERCENTAGE = 25;

robot::Motor motor_handler {FEHMotor::Motor0, FEHMotor::Motor3, FEHIO::P2_7, FEHIO::P1_7};
DigitalInputPin distance_sensor {FEHIO::P3_7};

// FEHMotor left_motor {FEHMotor::Motor0, 9};
// FEHMotor right_motor {FEHMotor::Motor3, 9};


// void task_1()
// {
//     RCS.InitializeTouchMenu(RCS_IDENTIFYING_STRING);  // Run Menu to select Region (e.g., A, B, C, D)
//     int lever = RCS.GetLever();  // Get a 0, 1, or 2 indicating which lever to pull
//     LCD.WriteLine( RCS.Time() );  // Get the match time remaining
// }

// void test_distance_sensor_minimum_distance()
// {
//     left_motor.SetPercent(LEFT_MOTOR_CORRECTION_FACTOR * MOTOR_PERCENTAGE);
//     right_motor.SetPercent(RIGHT_MOTOR_CORRECTION_FACTOR * MOTOR_PERCENTAGE);

//     while (distance_sensor.Value() == 0);
//     left_motor.Stop();
//     right_motor.Stop();
// }

// void test_distance_sensor_maximum_distance()
// {
//     left_motor.SetPercent(-LEFT_MOTOR_CORRECTION_FACTOR * MOTOR_PERCENTAGE);
//     right_motor.SetPercent(-RIGHT_MOTOR_CORRECTION_FACTOR * MOTOR_PERCENTAGE);

//     while (distance_sensor.Value());
//     left_motor.Stop();
//     right_motor.Stop();
// }

// void test_vertical_distance()
// {
//     LCD.WriteLine("Start moving upward!");
//     while (distance_sensor.Value() == 0);
//     LCD.WriteLine("No longer detected!");

//     Sleep(10.0);

//     LCD.WriteLine("Start moving downward!");
//     while (distance_sensor.Value() == 0);
//     LCD.WriteLine("No longer detected!");
// }

// void maze()
// {
//     motor_handler.move_backwards(MOTOR_PERCENTAGE);
//     while (distance_sensor.Value() == 1);
//     motor_handler.stop();
//     motor_handler.move_forward(MOTOR_PERCENTAGE, 2);
//     motor_handler.rotate_left(MOTOR_PERCENTAGE);
//     motor_handler.move_backwards(MOTOR_PERCENTAGE);
//     while (distance_sensor.Value() == 1);
//     motor_handler.stop();
//     motor_handler.move_forward(MOTOR_PERCENTAGE, 2);
//     motor_handler.rotate_right(MOTOR_PERCENTAGE);
//     motor_handler.move_backwards(MOTOR_PERCENTAGE);
//     while (distance_sensor.Value() == 1);
//     motor_handler.stop();
// }

int main(void)
{
    motor_handler.move_backwards(MOTOR_PERCENTAGE, 24);
    motor_handler.stop();
    Sleep(1.0);
    
    motor_handler.move_forward(MOTOR_PERCENTAGE);
    while (distance_sensor.Value() == 0);
    motor_handler.stop();
}
