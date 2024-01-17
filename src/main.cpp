#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Coloque as credenciais da sua rede
const char *ssid = "Coloque_o_nome_aqui";
const char *password = "coloque_a_password_aqui";
// Cria o objecto AsyncWebServer na porta 80
AsyncWebServer server(80);
// Código Web
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
 <title>ESP Web Server</title>
 <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
 <style>
 html {
 font-family: Arial;
 text-align: center;
 }
 body {
 max-width: 400px;
 margin:0px auto;
 }
 </style>
</head>
<body>
 <h1>Hello World!</h1>
</body>
</html>
)rawliteral";
void initWiFi()
{
  // Conexão Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}
void setup()
{
  //Porta serial para debugging
  Serial.begin(115200);
  initWiFi();
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/html", index_html); });
  // Inicia o servidor
  server.begin();
}
void loop()
{
  // Coloque seu code principal aqui, irá rodar repetidamente
}