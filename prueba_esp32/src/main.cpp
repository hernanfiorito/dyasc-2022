#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>


const char* ssid = "CAPPONI";
const char* password = "clau1963";
int led_amarillo = 13;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(led_amarillo, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected.");
  


  HTTPClient http;
  
 

  http.begin("https://api.travis-ci.org/repos/capponi/dyasc-2020/builds");
  int httpCode = http.GET();
  Serial.println(httpCode);

  String payload = http.getString();
  Serial.println(payload);
  
  Serial.println("\n------------------------------------\n");
  JSONVar myObject = JSON.parse(payload);


  JSONVar build = myObject[0];
  Serial.println(build);
  
  Serial.print("Estado");
  Serial.print(" = ");
  JSONVar state = build["state"];
  Serial.println(state);
  Serial.print("Resultado");
  Serial.print(" = ");
  JSONVar result = build["result"];
  Serial.println(result);

  
  http.end();
}

void loop() {
  digitalWrite(led_amarillo, HIGH);
  delay(2000);
  digitalWrite(led_amarillo, LOW);
  delay(1000);

}