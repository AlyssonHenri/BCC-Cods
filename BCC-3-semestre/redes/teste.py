# SERVIDOR
import socket
import random

HOST = 'localhost'
PORT = 9090

soquete = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

soquete.bind((HOST, PORT))

nome_servidor = input('Digite o nome do servidor: ')
print(f'Servidor {nome_servidor} iniciado')

while True:
    soquete.listen()

    conexao, endereco_cliente = soquete.accept()

    data = conexao.recv(1024)
    mensagem = data.decode()

    nome_cliente, numero_cliente = mensagem.split(':')

    print(f'{nome_cliente} se conectou ao servidor {nome_servidor}')

    if int(numero_cliente) < 1 or int(numero_cliente) > 100:
        print('Valor inválido recebido, encerrando o servidor')
        soquete.close()
        break

    numero_servidor = random.randint(1, 100)
    print(f'Número do cliente: {numero_cliente}\nNúmero do servidor: {numero_servidor}')

    soma = int(numero_cliente) + numero_servidor
    resposta = nome_servidor + ':' + str(numero_servidor)

    conexao.sendall(resposta.encode())

    conexao.close()