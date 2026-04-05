#include <EEPROM.h>

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int val1;
int val2;

int valX;
int valY;

int SensorX = A5;
int SensorY = A6;

int Switch = 7;

int LED1 = 8;
int LED2 = 9;
int LED3 = A0;
int LED4 = A1;

void setup() {
  Serial.begin(9600);
  
  mySwitch.enableTransmit(4);

   
  pinMode(SensorX , INPUT);
  pinMode(SensorY , INPUT);

  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  
  pinMode(Switch , INPUT_PULLUP);

  if (digitalRead(Switch) == LOW){
    val1 = analogRead(SensorX)/4;
    val2 = analogRead(SensorY)/4;
    
    EEPROM.write(0, val1);
    EEPROM.write(1, val2);
    
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
}

void loop() {
  valX = analogRead(SensorX)/4;
  valY = analogRead(SensorY)/4;

  if      (EEPROM.read(0) + 10 < valX ) { digitalWrite(LED1,HIGH); mySwitch.send(1111, 24);}  
  
  else if (EEPROM.read(0) - 10 > valX ) { digitalWrite(LED2,HIGH); mySwitch.send(2222, 24);}
  else if (EEPROM.read(1) + 10 < valY ) { digitalWrite(LED3,HIGH); mySwitch.send(3333, 24);}
  else if (EEPROM.read(1) - 10 > valY ) { digitalWrite(LED4,HIGH); mySwitch.send(4444, 24);} 
  
  else                                  { digitalWrite(LED1,LOW); 
                                          digitalWrite(LED2,LOW);
                                          digitalWrite(LED3,LOW);
                                          digitalWrite(LED4,LOW);  
                                          
                                         mySwitch.send(9999, 24); }
  delay(300);
}
