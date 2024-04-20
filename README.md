
# Project README: Accelerometer Display Application

## Project Overview

This project involves the development of a software application capable of reading and displaying real-time accelerometer data on a PC screen. The data is fetched from an accelerometer connected via USB. The application provides an object-oriented interface for low-level communication with one or multiple accelerometers and includes both real and emulated sensor data handling.

## Features

- **Sensor Management:** The `AccManager` class manages access to and monitoring of multiple sensors, allowing dynamic addition or removal of sensors from the USB interface.
- **Individual Sensor Handling:** The `AccSensor` class encapsulates access to individual sensors.
- **Data Visualization:** The application can display three curves (representing x, y, and z acceleration components) in red, green, and blue. Users can start and stop data acquisition and adjust the vertical scale from the interface.
- **Error Handling:** The application handles real-world scenarios like disconnection of sensors, providing robust error management.
- **Data Acquisition:** Features a timer-triggered acquisition every 100 ms, ensuring continuous data flow.
- **User Interface:** Includes menu items and buttons for controlling acquisition, scaling, and data display.
- **Graphical Display:** A specialized window displays the acceleration trace with adjustable pen thickness and color based on the acceleration components.
- **Distributed Version:** The project also includes a distributed application version, which supports real-time data reading and display across a network, accommodating multiple clients.

## Implementation Details

- **MFC-SDI Application:** Utilizes Microsoft Foundation Classes (MFC) in a Single Document Interface (SDI) setup.
- **Interactive Controls:** Users can interact through the UI to manage sensor configurations, start/stop data acquisition, and adjust display settings.
- **File Operations:** Supports saving and loading of accelerometer data to and from a file, using a common dialog box with a custom file extension.
- **Additional Functionality:** Custom features include selective display of curves and modular selection of display elements.

## Usage

1. **Starting the Application:** Launch the application, which automatically detects and initializes connected sensors.
2. **Managing Sensors:** Add or remove sensors via the application interface.
3. **Viewing Data:** Select the `View/Draw` menu option to open the data display window. Use zoom buttons to scale the visual output.
4. **Saving and Loading Data:** Data can be saved to and loaded from files, with support for handling only the most recent data points to optimize performance.

## Development Setup

- **Dependencies:** Requires MFC for UI components and standard C++ libraries for backend processing.
- **Compilation:** Include `AccSensor.h` and `AccManager` class into your project. Define necessary macros for compilation.
- **Configuration:** Adjust settings for sensor detection and display properties as needed.

## Future Enhancements

- **Improved Sensor Handling:** Enhance the capability to handle more complex sensor configurations.
- **User Interface Enhancements:** Upgrade the UI for better user interaction and visualization capabilities.
- **Network Capabilities:** Expand the distributed version to handle more clients and provide more robust network error handling.

This README provides a general overview and setup instructions for the Accelerometer Display Application project. For detailed implementation guidance, refer to the project's codebase and documentation files.

