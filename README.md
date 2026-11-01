# Bang-Bang Control Line Follower Robot


A beginner-friendly robotics project by **Axyz Edu**, introducing students
to Arduino programming, infrared sensors, motor control, and autonomous
robot navigation through hands-on experimentation.

The robot uses two infrared (IR) sensor modules to detect a line and an
Arduino UNO to control two DC geared motors through an L298N motor driver.

This project uses a simple **Bang-Bang (ON/OFF) control algorithm** to
steer the robot along a predefined track.

---

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [How It Works](#how-it-works)
- [Components Required](#components-required)
- [Hardware Connections](#hardware-connections)
- [Power Supply and Safety](#power-supply-and-safety)
- [Repository Structure](#repository-structure)
- [Assembly Instructions](#assembly-instructions)
- [Arduino Setup](#arduino-setup)
- [Bang-Bang Control Explained](#bang-bang-control-explained)
- [Limitations](#limitations)
- [Real-World Applications](#real-world-applications)
- [Testing and Calibration](#testing-and-calibration)
- [Troubleshooting](#troubleshooting)
- [Future Improvements](#future-improvements)
- [Safety Precautions](#safety-precautions)
- [License](#license)

---

## Project Overview

A line follower robot is an autonomous mobile robot that follows a
visible line on a surface using optical sensors.

In this project, two IR sensor modules are mounted at the front of the
robot. They detect differences in reflected infrared light between the
track and the surrounding surface.

The Arduino UNO reads the sensor outputs and determines the movement
of the two motors.

By independently controlling the left and right motors, the robot can
move forward and make corrective turns to follow the track.

### Working Principle

1. The IR sensors detect the line and surrounding surface.
2. The Arduino reads the digital outputs of the two sensors.
3. The control algorithm determines the required direction.
4. The L298N motor driver controls the motors.
5. The robot moves forward or corrects its direction.
6. This process repeats continuously while the robot is operating.

### Project Images

Add your project photographs to the `images/` directory.

Example:

![Assembled Line Follower Robot](images/robot_assembled.jpg)

*Figure: Fully assembled Axyz Edu DIY Line Follower Robot.*

---

## Features

- Arduino UNO-based control system
- Two IR sensors for line detection
- Two BO geared DC motors
- L298N dual H-bridge motor driver
- Two-wheel-drive chassis
- Rechargeable 18650 battery power supply
- Simple Bang-Bang control algorithm
- Beginner-friendly electronics and programming
- Suitable for robotics demonstrations and educational projects

---

## Components Required

| No. | Component | Quantity | Purpose |
|---|---|---:|---|
| 1 | Arduino UNO | 1 | Reads sensors and controls the robot |
| 2 | L298N motor driver module | 1 | Controls motor direction and speed |
| 3 | BO geared DC motors | 2 | Drive the robot |
| 4 | IR sensor modules | 2 | Detect the line |
| 5 | 2WD robot chassis | 1 | Supports the components |
| 6 | Robot wheels | 2 | Provide traction |
| 7 | 18650 rechargeable batteries | 2 | Supply electrical power |
| 8 | 18650 2S battery holder | 1 | Holds the two batteries in series |
| 9 | ON/OFF switch | 1 | Turns the robot power on or off |
| 10 | Jumper wires | As required | Connect electronic components |
| 11 | Caster wheel | 1 | Supports the front or rear of the chassis |
| 12 | Nuts and bolts | As required | Secure the components |
| 13 | IR sensor mount | 1 | Holds the IR sensors in position |

**Note:** Component appearance, motor specifications, and sensor module
design may vary depending on the supplied hardware.

---

## Hardware Connections

### 1. Arduino UNO to IR Sensors

| Arduino UNO | IR Sensor | Function |
|---|---|---|
| D3 | Left sensor OUT | Reads the left sensor |
| D4 | Right sensor OUT | Reads the right sensor |
| 5V | Both sensor VCC pins | Supplies sensor power |
| GND | Both sensor GND pins | Common ground |

The sensor modules must support the selected supply voltage. The
connections above assume that the supplied modules are compatible
with 5V operation.

### 2. Arduino UNO to L298N Motor Driver

| Arduino UNO | L298N | Function |
|---|---|---|
| D5 | ENA | Controls left motor enable/speed |
| D6 | IN1 | Left motor direction control |
| D7 | IN2 | Left motor direction control |
| D8 | IN3 | Right motor direction control |
| D9 | IN4 | Right motor direction control |
| D10 | ENB | Controls right motor enable/speed |
| GND | GND | Common electrical ground |

**Important:** Remove the ENA and ENB jumpers on the L298N module if
you intend to control the motor enables using Arduino PWM signals on
D5 and D10.

The Arduino UNO supports PWM on both D5 and D10.

### 3. L298N to Motors

| L298N Output | Connection |
|---|---|
| OUT1 | Left BO motor terminal 1 |
| OUT2 | Left BO motor terminal 2 |
| OUT3 | Right BO motor terminal 1 |
| OUT4 | Right BO motor terminal 2 |

If a motor rotates in the opposite direction from the expected
direction, switch its two output wires or adjust the motor direction
logic in the Arduino code.

Motor orientation and wiring determine which direction is considered
forward.

### 4. Battery and Power Connections

| Connection | Destination |
|---|---|
| Battery holder positive | ON/OFF switch input |
| ON/OFF switch output | L298N motor supply input (Vs or +12V terminal) |
| Battery holder negative | L298N GND |
| L298N GND | Arduino GND |
| Arduino GND | IR sensor GND |

The battery voltage is supplied to the motor power input of the L298N.
The exact terminal label depends on the motor driver module.

**Do not connect the 2S battery pack directly to the Arduino UNO 5V pin
or to the IR sensor VCC pins.**

The Arduino and sensors must receive power appropriate to their
electrical specifications.

Power the Arduino through USB or a suitable regulated supply.
If powering it from the battery pack through a separate regulator,
ensure that the regulator's output voltage and current rating are
appropriate.

The L298N module's onboard 5V regulator and jumper arrangements vary.
Follow the instructions for the exact module you are using. Do not
connect the module's 5V terminal to the Arduino 5V rail without first
confirming that the power arrangement is compatible.

**Common ground is essential:** the Arduino, sensor modules, and motor
driver must share a common ground reference for the control signals
to work correctly.

### Circuit Diagram

Place your circuit diagram in the `circuit/` directory.

![Line Follower Robot Circuit Diagram](circuit/circuit_diagram.png)

*Figure: Electrical connections between the Arduino UNO, IR sensors,
L298N motor driver, BO motors, and power supply.*

---

## Power Supply and Safety

The robot uses two 18650 rechargeable lithium-ion cells in a 2S
configuration.

For conventional 3.6–3.7V nominal cells:

- Nominal pack voltage: approximately 7.2–7.4V
- Fully charged pack voltage: up to 8.4V
- Battery chemistry: lithium-ion
- Configuration: two cells connected in series

The actual voltage and permitted charging limits depend on the
specific cells used.

### Battery Precautions

- Use compatible, undamaged cells with appropriate specifications.
- Use a suitable charger designed for the 2S battery configuration.
- Use appropriate overcharge, over-discharge, and overcurrent protection.
- Do not mix incompatible cells or cells with substantially different
  charge levels or conditions.
- Never short-circuit, puncture, crush, or expose the cells to fire.
- Disconnect the battery before changing wiring.

A battery holder alone does not provide battery protection or charging
control.

---

