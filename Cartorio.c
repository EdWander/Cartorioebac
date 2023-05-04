#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //bliblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refe-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
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
		printf("N�o foi poss�vel abrir o arquivo, ARQUIVO N�O LOCALIZADO!.\n");
			
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
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
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // Defdinindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
	
	    system("cls");
		
		setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	    
	    printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - REGISTRAR nomes\n");
	    printf("\t2 - CONSULTAR nomes\n");
	    printf("\t3 - DELETAR nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	    
	    scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	    
	    system("cls"); //renspons�vel por limpar a tela
	    
	    switch(opcao) //inicio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //chamada da fun��o registro
	    	break;
	    	
	    	case 2:
	    	consulta(); //chamada da fun��o consulta
			break;
			
			case 3:
			deletar(); //chamada da fun��o deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o N�O est� dispon�vel!");
			system("pause");
			break;
			
		} //fim de sele��o
	    
	    printf("Esse Software � de uso restrito da EBAC\n");
	}
}

