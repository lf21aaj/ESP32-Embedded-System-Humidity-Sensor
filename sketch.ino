#include <Arduino.h>
#include "DHT.h"

// define pins for components
#define DHTPIN 4         // dht22 data pin
#define DHTTYPE DHT22    // dht22 sensor type
#define RED_PIN 15       // rgb led red pin
#define GREEN_PIN 2      // rgb led green pin
#define BLUE_PIN 13      // rgb led blue pin
#define BUZZER_PIN 5     // buzzer pin
#define SWITCH_PIN 12    // slide switch for sleep mode

// initialize dht sensor object
DHT dht(DHTPIN, DHTTYPE);
bool sleepMode = false;
const float HUMIDITY_THRESHOLD = 80.0; // humidity alert threshold

// dummy data arrays for testing
float testHumidity[] = {30.0, 34.0, 38.5, 42.5, 45.0, 50.5, 52.5, 55.0, 60.0, 60.5, 65.0, 70.0, 75.5, 80.0, 85.0, 90.0, 95.0};
float testTemperature[] = {18.0, 19.5, 20.5, 21.0, 22.0, 23.5, 24.5, 25.0, 25.5, 26.0, 27.5, 28.0, 29.5, 30.0, 31.0, 32.0, 33.0};
int testIndex = 0;

void IRAM_ATTR handleSwitchInterrupt() {
    // check switch position and update RGB LED accordingly
    if (digitalRead(SWITCH_PIN) == LOW) {
        Serial.println("🟦 RGB LED: Cyan (Switch Right)");
        setRGBLED(0, 255, 255); // cyan color
    } else {
        Serial.println("⚫ RGB LED: Black (Switch Left)");
        setRGBLED(0, 0, 0); // turn off LED
    }
}

void setup() {
    Serial.begin(115200);
    
    // configure pin modes
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    
    attachInterrupt(digitalPinToInterrupt(SWITCH_PIN), handleSwitchInterrupt, CHANGE);
    
    // initialize dht sensor
    dht.begin();
    delay(2000); // allow dht22 to stabilize
    Serial.println("System initialised");
}

void loop() {
    // retrieve test data for humidity and temperature
    float humidity = testHumidity[testIndex];
    float temperature = testTemperature[testIndex];
    
    // display readings in serial monitor
    Serial.println("\n============================================");
    Serial.print("📊 Humidity: ");
    Serial.print(humidity);
    Serial.print("%  🌡 Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
    Serial.println("============================================");
    
    // update rgb led and buzzer based on humidity level
    controlRGBLED(humidity);
    controlBuzzer(humidity);
    
    // move to next data point (looping back when reaching end)
    testIndex = (testIndex + 1) % (sizeof(testHumidity) / sizeof(testHumidity[0]));
    
    delay(2000);
}

void controlRGBLED(float humidity) {
    if (humidity >= 90.0) {
        Serial.println("🟣 RGB LED: Purple (90% - 100%)");
        setRGBLED(128, 0, 128);
    } else if (humidity >= 80.0) {
        Serial.println("🔴 RGB LED: Red (80% - 90%)");
        setRGBLED(255, 0, 0);
    } else if (humidity >= 70.0) {
        Serial.println("🟠 RGB LED: Orange (70% - 80%)");
        setRGBLED(255, 125, 0);
    } else if (humidity >= 60.0) {
        Serial.println("🟡 RGB LED: Yellow (60% - 70%)");
        setRGBLED(255, 255, 0);
    } else if (humidity >= 50.0) {
        Serial.println("🟢 RGB LED: Green (50% - 60%)");
        setRGBLED(0, 255, 0);
    } else if (humidity >= 40.0) {
        Serial.println("🔵 RGB LED: Blue (40% - 50%)");
        setRGBLED(0, 0, 255);
    } else {
        Serial.println("⚪ RGB LED: White (30% - 40%)");
        setRGBLED(255, 255, 255);
    }
}

void controlBuzzer(float humidity) {
    if (humidity >= HUMIDITY_THRESHOLD) {
        Serial.println("🚨 Buzzer activated!");
        digitalWrite(BUZZER_PIN, HIGH);
        delay(500);
        digitalWrite(BUZZER_PIN, LOW);
    } else {
        Serial.println("🔇 Buzzer off");
    }
}

void setRGBLED(int r, int g, int b) {
    analogWrite(RED_PIN, r);
    analogWrite(GREEN_PIN, g);
    analogWrite(BLUE_PIN, b);
}