#pragma once

#include <FEHIO.h>
#include <cfloat>

enum LightType {
    RED_LIGHT,
    BLUE_LIGHT,
    NO_LIGHT,
    UNKNOWN_LIGHT
};

// Using a blue filter - might switch to red
const float RED_LIGHT_VOLTAGE = .5;
const float BLUE_LIGHT_VOLTAGE = .87;
const float NO_LIGHT_VOLTAGE = 3;
const float TOLERANCE = 0.08;

namespace robot
{
    class CdsCell
    {
    private:
        AnalogInputPin cds_cell;

    public:
        CdsCell(
            FEHIO::FEHIOPin cds_cell_pin
        );

        LightType detect_light();
    };
} // namespace robot
