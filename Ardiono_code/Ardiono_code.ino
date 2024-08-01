#include<util/
#include <LiquidCrystal.h>

const int rs= 12, en= 11, d4= 5, d5= 4, d6= 3, d7= 2;
LiquidCrystal lcd(rs, en,d4, d5, d6, d7); 

const int trigPin = 6;
const int echoPin = 8;
const int ledPin = 10;
const int buzzerPin = 9;


float duration_us, distance_cm;

void setup() {

  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration_us = pulseIn(echoPin, HIGH);


  distance_cm = 0.03482 * duration_us/2;  //Velocity of sound in air, Va=348.2m/s = 0.03482cm/us  


  if (distance_cm > 60) 
    {
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No one near");
      lcd.setCursor(0, 1);
      lcd.print("Distance: ");
      lcd.print(distance_cm);
      Serial.println("No one near");
      Serial.print("Distance: ");
      Serial.println(distance_cm);
      delay(10);
    }
  else if (distance_cm < 10) 
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Danger");
      lcd.setCursor(0, 1);
      lcd.print("Distance: ");
      lcd.print(distance_cm);
      Serial.println("Danger");
      Serial.print("Distance: ");
      Serial.println(distance_cm);
      delay(10);
      digitalWrite(ledPin, HIGH);
      analogWrite(buzzerPin, 0);
      delay(2500);
      digitalWrite(ledPin, LOW);
      analogWrite(buzzerPin, 255);
      delay(2500);
    }
  else
    {
      float x = 2*(60 - distance_cm);
      int bright=255*x/100;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Distance: ");
      lcd.print(distance_cm);
      lcd.setCursor(0, 1);
      lcd.print("approach: ");
      lcd.print(x);
      lcd.print("%");
      Serial.print("approach: ");
      Serial.print(x);
      Serial.println("%");
      Serial.print("Distance: ");
      Serial.println(distance_cm);
      delay(10);

      analogWrite(ledPin, bright);
      analogWrite(buzzerPin, 0);
      delay(1500);

      analogWrite(ledPin, 0);
      analogWrite(buzzerPin, bright);
      delay(1500);
      }
}
