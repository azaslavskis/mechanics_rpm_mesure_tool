# Mechanics RPM Measurement Tool

This simple device, built using an Arduino Nano and an A3144 Hall sensor, allows you to measure the RPM (Revolutions Per Minute) of a gear. The device is straightforward to construct and program, making it an excellent project for hobbyists and engineers alike.

---

## Schematic

The circuit is simple and consists of just two resistors, an A3144 Hall sensor, and an LED. Below is the basic schematic:

![Schematic](https://user-images.githubusercontent.com/20460747/205875397-4060d0ce-d347-449f-8a3f-94528122093f.png)

---

## Bill of Materials (BOM)

Here’s what you’ll need to build the device:

1. **1x Arduino Nano** – The microcontroller that processes the sensor readings.
2. **2x 1 kΩ Resistors** – For pull-up configuration and current limiting.
3. **1x A3144 Hall Sensor** – To detect magnetic pulses from the rotating gear.
4. **1x Breadboard** – For quick prototyping.
5. **Wires and Glue** – To secure connections during experiments.

---

## Software

The project consists of two main software components:

1. **Arduino Firmware**:
   - This code is uploaded to the Arduino Nano using the Arduino IDE.
   - It reads data from the Hall sensor and calculates the RPM or time between pulses.
   - Configuration options are available via `#define` directives in the firmware for customization.

2. **CLI Data Plotting Tool** (written in Rust):
   - This command-line tool plots the RPM data as a graph.
   - It also saves the data to a `data.txt` file for further analysis or post-processing.

---

## Demo

Here’s a demonstration of the device in action:

### Graph Plot
The CLI tool generates a live graph showing the RPM data in real time.

![Demo Graph](https://user-images.githubusercontent.com/20460747/205876439-df42d0a4-aea0-484f-ba7e-c943ae642ee8.png)

### Device Appearance
The device assembly is minimal and effective. To ensure stable connections during experiments, glue was used to secure the wires.

![Device Front](https://user-images.githubusercontent.com/20460747/205881930-d5dd1d3b-f1c6-4ead-b658-4e7744373b87.png)
![Device Back](https://user-images.githubusercontent.com/20460747/205882200-4570e1fa-9939-4851-8068-ae269bbb37a9.png)

### Video Demonstration
Watch the device in action:

[![Video Demonstration](https://img.youtube.com/vi/81ce0058-ae66-4d7c-8080-60a095a5715f/0.jpg)](https://user-images.githubusercontent.com/20460747/206208067-81ce0058-ae66-4d7c-8080-60a095a5715f.mp4)

---

This project is a cost-effective and straightforward way to measure RPM, making it a practical solution for various mechanical experiments and applications. With easy-to-follow schematics, a minimal BOM, and robust software support, it’s perfect for anyone looking to explore or enhance their understanding of rotational speed measurement.
