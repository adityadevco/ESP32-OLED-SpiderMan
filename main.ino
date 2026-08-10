#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "VideoFrame.h"

// ============================================================
// OLED
// ============================================================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1

#define SDA_PIN 21
#define SCL_PIN 22

#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// ============================================================
// VIDEO
// ============================================================

int currentFrame = 0;

unsigned long previousMillis = 0;

// ============================================================
// SETUP
// ============================================================

void setup() {

  Serial.begin(115200);

  delay(1000);

  Serial.println();
  Serial.println("==============================");
  Serial.println("ESP32 OLED VIDEO PLAYER");
  Serial.println("==============================");

  // ----------------------------------------------------------
  // I2C
  // ----------------------------------------------------------

  Wire.begin(SDA_PIN, SCL_PIN);

  // Start safely at 400 kHz
  Wire.setClock(400000);

  Serial.println("I2C started.");

  // ----------------------------------------------------------
  // OLED
  // ----------------------------------------------------------

  if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS
      )) {

    Serial.println("OLED initialization FAILED!");

    while (true) {
      delay(1000);
    }
  }

  Serial.println("OLED initialized successfully.");

  // ----------------------------------------------------------
  // Startup screen
  // ----------------------------------------------------------

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(15, 10);
  display.println("Spideyyyy edit");

  display.setCursor(15, 25);
  display.println("VIDEO PLAYER");

  display.setCursor(15, 40);
  display.println("Starting...");

  display.display();

  delay(1500);

  // ----------------------------------------------------------
  // Video information
  // ----------------------------------------------------------

  Serial.println();
  Serial.print("Frames: ");
  Serial.println(TOTAL_FRAMES);

  Serial.print("Frame delay: ");
  Serial.print(FRAME_DELAY);
  Serial.println(" ms");

  Serial.print("FPS: ");
  Serial.println(1000.0 / FRAME_DELAY);

  Serial.println("Starting video...");
}

// ============================================================
// LOOP
// ============================================================

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= FRAME_DELAY) {

    previousMillis = currentMillis;

    // --------------------------------------------------------
    // Draw current frame
    // --------------------------------------------------------

    display.clearDisplay();

    display.drawBitmap(
      0,
      0,
      video_frames[currentFrame],
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SSD1306_WHITE
    );

    display.display();

    // --------------------------------------------------------
    // Next frame
    // --------------------------------------------------------

    currentFrame++;

    if (currentFrame >= TOTAL_FRAMES) {

      currentFrame = 0;

      Serial.println("Video loop restarted.");
    }
  }
}