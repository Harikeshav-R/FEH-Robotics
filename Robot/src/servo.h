#pragma once

#include <FEHServo.h>
#include "constants.h"


namespace robot
{
    class Servo
    {
    private:
        FEHServo servo;

    public:
        Servo(
            FEHServo::FEHServoPort servo_port,
            int minimum,
            int maximum
        );

        void set_degree(int degree);
        void set_degree(float degree);

        void calibrate();
    };
} // namespace robot
