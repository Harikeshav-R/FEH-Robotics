#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHSD.h>
#include <FEHMotor.h>

// Declarations for analog optosensors
AnalogInputPin right_opto(FEHIO::P1_0);
AnalogInputPin middle_opto(FEHIO::P1_3);
AnalogInputPin left_opto(FEHIO::P1_7);

FEHMotor right_motor(FEHMotor::Motor0, 9);
FEHMotor left_motor(FEHMotor::Motor3, 9);

int FORWARD_SPEED = 30;
int TURN_SPEED = 15;
int REVERSE_SPEED = 10;
int TURN_DELAY = 1250;
int REVERSE_SHORT_DISTANCE_DELAY = 500;

float RIGHT_SENSOR_STRAIGHT_BOUNDS = 2.3;
float MIDDLE_SENSOR_STRAIGHT_BOUNDS = 2.2;
float LEFT_SENSOR_STRAIGHT_BOUNDS = 2.0;

float RIGHT_SENSOR_CURVED_BOUNDS = 2.6;
float MIDDLE_SENSOR_CURVED_BOUNDS = 2.35;
float LEFT_SENSOR_CURVED_BOUNDS = 2.35;

void stop()
{
    right_motor.Stop();
    left_motor.Stop();
}

void reverse_short_distance()
{
    right_motor.SetPercent(-REVERSE_SPEED);
    left_motor.SetPercent(-REVERSE_SPEED);

    Sleep(REVERSE_SHORT_DISTANCE_DELAY);
}

void turn_left()
{
    right_motor.SetPercent(TURN_SPEED);
    left_motor.SetPercent(-TURN_SPEED * 2);

    Sleep(TURN_DELAY);

    stop();
}

void turn_right()
{
    right_motor.SetPercent(-TURN_SPEED * 2);
    left_motor.SetPercent(TURN_SPEED);

    Sleep(TURN_DELAY);

    stop();
}

void move_left()
{
    right_motor.SetPercent(FORWARD_SPEED * 0.83);
    left_motor.SetPercent(FORWARD_SPEED * 0.5);
}

void move_right()
{
    left_motor.SetPercent(FORWARD_SPEED * 0.83);
    right_motor.SetPercent(FORWARD_SPEED * 0.5);
}

void move_forward()
{
    right_motor.SetPercent(FORWARD_SPEED);
    left_motor.SetPercent(FORWARD_SPEED);
}

bool right_sensor_on_line_straight()
{
    return right_opto.Value() > RIGHT_SENSOR_STRAIGHT_BOUNDS;
}

bool left_sensor_on_line_straight()
{
    return left_opto.Value() > LEFT_SENSOR_STRAIGHT_BOUNDS;
}

bool middle_sensor_on_line_straight()
{
    return middle_opto.Value() > MIDDLE_SENSOR_STRAIGHT_BOUNDS;
}

bool right_sensor_on_line_curved()
{
    return right_opto.Value() > RIGHT_SENSOR_CURVED_BOUNDS;
}

bool left_sensor_on_line_curved()
{
    return left_opto.Value() > LEFT_SENSOR_CURVED_BOUNDS;
}

bool middle_sensor_on_line_curved()
{
    return middle_opto.Value() > MIDDLE_SENSOR_CURVED_BOUNDS;
}

void get_optosensor_readings()
{
    float x, y; // for touch screen

    FEHFile *output_file = SD.FOpen("output.txt", "w");

    // Initialize the screen
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);

    LCD.WriteLine("Analog Optosensor Testing : Straight Line");
    LCD.WriteLine("Touch the screen");
    while (!LCD.Touch(&x, &y))
        ; // Wait for screen to be pressed
    while (LCD.Touch(&x, &y))
        ; // Wait for screen to be unpressed

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor on straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Left optosensor on straight line: %f\n", left_opto.Value());

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor off straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Left optosensor off straight line: %f\n", left_opto.Value());

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place right optosensor on straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Right optosensor on straight line: %f\n", right_opto.Value());

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place right optosensor off straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Right optosensor off straight line: %f\n", right_opto.Value());

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor on straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Middle optosensor on straight line: %f\n", middle_opto.Value());

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor off straight line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Middle optosensor off straight line: %f\n", middle_opto.Value());

    LCD.Clear(BLACK);
    LCD.WriteLine("Analog Optosensor Testing : Curved Line");
    LCD.WriteLine("Touch the screen");
    while (!LCD.Touch(&x, &y))
        ; // Wait for screen to be pressed
    while (LCD.Touch(&x, &y))
        ; // Wait for screen to be unpressed

    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor on curved line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Left optosensor on curved line: %f\n", left_opto.Value());

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor off curved line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Left optosensor off curved line: %f\n", left_opto.Value());

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place right optosensor on curved line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Right optosensor on curved line: %f\n", right_opto.Value());

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place right optosensor off curved line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Right optosensor off curved line: %f\n", right_opto.Value());

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor on curved line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Middle optosensor on curved line: %f\n", middle_opto.Value());

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor off curved line");
    Sleep(3000); // Wait to avoid double input
    // LCD.WriteLine("Touch screen to record value (1/12)");
    // while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    // while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
    SD.FPrintf(output_file, "Middle optosensor off curved line: %f\n", middle_opto.Value());

    // Print end message to screen
    LCD.Clear(BLACK);
    LCD.WriteLine("Test Finished");

    SD.FClose(output_file);
}

void line_following_robot()
{
    enum LineStates
    {
        MIDDLE,
        RIGHT,
        LEFT
    };

    int state = MIDDLE; // Set the initial state
    while (true)
    { // I will follow this line forever!
        switch (state)
        {
            // If I am in the middle of the line...
            case MIDDLE:
            {
                move_forward();
                /* Drive */
                if (right_sensor_on_line_straight())
                {
                    state = RIGHT; // update a new state
                }
                else if (left_sensor_on_line_straight())
                {
                    state = LEFT; // update a new state
                }
                /* Code for if left sensor is on the line */
                break;
            }
                
            // If the right sensor is on the line...
            case RIGHT:
            {
                move_right();
                // Set motor powers for right turn
                /* Drive */
                if (middle_sensor_on_line_straight())
                {
                    state = MIDDLE; // update a new state
                }
                else if (left_sensor_on_line_straight())
                {
                    state = LEFT; // update a new state
                }

                break;
            }
                
            // If the left sensor is on the line...
            case LEFT:
            {
                move_left();

                if (middle_sensor_on_line_straight())
                {
                    state = MIDDLE; // update a new state
                }
                else if (right_sensor_on_line_straight())
                {
                    state = RIGHT; // update a new state
                }

                break;
            }

            default: // Error. Something is very wrong.
            {
                LCD.WriteLine("Something went wrong!");
                state = MIDDLE;
                break;
            }
        }
    }
}

int main(void)
{
    line_following_robot();
}