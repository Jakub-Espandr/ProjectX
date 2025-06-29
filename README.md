<p align="center">
  <a href="https://ibb.co/vbX980J">
    <img src="https://i.ibb.co/hkY0v3K/projectx.webp" alt="projectx" width="300"/>
  </a>
</p>

<h1 align="center">ProjectX: Czech RoboRAVE Fire Fighting Robot</h1>
<p align="center"><em>Autonomous Fire Fighting Robot for Czech National RoboRAVE Competition</em></p>

## Overview
ProjectX is an Arduino Mega-based autonomous robot designed to compete in the Czech national round of RoboRAVE International Fire Fighting Challenge. The robot uses advanced sensor arrays and stepper motor control to navigate autonomously, detect candles using infrared sensors, and extinguish them using a propeller system without physical contact. Perfect for educational robotics competitions and autonomous navigation challenges.

---

# ProjectX: Czech RoboRAVE Fire Fighting Robot

This repository contains the code and documentation for our autonomous fire fighting robot designed to compete in the Czech national round of RoboRAVE International Fire Fighting Challenge.

## Robot Specifications

### Motors
- **2 Stepper Motors** for differential drive locomotion
  - Step resolution: 20 steps per movement (36 degrees rotation)
  - 90-degree turn: 600 steps

### Sensors

#### Line Following Sensors (12 total)
- **Front line sensors:** 2 sensors for basic line following
- **Left side line sensors:** 4 sensors (L1-L4)
- **Right side line sensors:** 4 sensors (R1-R4)

#### Candle Detection Sensors (12 total)
- **Left candle sensors:** 4 sensors (L1-L4)
- **Middle candle sensors:** 4 sensors (M1-M4)
- **Right candle sensors:** 4 sensors (R1-R4)

#### Other Sensors
- **Bumper sensor:** For collision detection
- **Ultrasonic sensor:** For obstacle detection
- **Start button:** For competition control

### Actuators
- **Servo motor:** Controls propeller for candle extinguishing
  - ON position: 104 degrees
  - OFF position: 176 degrees

### Control System
- **Microcontroller:** Arduino Mega
- **Communication:** Serial communication at 9600 baud
- **Power:** Autonomous operation with onboard power supply

## Robot Behavior

The robot operates autonomously with the following behaviors:
1. **Line following** using multiple line sensors
2. **Candle detection** using infrared sensors
3. **Obstacle avoidance** using ultrasonic and bumper sensors
4. **Candle extinguishing** using propeller system
5. **Random navigation** when no clear path is available

## Challenge Overview

This robot is designed for the Czech national round of RoboRAVE International Fire Fighting Challenge, where it must:
- Navigate autonomously within a defined arena
- Locate and extinguish candles without physical contact
- Avoid obstacles and walls
- Complete the task within time limits

## Files

### Main Project Files
- `projectX_final1.ino` - Arduino sketch for version 1
- `projectX_final1.cpp` - Implementation file for version 1
- `projectX_final1.h` - Header file for version 1
- `projectX_final2.ino` - Arduino sketch for version 2 (current)
- `projectX_final2.cpp` - Implementation file for version 2 (current)
- `projectX_final2.h` - Header file for version 2 (current)

### Project Directories
- `projectX_final1/` - Directory containing version 1 Arduino sketch
- `projectX_final2/` - Directory containing version 2 Arduino sketch

### Documentation
- `README.md` - This file - complete project documentation
- `roborave_readme.md` - Detailed competition rules and specifications

### Dependencies
- `libraries/` - External libraries directory
  - `Servo/` - Servo motor control library

### Configuration Files
- `.gitignore` - Git ignore rules
- `.DS_Store` - macOS system files (ignored by git)

---

## Competition Rules & Specifications

### Challenge Goal

The objective of this challenge is to design, build, and program an autonomous robot capable of locating and extinguishing four randomly placed candles within a field outlined by a white and black line. The robot must extinguish the candles without making physical contact with them.

### Divisions

This challenge typically includes teams from:
- Middle School
- High School  
- "Big Kids" divisions

### Robot Requirements & Constraints

