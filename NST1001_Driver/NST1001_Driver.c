/*ToDo: 
 * Add Fahrenheit and Kelvin
 * Add Pulldown mode and "Multicast" mode
 */
#include "NST1001_Driver.h"

/*  Setup counter 1/ 16-bit timer
 *  Maximum number of pulses = 3201 => ~150 degrees celcius
 */
void Counter_Setup(){
  
  cli();

  EN_DDR = (1<<EN_PIN); // Enable pin
  
//Timer 1 Normal mode with falling edge as clock source and noise suppression
  TCCR1A = (0<<COM1A1)|(0<<COM1A0)|(0<<COM1B1)|(0<<COM1B0)|(0<<WGM11)|(0<<WGM10);
  TCCR1B = (1<<ICNC1)|(0<<ICES1)|(0<<WGM13)|(0<<WGM12)|(1<<CS12)|(1<<CS11)|(0<<CS10); 
  TIMSK1 = (0<<ICIE1)|(0<<OCIE1B)|(0<<OCIE1A)|(0<<TOIE1);
  TCNT1 = 0;

  sei();
}

// Conversion period = 24 ms typ
// Communication period = 26ms typ
float Get_Temp(uint8_t TEMP_UNIT){

  float Temp = 0;
  uint8_t Unit = TEMP_UNIT;
  
  EN_PORT = (1 << EN_PIN);         // Enable pin
  
  TCNT1 = 0;
  
  _delay_ms(50);                    // Conversion delay
  EN_PORT = (0 << EN_PIN);         // Turning the sensor off
  
  Temp = ((TCNT1*0.0625) - 50.0625);

//Temp compensation, no compensation is needed in the interval 30 ≤ T ≤ 100 
  if(Temp < 30){
    Temp += ((Temp-30)*0.005);      // Compensatio for T < 30
  }
  else if (100 < Temp && Temp < 150){
    Temp += ((100-Temp)*0.012);     // Compensatio for 100 < T < 150
  }
  else if(Temp < -50 || Temp > 150){     // Sanity check
    Temp = 32500;
  }

//Changing uint, defaults to Celsius: 1 = Fahrenheit, 2 = Kelvin
  if(TEMP_UNIT == 1){
    Temp = ((Temp*1.8)+32);
  }
  else if(TEMP_UNIT == 2){
    Temp += 273.15;
  }
/*
  switch(Unit){
    case 1: // Fahrenheit
      Temp = ((Temp*1.8)+32);
      break;
    case 2: // Kelvin
      Temp += 273.15;
      break;
      
    //default:
  }
*/  
  
  return Temp;
}
