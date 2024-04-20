# Accelerometer Display Application

## Project Overview

This project consists of two main components: a Qt-based server (`QtServer`) and an MFC-based client (`MfcClient`). The `QtServer` reads real-time data from an accelerometer connected via USB and transmits it to multiple clients. The `MfcClient` displays the data fetched from the server. This setup allows for a distributed system where data acquisition and display are handled separately, enhancing flexibility and scalability.

## System Components

### QtServer

- **Data Handling:** Continuously reads accelerometer data and sends updates to connected clients.
- **Network Communication:** Uses a custom protocol to transmit packets containing acceleration data up to five times per second.
- **Client Management:** Capable of handling up to 50 simultaneous client connections.
- **Error Handling:** Manages sensor disconnections and transmits error states to clients.

### MfcClient

- **Data Reception:** Connects to `QtServer` via network and receives acceleration data.
- **User Interface:** Built using Microsoft Foundation Classes (MFC), provides a graphical display of acceleration vectors.
- **Interactivity:** Includes controls for starting/stopping data streams, scaling graphical output, and other interactive features.
- **Error Visualization:** Displays errors and alerts from the server regarding sensor connectivity and data integrity.

## Features

- **Distributed Architecture:** Separates data acquisition from data display, allowing for a modular and scalable system design.
- **Real and Emulated Sensor Data:** Handles both real and simulated data, enabling testing without physical hardware.
- **Graphical Display:** The client displays acceleration data graphically in a window, with curves colored red, green, and blue for different axes.
- **Dynamic Sensor Management:** Sensors can be dynamically added or removed from the server, and changes are reflected in real-time on the client.

## Implementation Details

### QtServer

- **Technology:** Developed using the Qt framework for robust network handling and backend processing.
- **Setup:** Runs continuously on a host machine, reading from the accelerometer and managing network communications.

### MfcClient

- **Technology:** Utilizes Microsoft Foundation Classes (MFC) for the client interface.
- **Interaction:** Users can control the application through a dedicated UI, managing connection settings and display options.

## Usage

1. **Server Initialization:** Start the `QtServer` which automatically begins reading from the connected accelerometer and awaits client connections.
2. **Client Connection:** Launch the `MfcClient`, which connects to the server via the network to receive data.
3. **Data Interaction:** Use the client's UI to start/stop data streams, adjust visualizations, and handle sensor configurations.
4. **Handling Disconnections:** Both server and client include error handling mechanisms to deal with potential hardware or network issues.

## Development Setup

- **Dependencies:** Requires Qt for the server and MFC for the client, alongside standard C++ libraries.
- **Compilation and Configuration:** Each component must be compiled separately with their respective frameworks and connected over a network configured for TCP/IP communication.
