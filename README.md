# LED Matrix with Real-Time Data Display
A 5×16 LED Matrix project designed to display **real-time time, date, and temperature** using an Arduino Nano. The project uses multiplexing to control 80 LEDs with a limited number of microcontroller I/O pins and integrates an RTC and temperature sensor for dynamic data display.

## Project Overview

The system consists of a 5×16 LED matrix controlled using an **Arduino Nano**, with row and column control implemented using a **CD4017 decade counter** and **74HC595 shift register**.  The display shows time, date and temperature in real time and a push button is used to toggle between the different display modes.

## Key Features

* 5×16 LED matrix containing **80 LEDs**
* Multiplexed row/column scanning to reduce required I/O pins
* **74HC595 shift register** for column control
* **CD4017 decade counter** for row scanning
* **DS3231 RTC** for real-time date and time
* Thermistor-based temperature measurement
* Push-button controlled display-mode switching
* Scrolling text and character display
* Real-time embedded data visualization
* Arduino-based firmware for display control




