#include <stdio.h>
#include <string.h>

// Definindo estrutura
typedef struct {
    int id;
    int quantidade;
    char nome[20];
    char descricao[50];
    char fabricante[20];
    float valor;
    
}Remedio;

int indice = 2;
Remedio remedios[10] ={
	{0, 1, "Dorflex", "Acao analgesica e relaxante muscular", "Sanofi-Aventis Farmaceutica Ltda", 2.50},
	{1, 1, "Multigrip", "Tratamento dos sintomas de gripes e resfriados", "Multilab", 3.00}
};

Remedio *PtrRemedio = remedios;
// criacao do arquivo txt
void salvarRemedios(Remedio *PtrRemedio, int indice){
    FILE *farmacia = fopen("remedios.txt", "w");
    if (farmacia == NULL){
        printf("Nao e possivel abrir esse arquivo\n");
        return;
    }
    int i;
    for (i = 0; i < indice; i++){
        fprintf(farmacia, "%d,%d,%s,%s,%s,%.2f \n", 
            PtrRemedio[i].id, PtrRemedio[i].quantidade, PtrRemedio[i].nome, PtrRemedio[i].descricao, PtrRemedio[i].fabricante, PtrRemedio[i].valor);
    }
    fclose(farmacia);
    printf("remedios salvos");
}


void carregarRemedio(Remedio *PtrRemedio, int *indice){
    FILE *farmacia = fopen("remedios.txt", "r");
    if (farmacia == NULL){
        printf("Nao e possivel abrir esse arquivo\n");
        return;
    }
    int i = 0;
    while(fscanf(farmacia, "%d,%d,%19[^,],%49[^,],%19[^,],%f \n", 
    	&PtrRemedio[i].id, 
		&PtrRemedio[i].quantidade, 
		PtrRemedio[i].nome, 
		PtrRemedio[i].descricao, 
		PtrRemedio[i].fabricante, 
		&PtrRemedio[i].valor) == 6){
        i++;
        
        if (i >=10){
            printf("Limites de remedios atingido\n");
            break;
        }   
    }
    
    *indice = i;
    fclose(farmacia);
    printf("carregado!!!\n");
}


// Funcao para adicionar um novo remedio
void cadastrarProduto(Remedio *PtrRemedio, int *indice) { 
    
    PtrRemedio[*indice].id = *indice;
	
	printf("Digite o nome do remedio: ");
    scanf(" %[^\n]", PtrRemedio[*indice].nome);
    //fflush(stdin); //para limpar o buffer depois de cada scanf e evitar alguns erros de leitura
    
    printf("Digite a descricao do remedio: ");
    scanf(" %[^\n]", PtrRemedio[*indice].descricao);
    fflush(stdin);
    
    printf("Digite a quantidade do remedio: ");
    scanf("%d", &PtrRemedio[*indice].quantidade);
   // fflush(stdin);
    
    printf("Digite o valor do remedio: ");
    scanf("%f", &PtrRemedio[*indice].valor);
  //  fflush(stdin);
    
    printf("Digite o fabricante do remedio: ");
    scanf(" %[^\n]", PtrRemedio[*indice].fabricante);
   // fflush(stdin);
   
	(*indice)++;
    salvarRemedios( PtrRemedio, *indice );

    printf("\nProduto cadastrado com sucesso!\n");
}

