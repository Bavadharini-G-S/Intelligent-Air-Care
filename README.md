# Intelligent-Air-Care
This project implements a predictive maintenance system for air conditioners, leveraging an ESP32 microcontroller and various sensors to monitor equipment health and proactively identify potential issues.

## Key Features
* **Real-time Air Conditioner Monitoring:**
* **Optional Vibration Detection:**
* **Cloud-Based Data Storage & Visualization:**
* **Automated Anomaly Detection:**
* **Actionable Notification System:** 

## Prerequisites
### Hardware Components
* ESP32 microcontroller
* MQ135 Air quality sensor
* Hx710B Air pressure sensor
* DHT11 Temperature & Humidity sensor
* SW420 Vibration sensor
* Breadboard
* Jumpercables
* MicroUSB Cable

### Software Stack
* Arduino IDE
* Adafruit IO
* Google Sheets
* Zapier

## Getting Started
### 1. Hardware setup
   - Assemble the hardware components based on the schematics.
   - Ensure a stable power supply for the ESP32 and sensors.

![PMS_Circuit_Diagram -2](https://github.com/Bavadharini-G-S/Intelligent-Air-Care/assets/115529616/aef104ba-f9c9-4665-bf3a-fc9c7823d543)

### 2. Software requirements

**Testing and Display:**

1. Upload _"PMS_Sensor_Test.io"_ to ESP32. This code tests the sensors and display by reading sensor values and showing them on both the OLED display and the serial monitor.

**Cloud Integration:**

1. Create an Adafruit IO Account.
2. Create a dashboard on Adafruit IO to visualize project data feeds (e.g., temperature, humidity).
3. Modify the WiFi network name (WLAN_SSID), password (WLAN_PASS), Adafruit username (AIO_USERNAME), API key (AIO_KEY), and feed names within the _"PMS_Cloud.ino"_ code to match your Adafruit IO setup.

**Google Sheets Integration:**

1. Open a new Google Spreadsheet and set row titles as "Date", "Time", "Temperature", "Humidity", "Vibration", "Air Pressure", and "Air Quality".
2. Navigate to Extensions > Apps Script within your Google Sheet.
3. Update "Spread Sheet ID" within the _"PMS_Excel_Apps_script.txt"_ code with the actual ID of your Google Sheet.
4. Deploy the Apps Script code and copy the generated script ID.
5. Update the GOOGLE_SCRIPT_ID variable in the _"PMS_Cloud.ino"_ code with the copied script ID.

**Zapier Integration:**

1. Configure Zapier to integrate your Google Sheet with Gmail for automated notifications in case of anomaly.

**Final Deployment:**

1. Upload the final version of the code to your ESP32 device.

### Workflow
![Critical-to-quality tree-3](https://github.com/Bavadharini-G-S/Intelligent-Air-Care/assets/115529616/38c2028d-dc62-4633-9c0f-0bc561007b8a)


### Screenshots for reference
<img width="959" alt="image" src="https://github.com/Bavadharini-G-S/Intelligent-Air-Care/assets/115529616/717a39be-48f2-4f27-8878-565c4c923ba2">
<img width="959" alt="image" src="https://github.com/Bavadharini-G-S/Intelligent-Air-Care/assets/115529616/2120b0fc-28d7-4dd3-9391-b888c4aa0575">
<img width="958" alt="Screenshot 2024-05-06 193807" src="https://github.com/Bavadharini-G-S/Intelligent-Air-Care/assets/115529616/f3b354c5-4a99-405c-8d83-44e7d8e64317">



