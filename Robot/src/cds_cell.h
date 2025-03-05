#pragma once

#include <FEHIO.h>
#include <cfloat>

enum LightType {
    RED_LIGHT,
    BLUE_LIGHT,
    NO_LIGHT,
    UNKNOWN
};

const float RED_LIGHT_VOLTAGE = 0.306;
const float BLUE_LIGHT_VOLTAGE = 2.165;
const float NO_LIGHT_VOLTAGE = 3.259;
const float TOLERANCE = 0.2;

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
