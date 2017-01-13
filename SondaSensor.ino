// Name
#define NAME "SensorDataCenter1Rack3"

// wifi
const char* ssid = "wifiNacho";
const char* password = "hamlet4225";

#include "pins_arduino.h"
#include "setup_th.h"
#include "setup_timer.h"
#include "setup_interaction.h"
#include "setup_wifi.h"

unsigned long previousMillis = 0;
const long interval = 1000; // 1000 = 1 sec

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  // DS3231 seconds, minutes, hours, day, date, month, year
  //setDS3231time(0,44,18,7,7,1,17);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    onLedWifi();
    onLedStatus();
  }
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    if (buttonStatus())
    {
      if (WiFi.status() == WL_CONNECTED) {
        onLedWifi();
      }
      onLedStatus();
    } else {
      offLedWifi();
      offLedStatus();
    }
    sendData(NAME, printHumidity(), printTemperature(), printTime());
  }

}

