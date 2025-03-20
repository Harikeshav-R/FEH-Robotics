#pragma once

// CDS CELL

// Using a blue filter - might switch to red
const float RED_LIGHT_VOLTAGE = .5;
const float BLUE_LIGHT_VOLTAGE = .87;
const float NO_LIGHT_VOLTAGE = 3;
const float TOLERANCE = 0.08;


// MOTOR

// VEX Motors max recommended voltage
const float DEFAULT_VOLTAGE = 7.2;

// Measured values
const float WHEEL_RADIUS = 2.75 / 2;
const float WHEEL_SPAN = 7.5;

// Experimentally determined values
const float LEFT_N = 169;
const float RIGHT_N = 162;

const float LEFT_N = 172;
const float RIGHT_N = 172;

// const float LEFT_N = 449 / 22.25;
// const float RIGHT_N = 453 / 22.25;

// Calculated values
const float COUNTS_PER_INCH = ((LEFT_N + RIGHT_N) / 2) / (2 * 3.14 * WHEEL_RADIUS);

// Right motor correction
const float RIGHT_MOTOR_SPEED_CORRECTION = 1.03;
const float LEFT_MOTOR_SPEED_CORRECTION = 1;


// MISC

const float MAXIMUM_BATTERY_VOLTAGE = 11.5;