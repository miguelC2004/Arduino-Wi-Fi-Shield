# Arduino-Wi-Fi-Shield

Este proyecto permite la conexión de un Arduino a Internet utilizando un módulo Wi-Fi. Se envían datos simulados desde el Arduino a una aplicación de Python, que actúa como servidor en la PC.

## Contenido del Repositorio

- **`wifi_data_sender.ino`**: Código para el Arduino que se encarga de la conexión Wi-Fi y envía datos al servidor.
- **`data_receiver.py`**: Script de Python que actúa como servidor, recibiendo y mostrando los datos del Arduino.

## Configuración

### Arduino
1. Abrir `wifi_data_sender.ino` en el entorno de desarrollo Arduino.
2. Reemplazar `TU_SSID_WIFI`, `TU_CONTRASEÑA_WIFI`, e `IP_O_URL_DESTINO` con la propia información de red Wi-Fi y dirección del servidor.
3. Cargar el código en tu placa Arduino.

### Python
1. Abrir una terminal en la carpeta del proyecto.
2. Ejecutar `pip install pyserial` para instalar la biblioteca pyserial.
3. Ejecutar `python data_receiver.py` para iniciar el servidor Python.

## Funcionamiento

1. El Arduino se conecta a la red Wi-Fi y envía datos simulados al servidor a través de una conexión TCP.
2. El servidor Python escucha en el puerto 80 y muestra los datos recibidos del Arduino.

## Notas

- Este proyecto utiliza una conexión TCP simple y una solicitud HTTP básica para la comunicación.
- Asegúrate de tener la biblioteca `WiFi.h` instalada en tu entorno de desarrollo Arduino.

## Referencias

- [Documentación de Arduino](https://www.arduino.cc/en/Reference/HomePage)
- [Python Socket Programming](https://docs.python.org/3/library/socket.html)

---
