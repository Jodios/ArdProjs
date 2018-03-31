#include <math.h>
#include "colourweel.h"
int r = 0;
int g = 0;
int b = 0;
void setup() {
  pinMode(sw_pin, INPUT);
  digitalWrite(sw_pin, HIGH);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
//  Serial.begin(9600);

}


void loop() {

  x = analogRead(x_pin);
  y = analogRead(y_pin);

  xdif = x - xprev;
  ydif = y - yprev;


  x = map(x, 0, 1023, -512, 512);
  y = map(y, 0, 1023, -512, 512);
  angle = atan2(y, x);
  angle = angle * CONVERSION; 
  angle = map(angle, -180, 180, 0, 360);

  r = abs(256 * cos(angle));
  g = abs(256 * cos(angle + 120));
  b = abs(256 * cos(angle - 120));
  
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
//  Serial.println(rgb[0]);
//  Serial.println(rgb[1]);
//  Serial.println(rgb[2]);

 
  
//  Serial.print("Radians: "); Serial.println(angle);
//  Serial.print("Angle: "); Serial.println(angle);
//  Serial.print("X: "); Serial.println(x);
//  Serial.print("Y: "); Serial.println(y);
//  Serial.println("==============================");




  xprev = x;
  yprev = y;


  delay(500);
}
