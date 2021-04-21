//#include <Servo.h>
//int servoPin = 12;
//Servo boxLock;
int nDoor = 13;// this pin is set to 5V when the riddle is solved

int buttonsAndCode[4] = {A0, A1, A2, A5};
int buttonState[4] = {0, 0, 0, 0};

bool solved = 0;

unsigned long previousMillis = 0;
unsigned long currentMillis = millis();
unsigned long period = 10000;

void setup() {
  // boxLock.attach(servoPin);

  for (int i = 0; i < 4; i++) {
    pinMode(buttonsAndCode[i], INPUT);
  }
  pinMode(nDoor, OUTPUT);
  digitalWrite(nDoor, LOW);// pull the "riddle solved" pin to ground
  Serial.begin(9600);
}

void loop() {

  if (solved == 0) {

    for (int i = 0; i < 4; i++) {

      //      unsigned long time_start = millis();// start time
      //      while (millis() - time_start <= 6000) {// Gives them 6 seconds to press the next correct button

      untilCorrectPressed(i);
      previousMillis = currentMillis;

      // }
      if (currentMillis - previousMillis >= period) {
        reset();
        previousMillis = currentMillis;
      }
    }
    //    while (buttonState[0] < 800) {
    //      buttonState[0] = analogRead(buttonsAndCode[0]);
    //      Serial.print(buttonState[0]);
    //      delay(2000);
    //      if (buttonState[0] >= 800) {
    //        Serial.print("first pressed \n");
    //if((buttonState[1] > 800) || (buttonState[2] > 800) || (buttonState[3] > 800)){
    //
    //      }
    //      }
    //
    //    }
    //    while (buttonState[1] < 800) {
    //      buttonState[1] = analogRead(buttonsAndCode[1]);
    //      Serial.print(buttonState[1]);
    //      delay(3000);
    //      if (buttonState[1] >= 800) {
    //        Serial.print("second pressed \n");
    //if((buttonState[0] > 800) || (buttonState[2] > 800) || (buttonState[3] > 800)){
    //
    //      }
    //      }
    //
    //    }
    //    while (buttonState[2] < 800) {
    //      buttonState[2] = analogRead(buttonsAndCode[2]);
    //      Serial.print(buttonState[2]);
    //      delay(3000);
    //      if (buttonState[2] >= 800) {
    //        Serial.print("third pressed \n");
    //if((buttonState[0] > 800) || (buttonState[1] > 800) || (buttonState[3] > 800)){
    //
    //      }
    //      }
    //
    //    }
    //    while (buttonState[3] < 800) {
    //      buttonState[3] = analogRead(buttonsAndCode[3]);
    //      Serial.print(buttonState[3]);
    //      delay(3000);
    //      if (buttonState[3] >= 800) {
    //        Serial.print("fourth pressed \n");
    //if((buttonState[0] > 800) || (buttonState[1] > 800) || (buttonState[2] > 800)){
    //
    //      }
    //      }
    //    }
  }
  for (int i = 0; i < 4; i++) {
    Serial.print(buttonState[i]);
    Serial.print("\n");
  }
  if ((buttonState[0] > 800) && (buttonState[1] > 800) && (buttonState[2] > 800) && (buttonState[3] > 800)) {//  Why does it always return true????

    solved = 1;
  }

  if (solved == 1); {//enter if the correct sequence was pressed
    // boxLock.write(180);// Make servo go to 90 degrees, unlocks the box.
    delay(5000);
    Serial.print("the box unlocks\n");
    Door();
  }
}
void untilCorrectPressed(int i) {
  while (buttonState[i] < 800) {
    buttonState[i] = analogRead(buttonsAndCode[i]);
    Serial.print(buttonState[i]);//shows the value of its button. Helps in debugging
    //    Serial.print("\n");
    delay(2000);
    if (buttonState[i] >= 800) {
      Serial.print("pressed correctly \n");
    }
  }
}
void Door() {
  digitalWrite(nDoor, HIGH);//Opens the box and waits until reset.
  while (true);
}
void reset() {
  buttonsAndCode[0] = analogRead(A0);
  buttonsAndCode[1] = analogRead(A1);
  buttonsAndCode[2] = analogRead(A2);
  buttonsAndCode[3] = analogRead(A5);
  buttonState[0] = 0;
  buttonState[1] = 0;
  buttonState[2] = 0;
  buttonState[3] = 0;
}
