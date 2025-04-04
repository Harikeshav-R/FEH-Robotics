#include <FEHLCD.h>
#include <FEHMotor.h>
#include <FEHIO.h>
#include <FEHRCS.h>
#include <FEHServo.h>
#include <FEHSD.h>
#include <FEHUtility.h>
#include <FEHBuzzer.h>

#include "cds_cell.h"
#include "motor.h"
#include "servo.h"
#include "utils.h"

const char* RCS_IDENTIFYING_STRING = "0800A8DJX";

AnalogInputPin right_opto(FEHIO::P1_0);
AnalogInputPin middle_opto(FEHIO::P1_3);
AnalogInputPin left_opto(FEHIO::P1_7);



void zelda()
{
    Buzzer.Tone(FEHBuzzer::A5, 1000);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 500);
    Buzzer.Tone(FEHBuzzer::G4, 100);
    Buzzer.Tone(FEHBuzzer::A5, 500);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 500);
    Buzzer.Tone(FEHBuzzer::G4, 100);
    Buzzer.Tone(FEHBuzzer::A5, 500);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::E4, 50);
    Buzzer.Tone(FEHBuzzer::E4, 50);
    Buzzer.Tone(FEHBuzzer::E4, 100);
    Buzzer.Tone(FEHBuzzer::E4, 50);
    Buzzer.Tone(FEHBuzzer::E4, 50);
    Buzzer.Tone(FEHBuzzer::E4, 100);
    Buzzer.Tone(FEHBuzzer::E4, 50);
    Buzzer.Tone(FEHBuzzer::E4, 50);
    Buzzer.Tone(FEHBuzzer::E4, 100);
    Buzzer.Tone(FEHBuzzer::E4, 100);
    Buzzer.Tone(FEHBuzzer::A5, 500);
    Buzzer.Tone(FEHBuzzer::E4, 750);
    Buzzer.Tone(FEHBuzzer::A5, 100);
    Buzzer.Tone(FEHBuzzer::A5, 50);
    Buzzer.Tone(FEHBuzzer::B5, 50);
    Buzzer.Tone(FEHBuzzer::Cs5, 50);
    Buzzer.Tone(FEHBuzzer::D5, 50);
    Buzzer.Tone(FEHBuzzer::E5, 1000);
    Buzzer.Tone(FEHBuzzer::E5, 100);
    Buzzer.Tone(FEHBuzzer::E5, 100);
    Buzzer.Tone(FEHBuzzer::F5, 100);
    Buzzer.Tone(FEHBuzzer::G5, 100);
    Buzzer.Tone(FEHBuzzer::A6, 1000);
    Buzzer.Tone(FEHBuzzer::A6, 100);
    Buzzer.Tone(FEHBuzzer::A6, 100);
    Buzzer.Tone(FEHBuzzer::G5, 100);
    Buzzer.Tone(FEHBuzzer::F5, 100);
    Buzzer.Tone(FEHBuzzer::G5, 250);
    Buzzer.Tone(FEHBuzzer::F5, 100);
    Buzzer.Tone(FEHBuzzer::E5, 1000);
}



void set_degree_slowly(robot::Servo servo, int start_degree, int end_degree, int iterations, int sleep_delay)
{
    int current_degree = start_degree;
    servo.set_degree(current_degree);

    float increment = (end_degree - start_degree) / iterations;

    for (int i = 0; i < iterations; i++)
    {
        servo.set_degree(current_degree);
        current_degree += increment;
        Sleep(sleep_delay);
    }
}


void opto_sensor_test(){
    float x, y; // for touch screen

    FEHFile *output_file = SD.FOpen("output.txt", "w");

    // Initialize the screen
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);

    LCD.WriteLine("Analog Optosensor Testing : Straight Line");
    LCD.WriteLine("Touch the screen");
    while (!LCD.Touch(&x, &y))
        ; // Wait for screen to be pressed
    while (LCD.Touch(&x, &y))
        ; // Wait for screen to be unpressed

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor on straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Left optosensor on straight line: %f\n", left_opto.Value());

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor off straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Left optosensor off straight line: %f\n", left_opto.Value());

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place right optosensor on straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Right optosensor on straight line: %f\n", right_opto.Value());

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place right optosensor off straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Right optosensor off straight line: %f\n", right_opto.Value());

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor on straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Middle optosensor on straight line: %f\n", middle_opto.Value());

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor off straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Middle optosensor off straight line: %f\n", middle_opto.Value());
}
    
