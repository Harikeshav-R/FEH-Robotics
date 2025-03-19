#include "utils.h"
#include "FEHLCD.h"

namespace robot
{
    float degrees_to_radians(int degrees)
    {
        return (3.14 / 180) * degrees;
    }

    float degrees_to_radians(float degrees)
    {
        return (3.14 / 180) * degrees;
    }

    void encoder_test(int speed, int milliseconds, Motor motor_handler)
    {
        motor_handler.move_forward(speed);
        Sleep(milliseconds);
        motor_handler.stop();

        LCD.Write("Left encoder count: ");
        LCD.WriteLine(motor_handler.left_encoder_counts());

        LCD.Write("Right encoder count: ");
        LCD.WriteLine(motor_handler.right_encoder_counts());
    }

    void encoder_test(int speed, float seconds, Motor motor_handler)
    {
        motor_handler.move_forward(speed);
        Sleep(seconds);
        motor_handler.stop();

        LCD.Write("Left encoder count: ");
        LCD.WriteLine(motor_handler.left_encoder_counts());

        LCD.Write("Right encoder count: ");
        LCD.WriteLine(motor_handler.right_encoder_counts());
    }
}