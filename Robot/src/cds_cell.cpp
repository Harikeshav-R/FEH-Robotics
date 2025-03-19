#include "cds_cell.h"
#include <cmath>

#include "FEHLCD.h"


namespace robot
{
    CdsCell::CdsCell(
        FEHIO::FEHIOPin cds_cell_pin
    ) : cds_cell(cds_cell_pin) {}

    LightType CdsCell::detect_light()
    {
        float voltage = cds_cell.Value();
        LCD.WriteLine(voltage);

        if (voltage < RED_LIGHT_VOLTAGE)
        {
            // LCD.WriteLine("Red!");
            return RED_LIGHT;
        }
        else if (std::fabs(voltage - BLUE_LIGHT_VOLTAGE) < TOLERANCE)
        {
            // LCD.WriteLine("VBlue!");

            return BLUE_LIGHT;
        }
        else if (std::fabs(voltage - NO_LIGHT_VOLTAGE) < TOLERANCE)
        {
            // LCD.WriteLine("No light!");
            return NO_LIGHT;
        }
        else
        {
            // LCD.WriteLine("Unknown!");
            return UNKNOWN_LIGHT;
        }
    }
}
