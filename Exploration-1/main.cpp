#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHMotor.h>
#include <FEHServo.h>


DigitalInputPin front_right(FEHIO::P0_0);
DigitalInputPin front_left(FEHIO::P3_7);

FEHMotor right_motor(FEHMotor::Motor0, 9);
FEHMotor left_motor(FEHMotor::Motor3, 9);

int FORWARD_SPEED = 40;
int TURN_SPEED = 15;
int REVERSE_SPEED = 10;
int TURN_DELAY = 1250;
int REVERSE_SHORT_DISTANCE_DELAY = 500;


void stop(){
    right_motor.Stop();
    left_motor.Stop();
}


void reverse_short_distance(){
    right_motor.SetPercent(-REVERSE_SPEED);
    left_motor.SetPercent(-REVERSE_SPEED);

    Sleep(REVERSE_SHORT_DISTANCE_DELAY);
}


void turn_left(){
    right_motor.SetPercent(TURN_SPEED);
    left_motor.SetPercent(-TURN_SPEED * 2);

    Sleep(TURN_DELAY);

    stop();
}

void turn_right(){
    right_motor.SetPercent(-TURN_SPEED * 2);
    left_motor.SetPercent(TURN_SPEED);

    Sleep(TURN_DELAY);

    stop();
}

void move_forward_indefinitely(){
    right_motor.SetPercent(FORWARD_SPEED);
    left_motor.SetPercent(FORWARD_SPEED);
}

bool bumper_detected(){
    return !front_left.Value() || !front_right.Value();
}


int main1(void)
{

    // AnalogInputPin CdS_cell(FEHIO::P2_6);
    // LCD.Clear();
    // while (1){
    //     float x=CdS_cell.Value();
    //     LCD.Write(x);
    //     LCD.Write("\n");
    //     Sleep(1.0);
    // }
    // AnalogInputPin cdS_cell(FEHIO::P2_6);
    // FEHServo arm_servo{FEHServo::Servo0};

    move_forward_indefinitely();

    float time_now = TimeNow();

    move_forward_indefinitely();

    while (true){
        if (bumper_detected()){
            break;
        }
    }

    reverse_short_distance();
    turn_left();

    move_forward_indefinitely();

    while (true){
        if (bumper_detected()){
            break;
        }
    }
    reverse_short_distance();

    turn_left();
    turn_left();

    move_forward_indefinitely();

    while (true){
        if (bumper_detected()){
            break;
        }
    }

    reverse_short_distance();

    turn_right();

    move_forward_indefinitely();

    while (true){
        if (bumper_detected()){
            break;
        }
    }

    reverse_short_distance();

    turn_right();
    turn_right();

    move_forward_indefinitely();

    while (true){
        if (bumper_detected()){
            break;
        }
    }

    stop();



    // while (true) {
        // if (bumper_detected()) {
        //     if (TimeNow() - time_now > 2) {
        //         stop();
        //         reverse_short_distance();
        //         turn_right();
        //         time_now = TimeNow();
        //         LCD.Write("Turning right at ");
        //         LCD.WriteLine(time_now);

        //     }
        //     else {
        //         stop();
        //         reverse_short_distance();
        //         turn_left();
        //         turn_left();
        //         time_now = TimeNow();
        //         LCD.Write("Taking U Turn at ");
        //         LCD.WriteLine(time_now);
        //     }

        //     move_forward_indefinitely();
        // }
    // }


   // Main loop for wall-following
    // while (true) {
    //     if (bumper_detected()) {
    //         // Collision detected, handle it
    //         stop();
    //         reverse_short_distance();  // Reverse to avoid collision
    //         turn_left();               // Turn left to avoid the obstacle
    //     } else {
    //         // No collision detected
    //         move_forward_indefinitely();  // Move forward continuously

    //         // Check if we can follow the right-hand wall
    //         stop();
    //         turn_right();                // Turn right to check for an open path
    //         move_forward_indefinitely(); // Move forward a short distance

    //         if (bumper_detected()) {
    //             // Wall detected, undo the right turn
    //             stop();
    //             reverse_short_distance();
    //             turn_left();  // Turn back to the original direction
    //         }
    //     }
    // }

    return 0;


    // while (1){
    //     right_motor.SetPercent(25);
    //     left_motor.SetPercent(-25);

    //     // if (front_right.Value() && front_left.Value()){
    //     //     right_motor.SetPercent(10);
    //     //     left_motor.SetPercent(10);
    //     //     if (count % 2 == 0){
    //     //         Sleep(2);
    //     //     }
    //     //     else {
    //     //         Sleep(1);
    //     //     }
    //     //     count++;
    //     // }
    // }

    // arm_servo.TouchCalibrate();
    // arm_servo.SetMin(500);
    // arm_servo.SetMax(2500);

    // while (1){
    //     float x = cdS_cell.Value();
    //     LCD.Write(x);
    //     LCD.Write("\n");
    //     arm_servo.SetDegree((180/3.3) * x);
    // }
}