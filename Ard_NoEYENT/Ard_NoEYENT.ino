//response button pin 
#define rsp_but 9;

//define LED pin 
int LEDS[] = {1,2,3,4,5,6,7,8};

void setup() {
  pinMode(rsp_but, INPUT);
  
  for(int LED_NUM = 0; LED_NUM < sizeof(LEDS); LED_NUM++) {
    pinMode(LEDS[LED_NUM], OUTPUT);
  }

  //shuffle LEDS ord
  for (int i = 0; i < sizeof(LEDS); i++) {
    int r = random(i, 8);
    int temp = LEDS[i];
    LEDS[i] = LEDS[r];
    LEDS[r] = temp;
  }

}

void loop() {
  for(int LED_NUM = 0; LED_NUM < sizeof(LEDS); LED_NUM++) {
    digitalWrite(LEDS[LED_NUM],HIGH);
    delay(500);
    digitalWrite(LEDS[LED_NUM],LOW);
    int r_delay = random(200, 2000);
    delay(r_delay);
  }

}
