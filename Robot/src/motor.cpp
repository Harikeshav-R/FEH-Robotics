#include "motor.h"
#include "utils.h"

namespace robot
{
    Motor::Motor(
        FEHMotor::FEHMotorPort left_motor_port,
        FEHMotor::FEHMotorPort right_motor_port,
        FEHIO::FEHIOPin left_encoder_pin,
        FEHIO::FEHIOPin right_encoder_pin
    ) : left_motor(left_motor_port, DEFAULT_VOLTAGE),
        right_motor(right_motor_port, DEFAULT_VOLTAGE),
        left_encoder(left_encoder_pin),
        right_encoder(right_encoder_pin) {}

    void Motor::stop()
    {
        left_motor.Stop();
        right_motor.Stop();
    }

    void Motor::move(int motor_speed, float distance, bool forward)
    {
        left_encoder.ResetCounts();
        right_encoder.ResetCounts();

        float counts = distance * COUNTS_PER_INCH;
        int speed = forward ? motor_speed : -motor_speed;
        left_motor.SetPercent(speed * LEFT_MOTOR_SPEED_CORRECTION);
        right_motor.SetPercent(speed * RIGHT_MOTOR_SPEED_CORRECTION);

        while ((left_encoder.Counts() + right_encoder.Counts()) / 2.0 < counts);

        stop();
    }

    void Motor::move_forward(int motor_speed)
    {
        move(motor_speed, FLT_MAX, true);
    }

    void Motor::move_forward(int motor_speed, float distance)
    {
        move(motor_speed, distance, true);
    }

    void Motor::move_backwards(int motor_speed)
    {
        move(motor_speed, FLT_MAX, false);
    }

    void Motor::move_backwards(int motor_speed, float distance)
    {
        move(motor_speed, distance, false);
    }

    void Motor::rotate(int turn_speed, float degrees, bool left)
    {
        left_encoder.ResetCounts();
        right_encoder.ResetCounts();

        float counts = (WHEEL_SPAN / 2) * degrees_to_radians(degrees) * COUNTS_PER_INCH;
        int left_speed = left ? -turn_speed : turn_speed;
        int right_speed = left ? turn_speed : -turn_speed;

        left_motor.SetPercent(left_speed * LEFT_MOTOR_SPEED_CORRECTION);
        right_motor.SetPercent(right_speed * RIGHT_MOTOR_SPEED_CORRECTION);

        while ((left_encoder.Counts() + right_encoder.Counts()) / 2.0 < counts);

        stop();
    }

    void Motor::rotate_left(int turn_speed)
    {
        rotate(turn_speed, 90, true);
    }

    void Motor::rotate_left(int turn_speed, float degrees)
    {
        rotate(turn_speed, degrees, true);
    }

    void Motor::rotate_right(int turn_speed)
    {
        rotate(turn_speed, 90, false);
    }

    void Motor::rotate_right(int turn_speed, float degrees)
    {
        rotate(turn_speed, degrees, false);
    }
}
