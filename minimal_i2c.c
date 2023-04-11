#include "minimal_i2c.h"

i2c_slave create_i2cslave(uint8_t clockpin, uint8_t datapin, volatile uint8_t* pPort)
{
	i2c_slave slave;
	slave.pPort = pPort;
	slave.clockpin = (1 << clockpin);
	slave.datapin = (1 << datapin);

	return slave;
}

void startcomm(i2c_slave* slave)
{
	*slave->pPort |= (slave->datapin); // Set Data High
	*slave->pPort |= (slave->clockpin); // Set Clock high
	*slave->pPort &= ~(slave->datapin); // Set Data low
}

void endcomm(i2c_slave* slave)
{
	*slave->pPort &= ~(slave->datapin); // Set Data Low
	*slave->pPort |= (slave->clockpin); // Set Clock high
	*slave->pPort |= (slave->datapin); // Set Data high
}

void sendByte(int8_t data, i2c_slave* slave)
{
	*slave->pPort &= ~(slave->clockpin); // Set Clock low
	for(int8_t i = 7; i >= 0; i--)
	{
		int8_t bit = data & (1 << i);

		*slave->pPort |= (slave->datapin); // Set Data high

		if(bit == 0)
		{
			*slave->pPort &= ~(slave->datapin); // Set Data low
			
		}
			*slave->pPort |= (slave->clockpin); // Set Clock high
			*slave->pPort &= ~(slave->clockpin); // Set Clock low
	}
	*slave->pPort |= (slave->clockpin); // Set Clock high
	*slave->pPort &= ~(slave->clockpin); // Set Clock low
}









