#pragma once

namespace robot
{
    float degrees_to_radians(int degrees);

    float degrees_to_radians(float degrees);

    float encoder_test(int speed, int milliseconds, Motor motor_handler);

    float encoder_test(int speed, float seconds, Motor motor_handler);
}