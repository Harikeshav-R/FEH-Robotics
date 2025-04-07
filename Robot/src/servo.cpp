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

    void Servo::set_degree(int start_degree, int end_degree, int iterations, int sleep_delay)
    {
        int current_degree = start_degree;
        servo.SetDegree(current_degree);

        float increment = (end_degree - start_degree) / iterations;

        for (int i = 0; i < iterations; i++)
        {
            servo.SetDegree(current_degree);
            current_degree += increment;
            Sleep(sleep_delay);
        }
    }

    void Servo::calibrate()
    {
        servo.TouchCalibrate();
    }
}
