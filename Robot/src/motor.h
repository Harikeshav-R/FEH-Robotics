#pragma once

#include <FEHMotor.h>
#include <FEHIO.h>
#include <cfloat>
#include "constants.h"


namespace robot
{
    class Motor
    {
    private:
        FEHMotor left_motor;
        FEHMotor right_motor;

        DigitalEncoder left_encoder;
        DigitalEncoder right_encoder;

        void move(int motor_speed, float distance, bool forward);
        void rotate(int turn_speed, float degrees, bool left);

    public:
        Motor(
            FEHMotor::FEHMotorPort left_motor_port,
            FEHMotor::FEHMotorPort right_motor_port,
            FEHIO::FEHIOPin left_encoder_pin,
            FEHIO::FEHIOPin right_encoder_pin
        );

        void stop();

        void move_forward(int motor_speed);
        void move_forward(int motor_speed, float distance);

        void move_backwards(int motor_speed);
        void move_backwards(int motor_speed, float distance);

        void rotate_left(int turn_speed);
        void rotate_left(int turn_speed, float degrees);

        void rotate_right(int turn_speed);
        void rotate_right(int turn_speed, float degrees);

        float left_encoder_counts();
        float right_encoder_counts();
    };
} // namespace robot
