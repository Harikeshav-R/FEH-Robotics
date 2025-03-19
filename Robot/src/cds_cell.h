#pragma once

#include <FEHIO.h>
#include <cfloat>
#include "constants.h"

enum LightType {
    RED_LIGHT,
    BLUE_LIGHT,
    NO_LIGHT,
    UNKNOWN_LIGHT
};

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
