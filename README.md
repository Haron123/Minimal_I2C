# Minimal_I2C
Minimal I2C Libary for 8 Bit Microcontroller, Can be used for 16/32/64 Bit Microcontrollers aswell but you'd have to manually adjust the variable Sizes  
  
The reason i wrote this was to use a I2C Slave with my attiny13a but space was a huge issue, its written in bare C without really using any libaries other than  stdio.h

## Usage :

As this is written in C you will have to define the I2C_Slave as struct.

### Example :

i2c_slave myslave = create_i2cslave(clockpin, datapin, Port Adress);

for the atmega328p if you use PB4 as Datapin and PB3 as Clockpin
it would be something like

volatile int8_t* pPORTB = (int8_t *)0x25; // PORT B ADDRESS on the atmega328p  
i2c_slave myslave = create_i2cslave(3, 4, pPORTB); // create_i2cslave returns the created i2c_slave  

startcomm(&myslave); // Starts communication  
sendByte(0xFF, &myslave); // Sends 0xFF  
skipAck(&myslave); // Skips acknowledge bit  
endcomm(&myslave); // Ends communication  



## Features (or rather lack of) :

- Can only send raw Bytes without any extra  
- startcomm and endcomm to send start and stop Signal  
- skipAck cant check the Ack only skips it  
- zero error_handling  
