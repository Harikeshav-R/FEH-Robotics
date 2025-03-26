#include "cds_cell.h"


namespace robot
{
    CdsCell::CdsCell(
        FEHIO::FEHIOPin cds_cell_pin
    ) : cds_cell(cds_cell_pin) {}

    LightType CdsCell::detect_light()
    {
        float voltage = cds_cell.Value();

        if (voltage < RED_LIGHT_VOLTAGE)
        {
            return RED_LIGHT;
        }
        else if (std::fabs(voltage - BLUE_LIGHT_VOLTAGE) < TOLERANCE)
        {
            return BLUE_LIGHT;
        }
        else if (std::fabs(voltage - NO_LIGHT_VOLTAGE) < TOLERANCE)
        {
            return NO_LIGHT;
        }
        else
        {
            return UNKNOWN_LIGHT;
        }
    }
}
