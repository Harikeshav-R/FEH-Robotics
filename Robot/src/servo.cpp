#include "servo.h"

namespace robot
{
    Servo::Servo(
        FEHServo::FEHServoPort servo_port,
        int minimum,
        int maximum
    ) : servo(servo_port)
    {
        servo.SetMin(minimum);
        servo.SetMax(maximum);
    }

    void Servo::set_degree(int degree)
    {
        servo.SetDegree(degree);
    }

    void Servo::set_degree(float degree)
    {
        servo.SetDegree(degree);
    }

    void Servo::calibrate()
    {
        servo.TouchCalibrate();
    }
}
