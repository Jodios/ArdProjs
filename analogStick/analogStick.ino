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
  Serial.begin(9600);

}

void loop() {

  x = analogRead(x_pin);
  y = analogRead(y_pin);

  xdif = x - xprev;
  ydif = y - yprev;


  x = map(x, 0, 1023, -512, 512);
  y = map(y, 0, 1023, -512, 512);
  double ax = static_cast<double>(x / 512);
  double ay = static_cast<double>(y / 512);

  if (x != 0.0 && y != 0.0)
  {
    angle = atan2(y, x);
  }
  Serial.print("Radians: "); Serial.println(angle * CONVERSION);
  Serial.print("Angle: "); Serial.println(angle);
  Serial.print("X: "); Serial.println(x);
  Serial.print("Y: "); Serial.println(y);
  Serial.print("AX: "); Serial.println(ax);
  Serial.print("AY: "); Serial.println(ay);
  Serial.println("==============================");




  xprev = x;
  yprev = y;


  delay(500);
}
