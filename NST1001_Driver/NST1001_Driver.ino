
#include "NST1001_Driver.c"

float Temperature;



void setup() {

  Serial.begin(115200);

  Counter_Setup();

}

void loop() {

  Temperature = Get_Temp(2);
  Serial.println(Temperature);
  delay(50);
  
  

}
