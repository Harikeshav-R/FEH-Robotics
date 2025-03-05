#include "motor.h"
#include "utils.h"
#include <FEHLCD.h>

namespace robot
{
    Motor::Motor(
        FEHMotor::FEHMotorPort left_motor_port,
        FEHMotor::FEHMotorPort right_motor_port,
        FEHIO::FEHIOPin left_encoder_pin,
        FEHIO::FEHIOPin right_encoder_pin
    )
    {
        this->voltage = DEFAULT_VOLTAGE;

        this->left_motor = new FEHMotor(left_motor_port, this->voltage);
        this->right_motor = new FEHMotor(right_motor_port, this->voltage);

        this->left_encoder = new DigitalEncoder(left_encoder_pin);
        this->right_encoder = new DigitalEncoder(right_encoder_pin);
    }

    Motor::~Motor()
    {
        delete this->left_motor;
        delete this->right_motor;

        delete this->left_encoder;
        delete this->right_encoder;
    }

    void Motor::stop()
    {
        right_motor->Stop();
        left_motor->Stop();
    }

    void Motor::move_forward(int motor_speed)
    {
        right_encoder->ResetCounts();
        left_encoder->ResetCounts();

        right_motor->SetPercent(motor_speed * RIGHT_MOTOR_SPEED_CORRECTION);
        left_motor->SetPercent(motor_speed * LEFT_MOTOR_SPEED_CORRECTION);
    }

    void Motor::move_forward(int motor_speed, float distance)
    {
        right_encoder->ResetCounts();
        left_encoder->ResetCounts();

        float counts = distance * COUNTS_PER_INCH;

        right_motor->SetPercent(motor_speed * RIGHT_MOTOR_SPEED_CORRECTION);
        left_motor->SetPercent(motor_speed * LEFT_MOTOR_SPEED_CORRECTION);

        while((left_encoder->Counts() + right_encoder->Counts()) / 2. < counts);

        right_motor->Stop();
        left_motor->Stop();
    }

    void Motor::move_backwards(int motor_speed)
    {
        right_encoder->ResetCounts();
        left_encoder->ResetCounts();

        right_motor->SetPercent(-motor_speed * RIGHT_MOTOR_SPEED_CORRECTION);
        left_motor->SetPercent(-motor_speed * LEFT_MOTOR_SPEED_CORRECTION);
    }

    void Motor::move_backwards(int motor_speed, float distance)
    {
        right_encoder->ResetCounts();
        left_encoder->ResetCounts();

        float counts = distance * COUNTS_PER_INCH;

        right_motor->SetPercent(-motor_speed * RIGHT_MOTOR_SPEED_CORRECTION);
        left_motor->SetPercent(-motor_speed * LEFT_MOTOR_SPEED_CORRECTION);

        while((left_encoder->Counts() + right_encoder->Counts()) / 2. < counts);

        right_motor->Stop();
        left_motor->Stop();
    }

    void Motor::rotate_left(int turn_speed)
    {
        right_encoder->ResetCounts();
        left_encoder->ResetCounts();

        float distance = (WHEEL_SPAN / 2) * degrees_to_radians(90);
        float counts = distance * COUNTS_PER_INCH;

        right_motor->SetPercent(turn_speed * RIGHT_MOTOR_SPEED_CORRECTION);
        left_motor->SetPercent(-turn_speed * LEFT_MOTOR_SPEED_CORRECTION);

        while((left_encoder->Counts() + right_encoder->Counts()) / 2. < counts);

        right_motor->Stop();
        left_motor->Stop();
    }

    void Motor::rotate_left(int turn_speed, float degrees)
    {
        right_encoder->ResetCounts();
        left_encoder->ResetCounts();

        float distance = (WHEEL_SPAN / 2) * degrees_to_radians(degrees);
        float counts = distance * COUNTS_PER_INCH;

        right_motor->SetPercent(turn_speed * RIGHT_MOTOR_SPEED_CORRECTION);
        left_motor->SetPercent(-turn_speed * LEFT_MOTOR_SPEED_CORRECTION);

        while((left_encoder->Counts() + right_encoder->Counts()) / 2. < counts);

        right_motor->Stop();
        left_motor->Stop();
    }

    void Motor::rotate_right(int turn_speed)
    {
        right_encoder->ResetCounts();
        left_encoder->ResetCounts();

        float distance = (WHEEL_SPAN / 2) * degrees_to_radians(90);
        float counts = distance * COUNTS_PER_INCH;

        right_motor->SetPercent(-turn_speed * RIGHT_MOTOR_SPEED_CORRECTION);
        left_motor->SetPercent(turn_speed * LEFT_MOTOR_SPEED_CORRECTION);

        while((left_encoder->Counts() + right_encoder->Counts()) / 2. < counts);

        right_motor->Stop();
        left_motor->Stop();
    }

    void Motor::rotate_right(int turn_speed, float degrees)
    {
        right_encoder->ResetCounts();
        left_encoder->ResetCounts();

        float distance = (WHEEL_SPAN / 2) * degrees_to_radians(degrees);
        float counts = distance * COUNTS_PER_INCH;

        right_motor->SetPercent(-turn_speed * RIGHT_MOTOR_SPEED_CORRECTION);
        left_motor->SetPercent(turn_speed * LEFT_MOTOR_SPEED_CORRECTION);

        while((left_encoder->Counts() + right_encoder->Counts()) / 2. < counts);

        right_motor->Stop();
        left_motor->Stop();
    }
}