// Funcao para alterar elementos
void alterarCampo (Remedio *PtrRemedio, int *indice){
    int id;
    printf("Selecione o ID que voce deseja alterar: \n");
    scanf("%d", &id);
    
    printf("Digite o nome do remedio(Novo): ");
    scanf(" %[^\n]", PtrRemedio[id].nome);
   // fflush(stdin);
    
    printf("Digite a descricao do remedio(Novo): ");
    scanf(" %[^\n]", PtrRemedio[id].descricao);
   // fflush(stdin);
    
    printf("Digite a quantidade do remedio(Novo): ");
    scanf("%d", &PtrRemedio[id].quantidade);
   // fflush(stdin);
    
    printf("Digite o valor do remedio(Novo): ");
    scanf("%f", &PtrRemedio[id].valor);
   // fflush(stdin);
    
    printf("Digite o fabricante do remedio(Novo): ");
    scanf(" %[^\n]", PtrRemedio[id].fabricante);
   // fflush(stdin);
   salvarRemedios( PtrRemedio, *indice );
    printf("\nProduto foi alterado\n");
}
// Funcao para listar os elementos
void exibirProduto(Remedio *PtrRemedio, int *indice) {
    
	int i;
	
	for(i = 0; i < *indice; i++){
        printf("\nID: %d\n", PtrRemedio[i].id);
        printf("Nome: %s\n", PtrRemedio[i].nome);
        printf("Descricao: %s\n", PtrRemedio[i].descricao);
        printf("Quantidade: %d\n", PtrRemedio[i].quantidade);
        printf("Valor: R$ %.2f\n", PtrRemedio[i].valor);
        printf("Fabricante: %s\n", PtrRemedio[i].fabricante);
    }
}

// funcao para verificar senha
int senha = 123;
int senhaInserida;
int senhaCorreta;
int *PtrSenha = &senha;
int *PtrSenhaInserida = &senhaInserida;

void verificarSenha(int PtrSenha, int PtrSenhaInserida) {
    do{
        printf("Digite sua senha: \n");
        scanf("%d", &PtrSenhaInserida);
        //fflush(stdin);

        if ((PtrSenhaInserida == PtrSenha)){
            senhaCorreta = 1;
        } else{
            senhaCorreta = 0;
        }
    } while(senhaCorreta < 1);
}

//Funcao para buscar elemento
void buscarElemento(Remedio *PtrRemedio){
    int i;
    printf("Digite o ID desejado: \n");
    scanf("%d", &i);
  //  fflush(stdin);

    printf("\nID: %d\n", PtrRemedio[i].id);
    printf("Nome: %s\n", PtrRemedio[i].nome);
    printf("Descricao: %s\n", PtrRemedio[i].descricao);
    printf("Quantidade: %d\n", PtrRemedio[i].quantidade);
    printf("Valor: R$ %.2f\n", PtrRemedio[i].valor);
    printf("Fabricante: %s\n", PtrRemedio[i].fabricante);
}


// Funcao para excluir elementos cadastrados
void excluirElemento(Remedio *PtrRemedio, int *indice){
    int remove, i;
    printf("Digite o ID desejado: \n");
    scanf("%d", &remove);
  //  fflush(stdin);

    printf("\nremedio excluido\n");

    for ( i = remove; i < *indice; i++){
        PtrRemedio[i] = PtrRemedio[i+1];
        PtrRemedio[i].id = PtrRemedio[i].id - 1;
    }
    (*indice) --;
    salvarRemedios( PtrRemedio, *indice );
}

int main() {

    carregarRemedio(PtrRemedio, &indice);
    verificarSenha(senha, senhaInserida);
    int opcao;

    // menu para selecionar as opcoes
    while (senhaCorreta > 0){
        printf("\n--- SISTEMA DE GERENCIAMENTO DE FARMACIA ---\n");
        printf("Escolha uma opcao:\n");
        printf("1. Cadastrar novo remedio\n");
        printf("2. Exibir remedios cadastrados\n");
        printf("3. Alterar informacoes\n");
        printf("4. Buscar remedio por ID\n");
        printf("5. Excluir elemento\n");
        
        printf("6. Sair(fechar sistema)\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(remedios, &indice);
                break;
            case 2:
                exibirProduto(remedios, &indice);
                break;
            case 3:
                alterarCampo(PtrRemedio, &indice);
                break;
            case 4:
                buscarElemento(remedios);
                break;
            case 5:
                excluirElemento(PtrRemedio, &indice);
                break;
            case 6:
                printf("Saindo do sistema...\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                
        }
    }
	return 0;
}