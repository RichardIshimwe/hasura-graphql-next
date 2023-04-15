#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

char ssid[] = "Joseph";         // your network SSID (name)
char password[] = "Jeph12345."; // your network key
WiFiClientSecure client;

// Just the base of the URL you want to connect to
#define TEST_HOST "api.hackaday.io"

// OPTIONAL - The finferprint of the site you want to connect to.
#define TEST_HOST_FINGERPRINT "58 A3 A3 03 58 4F 70 C4 F0 EC 79 7A 09 8B 92 D9 24 20 98 7D"
// The finger print will change every few months.

void setup()
{

  Serial.begin(115200);

  // Connect to the WiFI
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  client.setInsecure();

  makeHTTPRequest();
}

void makeHTTPRequest()
{

  // Opening connection to server (Use 80 as port if HTTP)
  if (!client.connect(TEST_HOST, 443))
  {
    Serial.println(F("Connection failed"));
    return;
  }

  // give the esp a breather
  yield();

  // Send HTTP request
  client.print(F("GET "));
  // This is the second half of a request (everything that comes after the base URL)
  client.print("/v1/projects/1340?api_key=lmrATMMYtm4PR6rs"); // %2C == ,

  client.println(F(" HTTP/1.0"));

  //Headers
  client.print(F("Host: "));
  client.println(TEST_HOST);

  client.println(F("Cache-Control: no-cache"));

  if (client.println() == 0)
  {
    Serial.println(F("Failed to send request"));
    return;
  }

  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));

  while (client.available())
{
  Serial.write(client.read());
}

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders))
  {
    Serial.println(F("Invalid response"));
    return;
  }

  while (client.available() && client.peek() != '{' && client.peek() != '[')
  {
    char c = 0;
    client.readBytes(&c, 1);
    Serial.print(c);
    Serial.println("BAD");
  }

  while (client.available())
{
  char c = 0;
  client.readBytes(&c, 1);
  Serial.print(c);
}

}

void loop()
{
  // put your main code here, to run repeatedly:
}
