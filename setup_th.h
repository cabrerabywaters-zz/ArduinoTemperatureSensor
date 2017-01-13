#include "Adafruit_Sensor.h"
#include "DHT.h"
#include "DHT_U.h"

#define DHTPIN D4

#define DHTTYPE DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

float printTemperature()
{

  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    return -999;
  }
  else {
    return event.temperature;
  }
}

float printHumidity()
{
  sensors_event_t event;
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    return -999;
  }
  else {
    return event.temperature;
  }
}
