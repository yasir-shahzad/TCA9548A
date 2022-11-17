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
#define TCA_CHANNEL_0              (0x00)   ///< TCA channel0 selection
#define TCA_CHANNEL_1              (0x01)   ///< TCA channel1 selection
#define TCA_CHANNEL_2              (0x02)   ///< TCA channel2 selection
#define TCA_CHANNEL_3              (0x04)   ///< TCA channel3 selection
#define TCA_CHANNEL_4              (0x08)   ///< TCA channel4 selection
#define TCA_CHANNEL_5              (0x10)   ///< TCA channel5 selection
#define TCA_CHANNEL_6              (0x20)   ///< TCA channel6 selection
#define TCA_CHANNEL_7              (0x40)   ///< TCA channel7 selection
#define TCA_CHANNEL_8              (0x80)   ///< TCA channel8 selection

class TCA9548A {
  public:
    TCA9548A(uint8_t i2c_bus, uint8_t i2c_addr = 0x70);
    ~TCA9548A();
    int openChannel(uint8_t channel);
    int closeChannel(uint8_t channel);
    int closeAll();

  private:
    int fd;
    uint8_t address;
    uint8_t _channels;
};

#endif