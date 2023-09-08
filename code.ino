#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int pingPin = A1; // Trigger Pin of Ultrasonic Sensor
const int echoPin = A0; // Echo Pin of Ultrasonic Sensor
long duration;
int distance;
int ir=8;
int ir1=11;
int cf=12;
int cf1=13;
int mot=9;
int mot1=10;
int buz=A3;
void setup() {
  pinMode(cf,OUTPUT);
  pinMode(cf1,OUTPUT);
  pinMode(ir1,INPUT);
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");  
  mlx.begin(); 
  lcd.begin(16,2);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buz,OUTPUT);
  lcd.setCursor(4,0);
  lcd.print("WELCOME");
  lcd.setCursor(0,1);
  lcd.print("Sanitizer disp sys");
  delay(2000);
  lcd.clear();
  pinMode(mot,OUTPUT);
  pinMode(mot1,OUTPUT);
  pinMode(ir,INPUT);
}
void loop() {
    delay(200);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance=duration*0.034/2;
int t=(mlx.readObjectTempF());
int ob=digitalRead(ir);
int ob1=digitalRead(ir1);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("T:");
lcd.setCursor(2,0);
lcd.print(t);
lcd.setCursor(8,0);
lcd.print("O:");
lcd.setCursor(10,0);
lcd.print(ob);
lcd.setCursor(0,1);
lcd.print("L:");
lcd.setCursor(2,1);
lcd.print(distance);
lcd.setCursor(8,1);
lcd.print("D:");
lcd.setCursor(10,1);
lcd.print(ob1);
if(ob==0)
{
  digitalWrite(mot,1);
}
else
{
  digitalWrite(mot,0);
}
if((distance>15)||(t>100))
{
  digitalWrite(buz,1);
}
else
{
  digitalWrite(buz,0);
}
if(ob1==0)
{
  digitalWrite(cf,1);
  digitalWrite(cf1,0);
}
else
{
  digitalWrite(cf,0);
  digitalWrite(cf1,0);
}
}
