#ifndef MINIMAL_I2C_H
#define MINIMAL_I2C_H

#include <avr/io.h>

// Struct for i2c slaves
typedef struct
{
	uint8_t clockpin;
	uint8_t datapin;
	volatile int8_t* pPort;
} i2c_slave;

/**
  * @brief creates an i2c slave
  * @param clockpin, Pin at which the clockpin of the slave is connected
  * @param datapin, Pin at which the datapin of the slave is connected
  * @param pPort, Pointer to the Address of the Port the above pins are located
  * @retval the created i2c slave
*/
i2c_slave create_i2cslave(uint8_t clockpin, uint8_t datapin, volatile uint8_t* pPort);

/**
  * @brief starts the i2c communication
  * @param slave, pointer for i2c slave
*/
void startcomm(i2c_slave* slave);

/**
  * @brief stops the i2c communication
  * @param slave, pointer for i2c slave
*/
void endcomm(i2c_slave* slave);

/**
  * @brief sends a byte
  * @param data, the byte to send
  * @param slave, pointer for i2c slave
*/
void sendByte(int8_t data, i2c_slave* slave);


#endif
