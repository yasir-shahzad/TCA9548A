
# TCA9548A

This repository contains code and documentation for the TCA9548A I2C Multiplexer. The TCA9548A allows for the expansion of I2C buses by enabling the connection of up to 8 separate I2C buses to a single microcontroller.


## Documentation
For more information on the TCA9548A multiplexer, see the documentation in the docs directory of this repository. This includes a datasheet and example code for using the multiplexer with Arduino.
[Datasheet](https://linktodocumentation)


## Authors

- [@Yasir Shahzad](https://www.github.com/Yasir-Shahzad)


## Support

For support, email yasirshahzad918@gmail.com or join our Slack channel.


## Usage/Examples
To use the TCA9548A multiplexer, you will need to include the TCA9548A.h file in your project and create an instance of the TCA9548A class. You can then use the selectChannel() function to switch between the different I2C devices connected to the multiplexer.


```javascript
#include "TCA9548A.h"

TCA9548A multiplexer;

void setup() {
  // Initialize the multiplexer
  multiplexer.begin();
}

void loop() {
  // Select channel 1
  multiplexer.selectChannel(1);

  // Perform I2C operations on devices connected to channel 1
}
```


## Contribution

If you have any suggestions or improvements for this repository, feel free to create a pull request or open an issue. Your contribution is greatly appreciated!

Please adhere to this project's `code of conduct`.

