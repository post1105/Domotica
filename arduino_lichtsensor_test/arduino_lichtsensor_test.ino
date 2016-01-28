#include <RCSwitch.h> //include de librairy die bij jouw schakelaar hoort.
 
#define sensorPin 0
//#define RFPin 4
 
int sensorReading = 0;
int thresholdValue = 20; //verander naar afstelling van je lichtsensor.
bool isSwitchOn = false;
RCSwitch mySwitch = RCSwitch(); //vervang dit met de transmitter die bij jouw schakelaar hoort.
RCSwitch mySwitch2 = RCSwitch();
RCSwitch mySwitch3 = RCSwitch();
 
void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(2);
  mySwitch2.enableTransmit(2);
  mySwitch3.enableTransmit(2);
  
 
}
 
//deze code gaat er vanuit dat je schakelaar aan het begin UIT staat.
void loop() {
  sensorReading = analogRead(sensorPin);
  Serial.print("Sensor reading: "); Serial.println(sensorReading);
  if(sensorReading >= thresholdValue) //ik ga hiervan uit van een ldr, als ik licht op de sensor schijnt wordt de waarde lager; is dat bij jullie niet het geval verander "<=" naar ">="
  {    
    if(!isSwitchOn)
    {
      Serial.println("transmitting on signal to switch");
     
         mySwitch.send(3874351,24);//1
         
        
     
      //vervang dit met de code die bij jouw schakelaar hoort
      isSwitchOn = true;
    }
    else
      Serial.println("switch is already ON. idling...");
  }
  else
  {
    if(isSwitchOn)
    {
      Serial.println("transmitting off signal to switch");
      mySwitch.send(3874350,24);//1
      //3 //vervang dit met de code die bij jouw schakelaar hoort
      isSwitchOn = false;
    }
    else
      Serial.println("switch is already OFF. idling...");
  }  delay(1500);
  delay(1500);
}
