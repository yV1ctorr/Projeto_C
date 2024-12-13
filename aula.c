#include <stdio.h>
#include <string.h>

// Definindo a estrutura
typedef struct {
    int id;
    int quantidade;
    char nome[20];
    char descricao[50];
    char fabricante[20];
    float valor;

}Remedio;

int indice = 0;
int *PtrIndex = &indice;
Remedio remedios[10];
Remedio *PtrRemedio = remedios;


// Função para adicionar um novo remedio
void cadastrarProduto(Remedio *PtrRemedio, int *PtrIndex) {
    
    printf("\nDigite um ID para o remedio: ");
    scanf("%d", &PtrRemedio[*PtrIndex].id);
    fflush(stdin);  //para limpar o buffer depois de cada scanf e evitar alguns erros de leitura
    
    printf("Digite o nome do remedio: ");
    scanf(" %[^\n]", PtrRemedio[*PtrIndex].nome);
    fflush(stdin);
    
    printf("Digite a descricao do remedio: ");
    scanf(" %[^\n]", PtrRemedio[*PtrIndex].descricao);
    fflush(stdin);
    
    printf("Digite a quantidade do remedio: ");
    scanf("%d", &PtrRemedio[*PtrIndex].quantidade);
    fflush(stdin);
    
    printf("Digite o valor do remedio: ");
    scanf("%f", &PtrRemedio[*PtrIndex].valor);
    fflush(stdin);
    
    printf("Digite o fabricante do remedio: ");
    scanf(" %[^\n]", PtrRemedio[*PtrIndex].fabricante);
    fflush(stdin);

    (*PtrIndex)++;
}

// Função para alterar informações
void alterarCampo (){
    int id;
    printf("Selecione o ID que voce deseja alterar: \n");
    scanf("%d", &id);
    
    printf("Digite o nome do remedio(Novo): ");
    scanf(" %[^\n]", PtrRemedio[id].nome);
    fflush(stdin);
    
    printf("Digite a descricao do remedio(Novo): ");
    scanf(" %[^\n]", PtrRemedio[id].descricao);
    fflush(stdin);
    
    printf("Digite a quantidade do remedio(Novo): ");
    scanf("%d", &PtrRemedio[id].quantidade);
    fflush(stdin);
    
    printf("Digite o valor do remedio(Novo): ");
    scanf("%f", &PtrRemedio[id].valor);
    fflush(stdin);
    
    printf("Digite o fabricante do remedio(Novo): ");
    scanf(" %[^\n]", PtrRemedio[id].fabricante);
    fflush(stdin);
}

// Função para exibir as informações
void exibirProduto(Remedio *PtrRemedio, int *PtrIndex) {
    for(int i = 0; i < *PtrIndex; i++){
        printf("\nID: %d\n", PtrRemedio[i].id);
        printf("Nome: %s\n", PtrRemedio[i].nome);
        printf("Descricao: %s\n", PtrRemedio[i].descricao);
        printf("Quantidade: %d\n", PtrRemedio[i].quantidade);
        printf("Valor: R$ %.2f\n", PtrRemedio[i].valor);
        printf("Fabricante: %s\n", PtrRemedio[i].fabricante);
    }
}


int main() {
    
    int opcao;

    while (1) {
        printf("\n--- Sistema de Gerenciamento de Farmacia ---\n");
        printf("Escolha uma opcao:\n");
        printf("1. Cadastrar produto\n");
        printf("2. Exibir produto\n");
        printf("3. Alterar campo\n");
        printf("7. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(remedios, &indice);
                break;
            case 2:
                exibirProduto(remedios, &indice);
                break;
            case 3:
                alterarCampo(*PtrRemedio, *PtrIndex);
                break;
            case 7:
                printf("Saindo do sistema...\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                
        }
    }

    return 0;
}