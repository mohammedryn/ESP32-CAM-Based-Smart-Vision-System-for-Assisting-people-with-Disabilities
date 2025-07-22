#include "esp_camera.h"
#include <WiFi.h>
// Change GPIO pin as needed for your buzzer
#define BUZZER_PIN 12 

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);

  camera_config_t config;
  // Configure camera settings for your board here...
  // Refer to the ESP32-CAM AI Thinker board or your hardware

  if (esp_camera_init(&config) != ESP_OK) {
    Serial.println("Camera init failed");
    while (true);
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
    return;
  }

  int red_pixels = 0;
  for (int i = 0; i < fb->len; i += 3) {
    uint8_t R = fb->buf[i];
    uint8_t G = fb->buf[i + 1];
    uint8_t B = fb->buf[i + 2];
    if (R > 200 && G < 50 && B < 50) {
      red_pixels++;
    }
  }

  if (red_pixels > 500) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
  }
  
  esp_camera_fb_return(fb);
  delay(100);
}
