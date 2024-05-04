import socket

# Configuración del servidor

HOST = '0.0.0.0'  # Todas las interfaces disponibles
PUERTO = 80  # Puerto HTTP

# Inicio del servidor
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PUERTO))
    s.listen()
    print(f"SRecibiendo en {HOST}:{PUERTO}")


    conn, addr = s.accept()
    with conn:
        print(f"Conexión establecida desde {addr}")
        while True:
            
            data = conn.recv(1024)
            if not data:
                break
            # Datos recibidos
            print(f"Datos recibidos: {data.decode()}")
