
/*.............................................................................................................................................................
  ...............................................................................................................................................................
  ...............................................................................................................................................................
  ......................@@@@@@@@@@@@@@...........................................................................................@@@@@@@.....@@@.................
  ...................@@@@@@@@@@@@@@@@@@@.....................................................................................@@@@@@@@@@@....@@@..................
  .................@@@@....@@@.......@@@@..................................@@@............................................@@@@@@@...@@@@...@@@...................
  ................@@......@@@.........@@@.................................@@@............................@@..............@@@@.......@@@@.@@@.....................
  .......................@@@..........@@@..............................................................@@@@@............@@@@@.......@@@@@@.......................
  .....................@@@...........@@@...@@...@@@.....@@@@...........@@@@.....@@@@@......@@@@@....@@@@@@@@@......................@@@@@@........................
  ....................@@@.........@@@@....@@@@@@@@@...@@@@@@@@.....@@@@@@@@@..@@@...@@...@@@@@@@@.....@@@..........................@@@@@.........................
  .................@@@@@.......@@@@@.....@@@@@.@@@...@@@....@@@..@@@@...@@...@@@...@@...@@@...@@@....@@@.........................@@@@@@..........................
  ...............@@@@@@@@@@@@@@@........@@....@@....@@@@....@@@........@@...@@@@@@@@...@@@..........@@@........................@@@@.@@@..........................
  .................@@@.................@@...@@......@@@.....@@@.......@@...@@@@.......@@@..........@@@...@@@.................@@@....@@@..........................
  ................@@@................@@@....@@@@@@..@@@@..@@@@.......@@...@@@@....@@..@@@....@@@..@@@...@@@................@@@@.....@@@..........................
  ...............@@@.................@@......@@@......@@@@@@........@@@.....@@@@@@@....@@@@@@@@...@@@@@@@@................@@@@......@@@@.........................
  ..............@@@@...............................................@.@@..................................................@@@@.......@@@@@@.......................
  ..............@@@..............................................@@.@@...........................................................................................
  ..............................................................@@.@@............................................................................................
  .............................................................@@.@@.............................................................................................
  ............................................................@@@@@..............................................................................................
  .............................................................@@@...............................................................................................
  ...............................................................................................................................................................
  ...............................................................................................................................................................
*/





// defined values, pins, states.....

const int stepPin1 = 2;  // left motor step
const int dirPin1 = 3;   // left motor dir

const int stepPin2 = 5;  // right motor step
const int dirPin2 = 6;   // right motor dir

int motorstep = 20;     // number of steps     (20/200) * 360 = 36 degrees
double rotation = 600;  // number of rotation for 90 de

int r;    // value right line
int l;    // value left line
int btt;  // start button

bool L;  // boolean left candle
bool R;  // boolean right candle
bool M;  // boolean middle candle
bool line;

int Lcandle;  // value left candle
int Rcandle;  // value right candle
int Mcandle;  // value middle candle

float randNumber;    // float for generating random number
float randRotation;  // float for generating random turn
int randState;       // int for generating random state


#include <Servo.h>
Servo myservo;  // define myservo as servo controller for propeller
int on = 104;   // 18-22 start point of potenciometer
int off = 176;  // 168-175 end point of potenciometer




