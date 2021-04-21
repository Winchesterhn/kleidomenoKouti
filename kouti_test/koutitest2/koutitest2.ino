//#include <Servo.h>
//int servoPin = 12;
//Servo boxLock;
int pinLed = 13;
int led = 0;

int buttonsAndCode[4] = {A0, A1, A2, A5};
int buttonState[4] = {0, 0, 0, 0};


void setup() {
  // boxLock.attach(servoPin);

  for (int i = 0; i < 4; i++) {
    pinMode(buttonsAndCode[i], INPUT);
  }
  Serial.begin(9600);
  pinMode (pinLed, OUTPUT);
  // Serial.begin(57600);
}

void loop() {
  //  digitalWrite(led, LOW);
  //
  //  for (int i = 0; i < 4; i++) {
  //    analogWrite(buttonsAndCode[i], LOW);
  //  }
  //  for (int i = 0; i < 4; i++) {
  //    buttonState[i] = analogRead(A0);
  //  }
  //  for (int i = 0; i < 4; i++) {
  //    Serial.print(buttonState[i]);
  //    Serial.print("\n");
  //  }
  buttonState[0] = analogRead(A0);
  Serial.print(buttonState[0]);
  Serial.print("\n");
  buttonState[1] = analogRead(A1);
  Serial.print(buttonState[1]);
  Serial.print("\n");
  buttonState[2] = analogRead(A2);
  Serial.print(buttonState[2]);
  Serial.print("\n");
  buttonState[3] = analogRead(A5);
  Serial.print(buttonState[3]);
  Serial.print("\n");
  digitalWrite(led, LOW);
}
