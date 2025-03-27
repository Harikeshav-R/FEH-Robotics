#pragma once

#include <FEHIO.h>
#include <FEHMotor.h>
#include <FEHServo.h>

// CDS CELL

// Using a red filter
const FEHIO::FEHIOPin CDS_CELL_PIN = FEHIO::P2_0;

const float RED_LIGHT_VOLTAGE = 0.5;
const float BLUE_LIGHT_VOLTAGE = .95;
const float NO_LIGHT_VOLTAGE = 2.5;
const float TOLERANCE = 0.15;

// MOTOR
const FEHMotor::FEHMotorPort LEFT_MOTOR_PORT = FEHMotor::Motor3;
const FEHMotor::FEHMotorPort RIGHT_MOTOR_PORT = FEHMotor::Motor0;

const FEHIO::FEHIOPin LEFT_ENCODER_PIN = FEHIO::P1_0;
const FEHIO::FEHIOPin RIGHT_ENCODER_PIN = FEHIO::P2_7;

// VEX Motors max recommended voltage
const float DEFAULT_VOLTAGE = 7.2;

// Measured values
const float WHEEL_RADIUS = 2.75 / 2;
const float WHEEL_SPAN = 7.5;

// Experimentally determined values
const float LEFT_N = 172;
const float RIGHT_N = 172;

// Calculated values
const float COUNTS_PER_INCH = ((LEFT_N + RIGHT_N) / 2) / (2 * 3.14 * WHEEL_RADIUS);

// Right motor correction
const float RIGHT_MOTOR_SPEED_CORRECTION = 1.06;
const float LEFT_MOTOR_SPEED_CORRECTION = 1;


// SERVO
const FEHServo::FEHServoPort WINDOW_SERVO_PORT = FEHServo::Servo0;
const FEHServo::FEHServoPort ARM_SERVO_PORT = FEHServo::Servo7;

const int ARM_SERVO_MIN = 730;
const int ARM_SERVO_MAX = 2400;

const int WINDOW_SERVO_MIN = 500;
const int WINDOW_SERVO_MAX = 2500;


// OPTOSENSORS
// Blue wire is right, gray is left, purple is center. 

// MISC
const float MAXIMUM_BATTERY_VOLTAGE = 11.5;
// const char* RCS_IDENTIFYING_STRING = "0800A8DJX";