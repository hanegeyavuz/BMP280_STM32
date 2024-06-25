# BMP280_STM32
This project demonstrates how to read data from a BMP280 Pressure and Temperature sensor using the STM32F407VG Discovery development board. The sensor readings are then transmitted to another device via UART communication.


## Table of Contents
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Setup and Configuration](#setup-and-configuration)
- [How to Use](#how-to-use)
- [Contributing](#Contributing)
- [License](#license)
- [Authors](#Authors)

## Features
- Reads pressure concentration using the BMP280 sensor.
- Transmits sensor data over UART.

## Hardware Requirements
- STM32 microcontroller (e.g., STM32F4 series)
- BMP280 pressure sensor
- UART interface for data transmission
- RTC module (if not integrated in the MCU)
- LED and resistor for status indication

## Software Requirements
- STM32CubeIDE or any suitable IDE for STM32 development
- STM32CubeMX for generating initialization code
- HAL (Hardware Abstraction Layer) library

## Setup and Configuration
1. **Hardware Setup:**
   - Connect the BMP280 sensor to the I2C pins of the STM32.
   - Connect the UART TX and RX pins to a serial communication module.

2. **Software Configuration:**
   - Use STM32CubeMX to configure the peripherals: ADC, UART, GPIO, and RTC.
   - Generate the initialization code and import it into your STM32CubeIDE project.


## How-To-Use
- **Build the Project**
    - Open the project in STM32CubeIDE, build, and upload it to your STM32 microcontroller.
- **Monitor Output**
    - Use a serial terminal (e.g., PuTTY) to monitor the UART output. The sensor data will be transmitted periodically.

## Contributing
- Contributions are welcome! If you have any suggestions or find any bugs, please open an Issue or submit a Pull Request.
## License
This project is licensed under the GPL License - see the `LICENSE` file for details.
## Authors
- Muhammed Yavuz Hanege

