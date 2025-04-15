#include <FEHLCD.h>
#include <FEHMotor.h>
#include <FEHIO.h>
#include <FEHRCS.h>
#include <FEHServo.h>
#include <FEHUtility.h>
#include <FEHSD.h>

#include "cds_cell.h"
#include "motor.h"
#include "opto_sensor.h"
#include "servo.h"
#include "utils.h"

const char* RCS_IDENTIFYING_STRING = "0800A8DJX";

robot::Motor motor_handler {LEFT_MOTOR_PORT, RIGHT_MOTOR_PORT, LEFT_ENCODER_PIN, RIGHT_ENCODER_PIN};

robot::Servo window_servo_handler {WINDOW_SERVO_PORT, WINDOW_SERVO_MIN, WINDOW_SERVO_MAX};
robot::Servo arm_servo_handler {ARM_SERVO_PORT, ARM_SERVO_MIN, ARM_SERVO_MAX};
robot::Servo lever_servo_handler {LEVER_SERVO_PORT, LEVER_SERVO_MIN, LEVER_SERVO_MAX};

robot::CdsCell cds_cell_handler {CDS_CELL_PIN};

robot::OptoSensor opto_sensor_handler {LEFT_OPTO_SENSOR_PIN, MIDDLE_OPTO_SENSOR_PIN, RIGHT_OPTO_SENSOR_PIN};

// int main(){
//     float x, y; // for touch screen

//     // Initialize the screen
//     LCD.Clear(BLACK);
//     LCD.SetFontColor(WHITE);

//     LCD.WriteLine("Analog Optosensor Testing");
//     LCD.WriteLine("Touch the screen");
//     while (!LCD.Touch(&x, &y))
//         ; // Wait for screen to be pressed
//     while (LCD.Touch(&x, &y))
//         ; // Wait for screen to be unpressed

//     LCD.Clear(BLACK);


//     robot::Motor motor_handler {LEFT_MOTOR_PORT, RIGHT_MOTOR_PORT, LEFT_ENCODER_PIN, RIGHT_ENCODER_PIN};

//     float left_opto_on_line_value = left_opto.Value();
//     float right_opto_on_line_value = right_opto.Value();
//     float middle_opto_on_line_value = middle_opto.Value();

//     motor_handler.move_backwards(50, 1);

//     Sleep(1.0);
    
//     float left_opto_off_line_value = left_opto.Value();
//     float right_opto_off_line_value = right_opto.Value();
//     float middle_opto_off_line_value = middle_opto.Value();

//     Sleep(1.0);

//     LCD.Clear(BLACK);

//     LCD.Write("Left opto on line: ");
//     LCD.WriteLine(left_opto_on_line_value);

//     LCD.Write("Left opto off line: ");
//     LCD.WriteLine(left_opto_off_line_value);

//     LCD.Write("Right opto on line: ");
//     LCD.WriteLine(right_opto_on_line_value);

//     LCD.Write("Right opto off line: ");
//     LCD.WriteLine(right_opto_off_line_value);

//     LCD.Write("Middle opto on line: ");
//     LCD.WriteLine(middle_opto_on_line_value);

//     LCD.Write("Middle opto off line: ");
//     LCD.WriteLine(middle_opto_off_line_value);

//     return 0;
// }

    
int main(void)
{    
    RCS.InitializeTouchMenu(RCS_IDENTIFYING_STRING);

    // START ROBOT COMPOSTER TASK
    while (cds_cell_handler.detect_light() != LightType::RED_LIGHT);

    LCD.WriteLine("Start!");

    motor_handler.follow_line(50, opto_sensor_handler, 200);

    // arm_servo_handler.set_degree(50);
    
    // motor_handler.move_forward(50, 23);
    // motor_handler.rotate_left(50, 155);
    // motor_handler.move_backwards(50, 16);
    // motor_handler.move_forward(50, 18.5);

    // for (int i = 0; i < 5; i++)
    // {
    //     arm_servo_handler.set_degree(50, 160, 10, 50);
    //     motor_handler.move_backwards(50, 2);
    //     arm_servo_handler.set_degree(160, 50, 10, 50);
    //     motor_handler.move_forward(50, 2);
    // }

    // motor_handler.move_backwards(50, 2);
    // arm_servo_handler.set_degree(50, 160, 10, 10);

    // motor_handler.move_forward(50, 2);

    // for (int i = 0; i < 3; i++)
    // {
    //     arm_servo_handler.set_degree(160, 50, 10, 50);
    //     motor_handler.move_backwards(50, 2);

    //     arm_servo_handler.set_degree( 50, 160, 10, 50);
    //     motor_handler.move_forward(50, 2);
    // }

    // motor_handler.move_backwards(50, 2);
    // arm_servo_handler.set_degree(0);

    // motor_handler.move_backwards(50, 22);
    // motor_handler.move_forward(50, 10);

    // // END ROBOT COMPOSTER TASK

    // // START ROBOT APPLE BUCKET TASK

    // motor_handler.rotate_right(50, 115);
    // motor_handler.move_backwards(50, 2);

    // arm_servo_handler.set_degree(0, 150, 10, 50);

    // motor_handler.move_forward(50, 3);

    // // // Pick up apple bucket
    // arm_servo_handler.set_degree(150, 50, 10, 50);

    // // Drive back to start
    // motor_handler.move_backwards(50, 4.85);
    // motor_handler.rotate_right(50, 47);
    // motor_handler.move_backwards(50, 17.1);

    // // Drive to place apple bucket
    // motor_handler.rotate_right(50, 42.5);
    // motor_handler.move_forward(50, 42);
    // motor_handler.rotate_right(50, 20);

    // // Place
    // arm_servo_handler.set_degree(50, 140, 10, 50);

    // // END APPLE BUCKET

    // // Align with levers
    // motor_handler.move_backwards(50, 5.3);
    // motor_handler.rotate_left(50, 60);

    // lever_servo_handler.set_degree(0);
    // Sleep(1.0);

    // // Move to lever
    // motor_handler.move_forward(50, 17.5);

    // // Flick lever
    // Sleep(1.0);
    // lever_servo_handler.set_degree(180);
    // Sleep(1.0);

    // motor_handler.move_backwards(50, 5);

    // Sleep(1.0);
    // lever_servo_handler.set_degree(180);
    // Sleep(1.0);

    // motor_handler.move_forward(50, 5);

    // Sleep(1.0);
    // lever_servo_handler.set_degree(0);
    // Sleep(1.0);

	// return 0;
}
