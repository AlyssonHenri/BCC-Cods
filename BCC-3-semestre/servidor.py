import socket
import threading
import random

numero_server = (random.randint(1,100))

print(numero_server)

ip = 'localhost'
porta = 5015

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((ip, porta))

server.listen(5)

print('[*] Escutando %s:%d' % (ip, porta))


def handle_client(client_socket):
    client_socket.send(b'Qual seu nome?\n')

    request = client_socket.recv(1024)

    print(f'[*] Nome do client: {nome}')

    numero_client = client_socket.recv(1024)
    
    numero_retorno = int(numero_client) + numero_server

    client_socket.send(str(numero_retorno).encode())

    client_socket.close()




while True:
    client, addr = server.accept()
    print('[*] Conecção aceita de: %s:%d' % (addr[0], addr[1]))
    client_handler = threading.Thread(target=handle_client, args=(client,))
    client_handler.start()

