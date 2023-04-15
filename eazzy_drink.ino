#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Joseph";
const char* password = "Jeph12345.";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("connecting to wifi....");
  }
  Serial.println("connected to wifi");
}

void loop() {
  // put your main code here, to run repeatedly:
//if(WiFi.status() == WL_CONNECTED){
//  HTTPClient http;
//  http.begin("https://rich-puce-barnacle-gear.cyclic.app");
////  http.begin("https://puce-helpful-xerus.cyclic.app/");
//  int httpCode = http.GET();
//  Serial.print("this is httpCode"+httpCode);
//  if(httpCode == HTTP_CODE_OK){
//    String payload = http.getString();
//    Serial.print("ok");
//    Serial.println(payload);
//  }else {
//    Serial.println("Error: " + httpCode);
//  }
//  http.end();
//}
//  delay(1000);
};
