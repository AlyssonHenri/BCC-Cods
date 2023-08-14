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
                    funcao = input("Digite a equação: ")  # Entrada da equação
                    funcao = ajustar_func(funcao)
                    start = float(input("Digite o ponto [x , _]: "))  # Inicio do intervalo [x,y]
                    fim = float(input("Digite o ponto [_ , x]: "))  # Fim do intervalo [x,y]
                    precisao = float(input("Digite o valor de precisão: "))  # Valor de parada do algoritmo

                    print("x-------------------------------------------------------------------------------------x")
                    print("|{:<15} | {:<20} | {:<25} | {:<15} |".format("Iteração", "X", "f(x)", "b - a"))
                    print("|-------------------------------------------------------------------------------------|")

                    a = start
                    b = fim
                    fA = f(a, funcao)
                    fB = f(b, funcao)
                    itera = 0

                    if fA * fB > 0:
                        raise Exception('Erro - Impossivel realizar metodo!')

                    while b - a > precisao:
                        itera += 1
                        x = (a + b) / 2.0
                        y = f(x, funcao)

                        if y * fA > 0:
                            a = x
                        else:
                            b = x

                        # Faz formatação dos numeros positivos para deixar a tabela uniforme
                        y_form = " " + str(y) if y >= 0 else str(y)
                        print("|{:<15} | {:<20} | {:<25} | {:<15} |".format(itera, x, y_form, b - a))
                    print("x-------------------------------------------------------------------------------------x")

                    retn_menu = int(input("\n\nPressione 0 para retornar ao menu\n"))

            case 3:
                limpa_terminal()
                print("\nObrigado por utilizar!")
                retn_menu = 3

            case _ :
                # Case padrão para caso entre algum valor diferente, esse texto nunca deve aparecer, se está aparecendo algo de errado aconteceu
                print("\nValor de entrada inválido!")

MainLoop()
