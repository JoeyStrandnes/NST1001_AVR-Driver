# NST1001 Driver

##### This is a simple AVR driver for the NST1001 temperature sensor. (Work In Progress)

##### This driver utilizes Timer-Counter 1 (TCCR1) to measure the temperature from the sensor.

### Supported units

- Celsius (default)
- Kelvin
- Fahrenheit 

### Supported modes of operation

- Pullup mode
- Pulldown mode
- Multicast mode (Not yet)

### Pullup mode

![Pullup](https://i.imgur.com/5tKvrPX.png)

### Pulldown mode

![Pulldown](https://i.imgur.com/vMNZmDU.png)

### Known issues

##### Taking rapid measurements or drifting clock. The spikes below are caused by looping the measurement with zero delay, a minimum delay of 1ms between measurements is required to ensure stability in the system. Instability can also be caused if the system clock significantly drifts.

![Timing Error](https://i.imgur.com/08EtMkI.png)