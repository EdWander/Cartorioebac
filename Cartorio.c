#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //bliblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refe-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o a significa adicionar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
			
}

int consulta()
{
	setlocale(LC_ALL,"portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //cria o arquivo e o r significa ler
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, ARQUIVO NÃO LOCALIZADO!.\n");
			
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
		
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser DELETADO: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // Defdinindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
	
	    system("cls");
		
		setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	    
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - REGISTRAR nomes\n");
	    printf("\t2 - CONSULTAR nomes\n");
	    printf("\t3 - DELETAR nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	    
	    scanf("%d" , &opcao); //armazenando a escolha do usuário
	    
	    system("cls"); //rensponsável por limpar a tela
	    
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); //chamada da função registro
	    	break;
	    	
	    	case 2:
	    	consulta(); //chamada da função consulta
			break;
			
			case 3:
			deletar(); //chamada da função deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Essa opção NÃO está disponível!");
			system("pause");
			break;
			
		} //fim de seleção
	    
	    printf("Esse Software é de uso restrito da EBAC\n");
	}
}

