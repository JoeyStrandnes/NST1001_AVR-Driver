
#ifndef NST1001_DRIVER_H
#define NST1001_DRIVER_H

#include <avr/io.h>
#include <util/delay.h>

// Selecting control/enable pin for sensor
#define NST_EN_DDR  DDRB
#define NST_EN_PORT PORTB
#define NST_EN_PIN  PB1

void Counter_Setup(uint8_t const Mode);
float Get_Temp(uint8_t const TEMP_UNIT);


#endif
