#include <WiFi.h>

const char* ssid = ""; //aquí se pone el ssid
const char* password = ""; //aquí va la contraseña
const char* host = ""; //es necesario ingresar el host, sea por default o uno propio
const int puerto = 80; // Puerto HTTP

void setup() {
  Serial.begin(115200);
  delay(10);

  // Conexión con el Wi-Fi
  Serial.println();
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conectado a la red Wi-Fi");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Generar datos aleatorios (esto es una simulación)
  int dato = random(0, 100);

  // Enviar datos
  Serial.print("Conectando a ");
  Serial.println(host);

  // Usar una conexión TCP
  WiFiClient client;
  if (!client.connect(host, puerto)) {
    Serial.println("Falla de conexión");
    return;
  }

  // Solicitud HTTP
  String url = "/receive_data?dato=" + String(dato);
  Serial.print("URL: ");
  Serial.println(url);

  // Enviar la solicitud HTTP al servidor
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  // Esperando la respuesta del servidor
  while (client.connected()) {
    if (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  }

  Serial.println();
  Serial.println("Cerrando conexión");
  client.stop();

  // Esperar antes de enviar más datos
  delay(5000);
}
