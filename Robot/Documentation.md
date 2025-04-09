## Motor Class Documentation

### Overview
The `robot::Motor` class provides high-level control of a robot's drive motors and encoders. It supports directional movement, rotation, and encoder feedback while compensating for battery voltage and individual motor characteristics.

---

### Constructor

#### `Motor(FEHMotor::FEHMotorPort left_motor_port, FEHMotor::FEHMotorPort right_motor_port, FEHIO::FEHIOPin left_encoder_pin, FEHIO::FEHIOPin right_encoder_pin)`
Initializes the Motor object with given motor ports and encoder pins.

- **Parameters:**
  - `left_motor_port`: Port to which the left motor is connected.
  - `right_motor_port`: Port to which the right motor is connected.
  - `left_encoder_pin`: Pin associated with the left encoder.
  - `right_encoder_pin`: Pin associated with the right encoder.

---

### Public Methods

#### `void stop()`
Stops both motors immediately by setting their power to zero.

---

#### `void move(int motor_speed, float distance, bool forward, bool indefinite = false)`
Drives both motors at the specified speed in a given direction for a specific distance or indefinitely.

- **Parameters:**
  - `motor_speed`: Speed percentage for motor operation.
  - `distance`: Distance to move in inches (ignored if `indefinite` is true).
  - `forward`: `true` to move forward, `false` to move backward.
  - `indefinite`: If `true`, moves indefinitely until manually stopped.

---

#### `void move_forward(int motor_speed)`
Moves the robot forward indefinitely at the given speed.

- **Parameters:**
  - `motor_speed`: Speed percentage for forward movement.

---

#### `void move_forward(int motor_speed, float distance)`
Moves the robot forward a specific distance at the given speed.

- **Parameters:**
  - `motor_speed`: Speed percentage for forward movement.
  - `distance`: Distance in inches to move forward.

---

#### `void move_backwards(int motor_speed)`
Moves the robot backward indefinitely at the specified speed.

- **Parameters:**
  - `motor_speed`: Speed percentage for backward movement.

---

#### `void move_backwards(int motor_speed, float distance)`
Moves the robot backward a specific distance at the given speed.

- **Parameters:**
  - `motor_speed`: Speed percentage for backward movement.
  - `distance`: Distance in inches to move backward.

---

#### `void rotate(int turn_speed, float degrees, bool left)`
Rotates the robot in place by a specified number of degrees either to the left or right.

- **Parameters:**
  - `turn_speed`: Speed percentage for rotation.
  - `degrees`: Rotation angle in degrees.
  - `left`: `true` for left rotation, `false` for right.

---

#### `void rotate_left(int turn_speed)`
Rotates the robot 90 degrees to the left at the given speed.

- **Parameters:**
  - `turn_speed`: Speed percentage for rotation.

---

#### `void rotate_left(int turn_speed, float degrees)`
Rotates the robot left by a custom degree value.

- **Parameters:**
  - `turn_speed`: Speed percentage for rotation.
  - `degrees`: Angle to rotate left.

---

#### `void rotate_right(int turn_speed)`
Rotates the robot 90 degrees to the right at the given speed.

- **Parameters:**
  - `turn_speed`: Speed percentage for rotation.

---

#### `void rotate_right(int turn_speed, float degrees)`
Rotates the robot right by a custom degree value.

- **Parameters:**
  - `turn_speed`: Speed percentage for rotation.
  - `degrees`: Angle to rotate right.

---

#### `float left_encoder_counts()`
Returns the number of counts recorded by the left encoder since last reset.

- **Returns:**
  - `float`: Encoder count from the left motor.

---

#### `float right_encoder_counts()`
Returns the number of counts recorded by the right encoder since last reset.

- **Returns:**
  - `float`: Encoder count from the right motor.

---

## Servo Class Documentation

### Overview
The `robot::Servo` class provides an interface for controlling a servo motor, supporting direct positioning, gradual transitions, and calibration.

---

### Constructor

