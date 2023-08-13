import socket

target_host = 'localhost'
target_port = 5015

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((target_host, target_port))

response01 = client.recv(4096)
print(response01.decode())

client.send('Neyzinho:13'.encode())

response02 = client.recv(4096)
print(f'Número de retorno: {response02.decode()}')