
#include "NST1001_Driver.c"

float Temperature;



void setup() {

  Serial.begin(115200);

  Counter_Setup(1);

}

void loop() {

  Temperature = Get_Temp(0);
  Serial.println(Temperature);
  _delay_ms(10);
  //delay(50);
  
  

}
