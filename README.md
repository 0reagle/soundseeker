# Sound-Seeking Autonomous Robot

## Project Overview

This project aims to develop an autonomous mobile robot capable of locating and moving towards the loudest sound source in its environment. The robot combines embedded systems, signal processing, sensor integration, and autonomous navigation.

The project is being developed incrementally, with each subsystem tested independently before integration into the complete robot.

---

## Current Prototype

![Current setup](images/current-setup.jpg)

The current prototype is being used to test the microphone and power system before the full drive system is added.

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

### Phase 2 – Microphone Characterisation and Sound Detection (In Progress)

Objectives:

* Connect and test the MAX9814 microphone amplifier.
* Read microphone output using the ESP32 ADC.
* Understand how the microphone signal changes in quiet and loud conditions.
* Create a simple sound-detection rule.

Current Status:

* ESP32 configured for microphone testing.
* MAX9814 connected to GPIO32 on the ESP32.
* Raw ADC readings confirmed to change with sound.
* Simple averaging was tested but did not clearly show sound strength.
* A min/max sampling method was implemented to measure signal variation.
* A first sound-detection threshold has been tested.

Method:

Instead of using the average ADC value, the program records the lowest and highest microphone readings over a short sampling window.

```text
sound level = highest reading - lowest reading
```

Measured Results:

| Test condition           | Approximate sound level |
| ------------------------ | ----------------------: |
| Quiet room               |                450–800  |
| Speaking near microphone |                1500+    |
| Clap                     |               2500+ |
| Tap near microphone      |               1800+ |

A temporary threshold of 1500 was selected for early testing.

Current behaviour:

```text
if sound level > 1500:
    sound detected
else:
    no sound
```

Completed:
* Soldered header pins to the MAX9814 microphone module.
* Connected the MAX9814 output to ESP32 GPIO32.
* Confirmed that raw ADC readings change with sound.
* Tested a min/max sampling method to estimate sound activity.
* Implemented a first threshold-based sound detection test.

Next Steps:
* Repeat microphone testing with the soldered header connection.
* Test different threshold values in different environments.
* Improve the sound-detection logic before moving to direction finding.

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
