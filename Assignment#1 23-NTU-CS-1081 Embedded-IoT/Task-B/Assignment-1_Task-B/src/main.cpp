//Nimra Fatima 23-NTU-CS-1081
//Buzzer with press detection
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- OLED setup ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// --- Pin Configuration ---
#define BUTTON_PIN 35
#define LED1 17
#define LED2 18
#define LED3 19
#define BUZZER 5

// --- Variables for button press detection ---
unsigned long pressStartTime = 0;
bool buttonPressed = false;
bool ledsOn = false;

void showMessage(String msg); // Function declaration

void setup() {
  Serial.begin(115200);

  // OLED Initialization
  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("OLED init failed"));
    while (true);
  }

  // Clear OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);
  display.println("System Ready!");
  display.display();

  // Pin modes
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button active LOW
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Initially all OFF
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(BUZZER, LOW);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  // Button pressed (active LOW)
  if (buttonState == LOW && !buttonPressed) {
    buttonPressed = true;
    pressStartTime = millis();
  }

  // Button released
  if (buttonState == HIGH && buttonPressed) {
    buttonPressed = false;
    unsigned long pressDuration = millis() - pressStartTime;

    if (pressDuration < 1500) {
      // --- Short Press Detected ---
      ledsOn = !ledsOn;
      digitalWrite(LED1, ledsOn);
      digitalWrite(LED2, ledsOn);
      digitalWrite(LED3, ledsOn);
      showMessage("Short Press Detected");
      Serial.println("Short Press Detected");
    } else {
      // --- Long Press Detected ---
      showMessage("Long Press Detected");
      Serial.println("Long Press Detected");
      tone(BUZZER, 1000);  // 1 kHz tone
      delay(1000);
      noTone(BUZZER);
    }
  }
}

// --- OLED Display Message Function ---
void showMessage(String msg) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 25);
  display.println(msg);
  display.display();
}
