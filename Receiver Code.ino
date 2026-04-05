#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <RCSwitch.h>

SoftwareSerial mySerial(8, 9);

LiquidCrystal lcd(A5, 3, 4, 5, 6, 7);

RCSwitch mySwitch = RCSwitch();

int flag;

char C;

int value;
int Buzzer = A0;

long Time;

void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  mySwitch.enableReceive(0); 
  delay(100);

  lcd.begin(16, 2);
  lcd.print("  HEALTH  CARE  ");

  flag = 0;
  delay(5000);

  pinMode(Buzzer,OUTPUT);
}


void loop(){
  if (mySwitch.available()) {   
    value = mySwitch.getReceivedValue();
    mySwitch.resetAvailable();
    digitalWrite(13,HIGH);
    Serial.println(value);
    delay(10);
    digitalWrite(13,LOW);
  }
  
  lcd.setCursor(0,0);
  
  if     ( value == 1111){digitalWrite(Buzzer,HIGH); delay(10);lcd.print("CALL ATTENDENT ");digitalWrite(Buzzer,LOW);delay(10);if (millis()-Time > 10000){SendMessageA();Time = millis();}}
  else if( value == 2222){digitalWrite(Buzzer,HIGH); delay(10);lcd.print("I NEED WATER   ");digitalWrite(Buzzer,LOW);delay(10);if (millis()-Time > 10000){SendMessageB();Time = millis();}}
  else if( value == 3333){digitalWrite(Buzzer,HIGH); delay(10);lcd.print("I AM HUNGRY    ");digitalWrite(Buzzer,LOW);delay(10);if (millis()-Time > 10000){SendMessageC();Time = millis();}}
  else if( value == 4444){digitalWrite(Buzzer,HIGH); delay(10);lcd.print("SOME PROBLEM   ");digitalWrite(Buzzer,LOW);delay(10);if (millis()-Time > 10000){SendMessageD();Time = millis();}}
  else if( value == 9999){lcd.print(" NO COMMAND     ");Time = millis(); }
}


void SendMessageA(){
  lcd.setCursor(0,1);
  lcd.print("MAIL SENDING  ");
  mySerial.println("AT+CMGF=1");
  
  digitalWrite(Buzzer,HIGH);
  delay(1000);
   
  mySerial.println("AT+CMGS=\"+919001008233\"\r"); 
  
  digitalWrite(Buzzer,LOW);
  delay(1000);
  
  mySerial.println(" CALL ATTENDENT ");
  
  digitalWrite(Buzzer,HIGH);  
  delay(100);
  
  mySerial.println((char)26);
  lcd.setCursor(0,1);
  lcd.print("SENT            ");

  digitalWrite(Buzzer,LOW);
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("                ");
}

void SendMessageB(){
  lcd.setCursor(0,1);
  lcd.print("MAIL SENDING   ");
  mySerial.println("AT+CMGF=1");
  
  digitalWrite(Buzzer,HIGH);
  delay(1000);
  
  mySerial.println("AT+CMGS=\"+919001008233\"\r"); 
  
  digitalWrite(Buzzer,LOW);
  delay(1000);
  
  mySerial.println(" I NEED WATER ");
  
  digitalWrite(Buzzer,HIGH);
  delay(100);
  mySerial.println((char)26);
  lcd.setCursor(0,1);
  lcd.print("SENT            ");
  
  digitalWrite(Buzzer,LOW);
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("                ");
}

void SendMessageC(){
  lcd.setCursor(0,1);
  lcd.print("MAIL SENDING   ");
  mySerial.println("AT+CMGF=1");
  
  digitalWrite(Buzzer,HIGH);
  delay(1000);
   
  mySerial.println("AT+CMGS=\"+919001008233\"\r"); 
  
  digitalWrite(Buzzer,LOW);
  delay(1000);
  mySerial.println(" I AM HUNGRY ");
  
  digitalWrite(Buzzer,HIGH);
  delay(100);
  mySerial.println((char)26);
  lcd.setCursor(0,1);
  lcd.print("SENT            ");
  
  digitalWrite(Buzzer,LOW);
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("                ");
}

void SendMessageD(){
  lcd.setCursor(0,1);
  lcd.print("MAIL SENDING   ");
  mySerial.println("AT+CMGF=1");
  
  digitalWrite(Buzzer,HIGH);
  delay(1000);
  mySerial.println("AT+CMGS=\"+919001008233\"\r"); 
  
  digitalWrite(Buzzer,LOW);
  delay(1000);
  mySerial.println(" SOME PROBLEM ");
  
  digitalWrite(Buzzer,HIGH);
  delay(100);
  mySerial.println((char)26);
  lcd.setCursor(0,1);
  lcd.print("SENT            ");
  
  digitalWrite(Buzzer,LOW);
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("                ");
}
