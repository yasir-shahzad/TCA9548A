#include "TCA9548A.h"

void TCA9548A::openChannel(uint8_t channel)
{
    int buff = 0x00;    
    buff = 1 << channel;
    this->_channels |= buff;

    if (ioctl(fd, I2C_SLAVE, _address) < 0)
    {
        cout << " I2c  Connection not established" << endl;
    }

    if (write(fd, &_channels , sizeof(_channels)) < 0) //smbus library can also be used here
    {
        cout << "Write Error: " << errno << endl;
    }

}

void TCA9548A::closeChannel(uint8_t channel)
{
    int buff = 0x00;    
    buff = 1 << channel;
    this->_channels ^= buff;

    if (ioctl(fd, I2C_SLAVE, _address) < 0)
    {
        cout << " I2c  Connection not established" << endl;
    }

    if (write(fd, &_channels , sizeof(_channels)) < 0) //smbus library can also be used here
    {
        cout << "Write Error: " << errno << endl;
    }

}

void TCA9548A::closeAll()
{
    this->_channels = 0x00;
    if (ioctl(fd, I2C_SLAVE, _address) < 0)
    {
        cout << " I2c  Connection not established" << endl;
    }

    if (write(fd, &_channels , sizeof(_channels)) < 0) //smbus library can also be used here
    {
        cout << "Write Error: " << errno << endl;
    }
}