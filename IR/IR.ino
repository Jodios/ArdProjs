#include "IRremote.h"
#include "def.h"

#define RECIEVER 11
#define LIGHT 2

IRrecv irrecv(RECIEVER);
decode_results results;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean isON = false;
  if(irrecv.decode(&results)){
    const char* x = {translateIR(&results)};
    Serial.println(x);
    
    if(strcmp(x,"POWER") && !isON){
      isON = true;
      digitalWrite(LIGHT, HIGH);
    }else if(strcmp(x,"POWER") && isON){
      isON = false;
      digitalWrite(LIGHT, LOW);
    }

    Serial.println(isON);
    Serial.println(x);
    irrecv.resume();
  }
  
  delay(600);

}
