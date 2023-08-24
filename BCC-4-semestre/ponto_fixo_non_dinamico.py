import os
import math

def limpa_terminal():
    if os.name == 'posix':
        os.system('clear')  # Para Linux e macOS
    else:
        os.system('cls')    # Para Windows

# Definir a função
def f(x, funcao):
    return eval(funcao)

# Lista com muitas variações de possiveis g(x), o codigo itera por todas elas até uma convergir ao resultado
# Há sempre possibilidade de nenhuma convergir, nesse caso é necessário adicionar ainda mais funçoes
# O desafio é como gerar uma tabela dessas para cada input diferente
gx_funçoes_possiveis = [
    lambda x: 1/math.sqrt(1+x),
    lambda x: math.log(x + 4),
    lambda x: (x**3 + 3) / 9,
    lambda x: math.exp(-x/3),
    lambda x: (x**3 + 9) / 9,
    lambda x: 3 / (x**2 - 9),
    lambda x: (x**3 - 3) / 9,
    lambda x: math.sin(x) + 3,
    lambda x: math.cos(x) + 3,
    lambda x: math.atan(x) + 3,
    lambda x: 3 / math.sqrt(9 - x) if 9 - x >= 0 else x,
    lambda x: math.pow(9 - x, 1/3),
    lambda x: math.pow(9 - 3*x, 1/3),
]


# Permite usar sen, cos, e, raiz, log na equação
def ajustar_func(funcao):
    funcao = funcao.replace("cos(", "math.cos(")
    funcao = funcao.replace("sen(", "math.sin(")
    funcao = funcao.replace("sqrt(", "math.sqrt(")
    funcao = funcao.replace("log(", "math.log(")
    funcao = funcao.replace("e", str(math.e))
    
    return funcao

def MainLoop():
    retn_menu = 0  # Inicialize retn_menu aqui
    while retn_menu != 3:
        limpa_terminal()
        selecao = int(input("----------------------------\n"
                            "| 1 -> Como usar           |\n"
                            "| 2 -> Calcular            |\n"
                            "| 3 -> Finalizar programa  |\n"
                            "----------------------------\n"))

        match selecao: 
            case 1:
                retn_menu = 1  # Reinicialize retn_menu aqui
                limpa_terminal()
                while retn_menu != 0:
                    retn_menu = int(input("Ao selecionar a opção de calcular no menu inicial você sera requisitada(o) a inserir uma equação\n"
                        "dentro deste programa as equações são construidas no seguinte formato\n\n"
                        "-> x**3 Representa um valor de x elevado a um numero, neste caso x elevado a 3.\n"
                        "-> 3*x  Representa uma multiplicação.\n"
                        "-> sqrt(x)  Representa uma raiz.\n"
                        "-> cos(x)  Representa o cosseno de x.\n"
                        "-> sen(x)  Representa o seno de x.\n"
                        "-> log(x)  Representa o logaritmo natural de x.\n"
                        "-> e  Representa o número de Euler.\n\n"
                        "Aqui estão alguns exemplos de como formatar sua entrada:\n"
                        "  x**3 - 9*x + 3\n\n"
                        "  (x+2) * (x+1)*x * (x-1)**3 * (x-2)\n\n"
                        "  x * cos(x) -2*x**2 +3*x -1\n\n"
                        "  x**2 -5 * sen(x) * e**2\n\n"
                        "  cos(x) - sqrt(x)\n\n"
                        "  log(x) - 2\n\n"
                        "Pressione 0 para retornar ao menu\n"))

            case 2:
                retn_menu = 1  # Reinicialize retn_menu aqui
                while retn_menu != 0:
                    limpa_terminal()
                    
                    # Input Section
                    funcao = input("Digite a equação: ")  # Entrada da equação
                    funcao = ajustar_func(funcao)
                    x0 = float(input('Digite o valor de x0: '))
                    precisao = float(input("Digite o valor de precisão: "))  # Valor de parada do algoritmo

                    # Implementação do metodo de ponto fixo
                    def metodo_ponto_fixo(g, x0, precisao):
                        x_antigo = x0
                        x_novo = g(x_antigo)  # Initialize x_novo before the loop
                        while abs(x_novo - x_antigo) >= precisao:
                            x_antigo = x_novo
                            x_novo = g(x_antigo)

                            if x_novo == precisao * 1.5:
                                break

                        return x_novo  # Retorna o valor mais próximo mesmo se a convergência não foi alcançada

                    raizes_aproximadas = []

                    # Acumula todos os valores produzidos dentro da lista
                    for g in gx_funçoes_possiveis:
                        raiz = metodo_ponto_fixo(g, x0, precisao)
                        raizes_aproximadas.append(raiz)

                    # Verifica o resultado de todos os g(x) e extrai o mais proximo da proximo
                    # key=lambda r: abs(r - x0) é usado para que o min selecione aquele com a menor distancia não o menor numero
                    raiz_mais_proxima = min(raizes_aproximadas, key=lambda r: abs(r - x0))
                    print(f"Raiz aproximada encontrada: {raiz_mais_proxima}")

                    retn_menu = int(input("\n\nPressione 0 para retornar ao menu\n"))

            case 3:
                limpa_terminal()
                print("\nObrigado por utilizar!")
                retn_menu = 3

            case _ :
                # Case padrão para caso entre algum valor diferente, esse texto nunca deve aparecer, se está aparecendo algo de errado aconteceu
                print("\nValor de entrada inválido!")

MainLoop()