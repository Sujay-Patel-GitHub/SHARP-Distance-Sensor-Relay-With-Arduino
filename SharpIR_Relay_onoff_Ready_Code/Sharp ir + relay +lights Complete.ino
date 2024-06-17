#include "SharpIR.h"
#define IRPin1 A5
#define IRPin2 A4
#define IRPin3 A3
#define IRPin4 A2
#define relayPin9 9
#define relayPin10 10
#define relayPin7 7
#define relayPin3 3
#define relayPin12 12
#define relayPin13 13
#define relayPin5 5
#define model 100500

int distance1_cm;
int distance2_cm;
int distance3_cm;
int distance4_cm;

SharpIR sensor1 = SharpIR(IRPin1, model);
SharpIR sensor2 = SharpIR(IRPin2, model);
SharpIR sensor3 = SharpIR(IRPin3, model);
SharpIR sensor4 = SharpIR(IRPin4, model);

void setup() {
  pinMode(relayPin9, OUTPUT);
  pinMode(relayPin10, OUTPUT);
  pinMode(relayPin7, OUTPUT);
  pinMode(relayPin12, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin13, OUTPUT);
  pinMode(relayPin5, OUTPUT);
  pinMode(1, INPUT);
  
  digitalWrite(relayPin9, LOW); 
  digitalWrite(relayPin10, LOW); 
  digitalWrite(relayPin7, HIGH);
  digitalWrite(relayPin3, HIGH); 
  digitalWrite(relayPin5, LOW);   
  digitalWrite(relayPin12, HIGH); 
  digitalWrite(relayPin13, HIGH); 

  Serial.begin(9600); 
}

void zigzag() {
  digitalWrite(relayPin9, HIGH); 
  digitalWrite(relayPin10, HIGH);  
  digitalWrite(relayPin7, LOW);
  digitalWrite(relayPin3, LOW); 
  digitalWrite(relayPin5, HIGH);   
  digitalWrite(relayPin12, LOW); 
  digitalWrite(relayPin13, LOW); 
  delay(500);
  digitalWrite(relayPin13, HIGH);
  delay(500);
  digitalWrite(relayPin3, HIGH);
  delay(500);
  digitalWrite(relayPin12, HIGH);
  delay(500);
  digitalWrite(relayPin5, LOW);
  delay(500);
  digitalWrite(relayPin7, HIGH);
  delay(500);
  digitalWrite(relayPin10, LOW);
  delay(500);
  digitalWrite(relayPin9, LOW); 
  delay(500);
  digitalWrite(relayPin9, HIGH);
  delay(500);
  digitalWrite(relayPin10, HIGH);
  delay(500);
  digitalWrite(relayPin7, LOW);
  delay(500);
  digitalWrite(relayPin3, LOW); 
  delay(500);
  digitalWrite(relayPin5, HIGH);
  delay(500);
  digitalWrite(relayPin12, LOW);
  delay(500);
  digitalWrite(relayPin13, LOW);
}

