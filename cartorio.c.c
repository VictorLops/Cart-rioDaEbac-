#include <stdio.h> //bibioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocações de texto por região

int main() 
{
	int registro() //função responsavel por cadastrar os usúarios no sistema
	{
		//inicio da criação de variaveis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//final da criação variaveis/strings
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuario
		scanf("%s",cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das string
		
		FILE *file; //cria arquivo
		file = fopen(arquivo, "w"); //cria o arquivo
		fprintf(file,cpf); //salvo o valor da variavel
		fclose(file); //fecho o arquivo
		
		file = fopen(arquivo, "a"); //abrindo o arquivo
		fprintf(file, ","); //salvando o valor na variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o nome a ser cadastrado: "); //coletando informações do usuario
		scanf("%s",nome); //%s refere-se a string
		
		file = fopen(arquivo, "a"); //Abrindo o arquivo
		fprintf(file,nome); //salvando o valor na variavel
		fclose(file); //fechando o arquivo
		
		file = fopen(arquivo, "a"); //Abrindo o arquivo
		fprintf(file, ","); //salvando o valor na variavel
		fclose(file); //fechando o arquivo
		
		printf("Digite o sobrenome a ser cadrastrado: "); //coletando informações do usario
		scanf("%s",sobrenome); //%s refere-se a string
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a"); //Abrindo o arquivo
		fprintf(file, ","); //salvando o valor na variavel
		fclose(file); //fechando o arquivo
		
		printf("Digite o cargo a ser registrado: "); //coletando informações do usario
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
	fclose(file); //fechado o arquivo
  	
	if(file == NULL)
{
	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}
	
	while(fgets(conteudo, 100, file) != NULL)
{
	printf("\n essas são as informações: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	system ("pause"); //pausa o sistema para coleta de informações
	

		
	}
	int deletar()
	{	
		char cpf [40];
		
		printf("Digite o CPG do usúario a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		fclose(file);
		
		if(file == NULL)
		{
			printf("O usuário não se encontra no sistema!. \n");
			system("pause");
		}	
		
	}
	
	
	int opcao=0; //definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a opção que deseja no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); //fim do menu
		printf("\t4 - Sair do sistema \n\n)");
		printf("opção:");//Fim do menu
		
	
	
		scanf("%d", &opcao); //armazenamento a escolha da usuário
	
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
			case 4: 
			printf("Obrigado por utulizar o sistema\n");
			return 0;
			break;
			
			default:
				printf("Essa opção não está disponivel\n");
				system("pause");
				break;
			
		}

	}

}

