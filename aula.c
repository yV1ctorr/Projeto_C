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

// Função para cadastrar um novo remedio
void cadastrarProduto(Remedio *r) {
    
    printf("\nDigite um ID para o remedio: ");
    scanf("%d", &r->id);
    fflush(stdin);
    
    printf("Digite o nome do remedio: ");
    scanf(" %[^\n]", &r->nome);
    fflush(stdin);
    
    printf("Digite a descrição do remedio: ");
    scanf(" %[^\n]", &r->descricao);
    fflush(stdin);
    
    printf("Digite a quantidade do remdio: ");
    scanf("%d", &r->quantidade);
    fflush(stdin);
    
    printf("Digite o valor do remdio: ");
    scanf("%f", &r->valor);
    fflush(stdin);
    
    printf("Digite o fabricante do remdio: ");
    scanf("%[^\n]", &r->fabricante);
    fflush(stdin);
}
// Função para alterar campos
// void alterarCampo (){
//     printf("Selecione o campo que você deseja alterar: \n");
//     printf("1. Nome\n");
//     printf("2. Descricao");
//     printf("3. Quantidade");
//     printf("4. Valor");
//     printf("5. Fabricante");
// }

// Função para exibir as informações
void exibirProduto(Remedio r) {
    printf("\nID: %d\n", r.id);
    printf("Nome: %s\n", r.nome);
    printf("Descrição: %s\n", r.descricao);
    printf("Quantidade: %d\n", r.quantidade);
    printf("Valor: R$ %.2f\n", r.valor);
}

int main() {

    Remedio remedio;
    int opcao;

    while (opcao == NULL) {
        printf("\n--- Sistema de Gerenciamento de Loja de Esportes ---\n");
        printf("Escolha uma opcao:\n");
        printf("1. Cadastrar produto\n");
        printf("2. Exibir produto\n");
        printf("3. Alterar campo\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(&remedio);
                break;
            case 2:
                exibirProduto(remedio);
                break;
            case 3:
                alterarCampo(remedio);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}