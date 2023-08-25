import os
import math

def limpa_terminal():
    if os.name == 'posix':
        os.system('clear')  # Para Linux e macOS
    else:
        os.system('cls')    # Para Windows

def func_calc(x, funcao):
    return eval(funcao)

def ajustar_func(funcao):
    funcao = funcao.replace("cos(", "math.cos(")
    funcao = funcao.replace("sen(", "math.sin(")
    funcao = funcao.replace("sqrt(", "math.sqrt(")
    funcao = funcao.replace("log(", "math.log(")
    funcao = funcao.replace("e", str(math.e))
    return funcao

def MainLoop():
    retn_menu = 0
    while retn_menu != 3:
        limpa_terminal()
        selecao = int(input("----------------------------\n"
                            "| 1 -> Como usar           |\n"
                            "| 2 -> Calcular            |\n"
                            "| 3 -> Fechar Programa     |\n"
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
                retn_menu = 1
                while retn_menu != 0:
                    limpa_terminal()

                    # Inputs
                    funcao = input("Digite a equação: ")
                    funcao = ajustar_func(funcao)

                    funcao_gx = input("Digite a equação iterada: ")
                    funcao_gx = ajustar_func(funcao_gx)
                    gx = lambda x: func_calc(x, funcao_gx)

                    x0 = float(input("Digite o valor de x0: "))
                    precisao = float(input("Insira o valor de precisão: "))

                    print("x-------------------------------------------------------------x")
                    print("|{:<15} | {:<20} |".format("Iteração", "X"))
                    print("|-------------------------------------------------------------|")

                    # Implementação do metodo do ponto fixo
                    x_antigo = x0
                    x_novo = func_calc(x_antigo,funcao_gx)
                    itera = 0

                    while abs(x_novo - x_antigo) >= precisao:
                        itera += 1
                        x_antigo = x_novo
                        x_novo = func_calc(x_antigo,funcao_gx)
                        print("|{:<15} | {:<20} |".format(itera, x_novo))




                    print("x-------------------------------------------------------------x")
                    #print(f"Raiz aproximada encontrada: {raiz_aproximada}")

                    retn_menu = int(input("\n\nDigite 0 para retornar ao menu\n"))

            case 3:
                limpa_terminal()
                print("\nObrigado por usar o programa")
                retn_menu = 3

            case _ :
                # Case padrão para caso entre algum valor diferente, esse texto nunca deve aparecer, se está aparecendo algo de errado aconteceu
                print("\nValor de entrada inválido!")

MainLoop()
