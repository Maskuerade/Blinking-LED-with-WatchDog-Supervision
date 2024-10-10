# Blinking LED with Watchdog Supervision on ATmega328P

## Project Overview

This repository contains the source code and simulation files for the **Third Year Final Project - 2024**, an embedded systems project that implements an LED blinking feature with watchdog supervision on an ATmega328P microcontroller.

### Key Components:
1. **LED Management (LEDMgr)**: Controls the blinking behavior of an LED using GPIO functions.
2. **GPIO**: Provides pin initialization and control for the LED.
3. **Watchdog Driver (WDGDrv)**: Manages the hardware watchdog with a timeout of 64ms, responsible for resetting the system in case of software malfunctions.
4. **Watchdog Manager (WDGM)**: Monitors the health of the LEDMgr, ensuring that the system remains responsive.

### Project Requirements:
The project requires the following features to be implemented:
- **GPIO Control**: A GPIO module initializes the pin for the LED and controls its on/off state.
- **LED Blinking**: The LED toggles every 500ms, managed by the LEDMgr component.
- **Watchdog Timer**: The watchdog resets the system if the LEDMgr or WDGM becomes unresponsive.
- **Supervision**: The WDGM ensures that the LEDMgr is called regularly, refreshing the watchdog if everything is running correctly.

### Functionality:
- **GPIO_Init()**: Initializes the pin connected to the LED.
- **GPIO_Write()**: Writes the LED state (on/off) to the designated pin.
- **LED_Init()**: Initializes the LEDMgr component.
- **LED_Manage()**: Manages LED blinking every 500ms, called in a loop every 10ms.
- **WDGDrv_Init()**: Initializes and starts the watchdog with a 64ms timeout.
- **WDGM_Init()**: Initializes the WDGM to monitor the LEDMgr.
- **WDGM_MainFunction()**: Supervises the periodic calls to LED_Manage() and ensures that the watchdog is refreshed properly.
- **WDGM_ProvideSupervisionStatus()**: Returns the health status of LEDMgr to the WDGDrv.
- **WDGM_AlivenessIndication()**: Ensures that the LEDMgr is being called regularly, which helps the WDGM assess if the system is running correctly.

## Features

1. **LED Blinking with Periodicity**:
   - The LED blinks every 500ms, managed by LED_Manage() function using GPIO_Write().
   
2. **Watchdog Supervision**:
   - The watchdog timer is configured to reset the system if the software stops working correctly, ensuring robustness.
   - WDGM monitors the LEDMgr and keeps the watchdog refreshed if the system remains healthy.

3. **Fault Scenarios**:
   - Positive Scenario: Ensures that LEDMgr is called at the correct intervals and the watchdog is refreshed on time.
   - Negative Scenarios:
     - WDGM_MainFunction call is commented, leading to watchdog reset after 50ms.
     - WDGM_AlivenessIndication call is commented, leading to a reset after 100ms.
     - LED_Manage call frequency is modified to 5ms, triggering a watchdog reset after 100ms.

## Folder Structure

```bash
.
├── GPIO/                    # Contains GPIO implementation files
├── LED/                     # LEDMgr component source files
├── Timer/                   # Timer configuration and ISR files
├── WDGM/                    # Watchdog Manager component source files
├── WDGDRV/                  # Watchdog Driver implementation
├── src/                     # Main source files for the project
├── working_bef_oscilloscope/ # Test files for oscilloscope simulation
├── .gitignore               # Git ignore file
├── README.md                # Project documentation (this file)
└── WDG_Project.pdsprj       # Project file for development environment
```

## Getting Started

### Prerequisites:
- **ATmega328P** microcontroller.
- Embedded C development environment.
- Oscilloscope (optional for simulation testing).

### Steps to Run:
1. **Clone the repository**:
    ```bash
    git clone https://github.com/username/blinkingled-watchdog.git
    cd blinkingled-watchdog
    ```

2. **Compile the code** using your preferred embedded systems IDE (e.g., Atmel Studio).
   
3. **Flash the compiled code** onto the ATmega328P using an AVR programmer.

4. **Run the simulation** using the provided test scenarios and verify system functionality using an oscilloscope.

### Simulation Scenarios:
- **Positive Scenario**: Check the LED blinking rate and ensure watchdog reset is avoided.
- **Negative Scenario 1**: Comment WDGM_MainFunction and observe a reset after 50ms.
- **Negative Scenario 2**: Comment WDGM_AlivenessIndication and verify a reset after 100ms.
- **Negative Scenario 3**: Change LED_Manage periodicity and verify system reset after 100ms.

## Testing and Debugging

You can simulate and test the project with the provided **working_bef_oscilloscope** folder files. A screen recording is required to demonstrate the following:

1. **Positive Test**: Verifying correct periodic LED blinking and watchdog refresh.
2. **Negative Tests**: Demonstrating failure cases where the watchdog resets the system.

Use test pins and an oscilloscope to validate timings.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to reach out for any questions or collaboration opportunities related to this project!
