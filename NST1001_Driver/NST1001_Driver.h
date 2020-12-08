
#ifndef NST1001_DRIVER_H
#define NST1001_DRIVER_H

#include <avr/io.h>
#include <util/delay.h>

// Selecting control/enable pin for sensor
#define EN_DDR  DDRB
#define EN_PORT PORTB
#define EN_PIN  PB0

void Counter_Setup();
float Get_Temp(uint8_t TEMP_UNIT);

#endif
