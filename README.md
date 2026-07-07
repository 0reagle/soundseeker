# Sound-Seeking Autonomous Robot

## Project Overview

This project aims to develop an autonomous mobile robot capable of locating and moving towards the loudest sound source in its environment. The robot combines embedded systems, signal processing, sensor integration, and autonomous navigation.

The project is being developed incrementally, with each subsystem tested independently before integration into the complete robot.

---

## Objectives

* Detect and analyse sound using microphones.
* Determine the direction of a sound source.
* Rotate towards the loudest sound.
* Navigate towards the sound source.
* Avoid obstacles while moving.
* Integrate multiple sensors into a single autonomous system.

---

## Hardware

### Processing

* LPC1768 Development Board
* ESP32 ESP-32S

### Sensors

* MAX9814 Microphone Amplifier
* HC-SR04 Ultrasonic Sensor
* BNO055 IMU (planned)

### Actuation

* ST3215 Bus Servo
* 2 × TT DC Gear Motors

### Power

* 7.4V Li-Ion Battery
* DC-DC Buck Converter

---

## Development Progress

### Phase 1 – Power System ✅

Objectives:

* Power the control electronics from a battery.
* Design a safe power distribution system.

Completed:

* Connected 7.4V battery to buck converter.
* Verified output voltage of 5.116V.
* Successfully powered LPC1768 from regulated supply.
* Implemented Y-split power distribution approach for future subsystem expansion.

Lessons Learned:

* Importance of power distribution planning.
* Connector selection and wire gauge considerations.
* Safe soldering and insulation practices.

---

### Phase 2 – Microphone Characterisation (In Progress)

Objectives:

* Connect and test the MAX9814 microphone.
* Understand sensor output behaviour.
* Establish baseline sound measurements.

Current Status:

* ESP32 configured for microphone testing.
* CP2102 USB driver installed and configured.
* Initial ADC measurements collected.

Observations:

* Covered microphone: approximately hundreds of ADC counts.
* Uncovered microphone: approximately 3000–3500 ADC counts.

Next Steps:
* Solder Header to MAX9814
* Characterise ambient noise levels.
* Investigate response to speech and impulse sounds.
* Develop sound detection algorithms.

---

## Planned Development

### Phase 3 – Sound Processing

* Noise filtering.
* Threshold detection.
* Sound intensity estimation.

### Phase 4 – Direction Finding

* Multi-microphone comparison.
* Direction estimation.

### Phase 5 – Servo Tracking

* Directional scanning.
* Sound source localisation.

### Phase 6 – Obstacle Avoidance

* Ultrasonic sensing.
* Navigation logic.

### Phase 7 – Drive System

* Motor controller integration.
* Autonomous movement.

### Phase 8 – Full System Integration

* Autonomous sound-seeking behaviour.

---

## Current Status

The power system has been completed and microphone testing is currently underway. The next milestone is to characterise the microphone response and develop reliable sound detection methods before introducing directional tracking and autonomous movement.
