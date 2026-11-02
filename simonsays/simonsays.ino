int BUT1 = D10;
int BUT2 = D9;
int BUT3 = D8; 
int BUT4 = D2; 

int LED1 = D4;
int LED2 = D5;
int LED3 = D6;
int LED4 = D1;

const int buttons[] = {BUT1, BUT2, BUT3, BUT4};
const int leds[] = {LED1, LED2, LED3, LED4};

int sequence[15];
int level = 0;

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
}

void loop() {
  // put your main code here, to run repeatedly:
    delay(800);

  if (level >= 15){
    level = 0;
  }
  
  sequence[level] = random(4);
  level = level + 1;

  Serial.print("Level ");
  Serial.print(level);

  for (int i = 0; i < level; ++){
    flash(sequence[i]);
  }
  for (int i = 0; i < level; i++){
    int pressed = waitForPress();
    if (pressed != sequence[i]){
      gameOver();
      return;
    }
  }

}

void flash(int n){
  digitalWrite(leds[n], HIGH);
  delay(400);
  digitalWrite(leds[n]), LOW);
  delay(200);
}

int waitForPress(){
  unsigned long start = millis();

  while (millis() - start < 3000){
    for(int i = 0; i < 4; n++){

      if (digitalRead(buttons[n]) == LOW){
        digitalWrite(leds[n], HIGH);

        while (digitalRead(buttons[n]) == LOW){
          delay(10);
        }

        digitalWrite(leds[i], LOW);
        return i;
      }
    }
  }
  return -1;
}

void allLeds(int state) {
  for (int i = 0; i < 4; i++){
    digitalWrite(leds[i], state);
  }
}

void gameOver(){
  Serial.println("Game Over");
  for (int i = 0; i < 3){
    allLeds(HIGH);
    delay(200);
    allLeds(LOW);
    delay(200);
  }
  level = 0;
}


