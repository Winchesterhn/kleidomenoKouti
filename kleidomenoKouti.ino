#include <Servo.h>// library necessary for micro servo
int servoPin = 12;
Servo boxLock;
int nDoor = 13;// this pin will be set to 5V when the riddle is solved

int buttonsAndCode[5] = {2, 3, 4, 5, 6};//declare all button pins. The first 4 are the correct sequence. 
int buttonState[5] = {0, 0, 0, 0, 0};//flag refering to the state of the button

void setup() {
  boxLock.attach(servoPin);

  for (int i = 0; i < 5; i++) {
    pinMode(buttonsAndCode[i], INPUT);// declare all button pins as input
  }
  pinMode(nDoor, OUTPUT);
  digitalWrite(nDoor, LOW);// pull the "riddle solved" pin to ground
  Serial.begin(9600);// Allow serial communication. For debugging.
}

void loop() {
  int pressed;
  int i = 0;
  while (i < 4) {
   //Reads all the buttons and sets the ButtonState table accordingly.
    for (int j = 0; j < 5; j++) {
      buttonState[j] = digitalRead(buttonsAndCode[j]);
      //Waits while a button is pressed. Necessary, so the arduino doesn't read the same button multiple times.
      while (digitalRead(buttonsAndCode[j]) == 1) {
        delay(100);
      }
    }
    pressed = -1;//A value that would not be reached. 
    //Checks which button is pressed and sets the variable "pressed" accordingly.
    for (int j = 0; j < 5; j++) {
      if (buttonState[j] == 1) {
        pressed = j;
        break;// when it knows which is pressed, it exits the "for loop".
      }
    }
    //Checks if any button was pressed. If it was correct, moves on to the next. If not, restarts.
    if (pressed >= 0) {
      if ( pressed == i ) {
        i = i + 1;
        Serial.print("correct: ");
        Serial.println(pressed);
      }
      else {
        Serial.print("wrong: ");
        Serial.print(pressed);
        Serial.println("  Resets! ");
        i = 0;
      }
    }
  }
  Door();//Opens the box and waits until reset.
}


//Opens the box and waits until reset.
void Door() {
  digitalWrite(nDoor, HIGH);
  boxLock.write(180);// Make servo go to 90 degrees, unlocks the box.
  Serial.print("the box unlocks\n");
  while (true);
}
