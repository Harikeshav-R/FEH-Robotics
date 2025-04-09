#include "opto_sensor.h"

#include <FEHLCD.h>


namespace robot
{
    OptoSensor::OptoSensor(
        FEHIO::FEHIOPin left_opto_sensor_pin,
        FEHIO::FEHIOPin middle_opto_sensor_pin,
        FEHIO::FEHIOPin right_opto_sensor_pin
    ) : left_opto_sensor(left_opto_sensor_pin),
        middle_opto_sensor(middle_opto_sensor_pin),
        right_opto_sensor(right_opto_sensor_pin) {}

    bool OptoSensor::right_sensor_on_line_straight()
    {
        return right_opto_sensor.Value() > RIGHT_OPTO_SENSOR_STRAIGHT_BOUNDS;
    }
    
    bool OptoSensor::left_sensor_on_line_straight()
    {
        return left_opto_sensor.Value() > LEFT_OPTO_SENSOR_STRAIGHT_BOUNDS;
    }
    
    bool OptoSensor::middle_sensor_on_line_straight()
    {
        return middle_opto_sensor.Value() > MIDDLE_OPTO_SENSOR_STRAIGHT_BOUNDS;
    }
    
    bool OptoSensor::right_sensor_on_line_curved()
    {
        return right_opto_sensor.Value() > RIGHT_OPTO_SENSOR_CURVED_BOUNDS;
    }
    
    bool OptoSensor::left_sensor_on_line_curved()
    {
        return left_opto_sensor.Value() > LEFT_OPTO_SENSOR_CURVED_BOUNDS;
    }
    
    bool OptoSensor::middle_sensor_on_line_curved()
    {
        return middle_opto_sensor.Value() > MIDDLE_OPTO_SENSOR_CURVED_BOUNDS;
    }

    LineState OptoSensor::detect_state()
    {
        LineState state;

        if (right_sensor_on_line_straight())
        {
            state = LineState::RIGHT;
        }
        else if (left_sensor_on_line_straight())
        {
            state = LineState::LEFT;
        }
        else if (middle_sensor_on_line_straight())
        {
            state = LineState::MIDDLE;
        }

        return state;
    }
}
