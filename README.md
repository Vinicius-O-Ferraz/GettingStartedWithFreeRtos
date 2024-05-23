## Getting Started With FreeRtos

<p align="center">
  <img src="https://github.com/Vinicius-O-Ferraz/GettingStartedWithFreeRtos/assets/146992032/fbc5af90-9207-4117-9e2c-38235a949472"  width="40%" height="auto" style="float: left;" />
  <img src="https://github.com/Vinicius-O-Ferraz/GettingStartedWithFreeRtos/assets/146992032/855af390-9e77-4f55-9a98-f52e65c50da3" width="30%" height="auto" alt="Dio_Logo" style="float: left;" />
</p>



### What is FreeRTOS
FreeRTOS is a popular open-source real-time operating system (RTOS) designed for microcontrollers and small microprocessors. Unlike a full-fledged operating system on your computer, FreeRTOS is much smaller and focuses on providing core functionality for embedded systems.

Here's a breakdown of what FreeRTOS offers:

* Real-time scheduling: This ensures predictable and timely responses to events. It's crucial for embedded systems that need to react quickly, like controlling motors or processing sensor data.
* Task management: FreeRTOS allows you to break down your program into smaller, independent tasks that can run concurrently. This improves efficiency and responsiveness.
* TCP/IP stack (optional): This enables communication over networks, making FreeRTOS suitable for Internet of Things (IoT) applications.

### Applications of FreeRTOS
FreeRTOS is a versatile RTOS used in various embedded systems due to its ease of use, reliability, and open-source nature. Here are some common applications:

* Internet of Things (IoT): FreeRTOS's small footprint and networking capabilities make it ideal for resource-limited IoT devices that collect and transmit data.
* Industrial automation: Predictable scheduling and real-time control are essential in industrial automation systems like robots or controllers. FreeRTOS excels in these applications.
* Consumer electronics: From wearables to smart home devices, FreeRTOS helps manage complex functionalities while conserving battery life.
* Medical devices: Some medical devices require precise timing and responsiveness, which FreeRTOS's real-time scheduling can provide.

### FreeRTOS applications on ESP32

This repository serves as a learning and development environment for studying the use of FreeRTOS with the ESP32 microcontroller. Here, we will delve into the functionalities of FreeRTOS and explore its implementation on the ESP32 platform.

The project will focus on creating examples and applications that demonstrate how FreeRTOS can be used to manage tasks, schedule events, and achieve real-time control on the ESP32.

Feel free to explore, contribute, and learn alongside us as we unlock the potential of FreeRTOS for embedded development on the ESP32!

### Getting Started

* 1- Install the freertos at https://www.freertos.org/
* 2- Install Vscode at https://code.visualstudio.com/
* 3- Install the plaformIo extension on Vscode and configure it accordingly to your board
* 4- clone this repository using `git clone https://github.com/Vinicius-O-Ferraz/GettingStartedWithFreeRtos.git`
* 5- and run the main class using platformIO

### Blimp

The code will example two tasks that will toggle the LED on the Arduino board at different frequencies. One LED will blink on and off every 500 milliseconds, while the other will blink on and off every 323 milliseconds. This demonstrates how FreeRTOS allows for multiple tasks to run concurrently, creating a more complex behavior compared to a simple loop in a traditional Arduino program.

https://github.com/Vinicius-O-Ferraz/GettingStartedWithFreeRtos/assets/146992032/e67f94f5-a686-4922-8d28-bd8b558a6b70