Our robot adheres to the following requirements and design constraints for the Fire Fighting Challenge:

- **Autonomy**: The robot operates autonomously
- **Cost**: The total cost of the robot is $1,500 USD or less
- **Extinguishing System Control**: The robot's program can control the start and stop of its extinguishing system via a sensor that interacts with either the candle or the circle the candle is placed on
- **Safety Guard**: If a high-speed propeller is used, the robot has a safety guard in place
- **Sensors and Processors**: Multiple sensors and processors are allowed
- **Volume**: The robot's volume does not exceed 65,030 cm³

### General Rules of Play

- **Starting Position**: The robot begins each heat at a spot along the border chosen by the challenge coordinator
- **First Candle Visibility**: The first candle is in plain view of the robot at the start of the challenge
- **Time Limit**: The robot has 3 minutes to extinguish all four candles
- **Player Interaction**: Only players can operate and manipulate the robot during a heat. If a player touches the robot after the challenge begins, the run ends, and scoring is based on the number of candles extinguished at that point
- **Practice Tracks**: Official tracks are available for practice when not in use by competitors
- **Official Runs**: Teams get 10 official scored runs during the challenge scoring period
- **Tournament Selection**: The total of the 5 highest official scores are used to determine tournament selection

### Challenge Specifications

#### The Track

- **Field Dimensions**: The challenge field is 2.4m × 3.5m
- **Border**: A border is constructed using white and black duct tape. The white duct tape is 7.5cm wide with a 2.5cm black duct tape line down its center
- **Random Placement**: Candles and walls are randomly placed for every run
- **Lighting Conditions**: The challenge may be held in areas with natural light, so the robot is engineered to adapt to changing lighting conditions

#### The Candles

- **Placement**: Candles stand at the center of a white vinyl circle, indicated by a 5cm diameter black circle
- **Height**: Candle heights vary between 10cm and 45cm
- **Circle Dimensions**: The circle has a 40cm diameter, with a 2.5cm black line 2.5cm in from its outer edge

**Wall Obstructions**: Candles can be blocked by walls in varying configurations:
- 1 candle: No wall
- 1 candle: 1 wall
- 1 candle: 2 walls
- 1 candle: 3 walls

#### The Walls

- **Width**: Wall widths vary from 20cm to 35cm
- **Height**: Walls are 40cm tall
- **Bases**: Walls are held up by wooden bases that are 3.5cm tall and may span the approximate width of the wall

> **Note**: All challenge dimensions are approximate.

### Scoring

Scoring is based on the number of candles extinguished. A "remaining time bonus" is awarded only if all four candles are extinguished. Otherwise, only points for extinguished candles are awarded.

#### Penalty Rules

A 50% penalty off the candle's value is applied if:
- A candle is extinguished by the robot when it is completely outside the circle
- The candle is touched during the process of extinguishing the flame

The "process of extinguishing the lit candle" is defined as: entering into the circle, extinguishing, and leaving the circle. During this time, the robot cannot make contact with the candle.

Previously extinguished candles become obstacles and do not count as a penalty if touched.

#### Scoring Matrix

| Number of Candles Extinguished | First | Second | Third | Fourth | Total Possible Score |
|--------------------------------|-------|---------|-------|--------|---------------------|
| Half points due to penalty*    | 50    | 100     | 150   | 200    | 1000               |
| Full Points                    | 100   | 200     | 300   | 400    |                    |
| **Time Bonus**                 |       |         |       |        | **0-180** (Clock counts down from 180 seconds and stops when the robot extinguishes the fourth candle) |

### Tournament Scoring

The top eight teams will compete in a final tournament. Advancing teams are seeded into the tournament bracket based on their aggregate score. The "Runner Up" is used to determine 3rd place based on the outcome of the semi-finals.

---

## 🔐 License

This project is licensed under the **Non-Commercial Public License (NCPL v1.0)**  
© 2025 Jakub Ešpandr - Born4FLight, FlyCamCzech

See the [LICENSE](https://github.com/Jakub-Espandr/ProjectX/raw/main/LICENSE) file for full terms.