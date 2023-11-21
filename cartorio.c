#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibilioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings
// \t � uma fun��o de espa�o no inicio do texto

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de variaveis/string
	char arquivo[40]; //usa-se CHAR para quando for usar caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de variaveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //Coletando as informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel para copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //pasta onde se encontra o arquivo - cria o arquivo, "w" � para escrever (Ing.Write)
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a" � para atualizar o arquivo
	fprintf(file, ","); //variavel usada separar o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("digite o nome a ser cadastrado: "); //coleta a informa��o do usuario
	scanf("%s", nome); //salva a informa��o no sistema, para usar depois
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
}

int consulta() //fun��o para consulta de usu�rio dentro do programa
{
	setlocale(LC_ALL, "Portuguese"); //Escolhendo a lingua de onde o programa vai rodar
	
	char cpf[40]; //Usa-se CHAR para quando for caracteres
	char conteudo[200];
	
	printf("Digite o cpf para consultar: ");
	scanf("%s", cpf);
	
	FILE *file;//Selecionando o arquivo que vai ser aberto
	file = fopen(cpf, "r"); //abre o arquivo e leia ele usando o "r" (Ing.Read)

	
	if(file == NULL) //if � o "SE" em um pragrama��o e else para "ENT�O"
	{
		printf("N�o foi possivel encontrar o arquivo, CPF n�o cadastrado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //While � usado para procurar dentro do arquivo, at� achar a informa��o que o usu�rio pediu.
	{
		printf("\nEssas s�o as informa��es do CPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
		
	system("pause"); //Pausa a programa��o para o usu�rio conseguir ler a resposta.

}

int excluir() //fun��o para fazer a exclus�o do usu�rio
{
	
	char cpf [40];
	
	
	printf("Qual cpf deseja excluir?: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file ==NULL);
	{
		printf("Usu�rio deletado com sucesso! \n\n");
		system("pause");
	}

	
}
	

			
int main() 
{
	int opcao=0; //Defini��o de vari�veis
	int laco=1; //x � a variavel (pode ser um nome que ajude a identificar depois)
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsavel por fazer a limpeza da tela
		
	
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
		printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
		printf("Escolha as op��es desejada no menu:\n\n"); //menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Excluir os nomes\n");
		printf("\t4 - Sair do programa\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando as escolhas do usu�rio
		
		system("cls"); //usado para fazer a limpeza da tela
		
			switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			excluir();
			break;
			
			case 4:
			printf("Obrigado por usar o sistema!\n");
			return 0;
			break;
					
			default:
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");
			break;
		} //fim da sele��o


	} 



	}
