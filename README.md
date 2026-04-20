# Desk-Pals

Desk-Pals is a capstone engineering project focused on building a small mobile desk robot that supports productivity, engagement, and human-centered interaction in workspaces.

The robot is designed to move on wheels and hold a phone on its front face, where animations, expressions, and interface elements can be displayed. 
Our long-term goal is to connect the robot body, embedded control system, and mobile app into one integrated experience.

## Project Overview

Desk-Pals is being developed as a multidisciplinary engineering prototype involving:

- Embedded systems and Arduino-based motor control
- Hardware/software integration
- Mechanical design and robot body prototyping
- App development for interaction and control
- User-centered design and validation testing

This repository houses the Arduino and hardware-integration code for the Desk-Pals robot, with development organized through an iterative design process.

## Current Focus

At this stage, the repository contains the full progression of logic used to develop the hardware-to-Bluetooth integration pipeline, with full integration with the mechanical subsystem. 
The code reflects an iterative design approach, moving from isolated motor testing toward integrated robot control:

1. Preliminary motor driver-to-motor (wheel) testing  
2. Configuring keyboard input to change the direction of one wheel (forward, backward)  
3. Testing keyboard input for two-wheel directional control (spinning left, right)  
4. Configuring Bluetooth input to change the direction of both wheels  
5. Configuring wheel speed appropriately so the robot body can rotate effectively as part of mechanical subsystem integration  

Together, these steps document the evolution of the robot’s motion-control system from basic electrical validation to integrated wireless control.

## Repository Structure

```text
Desk-Pals/
├── arduino_code/    # Arduino development files for motor control, wheel testing, and Bluetooth integration
└── README.md        # Project documentation
