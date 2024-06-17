#include "SharpIR.h"

#define IRPin1 A5
#define IRPin2 A4
#define IRPin3 A3
#define IRPin4 A2

//#define relayPin1 12

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
  Serial.begin(9600);

  
}

void loop() {
  distance1_cm = sensor1.distance();
  distance2_cm = sensor2.distance();
  distance3_cm = sensor3.distance();
  distance4_cm = sensor4.distance();

  Serial.print("Sensor 1: ");
  Serial.print(distance1_cm);
  Serial.print(" cm, ");

  Serial.print("Sensor 2: ");
  Serial.print(distance2_cm);
  Serial.print(" cm, ");

  Serial.print("Sensor 3: ");
  Serial.print(distance3_cm);
  Serial.print(" cm, ");

  Serial.print("Sensor 4: ");
  Serial.print(distance4_cm);
  Serial.println(" cm");

  delay(100);


  // if (distance4_cm <= 100) {
  //   digitalWrite(relayPin1, LOW); // Turn on relay connected to pin 12
  //   //digitalWrite(relayPin2, LOW);  // Turn off relay connected to pin 13
  // } else if (distance4_cm > 100) {
  //   digitalWrite(relayPin1, HIGH);  // Turn off relay connected to pin 12
  //   //digitalWrite(relayPin2, HIGH); // Turn on relay connected to pin 13
  // }
  
  // if (distance4_cm >= 200 || distance4_cm == 0) {
  //  // digitalWrite(relayPin3, HIGH); // Turn off relay connected to pin 12
  //   digitalWrite(relayPin1, LOW); // Turn off relay connected to pin 13
  // }

  delay(100);
}
