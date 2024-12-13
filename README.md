# Robotic Arm Servo Control with Position Matrix

This project demonstrates the use of a robotic arm controlled via servos. The system interprets position data received through serial communication and moves the robotic arm to pick and place objects based on a predefined position matrix.

## Features

- **Servo Control**: Smooth movement of 5 servos to specified angles.
- **Predefined Position Matrix**: A 64x4 matrix defines servo angles for specific positions.
- **Serial Communication**: Receives positions in the format `x1:y1|x2:y2` to control the robotic arm.
- **Pick-and-Place Functionality**: The robotic arm can pick an object from one position and place it at another.
- **Home Position**: Returns the arm to its default "home" position after each operation.

---

## Hardware Requirements

1. Robotic arm with **5 servo motors**.
2. Microcontroller (e.g., Arduino).
3. Power supply suitable for the servos.
4. A computer or Raspberry Pi to send position data via serial communication.

---

## Software Requirements

- Arduino IDE.
- Servo library (included by default in Arduino IDE).

---

## Wiring Diagram

1. Connect the 5 servo motors to the pins specified in the code:
    - Servo 1: Pin 5
    - Servo 2: Pin 6
    - Servo 3: Pin 9
    - Servo 4: Pin 10
    - Servo 5: Pin 11
2. Ensure a stable power source for all servos to avoid power fluctuations.
3. Use appropriate resistors or filters to protect the microcontroller pins.

---

## Code Overview

### Key Components

1. **Position Matrix**: 
   The `positions_matrix[64][4]` contains predefined angles for the servos to position the robotic arm at 64 different locations.

2. **Servo Control**:
   - The `move` function smoothly transitions a servo to a target angle, incrementing or decrementing the current angle step-by-step.

3. **Home Function**:
   - The `home` function resets the robotic arm to a default position.

4. **Serial Communication**:
   - The code reads strings in the format `x1:y1|x2:y2` to determine the pick and place positions in the matrix.

---

### Code Breakdown

1. **Setup**:
   - Attaches servos to their respective pins.
   - Initializes them to default positions.

2. **Loop**:
   - Reads incoming data via Serial.
   - Parses the pick (`pos1`) and place (`pos2`) positions from the received string.
   - Moves the arm to pick the object, transitions to place position, and drops the object.
   - Returns the arm to the home position.
   - Notifies the sender that the operation is complete.

---

## Usage

1. Upload the code to your Arduino using the Arduino IDE.
2. Connect the robotic arm as per the wiring diagram.
3. Send position commands to the Arduino in the format `x1:y1|x2:y2` where:
   - `x1` and `y1` define the pick position.
   - `x2` and `y2` define the place position.
4. Observe the robotic arm executing the pick-and-place operation.

---

## Example Commands

- `1:1|3:4`: Pick from position `(1,1)` and place at position `(3,4)`.
- `4:2|6:6`: Pick from position `(4,2)` and place at position `(6,6)`.

---

## Customization

1. **Modify Default Angles**:
   Adjust `defaultAngles` to change the robotic arm's starting position.
2. **Update Position Matrix**:
   Modify `positions_matrix` to redefine angles for specific positions.
3. **Tweak Movement Speed**:
   Adjust the delay in the `move` function for faster or slower movements.

---

## Future Improvements

- Add collision detection to avoid obstacles during movement.
- Implement error handling for invalid or incomplete serial commands.
- Add real-time feedback or status updates via LEDs or an LCD.

---

## License

This project is open-source. Feel free to modify and distribute the code.

---

## Acknowledgments

This project uses the Arduino Servo library to control servo motors and integrates basic robotics concepts for practical implementation.
