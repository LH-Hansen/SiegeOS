# SiegeOS
SiegeOS is a next-generation, Bluetooth-enabled catapult system designed for precision, power, and remote control. Developed by [Kinetic Command], the system combines classic engineering with modern tech—allowing users to launch projectiles via smartphone with pinpoint accuracy. With custom-built firmware and a sleek mobile interface, SiegeOS redefines siege warfare for the digital age.

## Table of Contents

### Getting Started
- [Introduction](#-introduction)
- [Features](#-features)
- [Future Plans](#-future-plans)
- [System Requirements](#%EF%B8%8F-system-requirements)
- [Installation](#-installation)
- [Usage](#-usage)
- [Screenshots](#-screenshots)
- [FAQs](#-faqs)

### Technical Details
- [Diagrams](#-diagrams)
- [Framework](#%EF%B8%8F-framework)
- [Dependencies](#-dependencies)
- [API Documentation](#-api-documentation)
- [Versioning & Changelog](#-versioning-and-changelog)
- [TODO](#-todo-list)
- [Known Issues](#-known-issues)
- [Contributing](#-contributing)
- [Acknowledgments](#-acknowledgments)
- [License](#-license)
- [Contact](#-contact)

<br>

# Getting Started

<br>

## 📘 Introduction

This project is a microcontroller-based catapult system powered by an Arduino UNO R4. It allows users to adjust the horizontal angle of the catapult using a potentiometer or smartphone and control various motorized components like a stepper motor and DC motor to prepare and fire projectiles. A mobile app communicates with the Arduino via Bluetooth using Serial Port Protocol (SPP) for remote control and monitoring.

<br>

## 🌟 Features

- **Analog User Input**: Potentiometer-based angle adjustment for intuitive user control.
- **Stepper Motor Control**: Precision horizontal rotation based on angle feedback.
- **Feedback Mechanism**: Second potentiometer reads the actual catapult angle for real-time display and motion syncing.
- **LCD Output**: Displays current rotational angle for user feedback.
- **Bluetooth SPP Communication**: Mobile app interface to control and trigger various mechanisms.
- **DC Motor Wind-up System**: Prepares the firing mechanism.
- **Firing System**: Launches projectile using a pneumatic actuator.

<br>

## 🚀 Future Plans

- **Trajectory Calculation**: Predict and visualize shot arcs based on angle and tension.
- **Mobile App Enhancements**: Expand mobile interface with more feedback and control options.

<br>

## 🖥️ System requirements

| **Category**          | **Requirements**                                                              |
|-----------------------|-------------------------------------------------------------------------------|
| **Operating System**   | - Windows 10 or later <br> - macOS 10.15 or later <br> - Linux (Ubuntu 18.04+) |
| **Processor**          | Any 2 GHz dual-core or higher                                                 |
| **Memory**             | 2 GB RAM (4 GB recommended)                                                   |
| **Storage**            | 100 MB for Arduino IDE and libraries                                          |
| **Software**           | - Arduino IDE v2.x <br> - Serial Bluetooth Terminal App (Android/iOS)         |
| **Additional Tools**   | - USB cable for Arduino <br> - Soldering tools (for hardware setup)           |

<br>

## 📦 Installation

### Arduino IDE

1. Download and install [Arduino IDE](https://www.arduino.cc/en/software)
2. Clone this repository:

```bash
git clone https://github.com/yourusername/catapult-controller.git
cd catapult-controller
```

3. Open the `.ino` file in Arduino IDE.
4. Select the correct board: **Arduino UNO R4**
5. Upload the code to your board.

<br>

## 📖 Usage

### Running the System

1. Power on the Arduino UNO R4 and ensure motors are connected.
2. Adjust the first potentiometer to select the horizontal firing angle.
3. The stepper motor will rotate the catapult to match the selected angle.
4. View the live angle feedback on the LCD.
5. Open the mobile app and connect to the Arduino via Bluetooth SPP.
6. Use app buttons to:
   - Change horizontal firing angle
   - Wind the DC motor (pull back firing arm)
   - Trigger the pneumatic actuator (fire)


### Example command flow:

1. Open Bluetooth app and connect to device.
2. Adjust angle
3. Tap `Wind` to activate DC motor.
4. Tap `Fire` to trigger the pneumatic cylinder.
5. Repeat as needed.

<br>

## 📸 Screenshots

Here are some concept visuals (replace with real ones when available):

### Hardware Setup

![Hardware](path/to/hardware-setup.png)

### Bluetooth App Interface

![App](path/to/bluetooth-app.png)

### LCD Display

![LCD](path/to/lcd-display.png)

<br>

## ❓ FAQs

### 1. What is this project about?
A precision-controlled Arduino catapult system operated via analog input and Bluetooth app.

### 2. How do I install the project?
Follow the steps in the [Installation](#-installation) section.

### 3. How can I contribute to this project?
See the [Contributing](#-contributing) section.

### 4. What are the system requirements?
Refer to the [System Requirements](#%EF%B8%8F-system-requirements) section above.

### 5. How do I report bugs or issues?
Bug reporting as not supported as of yet.

### 6. Where can I find more information?
Refer to this README or upcoming [Wiki](#).

<br>

# Technical Details

<br>

## 📊 Diagrams

### 1. System Architecture

![System Architecture](path/to/system-architecture.png)

*Shows how the Arduino communicates with input/output peripherals and Bluetooth app.*

### 2. Workflow Diagram

![Workflow](path/to/workflow-diagram.png)

*Demonstrates user input, mechanical response, and mobile communication cycle.*

<br>

## 🛠️ Framework

This project is built on the **Arduino Framework** using **C++**.

| Project Component | Language/Platform | Folder |
|-------------------|-------------------|--------|
| Firmware          | Arduino C++       | /src   |
| Mobile App        | N/A (external)    | N/A    |

<br>

## 📚 Dependencies

| Library             | Description                                 |
|---------------------|---------------------------------------------|
| `Stepper.h`         | For stepper motor control                   |
| `LiquidCrystal.h`   | For LCD display interface                   |
| `SoftwareSerial.h`  | For SPP Bluetooth communication (if used)   |

Install via Arduino Library Manager.

<br>

## 📡 API Documentation

This project does not include REST APIs. However, Bluetooth commands follow this protocol:

| Command | Description                 |
|---------|-----------------------------|
| `W`     | Wind-up using DC motor      |
| `F`     | Fire the pneumatic actuator |
| `S`     | Stop all motors             |

*Sent from a mobile app via SPP Bluetooth.*

<br>

## 📋 Versioning and Changelog

### Current Version

Current version: `1.0.0`

### Changelog

#### [1.0.0] - 2025-06-15
- Initial release with potentiometer input
- Stepper motor angle sync
- LCD angle feedback

<br>

## 🐞 Known Issues

- **LCD flicker**: Under power fluctuation.
  - **Status**: Under investigation.

<br>

## ✅ TODO List

### [HIGH] Critical Tasks
- [ ] Implement bluetooth
- [ ] Cretae mobile app
- [ ] Add LED feedback

### [MEDIUM] Important Features
- [ ] Improve Bluetooth data validation.
- [ ] Implement buzzer warning before firing

### [LOW] Enhancements
- [x] Refactor code into modules.

<br>

## 🤝 Contributing

Thank you for your interest! Contributions are not open at this time, but feel free to fork and experiment.

<br>

## 🔗 Acknowledgments

- **Arduino**: Open-source hardware and IDE platform.
- **Stepper Library**: For motor control ease.
- **Inspiration**: DIY weaponry and robotics hobbyists online.

<br>

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

<br>

## 📫 Contact

Inquiries - N/A at this time.

Project Link: [Catapult Controller](https://github.com/yourusername/catapult-controller)
