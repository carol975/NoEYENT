#define baud_rate 9600

//response button pin 
const byte rsp_but = 2;
volatile byte rsp_clicked = LOW;
 

int LEDS[] = {3,4,5,6,7};
int LEDHITS[] = {0,0,0,0,0};  
int PREV_LEDHITS[] = {0,0,0,0,0};


void setup() {

  Serial.begin(baud_rate);
  //Setup for interrupts
  pinMode(rsp_but, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rsp_but), click, HIGH);
  
  
  for(int LED_NUM = 0; LED_NUM < 5; LED_NUM++) {
    pinMode(LEDS[LED_NUM], OUTPUT);
  }

  //shuffle LEDS ord
  for (int i = 0; i < 5; i++) {
    int r = random(i, 4);
    int temp = LEDS[i];
    LEDS[i] = LEDS[r];
    LEDS[r] = temp;
  }

  //GUI
  Serial.println("==================WELCOME TO SIGHTSAVER==================");
  Serial.println("Instructions:");
  Serial.println("1. Hold the SIGHTSAVER goggle against your forehead");
  Serial.println("2. Cover one of your eyes");
  Serial.println("4. Locate the YELLOW spot on the cellphone screen with your eye, maintain gaze on the YELLOW spot throughout the test"); 
  Serial.println("5. Locate the response button on the right side of the goggle leg");
  Serial.println("6. Maintain gaze on the YELLOW SPOT, when you sense GREEN LED light up with your PERIPHERAL vision, click once on the response button");
  Serial.println("");
  Serial.println("=========================================================");
  delay(10000); //delay 10 seconds 

  Serial.println("Get ready, the test will begin shortly");
  delay(3000);
}

void loop() {
  for(int LED_NUM = 0; LED_NUM < 5; LED_NUM++) {
    digitalWrite(LEDS[LED_NUM],HIGH);
    Serial.println(LEDS[LED_NUM]);
    delay(500);
    digitalWrite(LEDS[LED_NUM],LOW);
    if(rsp_clicked == HIGH) {
      Serial.println("rsp is clicked");  
      rsp_clicked = LOW;
      LEDHITS[LED_NUM] = 1;
    }
    else {
      LEDHITS[LED_NUM] = -1;
    }
    
    int r_delay = random(200, 2000);
    delay(r_delay);
  }


  displayResult();
}

void click() {
  rsp_clicked = HIGH;
  //Serial.println("rsp is clicked");
  //rsp_clicked = LOW; //these are just for later use maybe..
}

void displayResult() {
  Serial.println("==================TEST COMPLETED=========================");
  Serial.println("==================RESULT=================================");
  Serial.print("Date: ");
  Serial.println(millis());
  Serial.println("Peripheral LED Seen Y = Seen, N = Not Seen");
  Serial.println("");
  Serial.println("L1 L2 L3 L4 L5");
  for(int LED_NUM = 0; LED_NUM < 5; LED_NUM++) {
     if(LEDHITS[LED_NUM] == 1) {
      Serial.print("Y  ");
     }
     else {
      Serial.print("N  ");
     }

  }
  Serial.print("\r\n");

  Serial.println("---CHANGES FROM PREVIOUS TEST--");
  //Changes comparison
  for( int LED_NUM = 0; LED_NUM <5; LED_NUM++) {
    if(LEDHITS[LED_NUM] != PREV_LEDHITS[LED_NUM]) {
      if(LEDHITS[LED_NUM] == -1) {
        Serial.print("L");
        Serial.print(LED_NUM);
        Serial.println(":PREV SEEN, CURR NOT SEEN");
      }
      else {
        Serial.print("L");
        Serial.print(LED_NUM);
        Serial.println(":PREV NOT SEEN, CURR SEEN");
      }
    }
  }
  Serial.println("");
  Serial.println("========================END==========================");

  //update previous LED HITS result);
  memcpy(LEDHITS,PREV_LEDHITS, 5*sizeof(int)); 
}




