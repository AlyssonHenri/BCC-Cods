import socket

host = 'localhost'
porta = 5015

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((host, porta))

nome = input("Insira seu nome de usuario: ")
client.send(nome.encode('utf-8'))

while True:
    numero = input("Insira um numero: ")

    client.send(numero.encode('utf-8'))
    num_retorn = client.recv(1024).decode('utf-8')
    print(num_retorn)
    
    if numero.isdigit():
        pass
    else:
        break

