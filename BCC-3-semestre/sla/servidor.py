import socket
import threading

numero_server = 13

ip = 'localhost'
porta = 5015

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((ip, porta))

server.listen(5)

print('[*] Escutando %s:%d' % (ip, porta))


def handle_client(client_socket):
    nome = client_socket.recv(1024)

    print(f'[*] Nome do client: {nome.decode("utf-8")}')

    while True:
        numero_client = client_socket.recv(1024)
        
        if numero_client.isdigit():
            numero_retorno = int(numero_client) + numero_server
            client_socket.send(str(numero_retorno).encode())
        else:
            client_socket.close()
            break
    

while True:
    client, addr = server.accept()
    print('[*] Conecção aceita de: %s:%d' % (addr[0], addr[1]))
    client_handler = threading.Thread(target=handle_client, args=(client,))
    client_handler.start()
