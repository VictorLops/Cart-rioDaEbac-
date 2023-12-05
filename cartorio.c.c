#include <stdio.h> //bibioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o

int main() 
{
	int registro() //fun��o responsavel por cadastrar os us�arios no sistema
	{
		//inicio da cria��o de variaveis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//final da cria��o variaveis/strings
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usuario
		scanf("%s",cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das string
		
		FILE *file; //cria arquivo
		file = fopen(arquivo, "w"); //cria o arquivo
		fprintf(file,cpf); //salvo o valor da variavel
		fclose(file); //fecho o arquivo
		
		file = fopen(arquivo, "a"); //abrindo o arquivo
		fprintf(file, ","); //salvando o valor na variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usuario
		scanf("%s",nome); //%s refere-se a string
		
		file = fopen(arquivo, "a"); //Abrindo o arquivo
		fprintf(file,nome); //salvando o valor na variavel
		fclose(file); //fechando o arquivo
		
		file = fopen(arquivo, "a"); //Abrindo o arquivo
		fprintf(file, ","); //salvando o valor na variavel
		fclose(file); //fechando o arquivo
		
		printf("Digite o sobrenome a ser cadrastrado: "); //coletando informa��es do usario
		scanf("%s",sobrenome); //%s refere-se a string
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a"); //Abrindo o arquivo
		fprintf(file, ","); //salvando o valor na variavel
		fclose(file); //fechando o arquivo
		
		printf("Digite o cargo a ser registrado: "); //coletando informa��es do usario
		scanf("%s",cargo); //%s refere-se a string
		
		file = fopen(arquivo, "a"); //Abrindo o arquivo
		fprintf(file,cargo); //salvando o valor na variavel
		fclose(file); //fechando o arquivo
		
		system("pause");
		
	}
	int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r");
  	
	if(file == NULL)
{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
}
	
	while(fgets(conteudo, 100, file) != NULL)
{
	printf("\n essas s�o as informa��es: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	system ("pause"); //pausa o sistema para coleta de informa��es
	

		
	}
	int deletar()
	{	
		char cpf [40];
		
		printf("Digite o CPG do us�ario a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		fclose(file);
		
		if(file == NULL)
		{
			printf("O usu�rio n�o se encontra no sistema!. \n");
			system("pause");
		}	
		
	}
	
	
	int opcao=0; //definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a op��o que deseja no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); //fim do menu
		printf("op��o:");
	
	
		scanf("%d", &opcao); //armazenamento a escolha da usu�rio
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
				registro();
				break;
			case 2:
				consultar();
				break;
			case 3:
				deletar();
				break;
			default:
				printf("Essa op��o n�o est� disponivel\n");
				system("pause");
				break;
			
		}

	}

}

