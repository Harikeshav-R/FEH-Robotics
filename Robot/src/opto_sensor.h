#pragma once

#include <FEHIO.h>
#include <cfloat>
#include <cmath>

#include "constants.h"

enum LineState {
    MIDDLE, RIGHT, LEFT
};

namespace robot
{
    class OptoSensor
    {
    private:
        AnalogInputPin left_opto_sensor;
        AnalogInputPin middle_opto_sensor;
        AnalogInputPin right_opto_sensor;

        bool left_sensor_on_line_straight();
        bool middle_sensor_on_line_straight();
        bool right_sensor_on_line_straight();

        bool left_sensor_on_line_curved();
        bool middle_sensor_on_line_curved();
        bool right_sensor_on_line_curved();

    public:
        OptoSensor(
            FEHIO::FEHIOPin left_opto_sensor_pin,
            FEHIO::FEHIOPin middle_opto_sensor_pin,
            FEHIO::FEHIOPin right_opto_sensor_pin
        );

        LineState detect_state();
    };
} // namespace robot
