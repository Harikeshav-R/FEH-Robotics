#include "cds_cell.h"

#include <FEHLCD.h>


namespace robot
{
    CdsCell::CdsCell(
        FEHIO::FEHIOPin cds_cell_pin
    ) : cds_cell(cds_cell_pin) {}

    LightType CdsCell::detect_light()
    {
        float voltage = cds_cell.Value();

        LCD.WriteLine(voltage);

        if (std::fabs(voltage - RED_LIGHT_VOLTAGE) < CDS_CELL_TOLERANCE)
        {
            return RED_LIGHT;
        }
        else if (std::fabs(voltage - BLUE_LIGHT_VOLTAGE) < CDS_CELL_TOLERANCE)
        {
            return BLUE_LIGHT;
        }
        else if (std::fabs(voltage - NO_LIGHT_VOLTAGE) < CDS_CELL_TOLERANCE)
        {
            return NO_LIGHT;
        }
        else
        {
            return UNKNOWN_LIGHT;
        }
    }
}
