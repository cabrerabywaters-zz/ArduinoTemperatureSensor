#include "ESP8266WiFi.h"

// Test
void sendData(String nameArduino, float humidity, float temperature, String currentTime )
{
  const char* host = "data.sparkfun.com";
  const char* streamId   = "g6Q5bAZnpqur9DYr1gQq";
  const char* privateKey = "qzwqlZG17Ycbz5pbDea4";

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  String url = "/input/";
  url += streamId;
  url += "?private_key=";
  url += privateKey;
  url += "&humidity=";
  url += humidity;
  url += "&name=";
  url += nameArduino;
  url += "&temperature=";
  url += temperature;
  url += "&time=";
  url += currentTime;
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      client.stop();
      return;
    }
  }
}