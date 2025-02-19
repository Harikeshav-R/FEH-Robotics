#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHSD.h>
#include <FEHMotor.h>


// Declarations for analog optosensors
AnalogInputPin right_opto(FEHIO::P1_0);
AnalogInputPin middle_opto(FEHIO::P1_3);
AnalogInputPin left_opto(FEHIO::P1_7);

FEHMotor right_motor(FEHMotor::Motor3, 9);
FEHMotor left_motor(FEHMotor::Motor0, 9);

DigitalEncoder right_encoder(FEHIO::P2_6);
DigitalEncoder left_encoder(FEHIO::P2_7);

int FORWARD_SPEED = 30;
int TURN_SPEED = 15;
int REVERSE_SPEED = 10;
int TURN_DELAY = 1250;
int REVERSE_SHORT_DISTANCE_DELAY = 500;

float RIGHT_SENSOR_STRAIGHT_BOUNDS = 2.171;
float MIDDLE_SENSOR_STRAIGHT_BOUNDS = 1.579;
float LEFT_SENSOR_STRAIGHT_BOUNDS = 1.613;

float RIGHT_SENSOR_CURVED_BOUNDS = 2.318;
float MIDDLE_SENSOR_CURVED_BOUNDS = 1.669;
float LEFT_SENSOR_CURVED_BOUNDS = 1.825;

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
    right_motor.SetPercent(FORWARD_SPEED * 0.8);
    left_motor.SetPercent(FORWARD_SPEED * 0.2);
}

void move_right()
{
    left_motor.SetPercent(FORWARD_SPEED * 0.8);
    right_motor.SetPercent(FORWARD_SPEED * 0.2);
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
                LCD.Write("On middle. Sensor Value: ");
                LCD.WriteLine(middle_opto.Value());
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
                LCD.Write("On right. Sensor Value: ");
                LCD.WriteLine(right_opto.Value());
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
                LCD.Write("On left. Sensor Value: ");
                LCD.WriteLine(left_opto.Value());

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

void move_forward_test(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    right_motor.SetPercent(percent);
    left_motor.SetPercent(percent);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void shaft_encoding_test()
{
    int motor_percent = 60; //Input power level here
    int expected_counts = 243; //Input theoretical counts here

    float x, y; //for touch screen

    //Initialize the screen
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);

    LCD.WriteLine("Shaft Encoder Exploration Test");
    LCD.WriteLine("Touch the screen");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed

    move_forward_test(motor_percent, expected_counts); //see function

    Sleep(2.0); //Wait for counts to stabilize
    //Print out data
    LCD.Write("Theoretical Counts: ");
    LCD.WriteLine(expected_counts);
    LCD.Write("Motor Percent: ");
    LCD.WriteLine(motor_percent);
    LCD.Write("Actual LE Counts: ");
    LCD.WriteLine(left_encoder.Counts());
    LCD.Write("Actual RE Counts: ");
    LCD.WriteLine(right_encoder.Counts());
}


void encoder_turn_right(){
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();
    //Set both motors to desired percent
    //hint: set right motor backwards, left motor forwards
    //<ADD CODE HERE>
    int percent = 25;
    int counts = 217;

    //Set both motors to desired percent
    right_motor.SetPercent(-percent);
    left_motor.SetPercent(percent);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}


void encoder_turn_left(){
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();
    //Set both motors to desired percent
    //hint: set right motor backwards, left motor forwards
    //<ADD CODE HERE>
    int percent = 25;
    int counts = 215;

    //Set both motors to desired percent
    right_motor.SetPercent(percent);
    left_motor.SetPercent(-percent);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}


void encoder_move_forward(float distance){
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    float counts = 41.55737705 * distance;

    int percent = 25;

    right_motor.SetPercent(percent);
    left_motor.SetPercent(percent + 1);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}


int main(void)
{
    float x, y;

    LCD.WriteLine("Touch the screen to start");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    encoder_move_forward(14.0);
    Sleep(1000);

    encoder_turn_left();
    Sleep(1000);

    encoder_move_forward(10.0);
    Sleep(1000);

    encoder_turn_right();
    Sleep(1000);

    encoder_move_forward(4.0);
    Sleep(1000);
}