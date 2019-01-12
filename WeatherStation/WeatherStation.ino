#include <ESP8266WiFi.h>
const char* ssid = "mycci9E";
const char* password = "clevergadfly385";
const char* host = " Gill ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  Serial.print("connecting to ");
  Serial.println(host);
  //Wifi client class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println(" Failure to connect ");

    return;

  }

  // creating URI for the request
  String url = "/guide/";
  Serial.print("Requesting URL: ");
  Serial.println(url);

  // Sending request to server,


  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  unsigned long timeout = millis();

  while (client.available() == 0) {
    if (millis() - timeout > 5000){
        Serial.println(">>> Client Timeout !"); 
        client.stop();
        return;
      }

    }

  // read all lines from server and print them in Serial 
  while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
    
    }







}
