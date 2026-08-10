# ESP32 OLED Spider-Man Video Display 🕷️

A simple ESP32 project that plays a pre-converted bitmap animation on a 128×64 I2C OLED display.

## Components

- ESP32 Dev Module
- 0.96-inch 128×64 I2C OLED display
- Breadboard
- 4 × jumper wires
- USB cable
- Computer with Arduino IDE

## Wiring

| OLED Pin | ESP32 Pin |
|---|---|
| GND | GND |
| VDD | 3.3V |
| SCK | GPIO 22 |
| SDA | GPIO 21 |

> On this I2C OLED, the pin labeled **SCK** is the I2C clock line, equivalent to **SCL**.

## Software

Install:
- Adafruit GFX Library
- Adafruit SSD1306

Arduino IDE board:
`ESP32 Dev Module`

OLED I2C address:
`0x3C`

## Project Structure

Keep both files in the same Arduino sketch folder:

```text
ESP32-OLED-SpiderMan/
├── ESP32-OLED-SpiderMan.ino
└── VideoFrame.h
```

`ESP32-OLED-SpiderMan.ino` contains the ESP32 setup, OLED initialization, and video playback code.

`VideoFrame.h` contains the converted bitmap animation frames.

## Animation

- Resolution: 128 × 64
- Frames: 582
- Frame size: 1024 bytes
- Frame delay: 33 ms
- Target: approximately 30 FPS

## How It Works

```text
Animation
   ↓
1-bit 128×64 bitmap frames
   ↓
VideoFrame.h
   ↓
ESP32
   ↓ I2C
OLED
   ↓
Animation playback
```

## Upload

1. Connect the ESP32 to your computer by USB.
2. Open the `.ino` file in Arduino IDE.
3. Select **ESP32 Dev Module**.
4. Select the correct USB serial port.
5. Upload the sketch.
6. Open Serial Monitor at **115200 baud** for debug messages.

No Wi-Fi, cloud service, API, or online ID is required. The animation is stored locally in `VideoFrame.h`.

## Result

🕷️ **ESP32 + OLED + code = Spider-Man on a tiny screen!**
