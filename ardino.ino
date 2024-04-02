#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>
 
#define PIN_TX    11
#define PIN_RX    10
SoftwareSerial mySerial(PIN_TX,PIN_RX);
DFRobot_SIM808 sim808(&mySerial);
 
#define PHONE_NUMBER  "+9876543210"   
 
#define FLAME 7
int pinSensor=6;
int pinBuzzer=13;
int pirSensor=0;
void setup(){
  pinMode(pinSensor,INPUT);
  pinMode(pinBuzzer,OUTPUT);
  pinMode(FLAME,INPUT);
  Serial.begin(9600);
}
void loop(){
  if(digitalRead(pinSensor)==HIGH || digitalRead(FLAME)==LOW)
  {
    Serial.println("object detected");
    tone(pinBuzzer,1000,500);
    calling();
  }
  else
  {
    Serial.println("not detected");
  }
  delay(1000);
}
 
void calling() {
  mySerial.begin(9600);
  Serial.begin(9600);
  Serial.println("Sim800 init success");
  Serial.println("Start to call ...");
 
  sim800.callUp(PHONE_NUMBER);
  delay(2000);
  tone(pinBuzzer,1500);
  delay(10000);
  noTone(pinBuzzer);
   
}