void loop() {
  int pin1State = digitalRead(1);
  Serial.println(pin1State);  
  delay(1000);  

  if (pin1State == HIGH) {
    zigzag();

    unsigned long lastDetectionTime = millis();

    while (true) {
      distance1_cm = sensor1.distance();
      distance2_cm = sensor2.distance();
      distance3_cm = sensor3.distance();
      distance4_cm = sensor4.distance();

      bool anySensorDetected = (distance1_cm >= 1 && distance1_cm < 250) ||
                               (distance2_cm >= 1 && distance2_cm < 250) ||
                               (distance3_cm >= 1 && distance3_cm < 250) ||
                               (distance4_cm >= 1 && distance4_cm < 250);

      if (anySensorDetected) {
        lastDetectionTime = millis();
        if (distance1_cm >= 0 && distance1_cm < 250) {
          if (distance1_cm == 0 || distance1_cm >= 220) {
            digitalWrite(relayPin9, HIGH); 
            digitalWrite(relayPin10, HIGH); 
            digitalWrite(relayPin7, LOW);
            digitalWrite(relayPin3, LOW); 
            digitalWrite(relayPin5, HIGH);   
            digitalWrite(relayPin12, LOW); 
            digitalWrite(relayPin13, LOW);  
          } else if (distance1_cm <= 120) {
            digitalWrite(relayPin9, HIGH); 
            digitalWrite(relayPin10, LOW); 
            digitalWrite(relayPin7, LOW);
            digitalWrite(relayPin3, LOW); 
            digitalWrite(relayPin5, HIGH);   
            digitalWrite(relayPin12, LOW); 
            digitalWrite(relayPin13, LOW); 
          } else if (distance1_cm >= 150) {
            digitalWrite(relayPin9, LOW); 
            digitalWrite(relayPin10, HIGH); 
            digitalWrite(relayPin7, LOW);
            digitalWrite(relayPin3, LOW); 
            digitalWrite(relayPin5, HIGH);   
            digitalWrite(relayPin12, LOW); 
            digitalWrite(relayPin13, LOW); 
          }
        }
        if(distance2_cm >= 0 && distance2_cm <= 250){

   if(distance2_cm == 0 || distance2_cm >= 220 ){
     
  //digitalWrite(relayPin9, LOW);
  digitalWrite(relayPin7, LOW);  
  // digitalWrite(relayPin10, LOW); 
  // digitalWrite(relayPin3, HIGH); 
  // digitalWrite(relayPin5, LOW);   
  // digitalWrite(relayPin12, HIGH); 
  // digitalWrite(relayPin13, HIGH); 

  }   

  else if(distance2_cm <= 150){
     
  digitalWrite(relayPin9, HIGH); 
  digitalWrite(relayPin10, HIGH); 
  digitalWrite(relayPin7, HIGH);
  digitalWrite(relayPin3, LOW); 
  digitalWrite(relayPin5, HIGH);   
  digitalWrite(relayPin12, LOW); 
  digitalWrite(relayPin13, LOW); 

  }
}
        if(distance3_cm >= 0 && distance3_cm <= 250){

  if(distance3_cm == 0 || distance3_cm >= 220 ){
     
  digitalWrite(relayPin3, LOW); 
  digitalWrite(relayPin5, HIGH); 
  // digitalWrite(relayPin9, LOW); 
  // digitalWrite(relayPin10, LOW); 
  // digitalWrite(relayPin7, HIGH); 
  // digitalWrite(relayPin12, HIGH); 
  // digitalWrite(relayPin13, HIGH); 

  }

  else if(distance3_cm <= 130){
     
  digitalWrite(relayPin9, HIGH); 
  digitalWrite(relayPin10, HIGH); 
  digitalWrite(relayPin7, LOW);
  digitalWrite(relayPin3, HIGH); 
  digitalWrite(relayPin5, HIGH);   
  digitalWrite(relayPin12, LOW); 
  digitalWrite(relayPin13, LOW); 

  }

  else if(distance3_cm >= 160){
     
  digitalWrite(relayPin9, HIGH); 
  digitalWrite(relayPin10, HIGH); 
  digitalWrite(relayPin7, LOW);
  digitalWrite(relayPin3, LOW); 
  digitalWrite(relayPin5, LOW);   
  digitalWrite(relayPin12, LOW); 
  digitalWrite(relayPin13, LOW); 

  }

}
if(distance4_cm >= 0 && distance4_cm <= 250){

 if(distance4_cm == 0 || distance4_cm >= 220 ){
     
  digitalWrite(relayPin13, LOW); 
  digitalWrite(relayPin12, LOW);  
  // digitalWrite(relayPin9, LOW); 
  // digitalWrite(relayPin10, LOW); 
  // digitalWrite(relayPin7, HIGH);
  // digitalWrite(relayPin3, HIGH); 
  // digitalWrite(relayPin5, LOW);

  }
  else if(distance4_cm <= 130){
     
  digitalWrite(relayPin9, HIGH); 
  digitalWrite(relayPin10, HIGH); 
  digitalWrite(relayPin7, LOW);
  digitalWrite(relayPin3, LOW); 
  digitalWrite(relayPin5, HIGH);   
  digitalWrite(relayPin12, LOW); 
  digitalWrite(relayPin13, HIGH); 

  }

  else if(distance4_cm >= 160){
     
  digitalWrite(relayPin9, HIGH); 
  digitalWrite(relayPin10, HIGH); 
  digitalWrite(relayPin7, LOW);
  digitalWrite(relayPin3, LOW); 
  digitalWrite(relayPin5, HIGH);   
  digitalWrite(relayPin12, HIGH); 
  digitalWrite(relayPin13, LOW); 

  }

}
      } else {
        if (millis() - lastDetectionTime >= 5000) {
          distance1_cm = sensor1.distance();
          distance2_cm = sensor2.distance();
          distance3_cm = sensor3.distance();
          distance4_cm = sensor4.distance();

          if ((distance1_cm < 250) || (distance2_cm < 250) || 
              (distance3_cm < 250) || (distance4_cm < 250)) {
            zigzag();
            lastDetectionTime = millis();
          }
        }
      }

      delay(1000);  // Add a delay to prevent rapid looping
    }
  }
  
}