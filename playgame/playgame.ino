#include <Keyboard.h>

int BUT1 = D10; // left + a
int BUT2 = D9; // down + s
int BUT3 = D8; // right + d
int BUT4 = D2; // up + w

int LED1 = D4;
int LED2 = D5;
int LED3 = D6;
int LED4 = D1;


void setup() {
  // put your setup code here, to run once:
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  pinMode(BUT4, INPUT_PULLUP);


  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  Keyboard.begin();
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  // lights up button 1 if pressed
  if (digitalRead(BUT1) == HIGH){
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  // lights up button 2 if pressed
  if (digitalRead(BUT2) == HIGH){
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  // lights up button 3 if pressed
  if (digitalRead(BUT3) == HIGH){
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
  // lights up button 4 if pressed
  if (digitalRead(BUT4) == HIGH){
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED4, LOW);
  }

  handleButton(BUT1, "a", KEY_LEFT_ARROW);
  handleButton(BUT2, "s", KEY_DOWN_ARROW);
  handleButton(BUT3, "d", KEY_RIGHT_ARROW);
  handleButton(BUT4, "w", KEY_UP_ARROW);

}

void handleButton(int pin, char asciiKey, uint8_t theKey) {
  if (digitalRead(pin) == LOW){
    Keyboard.press(asciiKey);
    Keyboard.press(theKey);
  } else {
    Keyboard.release(asciiKey);
    Keyboard.release(theKey);
  }
}











