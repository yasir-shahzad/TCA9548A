#ifndef _TCA9548A_H_
#define _TCA9548A_H_

#include <iostream>
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
using namespace std;

/* Channel hex values for writeRegister() function */
#define TCA_CHANNEL_0 0x0
#define TCA_CHANNEL_1 0x1
#define TCA_CHANNEL_2 0x2
#define TCA_CHANNEL_3 0x4
#define TCA_CHANNEL_4 0x8
#define TCA_CHANNEL_5 0x10
#define TCA_CHANNEL_6 0x20
#define TCA_CHANNEL_7 0x40
#define TCA_CHANNEL_8 0x80

class TCA9548A
{
    public:

        TCA9548A(uint8_t address = 0x70, string i2cChannel = "/dev/i2c-1")  // Default IC Address
        {
            _address = address;
            _i2cChannel = i2cChannel;
            fd =  open(_i2cChannel.c_str(), O_WRONLY);
            cout << "File number: " << fd << endl;
            cout << "Address: " << _address << endl;
            cout << "i2c Channel: " << _i2cChannel << endl;
        }
        void openChannel(uint8_t channel);
        void closeChannel(uint8_t channel);
        void closeAll();

        ~TCA9548A(){
            close(fd);
        }
        
    private:
        uint8_t _address;
        int fd;
        string _i2cChannel;
        uint8_t _channels;

};

#endif