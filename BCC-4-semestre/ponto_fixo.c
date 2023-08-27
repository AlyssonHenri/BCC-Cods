#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define TAMANHO_PILHA 100


typedef struct {
    double dados[TAMANHO_PILHA];
    int topo;
} Pilha;

typedef struct {
    char op; // Operador ('+', '-', '*', '/', '^', 'x', '(' ou ')')
    double num; // Valor do número, se op == 'n'
} Token;

void pilha_inicializa(Pilha *p) {
    p->topo = -1;
}

void pilha_empilha(Pilha *p, double valor) {
    if (p->topo < TAMANHO_PILHA - 1) {
        p->topo++;
        p->dados[p->topo] = valor;
    } else {
        printf("Erro: Pilha cheia.\n");
    }
}

double pilha_desempilha(Pilha *p) {
    if (p->topo >= 0) {
        double valor = p->dados[p->topo];
        p->topo--;
        return valor;
    } else {
        printf("Erro: Pilha vazia.\n");
        return 0.0;
    }
}

Token tokeniza(const char *expr, int *i) {
    Token token;
    char *endptr;

    if (expr[*i] >= '0' && expr[*i] <= '9') {
        token.op = 'n'; // 'n' indica um número
        token.num = strtod(expr + *i, &endptr);
        *i = endptr - expr; // Atualiza i para o próximo caractere após o número
    } else if (expr[*i] == '(' || expr[*i] == ')') {
        token.op = expr[*i];
        (*i)++;
    } else {
        token.op = expr[*i];
        (*i)++;
    }

    return token;
}

int precedencia(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

double calcula_expressao(const char *expr, double x) {
    Pilha pilha_operadores;
    Pilha pilha_valores;
    pilha_inicializa(&pilha_operadores);
    pilha_inicializa(&pilha_valores);

    int i = 0;
    while (expr[i] != '\0') {
        if (expr[i] == ' ') {
            i++;
            continue;
        }
        if (expr[i] >= '0' && expr[i] <= '9') {
            Token token = tokeniza(expr, &i);
            pilha_empilha(&pilha_valores, token.num);
        } else if (expr[i] == 'x') {
            pilha_empilha(&pilha_valores, x);
            i++;
        } else if (expr[i] == '(') {
            pilha_empilha(&pilha_operadores, '(');
            i++;
        } else if (expr[i] == ')') {
            while (pilha_operadores.topo >= 0 && pilha_operadores.dados[pilha_operadores.topo] != '(') {
                char op = pilha_operadores.dados[pilha_operadores.topo];
                pilha_desempilha(&pilha_operadores);
                
                double b = pilha_desempilha(&pilha_valores);
                double a = pilha_desempilha(&pilha_valores);
                double resultado;
                if (op == '+') resultado = a + b;
                else if (op == '-') resultado = a - b;
                else if (op == '*') resultado = a * b;
                else if (op == '/') resultado = a / b;
                else if (op == '^') resultado = pow(a, b);
                pilha_empilha(&pilha_valores, resultado);
            }
            if (pilha_operadores.topo >= 0 && pilha_operadores.dados[pilha_operadores.topo] == '(') {
                pilha_desempilha(&pilha_operadores); // Desempilha o '('
            }
            i++;
        } else {
            while (pilha_operadores.topo >= 0 && precedencia(pilha_operadores.dados[pilha_operadores.topo]) >= precedencia(expr[i])) {
                char op = pilha_operadores.dados[pilha_operadores.topo];
                pilha_desempilha(&pilha_operadores);
                
                double b = pilha_desempilha(&pilha_valores);
                double a = pilha_desempilha(&pilha_valores);
                double resultado;
                if (op == '+') resultado = a + b;
                else if (op == '-') resultado = a - b;
                else if (op == '*') resultado = a * b;
                else if (op == '/') resultado = a / b;
                else if (op == '^') resultado = pow(a, b);
                pilha_empilha(&pilha_valores, resultado);
            }
            pilha_empilha(&pilha_operadores, expr[i]);
            i++;
        }
    }

    while (pilha_operadores.topo >= 0) {
        char op = pilha_operadores.dados[pilha_operadores.topo];
        pilha_desempilha(&pilha_operadores);
        
        double b = pilha_desempilha(&pilha_valores);
        double a = pilha_desempilha(&pilha_valores);
        double resultado;
        if (op == '+') resultado = a + b;
        else if (op == '-') resultado = a - b;
        else if (op == '*') resultado = a * b;
        else if (op == '/') resultado = a / b;
        else if (op == '^') resultado = pow(a, b);
        pilha_empilha(&pilha_valores, resultado);
    }

    return pilha_desempilha(&pilha_valores);
}

void limpa_terminal() {
    system(CLEAR_SCREEN);
}

void LoopPrincipal() {
    int retn_menu = 0;
    while (retn_menu != 3) {
        limpa_terminal();
        int selecao;
        printf("----------------------------\n"
               "| 1 -> Como usar           |\n"
               "| 2 -> Calcular            |\n"
               "| 3 -> Fechar Programa     |\n"
               "----------------------------\n");
        scanf("%d", &selecao);

        switch (selecao) {
            case 1:
                retn_menu = 1;
                limpa_terminal();
                while (retn_menu != 0) {
                    retn_menu = 0;

                    printf("Insira as equacaoes sempre separando numeros e operadores por espaco nesse formato -> x * x + x\n\n");
                    printf("\nEm equacoes mais complexas utilize parenteses () para indicar a ordem das operacoes.\n");
                    printf("\nExemplo -> ((x ^ 3) / 9) + (1 / 3)");

                    printf("\n\nDigite 0 para retornar ao menu\n");
                    scanf("%d", &retn_menu);
                }
                break;

            case 2:
                retn_menu = 1;
                while (retn_menu != 0) {
                    limpa_terminal();

                    // Limpar o buffer de entrada
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);

                    // Entrada de Dados
                    char funcao[1000];
                    printf("Digite a equacao: ");
                    fgets(funcao, sizeof(funcao), stdin);
                    funcao[strcspn(funcao, "\n")] = '\0'; // Remover nova linha

                    char funcao_gx[1000];
                    printf("Digite a equacao iterada: ");
                    fgets(funcao_gx, sizeof(funcao_gx), stdin);
                    funcao_gx[strcspn(funcao_gx, "\n")] = '\0'; // Remover nova linha

                    double x0;
                    printf("Digite o valor de x0: ");
                    scanf("%lf", &x0);

                    double precisao;
                    printf("Insira o valor de precisao: ");
                    scanf("%lf", &precisao);

                    printf("x---------------------------------------x\n");
                    printf("|%-15s | %-15s |\n", "Iteracao", "x");
                    printf("|---------------------------------------|\n");

                    // Implementacao do método do ponto fixo
                    double x_antigo = x0;
                    double x_novo = calcula_expressao(funcao_gx, x_antigo);
                    int itera = 1;

                    while (fabs(calcula_expressao(funcao, x_antigo)) > precisao) {
                        printf("|%-15d | %-15lf |\n", itera, x_novo);
                        itera++;
                        x_antigo = x_novo;
                        x_novo = calcula_expressao(funcao_gx, x_antigo);
                    }

                    printf("x---------------------------------------x\n");

                    printf("\n\nDigite 0 para retornar ao menu\n");
                    scanf("%d", &retn_menu);
                }
                break;

            case 3:
                limpa_terminal();
                printf("\nObrigado por usar o programa\n");
                retn_menu = 3;
                break;

            default:
                printf("\nValor de entrada inválido!\n");
                break;
        }
    }
}

int main() {
    LoopPrincipal();
    return 0;
}
