#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Firebase.h> 

#define FIREBASE_HOST "https://console.firebase.google.com/project/smart-greenhouse-f56d5/database/smart-greenhouse-f56d5-default-rtdb/data/~2F"
#define FIREBASE_AUTH "AIzaSyCskwg8-Fm8UwQ2-kW23huGs7YLKbSRQNs"
#define DHTPIN 2     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT22    

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}
