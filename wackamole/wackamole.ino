int BUT1 = D10;
int BUT2 = D9;
int BUT3 = D8;
int BUT4 = D2; 

int LED1 = D4;
int LED2 = D5;
int LED3 = D6;
int LED4 = D1;

int buttonPins[] = {BUT1, BUT2, BUT3, BUT4};
int ledPins[] = {LED1, LED2, LED3, LED4};

int currentMole = -1;
unsigned long moleStartTime = 0;
unsigned long whackTimeout = 1000;
int score = 0;
bool moleAlive = false;

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

  Serial.println("Start!");
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (!moleAlive) {
    delay(random(200, 1000));
    pickedMole = random(0, 4);
    digitalWrite(ledPins[pickedMole], HIGH);
    moleStartTime = millis();
    moleAlive = true;
  }

  if (moleAlive && (millis() - moleStartTime > whackTimeout)) {
    gameOver()
  }

  if (moleAlive){
    for (int i = 0; i < 4; i++){
      if (digitalRead(buttonPins[i]) == LOW){
        if (i == pickedMole){
            digitalWrite(ledPins[pickedMole], LOW);
            moleAlive = false;
            score++;
            Serial.print("Hit! Score: ");
            Serial.println(score);

            if (whackTimeout > 250){
              whackTimeout -= 50;
            }
            delay(100);
            break;
        } else {
          gameOver();
        }
      }
    }
  }


}




void gameOver(){
  for (int i = 0; i < 4; i++){
    digitalWrite(ledPins[i], LOW);
  }
  Serial.print("Game Over! Score: ");
  Serial.println(score);

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 4; j++){
      digitalWrite(ledPins[i], HIGH);
    }
    delay(200);
    for (int j = 0; j < 4; j++){
      digitalWrite(ledPins[i], HIGH);
    }
    delay(200);
  }

  score = 0;
  whackTimeout = 1000;
  moleAlive = false;
  Serial.println("Game Restarting");
  delay(2000);
}










