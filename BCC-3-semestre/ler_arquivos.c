#include <stdio.h>
#include <dirent.h>
#include <windows.h>

int main()
{
    //CONFIG CORES
    HANDLE configCor;
    int cor;
    configCor = GetStdHandle(STD_OUTPUT_HANDLE);
    //CONFIG CORES

    //CONFIG LIB_ARQUIVOS
    DIR *diretorio;
    struct dirent *arquivo;
    diretorio = opendir("./");
    //CONFIG LIB_ARQUIVOS

    if (diretorio == NULL)
    {
        printf("Um erro ocorreu ao abrir o diretorio.\n");
        return 1;
    }
    
    while ((arquivo = readdir(diretorio)) != NULL)
    {
        if (arquivo->d_type == DT_REG)
        {
            cor = 8;
            SetConsoleTextAttribute(configCor, cor);
            printf("%s", arquivo->d_name);
            cor = 15;
            SetConsoleTextAttribute(configCor, cor);
            printf("*\n");
        }
        else if (arquivo->d_type == DT_DIR)
        {
            cor = 8;
            SetConsoleTextAttribute(configCor, cor);
            printf("%s", arquivo->d_name);
            cor = 15;
            SetConsoleTextAttribute(configCor, cor);
            printf("/\n");
        }
    }

    system("pause"); 
    return 0;
}