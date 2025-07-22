# 👁️‍🗨️ ESP32-CAM Assistive Vision System for the Differently-Abled

## 🧠 Project Objective

This project aims to build an affordable, compact, and efficient assistive technology using the **ESP32-CAM** module. It is designed to aid people with disabilities—especially those with visual impairments or mobility challenges—by recognizing visual inputs in real time and providing actionable feedback (e.g., voice alerts, haptic signals). This empowers users with improved **navigation**, **obstacle detection**, and **environmental awareness**.

---

## 🔧 Hardware Used

| Component               | Description                                           |
|------------------------|-------------------------------------------------------|
| **ESP32-CAM**          | Camera + microcontroller combo (OV2640 sensor)        |
| **FTDI Programmer**    | For uploading code via UART to ESP32-CAM              |
| **5V Power Supply**    | Regulated power source (battery or adapter)           |
| **Buzzer/Speaker**     | For audio feedback                                     |
| **Vibration Motor**    | For haptic feedback (alternative to buzzer)           |
| **MicroSD Card (opt.)**| For image logging and offline storage                 |
| **Raspberry Pi (opt.)**| For AI model inference (YOLO, MobileNet)              |

---

## 🔬 How it Works

### 1. 📸 Image Capture
- The **OV2640 camera** on the ESP32-CAM captures real-time images.
- Common resolutions: **320×240** or **640×480** (balanced for speed and quality).

### 2. 🧮 Image Processing
- **Onboard (ESP32)**:
  - Basic color detection (e.g., red objects).
  - Simple face or shape detection (TinyML or Haar Cascades).
- **Offloaded (Pi or Server)**:
  - Advanced object recognition using YOLO/MobileNet models.
  - Wi-Fi communication for image or data transfer.

### 3. 🎯 Decision Making
- Based on detection results:
  - If object/obstacle/human is detected → Trigger alert.
  - Feedback via buzzer or motor to inform the user.

### 4. 📡 Communication
- ESP32-CAM connects via **Wi-Fi**.
- Sends alerts to:
  - Mobile apps (Blynk, Telegram, or custom UI).
  - MQTT broker for smart home/IoT integration.
- Optional: Live stream camera feed.

---

## ✅ Achievements

- Achieved **5–10 FPS** real-time capture at 320×240 resolution.
- Onboard **color detection** and **basic face detection**.
- Feedback system with **buzzer or vibration**.
- Streaming via web UI or mobile app.
- Supports offloading to Raspberry Pi for deep learning.

---

## 🧠 Algorithms & Math

### 📷 Image Representation
RGB image is stored as a 3D matrix:  
`I(x, y, c), where c ∈ {R, G, B}`

---

### 🎨 Color Thresholding

**Example for detecting red:**

###
if (R > 200 && G < 50 && B < 50) {
    // Red object detected
}

Gray = 0.299 * R + 0.587 * G + 0.114 * B

Gx = [ -1  0  1
      -2  0  2
      -1  0  1 ]

Gy = [ -1 -2 -1
       0  0  0
       1  2  1 ]

Edge Magnitude = sqrt(Gx² + Gy²)

### Face/object detection 
using Haar cascades or tinyml classification
f(x) = argmax(wᵢ · x + bᵢ)


### 💻 Software Overview
🧠 ESP32-CAM Firmware (C++/Arduino)
- Image capture
- Color thresholding
- Feedback output (buzzer/vibration)
- Wi-Fi communication (optional)

### MATLAB
- Simulates : Edge detection, Color fitting, Face Detection

### Future scope
- 🔊 Text-to-Speech Integration (Google TTS API)
- 🤖 TinyML deployment on ESP32 using TFLite
- 🧠 Offload heavy models to Raspberry Pi 3B+
- ✋ Add gesture recognition or QR code scanning
- 🎙️ Voice input control for two-way interaction
- 🧤 Build into smart glove or wearable visor

### Social Impact 
