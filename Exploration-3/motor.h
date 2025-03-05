#pragma once

#include <FEHMotor.h>
#include <FEHIO.h>

// VEX Motors max recommended voltage
const float DEFAULT_VOLTAGE = 9;

// Measured values
const float WHEEL_RADIUS = 2.5 / 2;
const float WHEEL_SPAN = 6.8;

// Experimentally determined values
const float LEFT_N = 169;
const float RIGHT_N = 162;

// Calculated values
// const float COUNTS_PER_INCH = ((LEFT_N + RIGHT_N) / 2) / (2 * 3.14 * WHEEL_RADIUS);
const float COUNTS_PER_INCH = 41.55737705 / 2;

// Right motor correction
const float RIGHT_MOTOR_SPEED_CORRECTION = 1;
const float LEFT_MOTOR_SPEED_CORRECTION = 1;


namespace robot
{
    class Motor
    {
    private:
        float voltage;

        FEHMotor* left_motor;
        FEHMotor* right_motor;

        DigitalEncoder* left_encoder;
        DigitalEncoder* right_encoder;

    public:
        Motor(
            FEHMotor::FEHMotorPort left_motor_port,
            FEHMotor::FEHMotorPort right_motor_port,
            FEHIO::FEHIOPin left_encoder_pin,
            FEHIO::FEHIOPin right_encoder_pin
        );

        ~Motor();

        void stop();

        void move_forward(int motor_speed);
        void move_forward(int motor_speed, float distance);

        void move_backwards(int motor_speed);
        void move_backwards(int motor_speed, float distance);

        void rotate_left(int turn_speed);
        void rotate_left(int turn_speed, float degrees);

        void rotate_right(int turn_speed);
        void rotate_right(int turn_speed, float degrees);
    };
} // robot