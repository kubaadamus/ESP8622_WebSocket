#include <ESP8266WiFi.h>
#include <WebSocketClient.h>
String a="";
const char* ssid     = "Domek";
const char* password = "kubaadamus345aja1991";
char path[] = "/";
char host[] = "206.189.207.171";
  
WebSocketClient webSocketClient;

// Use WiFiClient class to create TCP connections
WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
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

  delay(2000);
  

  // Connect to the websocket server
  Serial.println("Connecting to  at port 80");
  if (client.connect("206.189.207.171", 80)) {
    Serial.println("Connected");
  } else {
    Serial.println("Connection failed.");
    while(1) {
      // Hang on failure
    }
  }

  // Handshake with the server
  webSocketClient.path = path;
  webSocketClient.host = host;
  if (webSocketClient.handshake(client)) {
    Serial.println("Handshake successful");
  } else {
    Serial.println("Handshake failed.");
    Serial.println(webSocketClient.handshake(client));
    while(1) {
      // Hang on failure
    }  
  }

}


void loop() {
  String data;

  if (client.connected()) {
    
    webSocketClient.getData(data);
    if (data.length() > 0) {
      Serial.print("Received data: ");
      Serial.println(data);
      Serial.print("czas odbioru: ");Serial.println(millis());
    }
    
    // capture the value of analog 1, send it alon
    //pinMode(1, INPUT);
    //data = String(analogRead(1));;
    
    a = String(millis())+ " 0123456789012345678901234567780";
    Serial.print("czas wysyłki: ");Serial.println(millis());
    webSocketClient.sendData(a);
    
    
  } else {
    Serial.println("Client disconnected.");
    while (1) {
      // Hang on disconnect.
    }
  }
  
  // wait to fully let the client disconnect
  delay(1000);
  
}
