#include "minimal_i2c.h"

i2c_slave create_i2cslave(int8_t clockpin, int8_t datapin, volatile int8_t* pPort)
{
	i2c_slave slave;
	slave.pPort = pPort;
	slave.clockpin = clockpin;
	slave.datapin = datapin;

	return slave;
}

void startcomm(i2c_slave* slave)
{
	*slave->pPort |= (1 << slave->datapin); // Set Data High
	*slave->pPort |= (1 << slave->clockpin); // Set Clock high
	*slave->pPort &= ~(1 << slave->datapin); // Set Data low
	*slave->pPort &= ~(1 << slave->clockpin); // Set Clock low
}

void endcomm(i2c_slave* slave)
{
	*slave->pPort &= ~(1 << slave->datapin); // Set Data Low
	*slave->pPort |= (1 << slave->clockpin); // Set Clock high
	*slave->pPort |= (1 << slave->datapin); // Set Data high
	*slave->pPort &= ~(1 << slave->clockpin); // Set Clock low
}

void sendByte(int8_t data, i2c_slave* slave)
{
	for(int8_t i = 7; i >= 0; i--)
	{
		int8_t bit = data & (1 << i);
		if(bit == 0)
		{
			*slave->pPort &= ~(1 << slave->datapin); // Set Data low
			*slave->pPort |= (1 << slave->clockpin); // Set Clock high
	*		slave->pPort &= ~(1 << slave->clockpin); // Set Clock low
		}
		else
		{
			*slave->pPort |= (1 << slave->datapin); // Set Data high
			*slave->pPort |= (1 << slave->clockpin); // Set Clock high
			*slave->pPort &= ~(1 << slave->clockpin); // Set Clock low
		}
	}
}

void skipAck(i2c_slave* slave)
{
	*slave->pPort |= (1 << slave->clockpin); // Set Clock high
	*slave->pPort &= ~(1 << slave->clockpin); // Set Clock low
}









