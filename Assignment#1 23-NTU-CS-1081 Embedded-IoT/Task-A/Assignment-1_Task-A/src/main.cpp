//Nimra Fatima23-NTU-CS-1081
//Task-A One press button for each mode
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
#define LED1 17
#define LED2 18
#define LED3 19
#define BTN_MODE 34
#define BTN_RESET 35

// --- Variables ---
int mode = 1;
bool lastModeState = HIGH;
bool lastResetState = HIGH;
unsigned long lastButtonTime = 0;
unsigned long lastBlinkTime = 0;
int fadeValue = 0;
int fadeDirection = 1;
int currentLED = 0;

void showMode();

void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BTN_MODE, INPUT_PULLUP);
  pinMode(BTN_RESET, INPUT_PULLUP);

  showMode();
}

void loop() {
  bool modeBtn = digitalRead(BTN_MODE);
  bool resetBtn = digitalRead(BTN_RESET);

  // --- Mode Button ---
  if (modeBtn == LOW && lastModeState == HIGH && millis() - lastButtonTime > 300) {
    mode++;
    if (mode > 4) mode = 1;
    showMode();
    lastButtonTime = millis();
  }

  // --- Reset Button ---
  if (resetBtn == LOW && lastResetState == HIGH && millis() - lastButtonTime > 300) {
    mode = 1;
    showMode();
    lastButtonTime = millis();
  }

  lastModeState = modeBtn;
  lastResetState = resetBtn;

  // --- Mode Functions ---
  switch (mode) {
    case 1: // All OFF
      analogWrite(LED1, 0);
      analogWrite(LED2, 0);
      analogWrite(LED3, 0);
      break;

    case 2: // Fast Alternate Blink
      if (millis() - lastBlinkTime >= 150) {
        currentLED = (currentLED + 1) % 3;

        analogWrite(LED1, 0);
        analogWrite(LED2, 0);
        analogWrite(LED3, 0);

        if (currentLED == 0) analogWrite(LED1, 255);
        else if (currentLED == 1) analogWrite(LED2, 255);
        else if (currentLED == 2) analogWrite(LED3, 255);

        lastBlinkTime = millis();
      }
      break;

    case 3: // All ON
      analogWrite(LED1, 255);
      analogWrite(LED2, 255);
      analogWrite(LED3, 255);
      break;

    case 4: // PWM fade
      if (millis() - lastBlinkTime >= 10) {
        fadeValue += fadeDirection * 5;
        if (fadeValue >= 255 || fadeValue <= 0) fadeDirection *= -1;

        analogWrite(LED1, fadeValue);
        analogWrite(LED2, 255 - fadeValue);
        analogWrite(LED3, (fadeValue / 2) + 50);
        lastBlinkTime = millis();
      }
      break;
  }
}

// --- OLED display ---
void showMode() {
  display.clearDisplay();
  display.setCursor(0, 10);
  display.setTextSize(2);
  display.print("Mode ");
  display.print(mode);
  display.setTextSize(1);
  display.setCursor(0, 40);

  switch (mode) {
    case 1: display.print("All LEDs OFF"); break;
    case 2: display.print("Fast Alternate Blink"); break;
    case 3: display.print("All LEDs ON"); break;
    case 4: display.print("PWM Fade All"); break;
  }

  display.display();
}
