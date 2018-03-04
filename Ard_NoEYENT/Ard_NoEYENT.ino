#define baud_rate 9600

//response button pin 
const byte rsp_but = 2;
volatile byte rsp_clicked = LOW;
 
//define LED pin 
int LEDS[] = {3,4,5,6,7,8,9,10};

void setup() {
  Serial.begin(baud_rate);
  //Setup for interrupts
  pinMode(rsp_but, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rsp_but), click, HIGH);

  
  for(int LED_NUM = 0; LED_NUM < sizeof(LEDS); LED_NUM++) {
    pinMode(LEDS[LED_NUM], OUTPUT);
  }

  //shuffle LEDS ord
  for (int i = 0; i < sizeof(LEDS); i++) {
    int r = random(i, 7);
    int temp = LEDS[i];
    LEDS[i] = LEDS[r];
    LEDS[r] = temp;
  }

}

void loop() {
  for(int LED_NUM = 0; LED_NUM < 8; LED_NUM++) {
    digitalWrite(LEDS[LED_NUM],HIGH);
    Serial.println(LEDS[LED_NUM]);
    delay(500);
    digitalWrite(LEDS[LED_NUM],LOW);
    int r_delay = random(200, 2000);
    delay(r_delay);
  }

}

void click() {
  rsp_clicked = HIGH;
  Serial.println("rsp_clicked");
  rsp_clicked = LOW; //these are just for later use maybe..
}


