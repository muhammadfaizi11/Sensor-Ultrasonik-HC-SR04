#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//define pin sensor ultrasonik
int trigPin = 8;
int echoPin = 9;

//define
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

//Variabel sensor ultrasonik
long duration;
float distanceCm, distanceInch;

//Variabel LCD
LiquidCrystal_I2C lcd(0x27, 20,4); //Set LCD Address to 0x27 for 20 chars and 4 line display

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init(); //Initialize LCD
  lcd.backlight();
  lcd.setCursor(0,1); //(0 menunjukan kolom ke, 1 menunjukan baris ke)
  lcd.print("PT SPINDO UNIT VI");
  lcd.setCursor(0,2);
  lcd.print("SIDOARJO, JAWA TIMUR");
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(100);
  digitalWrite(trigPin, HIGH);
  duration = pulseIn(echoPin,HIGH);
  //calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
//  distanceCm = duration / 58.2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  // Display to LCD   
  lcd.setCursor(0,1);
  lcd.print("Distance : ");
  lcd.setCursor(11,1);
  lcd.print(distanceCm);
  delay(1000);
}
