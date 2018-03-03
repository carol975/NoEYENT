//define LED pin 
int LEDS[] = {0,1,2,3,4,5,6,7};


void setup() {
  for(int LED_NUM = 0; LED_NUM < sizeof(LEDS); LED_NUM++) {
    pinMode(LEDS[LED_NUM], OUTPUT);
  }


}

void loop() {
  for(int LED_NUM = 0; LED_NUM < sizeof(LEDS); LED_NUM++) {
    digitalWrite(LEDS[LED_NUM],HIGH);
    delay(500);
    digitalWrite(LEDS[LED_NUM],LOW);
    delay(500);
  }

}