void calibration() {
  //                                                         o
  //                                                       ooOoo
  //                                                         o
  //                                                        | |
  Serial.print(" L1  ");         //   _________
  Serial.print(analogRead(A2));  //   |  X1   |
  Serial.print(" / L2 - ");      //   | ----- |
  Serial.print(analogRead(A3));  //   |  X2   |
  Serial.print(" / L3 - ");      //   | ----- |
  Serial.print(analogRead(A4));  //   |  X3   |
  Serial.print(" / L4 - ");      //   | ----- |
  Serial.print(analogRead(A5));  //   |  X4   |
  //                                                     _________
  Serial.print("  ||||    M1 - ");
  Serial.print(analogRead(A9));
  Serial.print(" / M2 - ");
  Serial.print(analogRead(A8));
  Serial.print(" / M3 - ");
  Serial.print(analogRead(A6));
  Serial.print(" / M4 - ");
  Serial.print(analogRead(A7));

  Serial.print("  ||||    R1 - ");
  Serial.print(analogRead(A11));
  Serial.print(" / R2 - ");
  Serial.print(analogRead(A13));
  Serial.print(" / R3 - ");
  Serial.print(analogRead(A10));
  Serial.print(" / R4 - ");
  Serial.print(analogRead(A12));
  Serial.print("   ***  ");
  if (digitalRead(10) == LOW) {
    Serial.print(" NA ");
  } else {
    Serial.print(" OBSTACLE ");
  }
  Serial.print("  ||  ");
  if (analogRead(A0) < r) {
    Serial.print(" line R ");
  } else {
    Serial.print(" no line R ");
  }
  Serial.print("  <>  ");
  if (analogRead(A1) < l) {
    Serial.print(" line L ");
  } else {
    Serial.print(" no line L ");
  }
  Serial.print("  ||  ");
  Serial.print(digitalRead(8));
  Serial.println();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void motorstop() {  // stop motor
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);
  for (int x = 0; x < motorstep; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1600);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1600);
  }
}
//-------------------------------------------------------------------------------
void goback() {  // go back
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);
  for (int x = 0; x < motorstep; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1600);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1600);
  }
}

//------------------------------------------------------------------------------
void gofwd() {  // go forward
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, LOW);
  for (int x = 0; x < motorstep; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1500);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1500);
  }
}


//-------------------------------------------------------------------------------

void propeller() {  // turn on propeller and candlestop seq.
  motorstop();
  myservo.write(on);
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  for (int x = 0; x < 73; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2900);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(2900);
  }

  delay(200);

  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  for (int x = 0; x < 120; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2900);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(2900);
  }

  delay(200);

  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  for (int x = 0; x < 120; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2900);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(2900);
  }

  delay(200);

  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  for (int x = 0; x < 120; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2900);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(2900);
  }

  delay(200);

  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  for (int x = 0; x < 120; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2900);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(2900);
  }

  delay(200);

  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  for (int x = 0; x < 60; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2900);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(2900);
  }
  myservo.write(off);
  delay(400);
}

//------------------------------------------------------------------------------

void search() {  // turn on propeller and candlestop seq.
  motorstop();
  delay(100);

  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  for (int x = 0; x < 73; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2200);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(2200);
    if ((analogRead(A6) < Mcandle or analogRead(A7) < Mcandle or analogRead(A8) < Mcandle or analogRead(A9) < Mcandle) and ((analogRead(A1) < r) or (analogRead(A0) < l))) {
      motorstop();
      delay(200);
      propeller();
      delay(100);
      break;
    }
  }
  delay(100);

  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  for (int x = 0; x < 110; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1800);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1800);
    if ((analogRead(A6) < Mcandle or analogRead(A7) < Mcandle or analogRead(A8) < Mcandle or analogRead(A9) < Mcandle) and (analogRead(A1) < r or analogRead(A0) < l)) {
      motorstop();
      delay(200);
      propeller();
      delay(100);
      break;
    }
  }

  delay(100);

  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  for (int x = 0; x < 63; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1800);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1800);
    if ((analogRead(A6) < Mcandle or analogRead(A7) < Mcandle or analogRead(A8) < Mcandle or analogRead(A9) < Mcandle) and (analogRead(A1) > r or analogRead(A0) > l)) {
      motorstop();
      delay(200);
      propeller();
      delay(100);
      break;
    }
  }
}

//------------------------------------------------------------------------------
void turnR() {  // turn right with line interrupt
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);

  for (int x = 0; x < motorstep; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(3600);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(3600);

    if (analogRead(A0) < l or analogRead(A1) < r) {
      x = 0;
      break;
    }
  }
}

//------------------------------------------------------------------------------

void randR() {

  randNumber = random(850, 1120);  // degrees of rotation
  randRotation = randNumber / 10;


  // delay min 200 for charge capacitor on PWB

  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);

  for (int x = 0; x < randRotation; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(3600);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(3600);

    if (analogRead(A0) < l or analogRead(A1) < r) {
      x = 0;
      break;
    }
  }
}

