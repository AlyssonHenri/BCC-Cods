#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char* arquivo = "test.c";
    struct stat statusArquiv;
    time_t ultimo_mod = 0;

    while (1) {
        if (stat(arquivo, &statusArquiv) == 0) {
            if (ultimo_mod == 0) {
                ultimo_mod = statusArquiv.st_mtime;
            } else if (statusArquiv.st_mtime != ultimo_mod) 
            {
                system("gcc test.c -o test.exe");
                ultimo_mod = statusArquiv.st_mtime;
            }
        } else {
            printf("arquivo inexistente\n");
            break;
        }
    }

    return 0;
}
