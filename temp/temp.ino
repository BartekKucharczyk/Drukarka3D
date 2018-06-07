#define TEMP 13
int x;
#define a -3.90376265282406e-07
#define b 0.000694757028155916
#define c -0.526943156403734
#define d 244.916353218021
#include<LiquidCrystal.h>
LiquidCrystal lcd(16,17,23,25,27,29);
void setup() {
Serial.begin(9600);

lcd.begin(20,4);
lcd.print("Hello!");
lcd.setCursor(1,0);
}

void loop() {
  // put your main code here, to run repeatedly:

x = analogRead(TEMP);

double y = a * (double)pow(x,3) + (double)b * pow(x,2) + (double)c * x + d;
Serial.println(x);
Serial.println(y);
lcd.setCursor(1,1);
lcd.print("Temp: ");
lcd.print(y);
delay(500);
}
