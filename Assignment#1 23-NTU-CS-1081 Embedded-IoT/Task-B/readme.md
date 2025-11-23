# Task B — Button Press Detection  
**Name:** Nimra Fatima  
**Registration No:** 23-NTU-CS-1081
**Section** BSCS-B
**Submit to** Sir Nasir

---

## Project Overview
This project demonstrates a **single-button press detection system** using an ESP32, 3 LEDs, a buzzer, and an OLED display. The system detects:

**Short Press (< 1.5s):** Toggles all LEDs ON/OFF  
**Long Press (> 1.5s):** Activates a buzzer tone  

The OLED displays the type of button press detected in real-time.

---

## Hardware Components

 Component        Pin Connected 

 Button           GPIO 35       
 LED1             GPIO 17       
 LED2             GPIO 18       
 LED3             GPIO 19       
 Buzzer           GPIO 5        
 OLED SDA         GPIO 21       
 OLED SCL         GPIO 22       

**Resistors:** 220Ω used for LEDs.

---

## Wiring Diagram / Pin Map
        ESP32                          
   GPIO 35 -->  Button
   GPIO 17  -->LED1  
   GPIO 18 --> LED2  
   GPIO 19 --> LED3  
   GPIO 5 --> Buzzer 
   GPIO 21 SDA--> OLED
   GPIO 22 SCL --> OLED


---

## Wokwi Simulation
https://wokwi.com/projects/445799678168031233

---


## How it Works
1. The button is configured with `INPUT_PULLUP` (active LOW).  
2. When pressed, the program records the press start time.  
3. On release, the press duration is calculated:
   If duration < 1.5 seconds → toggles LEDs and displays "Short Press Detected"
    If duration ≥ 1.5 seconds → plays buzzer and displays "Long Press Detected"  
4. OLED shows messages for user feedback.

---

<img width="475" height="329" alt="Long Press" src="https://github.com/user-attachments/assets/b9c358fe-035a-46b2-9a4e-052ad260a301" />
<img width="479" height="325" alt="Short press " src="https://github.com/user-attachments/assets/fae96bfa-3376-4327-aaee-cd4bce80cb98" />



  


