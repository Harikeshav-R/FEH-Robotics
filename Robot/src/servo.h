#pragma once

#include <FEHServo.h>
#include <FEHUtility.h>
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
        void set_degree(int start_degree, int end_degree, int iterations, int sleep_delay);

        void calibrate();
    };
} // namespace robot