#### `Servo(FEHServo::FEHServoPort servo_port, int minimum, int maximum)`
Initializes the Servo object on the specified port and configures its minimum and maximum calibrated pulse values.

- **Parameters:**
  - `servo_port`: Port to which the servo is connected.
  - `minimum`: Minimum calibrated pulse width.
  - `maximum`: Maximum calibrated pulse width.

---

### Public Methods

#### `void set_degree(int degree)`
Directly sets the servo position to the specified degree.

- **Parameters:**
  - `degree`: Target angle to set the servo to.

---

#### `void set_degree(int start_degree, int end_degree, int iterations, int sleep_delay)`
Moves the servo gradually from the start degree to the end degree over a number of iterations with delays between each movement step.

- **Parameters:**
  - `start_degree`: Starting position in degrees.
  - `end_degree`: Target position in degrees.
  - `iterations`: Number of intermediate steps.
  - `sleep_delay`: Delay in milliseconds between each step.

---

#### `void calibrate()`
Initiates touch calibration for the servo to align the pulse width range with physical endpoints.

- **Behavior:**
  - This is typically used to fine-tune servo limits based on physical constraints.

---

## CdsCell Class Documentation

### Overview
The `robot::CdsCell` class is used to detect different light conditions based on analog voltage readings from a CdS (photoresistor) cell.

---

### Constructor

#### `CdsCell(FEHIO::FEHIOPin cds_cell_pin)`
Initializes the CdsCell object with the given analog pin.

- **Parameters:**
  - `cds_cell_pin`: Analog pin connected to the CdS sensor.

---

### Public Methods

#### `LightType detect_light()`
Reads the voltage from the CdS sensor and determines the type of light based on preset voltage thresholds.

- **Returns:**
  - `LightType`: One of `RED_LIGHT`, `BLUE_LIGHT`, `NO_LIGHT`, or `UNKNOWN_LIGHT` depending on the detected voltage.

---

## OptoSensor Class Documentation

### Overview
The `robot::OptoSensor` class processes readings from three optical sensors and determines line position based on intensity thresholds for both straight and curved paths.

---

### Constructor

#### `OptoSensor(FEHIO::FEHIOPin left_opto_sensor_pin, FEHIO::FEHIOPin middle_opto_sensor_pin, FEHIO::FEHIOPin right_opto_sensor_pin)`
Initializes the OptoSensor object with the specified analog pins.

- **Parameters:**
  - `left_opto_sensor_pin`: Pin connected to the left optical sensor.
  - `middle_opto_sensor_pin`: Pin connected to the middle optical sensor.
  - `right_opto_sensor_pin`: Pin connected to the right optical sensor.

---

### Public Methods

#### `bool right_sensor_on_line_straight()`
Checks if the right optical sensor detects a line on a straight path.

- **Returns:**
  - `bool`: `true` if sensor detects a line, otherwise `false`.

---

#### `bool left_sensor_on_line_straight()`
Checks if the left optical sensor detects a line on a straight path.

- **Returns:**
  - `bool`: `true` if sensor detects a line, otherwise `false`.

---

#### `bool middle_sensor_on_line_straight()`
Checks if the middle optical sensor detects a line on a straight path.

- **Returns:**
  - `bool`: `true` if sensor detects a line, otherwise `false`.

---

#### `bool right_sensor_on_line_curved()`
Checks if the right optical sensor detects a line on a curved path.

- **Returns:**
  - `bool`: `true` if sensor detects a line, otherwise `false`.

---

#### `bool left_sensor_on_line_curved()`
Checks if the left optical sensor detects a line on a curved path.

- **Returns:**
  - `bool`: `true` if sensor detects a line, otherwise `false`.

---

#### `bool middle_sensor_on_line_curved()`
Checks if the middle optical sensor detects a line on a curved path.

- **Returns:**
  - `bool`: `true` if sensor detects a line, otherwise `false`.

---

#### `LineState detect_state()`
Determines the position of the line based on readings from the three optical sensors.

- **Returns:**
  - `LineState`: `RIGHT`, `LEFT`, or `MIDDLE` based on which sensor detects the line.

