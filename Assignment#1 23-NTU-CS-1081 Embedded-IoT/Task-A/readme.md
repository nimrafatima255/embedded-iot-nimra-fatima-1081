# Embedded-IoT System — Assignment 1  
# Name: Nimra Fatima  
#  Reg. No: 23-NTU-CS-1081  

# Project Title: LED Mode Control with OLED Display (ESP32)

# Objective:
This project demonstrates multiple LED control modes using an ESP32 microcontroller, with mode changes displayed on an OLED screen.  
Two buttons are used — one to change the LED mode, and another to reset all LEDs.

# **Features**
| Mode | Description | OLED Display |

 1 = All LEDs OFF  “All LEDs OFF” 
 2 = Fast Alternate Blink  “Fast Alternate Blink” 
 3 = All LEDs ON  “All LEDs ON” 
 4 = PWM Fade  “PWM Fade All” 



# **Hardware Components**
- ESP32 Board  
- 3 LEDs (connected via 220Ω resistors)  
- 2 Push Buttons  
- 0.96” OLED Display (I2C interface)  
- Jumper Wires & Breadboard  


# **Pin Connections**

 Component & ESP32 Pin

 LED1 GPIO 17 
 LED2 GPIO 18 
 LED3 GPIO 19 
 Mode Button GPIO 34 
 Reset Button GPIO 35 
 OLED SDA GPIO 21 
 OLED SCL GPIO 22 

# **Working Principle**
- **Button 1 (Mode Button):** Each short press cycles through LED modes (1 → 2 → 3 → 4).  
- **Button 2 (Reset Button):** Resets to Mode 1 (all LEDs OFF).  
- OLED displays the **current mode number and description**.  
- PWM fading and blinking are implemented using non-blocking `millis()` timing.


# **Code Explanation**
- 'analogWrite()' controls LED brightness (for fading).  
- 'millis()' ensures non-blocking delay-free LED transitions.  
- OLED uses **Adafruit_SSD1306** and **Adafruit_GFX** libraries for display output.  
- Button inputs are read using 'digitalRead()' with internal pull-up resistors.



# **Wokwi Simulation**
 **Wokwi Project Link:** 
((https://wokwi.com/projects/445781130964625409))
# **Screeshots** 
Screehshots are added in Task-A folder.



