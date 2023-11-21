#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bibilioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings
// \t é uma função de espaço no inicio do texto

int registro() //função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variaveis/string
	char arquivo[40]; //usa-se CHAR para quando for usar caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variaveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //Coletando as informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável para copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //pasta onde se encontra o arquivo - cria o arquivo, "w" é para escrever (Ing.Write)
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a" é para atualizar o arquivo
	fprintf(file, ","); //variavel usada separar o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("digite o nome a ser cadastrado: "); //coleta a informação do usuario
	scanf("%s", nome); //salva a informação no sistema, para usar depois
	
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

int consulta() //função para consulta de usuário dentro do programa
{
	setlocale(LC_ALL, "Portuguese"); //Escolhendo a lingua de onde o programa vai rodar
	
	char cpf[40]; //Usa-se CHAR para quando for caracteres
	char conteudo[200];
	
	printf("Digite o cpf para consultar: ");
	scanf("%s", cpf);
	
	FILE *file;//Selecionando o arquivo que vai ser aberto
	file = fopen(cpf, "r"); //abre o arquivo e leia ele usando o "r" (Ing.Read)

	
	if(file == NULL) //if é o "SE" em um pragramação e else para "ENTÃO"
	{
		printf("Não foi possivel encontrar o arquivo, CPF não cadastrado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //While é usado para procurar dentro do arquivo, até achar a informação que o usuário pediu.
	{
		printf("\nEssas são as informações do CPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
		
	system("pause"); //Pausa a programação para o usuário conseguir ler a resposta.

}

int excluir() //função para fazer a exclusão do usuário
{
	
	char cpf [40];
	
	
	printf("Qual cpf deseja excluir?: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file ==NULL);
	{
		printf("Usuário deletado com sucesso! \n\n");
		system("pause");
	}

	
}
	

			
int main() 
{
	int opcao=0; //Definição de variáveis
	int laco=1; //x é a variavel (pode ser um nome que ajude a identificar depois)
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsavel por fazer a limpeza da tela
		
	
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
		printf("### Cartório da EBAC ### \n\n"); //inicio do menu
		printf("Escolha as opções desejada no menu:\n\n"); //menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Excluir os nomes\n");
		printf("\t4 - Sair do programa\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando as escolhas do usuário
		
		system("cls"); //usado para fazer a limpeza da tela
		
			switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
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
			printf("Essa opção não está disponivel\n");
			system("pause");
			break;
		} //fim da seleção


	} 



	}
