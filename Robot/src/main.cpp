#include <FEHLCD.h>
#include <FEHMotor.h>
#include <FEHIO.h>

#include "motor.h"
#include "cds_cell.h"


int main(void)
{
    robot::Motor motor_handler {FEHMotor::Motor3, FEHMotor::Motor0, FEHIO::P1_0, FEHIO::P2_7};
    robot::CdsCell cds_cell_handler {FEHIO::P2_0};

    LightType start_light;

    while (1)
    {
        start_light = cds_cell_handler.detect_light();
        if (start_light == RED_LIGHT)
        {
            break;
        }
    }

    LCD.WriteLine("Start!");

    motor_handler.move_forward(50, 3);
    motor_handler.rotate_right(50, 65);
    motor_handler.move_forward(50, 8.3);
    motor_handler.rotate_left(50, 18);
    motor_handler.move_forward(50, 35);
    motor_handler.rotate_left(50, 100);
    motor_handler.move_backwards(75, 8);
    motor_handler.move_forward(50, 17.5);

    Sleep(1.0);

    LightType humidifier_light;


    while (1)
    {
        humidifier_light = cds_cell_handler.detect_light();
        if (humidifier_light == RED_LIGHT || humidifier_light == BLUE_LIGHT)
        {
            break;
        }
    }
    
    switch (humidifier_light)
    {
        case BLUE_LIGHT:
        {
            LCD.WriteLine("Blue light detected!");
            motor_handler.rotate_left(50, 20);
            motor_handler.move_forward(50, 4);
            motor_handler.rotate_right(50, 20);
            motor_handler.move_forward(50, 6);

            motor_handler.move_backwards(50, 6);
            motor_handler.rotate_left(50, 20);
            motor_handler.move_backwards(50, 4);
            motor_handler.rotate_right(50, 20);
            break;
        }

        case RED_LIGHT:
        {
            LCD.WriteLine("Red light detected!");
            motor_handler.rotate_right(50, 20);
            motor_handler.move_forward(50, 4);
            motor_handler.rotate_left(50, 20);
            motor_handler.move_forward(50, 6);

            motor_handler.move_backwards(50, 6);
            motor_handler.rotate_right(50, 20);
            motor_handler.move_backwards(50, 4);
            motor_handler.rotate_left(50, 20);
            break;
        }
    }

    motor_handler.move_backwards(50, 15);
    motor_handler.move_forward(50, 5);
    motor_handler.rotate_right(50, 85);
    motor_handler.move_backwards(80, 50);
}