int main(void)
{
    zelda();
    
    robot::Motor motor_handler {LEFT_MOTOR_PORT, RIGHT_MOTOR_PORT, LEFT_ENCODER_PIN, RIGHT_ENCODER_PIN};
    robot::Servo window_servo {WINDOW_SERVO_PORT, WINDOW_SERVO_MIN, WINDOW_SERVO_MAX};
    robot::Servo arm_servo {ARM_SERVO_PORT, ARM_SERVO_MIN, ARM_SERVO_MAX};

    robot::CdsCell cds_cell_handler {CDS_CELL_PIN};

    // while (1)
    // {
    //     set_degree_slowly(arm_servo, 50, 160, 10, 50);
    //     Sleep(500);
    //     set_degree_slowly(arm_servo, 160, 50, 10, 50);
    //     Sleep(500);
    // }

    while (cds_cell_handler.detect_light() != LightType::RED_LIGHT);

    LCD.WriteLine("Start!");

    arm_servo.set_degree(50);
    
    motor_handler.move_forward(50, 23.6);
    motor_handler.rotate_left(50, 137);
    motor_handler.move_forward(50, 6.9);

    for (int i = 0; i < 5; i++)
    {
        // arm_servo.set_degree(160);
        set_degree_slowly(arm_servo, 50, 160, 10, 50);
        // Sleep(500);

        motor_handler.move_backwards(50, 4);

        // Sleep(500);
        // arm_servo.set_degree(50);
        set_degree_slowly(arm_servo, 160, 50, 10, 50);
        // Sleep(500);

        motor_handler.move_forward(50, 4);
    }

    motor_handler.move_backwards(50, 4);
    arm_servo.set_degree(160);
    // motor_handler.rotate_right(50, 10);
    Sleep(500);

    motor_handler.move_forward(50, 4);

    for (int i = 0; i < 5; i++)
    {
        // arm_servo.set_degree(50);
        set_degree_slowly(arm_servo, 160, 50, 10, 50);
        // Sleep(500);

        motor_handler.move_backwards(50, 4);

        // Sleep(500);
        // arm_servo.set_degree(160);
        set_degree_slowly(arm_servo, 50, 160, 10, 50);
        // Sleep(500);

        motor_handler.move_forward(50, 4);
    }


    motor_handler.move_backwards(50, 2);
    arm_servo.set_degree(0);
    motor_handler.move_backwards(50, 4.9);
    motor_handler.rotate_right(50, 147);
    motor_handler.move_backwards(50, 26);

    // motor_handler.move_forward(50, 4);

    // while (true) { cds_cell_handler.detect_light(); }

    // RCS.InitializeTouchMenu(RCS_IDENTIFYING_STRING);

    // // while (cds_cell_handler.detect_light() != LightType::RED_LIGHT);

    // LCD.WriteLine("Start!");

    // arm_servo.set_degree(150);

    // // Drive to apple bucket
    // motor_handler.move_forward(50, 5);
    // motor_handler.rotate_right(50, 15);
    // motor_handler.move_forward(50, 13.3);
    // motor_handler.rotate_left(50, 60);
    // motor_handler.move_forward(50, 4.85);

    // Sleep(1.0);

    // // Pick up apple bucket
    // arm_servo.set_degree(90);

    // Sleep(1.0);

    // // Drive back to start
    // motor_handler.move_backwards(50, 4.85);
    // motor_handler.rotate_right(50, 47);
    // motor_handler.move_backwards(50, 17.1);

    // // Drive to place apple bucket
    // motor_handler.rotate_right(50, 42.5);
    // motor_handler.move_forward(50, 42);
    // motor_handler.rotate_right(50, 20);

    // // Place
    // Sleep(1.0);
    // arm_servo.set_degree(140);
    // Sleep(1.0);

    // // Align with levers
    // motor_handler.move_backwards(50, 5.3);
    // motor_handler.rotate_left(50, 60);

    // arm_servo.set_degree(40);
    // Sleep(1.0);

    // // Move to lever
    // motor_handler.move_forward(50, 17.5);

    // // Flick lever
    // Sleep(1.0);
    // arm_servo.set_degree(160);
    // Sleep(1.0);

    // motor_handler.move_backwards(50, 5);

    // Sleep(1.0);
    // arm_servo.set_degree(180);
    // Sleep(1.0);

    // motor_handler.move_forward(50, 5);

    // Sleep(1.0);
    // arm_servo.set_degree(0);
    // Sleep(1.0);

	// return 0;
}