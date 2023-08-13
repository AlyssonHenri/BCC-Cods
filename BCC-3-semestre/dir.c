#include <stdio.h>
#include <dirent.h>
#include <windows.h>
#include <locale.h>
#include <sys/stat.h>

int main()
{
    setlocale(LC_ALL, "");
    char dir[900];
    scanf("%s",dir);
    struct stat statusArquiv;

    //CONFIG CORES
    HANDLE configCor;
    int cor;
    configCor = GetStdHandle(STD_OUTPUT_HANDLE);
    //CONFIG CORES

    //CONFIG LIB_ARQUIVOS
    DIR *diretorio;
    struct dirent *arquivo;
    diretorio = opendir(dir);
    //CONFIG LIB_ARQUIVOS

    if (diretorio == NULL)
    {
        printf("Um erro ocorreu ao abrir o diretorio.\n");
        return 1;
    }
    
    while ((arquivo = readdir(diretorio)) != NULL)
    {   
        stat(arquivo->d_name, &statusArquiv);   
        //Arquivos Normais
        if (arquivo->d_type == DT_REG)
        {
            char * texto = strtok(arquivo->d_name,".");
            cor = 10;
            while (texto != NULL)
            {    
                if(cor==15)
                {
                    SetConsoleTextAttribute(configCor, 11);
                    printf(".");
                }
                SetConsoleTextAttribute(configCor, cor);
                printf("%s", texto);
                cor += 5;
                texto = strtok(NULL, ".");
            }
            SetConsoleTextAttribute(configCor, 15);
            printf("->");
            SetConsoleTextAttribute(configCor, 8);
            printf("%ld\n", statusArquiv.st_size);
        }

        //Pastas
        else if (arquivo->d_type == DT_DIR)
        {
            SetConsoleTextAttribute(configCor, 9);
            printf("%s", arquivo->d_name);
            SetConsoleTextAttribute(configCor, 11);
            printf("/");

            SetConsoleTextAttribute(configCor, 15);
            printf("->");
            SetConsoleTextAttribute(configCor, 8);
            printf("%ld\n", statusArquiv.st_size);
        }
    }
    SetConsoleTextAttribute(configCor, 15);

    system("pause"); 
    return 0;
}
