# Weapon Detection System Using IoT, Arduino, and Proximity Sensors

## Project Overview
The Weapon Detection System is an IoT-based security solution designed to enhance public safety by detecting potential weapons in public transportation hubs, airports, and other high-security areas. The system utilizes proximity sensors, an Arduino microcontroller, and a GSM communication module to detect metallic objects, trigger an alarm, and notify security personnel via SMS alerts.

This project has been implemented in:
- Physical Hardware Prototype (Real-world application)
- Tinkercad Simulation (Virtual testing for validation)

## Technology Stack & Components
### Hardware Components
- **Arduino Uno** – Microcontroller for processing sensor data.
- **Capacitive Proximity Sensor** – Detects metallic objects.
- **GSM Module (SIM900)** – Enables SMS-based alert notifications.
- **Buzzer** – Provides an audible alert upon detection.
- **16x2 LCD Display** – Displays real-time status and detection alerts.
- **Power Supply (9V, 1A)** – Powers the system.

### Software & Tools
- **Arduino IDE** – Writing and uploading firmware code.
- **Tinkercad** – Virtual circuit simulation for testing and validation.
- **GitHub** – Version control and collaboration.

## System Workflow & Operation
### Detection Mechanism
- The proximity sensor continuously scans for metallic objects.
- If a metallic object is detected within a predefined range, it is classified as a potential weapon.

### Alert & Notification System
- The buzzer activates to provide an immediate alert.
- The LCD displays "WEAPON DETECTED" as a warning message.
- The GSM module sends an SMS notification to security personnel.

### Real-Time Monitoring & Logging
- Wireless notifications via GSM for remote alerts.
- Serial Monitor logs detection events and system diagnostics.

## Project Implementation
### Hardware Deployment
- The system was constructed using physical electronic components and successfully tested.
- The GSM module was integrated to enable real-time security alerts.

### Virtual Testing (Tinkercad Simulation)
- The system was also tested in Tinkercad to validate its functionality before hardware deployment.
- The LCD, buzzer, and serial monitor outputs matched expected hardware behavior.

## Project Directory Structure
```
Weapon-Detection-System/
│── hardware/
│   ├── circuit_diagram.png  # Hardware circuit diagram
│   ├── hardware_code.ino    # Arduino firmware for real-world implementation
│   ├── Hardware_output.png  # Hardware results
│   ├── Hardware_setup.png   # Arduino connections for real-world implementation
│── simulation/
│   ├── tinkercad_simulation.png  # Screenshot of the simulation
│   ├── simulation_code.ino       # Arduino firmware for simulation
│   ├── Simulation_result.png     # Results achieved through tinkercad
│── docs/
│   ├── Weapon-Detection-Report.pdf  # Detailed technical report
│── LICENSE  # Open-source licensing information
│── .gitignore  # Files excluded from version control
├── README.md  # This project documentation
```

## Deployment & Execution
### Running on Physical Hardware
1. Upload the Arduino code (`hardware/hardware_code.ino`) to the Arduino Uno.
2. Assemble the hardware components as per the circuit diagram (`hardware/circuit_diagram.png`).
3. Power up the system and observe the LCD, buzzer, and GSM module for alerts.
4. Use the Serial Monitor to review logs and debug if necessary.

### Running on Tinkercad Simulation
1. Open Tinkercad and import the circuit design (`simulation/tinkercad_simulation.png`).
2. Upload the simulation firmware (`simulation/simulation_code.ino`).
3. Run the simulation and verify detection results.

## System Performance & Evaluation
### Hardware Testing Outcomes
- Successfully identified metallic objects in high-risk entry points.
- The GSM module successfully sent alerts to designated security contacts.
- The buzzer and LCD warnings functioned correctly.
- Reliable performance with minimal false positives.

### Tinkercad Simulation Outcomes
- Achieved detection accuracy similar to real-world implementation.
- Serial Monitor logs provided expected detection outputs.

## Licensing & Usage
This project is licensed under the MIT License – allowing free usage, modification, and distribution for research or educational purposes.

## Contributing to the Project
Interested in improving this project? Follow these steps:
1. Fork this repository.
2. Clone your fork:
   ```sh
   git clone https://github.com/ApoorvaN1701/Weapon-Detection-System.git
   ```
3. Make your changes and commit:
   ```sh
   git add .
   git commit -m "Enhanced feature XYZ"
   ```
4. Push to your fork and submit a Pull Request (PR).

## Contact & Support
For any queries, suggestions, or collaboration opportunities, reach out:
- **Email:** vaishnaviapoorva@gmail.com  
- **GitHub:** [ApoorvaN1701](https://github.com/ApoorvaN1701)

## Project Status
This system provides an effective, scalable, and real-time solution for enhancing public security against weapon threats.

Developed by **Apoorva N**  
Date: February 2025  
Domains: IoT, Security, Embedded Systems, Arduino

