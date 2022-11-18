.PHONY: TCA9548A

TCA9548A:examples/selectChannel.cpp
	g++ -std=c++17 examples/selectChannel.cpp src/TCA9548A.cpp -li2c -o bin/TCA9548A.out