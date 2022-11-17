#ifndef _TCA9548A_H_
#define _TCA9548A_H_

#include <fcntl.h>
#include <iostream>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std;

/* Channel hex values for writeRegister() function */
#define TCA_CHANNEL_0              (0x00)
#define TCA_CHANNEL_1              (0x01)
#define TCA_CHANNEL_2              (0x02)
#define TCA_CHANNEL_3              (0x04)
#define TCA_CHANNEL_4              (0x08)
#define TCA_CHANNEL_5              (0x10)
#define TCA_CHANNEL_6              (0x20)
#define TCA_CHANNEL_7              (0x40)
#define TCA_CHANNEL_8              (0x80)

class TCA9548A {
  public:
    TCA9548A(uint8_t i2c_bus, uint8_t i2c_addr = 0x70);
    ~TCA9548A();
    void openChannel(uint8_t channel);
    void closeChannel(uint8_t channel);
    void closeAll();

  private:
    int fd;
    uint8_t address;
    uint8_t _channels;
};

#endif