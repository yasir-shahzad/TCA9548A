#include "TCA9548A.h"

/**
 * @brief this method opens i2c port
 * @param i2c_bus  i2c bus number on physical board
 * @param i2c_addr salve address
 * @return 1 on success, -1s on failure
 */
TCA9548A::TCA9548A(uint8_t i2c_bus, uint8_t i2c_addr) {
    char device[32];
    address = i2c_addr;
    snprintf(device, sizeof(device), "/dev/i2c-%u", i2c_bus); // creating device address buffer
    if ((fd = open(device, O_RDWR)) < 0) {
        printf("File descriptor opening error %s\n", strerror(errno));
    }
    else {
        if (ioctl(fd, I2C_SLAVE, address) < 0)
        {
            std::cout << "Open fd error" << errno << std::endl;
        }
        printf("I2C connection established\n");
    }
}

int TCA9548A::openChannel(uint8_t channel) {
    int buff = 0x00;
    buff = 1 << channel;
    this->_channels |= buff;

    if (ioctl(fd, I2C_SLAVE, address) < 0) {
        cout << " I2c  Connection not established" << endl;
        return -1;
    }
    if (write(fd, &_channels, sizeof(_channels)) < 0) {
        cout << "Write Error: " << errno << endl;
        return -1;
    }
    return 1;
}

int TCA9548A::closeChannel(uint8_t channel) {
    int buff = 0x00;
    buff = 1 << channel;
    this->_channels ^= buff;

    if (ioctl(fd, I2C_SLAVE, address) < 0) {
        cout << " I2c  Connection not established" << endl;
        return -1;
    }
    if (write(fd, &_channels, sizeof(_channels)) < 0) {
        cout << "Write Error: " << errno << endl;
        return -1;
    }
    return 1;
}

int TCA9548A::closeAll() {
    this->_channels = 0x00;
    if (ioctl(fd, I2C_SLAVE, address) < 0) {
        cout << " I2c  Connection not established" << endl;
        return -1;
    }
    if (write(fd, &_channels, sizeof(_channels)) < 0) {
        cout << "Write Error: " << errno << endl;
        return -1;
    }
    return 1;
}

TCA9548A::~TCA9548A() {
close(fd);
}