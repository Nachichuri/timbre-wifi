#include <UniversalTelegramBot.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#define analogPin A0
#define BOT_TOKEN "1234567890:suCHaComPleXtOKen!" // API token que te da el BotFather
#define CHAT_ID "123456789" // Telegram Chat ID

char ssid[] = "SSID";
char password[] = "passw0rd!";
String ipAddress = "";

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Nos conectamos al waifi
  Serial.print("Conectando a red: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  ipAddress = ip.toString();
  client.setInsecure();
}

void sendTelegramMessage() {
  bot.sendMessage(CHAT_ID, "¡Creo que hay alguien en la puerta!");
}

void loop() {
  if (analogRead(analogPin) > 200) {
    Serial.println("Timbre presionado");
    sendTelegramMessage();
  }
  yield();
}