//-----------------------------------------------------------------------------

void randL() {
  randNumber = random(850, 1120);  // degrees of rotation
  randRotation = randNumber / 10;


  // delay min 200 for charge capacitor on PWB

  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);

  for (int x = 0; x < randRotation; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(3600);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(3600);

    if (analogRead(A0) < l or analogRead(A1) < r) {
      x = 0;
      break;
    }
  }
}
//-----------------------------------------------------------------------------
void turnL() {  // turn left with interrupt
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  for (int x = 0; x < motorstep; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(3600);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(3600);

    if (analogRead(A0) < l or analogRead(A1) < r) {
      x = 0;
      break;
    }
  }
}
//-------------------------------------------------------------------------------------------------

void randRotate() {                // robot random turn right/left
  randState = random(0, 2);        // direction of rotation
  randNumber = random(850, 1200);  // degrees of rotation
  randRotation = randNumber / 10;

  if (randState == 1) {
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, HIGH);

    for (int x = 0; x < randRotation; x++) {
      digitalWrite(stepPin1, HIGH);
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(3600);
      digitalWrite(stepPin1, LOW);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(3600);

      if (analogRead(A0) < l or analogRead(A1) < r) {
        x = 0;
        break;
      }
    }
    delay(100);
  }

  if (randState == 0) {
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, LOW);

    for (int x = 0; x < randRotation; x++) {
      digitalWrite(stepPin1, HIGH);
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(3600);
      digitalWrite(stepPin1, LOW);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(3600);

      if (analogRead(A0) < l or analogRead(A1) < r) {
        x = 0;
        break;
      }
    }
    delay(100);
  }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void setup() {
  //       MOTOR LEFT
  pinMode(stepPin1, OUTPUT);  // left motor step
  pinMode(dirPin1, OUTPUT);   // left motor dir

  //       MOTOR RIGHT
  pinMode(stepPin2, OUTPUT);  // right motor step
  pinMode(dirPin2, OUTPUT);   // left motor dir

  Serial.begin(9600);

  //       BUTTONS
  pinMode(13, INPUT_PULLUP);  // starting button
  pinMode(8, INPUT_PULLUP);   // bumper

  //       ULTRASONIC
  pinMode(10, INPUT_PULLUP);  // ultrasonic

  //...................................................

  //       LEFT
  pinMode(A0, INPUT);  // r
  pinMode(A1, INPUT);  // l
  pinMode(A2, INPUT);  // L1
  pinMode(A3, INPUT);  // L2
  pinMode(A4, INPUT);  // L3
  pinMode(A5, INPUT);  // L4

  //       MIDDLE
  pinMode(A6, INPUT);  // M3
  pinMode(A7, INPUT);  // M4
  pinMode(A8, INPUT);  // M2
  pinMode(A9, INPUT);  // M1

  //       RIGHT
  pinMode(A10, INPUT);  // R3
  pinMode(A11, INPUT);  // R1
  pinMode(A12, INPUT);  // R4
  pinMode(A13, INPUT);  // R2


  Serial.begin(9600);

  //                               VALUES
  /*..................................................................*/
  /*..................................................................*/
  /*..................................................................*/
  /* ... */ l = 140;        // value of left line          // ......
  /* ... */ r = 140;        // value of right line         // ......
  /* ... */ btt == 0;       // starting btt counter        // ......
  /* ... */ Lcandle = 480;  // value of left candle        // ......
  /* ... */ Mcandle = 480;  // value of middle candle      // ......
  /* ... */ Rcandle = 480;  // value of right candle       // ......
  /*..................................................................*/
  /*..................................................................*/
  /*..................................................................*/

  //                                SERVO
  myservo.attach(7);   // servo attached to MEGA pin 9
  myservo.write(off);  // define central servo position
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


void loop() {


  //calibration();

  if (digitalRead(13) == LOW) {  // wait for start button
    btt++;
    delay(400);
  }

  if (btt >= 1) {
    gofwd();
    myservo.write(off);

    //----------------------------------------------------------------------------------------------------------------------------

    // Left candle sensors
    if (analogRead(A2) < Lcandle or analogRead(A3) < Lcandle or analogRead(A4) < Lcandle or analogRead(A5) < Lcandle) {
      L = true;
    } else {
      L = false;
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // Middle candle sensors

    if (analogRead(A6) < Mcandle or analogRead(A7) < Mcandle or analogRead(A8) < Mcandle or analogRead(A9) < Mcandle) {
      M = true;
    } else {
      M = false;
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // Right candle sensors
    if (analogRead(A10) < Rcandle or analogRead(A11) < Rcandle or analogRead(A12) < Rcandle or analogRead(A13) < Rcandle) {
      R = true;
    } else {
      R = false;
    }

    //----------------------------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------------------------

    // detected right line and front candle FALSE

    if ((analogRead(A1) < r) and (M == false) and (analogRead(A0) > l) and (digitalRead(10) == LOW)) {
      motorstop();
      search();
      delay(200);
      for (int y = 0; y < 4; y++) {
        goback();
      }
      delay(400);

      /* for(int y = 0; y < 630/90; y++){
        turnR();
        }
      */
      randR();
      delay(100);
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // detected left line and front candle FALSE

    if ((analogRead(A0) < l) and (M == false) and (analogRead(A1) > r) and (digitalRead(10) == LOW)) {
      motorstop();
      search();
      delay(200);
      for (int y = 0; y < 4; y++) {
        goback();
      }
      delay(400);
      /*for(int y = 0; y <  630/90; y++){
        turnL();
        }
      */
      randL();
      delay(100);
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // detected right line and left line and front candle FALSE

    if ((analogRead(A1) < r and analogRead(A0) < l) and (M == false) and (digitalRead(10) == LOW) and (L == false) and (R == false)) {
      motorstop();
      search();
      delay(200);
      for (int y = 0; y < 4; y++) {
        goback();
      }
      delay(400);
      /*for(int y = 0; y <  630/90; y++){
        turnR();
        }
      */
      randRotate();
      delay(100);
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // ultrasonic and front candle FALSE


    if (((digitalRead(10) == HIGH) and (M == false)) and (analogRead(A1) > r or analogRead(A0) > l) and (digitalRead(8) == HIGH)) {  // ultrasonic true
      motorstop();
      delay(200);  // delay min 200 for completely stop motors and for discharge capacitor on PWB
      search();
      delay(100);

      for (int x = 0; x < 2; x++) {
        goback();
      }

      delay(400);
      randRotate();
      delay(100);
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // detected left candle

    if ((L == true) and (M == false)) {
      motorstop();
      delay(800);
      for (int y = 0; y < 630 / 90; y++) {
        turnL();
      }

      delay(1000);
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // detected right candle

    if ((R == true) and (M == false)) {
      motorstop();
      delay(800);
      for (int y = 0; y < 630 / 90; y++) {
        turnR();
      }

      delay(1000);
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // detected front candle and detected line and ultrasonic FALSE

    if (((analogRead(A1) < r or (analogRead(A0) < l)) and (M == true)) and (digitalRead(8) == HIGH) and ((digitalRead(10) == HIGH) or digitalRead(10) == LOW)) {
      motorstop();
      delay(200);


      delay(200);
      propeller();
      delay(100);
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // stop button
    if (digitalRead(13) == LOW) {
      motorstop();

      btt = 0;
      delay(1000);
    }


    //----------------------------------------------------------------------------------------------------------------------------

    // bumper
    if ((digitalRead(8) == LOW) and (M == false)) {
      motorstop();
      delay(100);
      for (int x = 0; x < 4; x++) {
        goback();
      }
      delay(400);

      randRotate();
      delay(100);
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // bumper  and candle true
    if ((digitalRead(8) == LOW) and (M == true)) {
      motorstop();
      delay(200);
      propeller();
      motorstop();
      delay(100);
      for (int x = 0; x < 4; x++) {
        goback();
      }
      delay(400);

      randRotate();
      delay(100);
    }

    //----------------------------------------------------------------------------------------------------------------------------
  }
}
