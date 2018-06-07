#define TEMP 13
#define HEATER 10
#define FAN 44

int x;
#define a -3.90376265282406e-07
#define b 0.000694757028155916
#define c -0.526943156403734
#define d 244.916353218021
#include<LiquidCrystal.h>
LiquidCrystal lcd(16, 17, 23, 25, 27, 29);
double e, u;
double temp;
double i;

void setup() {
  Serial.begin(9600);

  lcd.begin(20, 4);
  lcd.setCursor(1, 0);


  pinMode(FAN, OUTPUT);
  digitalWrite(FAN, HIGH);

  pinMode(HEATER, OUTPUT);
  digitalWrite(HEATER, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  x = analogRead(TEMP);

  temp = a * (double)pow(x, 3) + (double)b * pow(x, 2) + (double)c * x + d;
  Serial.println(x);
  Serial.println(temp);
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);

  lcd.setCursor(0, 1);
  lcd.print("e: ");
  lcd.print(e);

  lcd.setCursor(0, 2);
  lcd.print("u: ");
  lcd.print(u);

  lcd.setCursor(0, 3);
  lcd.print("i: ");
  lcd.print(i);

  delay(500);

  ////////////////////// 28.05 ///////////////////////

  // regulator PI
  e = 180 - temp;
  i = i + e * 0.1;               // po 1 sek == 1000 dlatego mnozymy razy 0.01
  u = 255/150 * e  + 0.5* i;     // w pomieszczeniu 30 stopni dlatego 180 - 30 = 150
  if (temp < 180)
  {
    analogWrite(HEATER, u > 255 ? 255 : floor(u));
  }
  else
  {
    digitalWrite(HEATER, LOW);
  }
  delay(10);




}
