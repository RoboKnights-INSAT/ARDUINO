int positions_matrix[64][4] = {
  {137, 65, 97, 135},
  {128, 70, 88, 134},
  {122, 53, 75, 134},
  {117, 43, 53, 148},
  {113, 27, 14, 170},
  {112, 20, 0, 153},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {127, 77, 118, 123},
  {118, 70, 105, 130},
  {112, 57, 82, 145},
  {110, 48, 64, 146},
  {110, 37, 26, 168},
  {106, 31, 0, 167},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {109, 81, 127, 126},
  {104, 74, 112, 129},
  {103, 62, 93, 135},
  {101, 51, 71, 144},
  {99, 34, 29, 168},
  {99, 24, 8, 167},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {90, 88, 135, 126},
  {90, 76, 116, 134},
  {90, 67, 98, 136},
  {90, 54, 76, 141},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {65, 84, 132, 32},
  {74, 75, 115, 136},
  {77, 67, 96, 136},
  {82, 56, 76, 141},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {83, 20, 0, 144},
  {90, 90, 90, 80},
  {48, 84, 130, 126},
  {60, 75, 113, 129},
  {67, 64, 92, 137},
  {72, 52, 69, 146},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {40, 75, 113, 132},
  {51, 70, 104, 132},
  {56, 61, 83, 138},
  {65, 46, 57, 152},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {33, 70, 103, 132},
  {44, 61, 85, 141},
  {52, 53, 70, 141},
  {56, 44, 47, 153},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {90, 90, 90, 80},
  {90, 90, 90, 80}
};


#include <Servo.h>  // Include the Servo library

#define NUM_SERVOS 5  // Number of servos

Servo servos[NUM_SERVOS];  // Create an array to store Servo objects
int servoPins[NUM_SERVOS] = {5, 6, 9, 10,11};  // Define pins for the servos
int currentAngles[NUM_SERVOS] = {90, 90, 60, 60,60}; 
int defaultAngles[NUM_SERVOS] = {90, 120, 90, 125,70}; // Current angles of the servos
int defaultStatic[NUM_SERVOS] = {90, 120, 90, 125,70}; // Current angles of the servos
int pos1;
int pos2;
// Function to move a servo smoothly to a target position
void move(Servo &servo, int &currentAngle, int targetAngle) {
  while (currentAngle != targetAngle) {
    if (currentAngle < targetAngle) {
      currentAngle++;                   // Increment the angle
    } else if (currentAngle > targetAngle) {
      currentAngle--;                   // Decrement the angle
    }
    servo.write(currentAngle);          // Move the servo
    delay(15);                          // Small delay for smooth move
  }
}
void home(){
  move(servos[1], currentAngles[1],120);
  // currentAngles[1]=90;
  move(servos[3], currentAngles[3],125);
  // currentAngles[3]=60;
   move(servos[2], currentAngles[2],146);
  // currentAngles[2]=90;
   move(servos[0], currentAngles[0],90);
  // currentAngles[0]=90;
  
  
}

void setup() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]);      // Attach each servo to its pin
    servos[i].write(defaultAngles[i]);   // Initialize the servos at the current angles
    //move(servos[i],defaultAngles[i], currentAngles[i] );
    delay(200);                          // Allow the servos to stabilize
  }
  Serial.begin(9600);    
}

void loop() {

  if (Serial.available() > 0) {  
        // Check if data is available
    String receivedString = Serial.readStringUntil('\n');  // Read the incoming data until newline
    // the form of the received string will be x1:y1|x2:y2
    pos1 = int(receivedString[2]) - 48 + ((int(receivedString[0]) - 48 -1) * 8) -1;
    pos2 = int(receivedString[6]) - 48 + (int(receivedString[4]) - 48 -1) * 8 -1;
    // pos1 = int(receivedString[0]) - 48 + ((int(receivedString[2]) - 48 -1) * 8) -1;
    // pos2 = int(receivedString[4]) - 48 + (int(receivedString[6]) - 48 -1) * 8 -1;
    for (int i = 3; i >-1; i--){
      
      move(servos[i],defaultAngles[i], currentAngles[i] );  
      defaultAngles[i]= defaultStatic[i] ;

      delay(200);

      }
    move(servos[0], currentAngles[0], positions_matrix[pos1][0]);
    delay(200); 
    move(servos[2], currentAngles[2], positions_matrix[pos1][2]);
    delay(200); 
      move(servos[3], currentAngles[3], positions_matrix[pos1][3]);
    delay(200); 
    
    move(servos[1], currentAngles[1], positions_matrix[pos1][1]);
    delay(20);
    move(servos[4], currentAngles[4],0);

      // return to pos 0 for the pos2
    // for (int i = 3; i >0; i--){
    move(servos[1], currentAngles[1], 120);
    
    for (int i = 2; i < 3; i++){
      move(servos[i], currentAngles[i], 90);
          delay(200);                          // Allow the servos to stabilize

    }

    // get to pos 2
    move(servos[0], currentAngles[0], positions_matrix[pos2][0]);
    delay(200); 
    move(servos[3], currentAngles[3], positions_matrix[pos2][3]);
    delay(200); 
    move(servos[2], currentAngles[2], positions_matrix[pos2][2]);
    delay(200);
    move(servos[1], currentAngles[1], positions_matrix[pos2][1]);
    delay(200); 

    // for (int i = 0; i < 4; i++){
    //   move(servos[i], currentAngles[i], positions_matrix[pos2][i]);
    //       delay(200);                          // Allow the servos to stabilize

    // }
    delay(20);
    move(servos[4], currentAngles[4],50);
    //return to home
    home();

    // notify the raspberry that we done
    Serial.print("done"); 

  }

}
