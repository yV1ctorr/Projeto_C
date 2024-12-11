#include <stdio.h>
#include <string.h>
int main() {
    typedef struct{
        char nome[20];
        int quantidade;
        float preco;
    } Remedio;

    Remedio remedio1 = {
        
        6,
        2.20
    };

    printf("O primeiro remedio é: %s\n", remedio1);

    return 0;
}