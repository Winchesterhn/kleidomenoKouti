int pinLed = 13;

int buttonsAndCode[4] = {8, 9, 10, 11};
int buttonState[4] = {0, 0, 0, 0};

bool solved = 0;

void setup() {
  // put your setup code here, to run once:
for (int i = 0; i < 4; i++) {
    pinMode(buttonsAndCode[i], INPUT);

  }
  Serial.begin(9600);
  digitalWrite(pinLed, LOW);
}

void loop() {
  
if (digitalRead(buttonState[0]) == LOW){ //if button1 is pressed
    checkEntered1(1); //call checkEntered and pass it a 1
    
    delay(1000);//wait, needed for correct functioning, otherwise
               //buttons are deemed to be pressed more than once
    
  }
  else if (digitalRead(buttonState[1]) == LOW){ //if button2 is pressed
    checkEntered1(2); //call checkEntered1 and pass it a 2
    
    delay(1000); //wait
    
  }
  else if (digitalRead(buttonState[2]) == LOW){ //if button3 is pressed
    checkEntered1(3); //call checkEntered1 and pass it a 3
    
    delay(1000); //wait
    
  }
  else if (digitalRead(buttonState[3]) == LOW){ //if button4 is pressed
    checkEntered1(4); //call checkEntered1 and pass it a 4
    
    delay(1000); //wait
    
  }
  
    
  }
