#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void OpenFile(char* nome, int type, FILE *f){
  /*FUNÇÃO PARA ABRIR STREAM E SETAR PONTEIRO DA STREAM*/
  // verificando o nome e a extensão dos arquivos
  int flagStr;
  flagStr = strlen(nome);

  if(flagStr == 0){
    printf("Erro! Nome vazio\n");
    return;
  }
  char *tipo;
  if (!(tipo = (char *) malloc(sizeof(char)))) {
		printf("Nao foi possível alocar a string\n");
		return;
	}
  const char *ptrNome = nome;

  switch (type){
      case 1:
        strncpy(tipo, "a", 1);
        printf("tipo: %s\n", tipo);
        printf("Tentando abrir\n");
        f = fopen(ptrNome, tipo); // abrindo o arquivo
        if(f == NULL){
            printf("Nao foi possivel abrir o arquivo\n");
            return;
        }else{
          printf("Arquivo aberto com sucesso!\n");
          char *palavra;
          // ISSO ESTÁ SENDO FEITO APENAS POR MOTIVO ACADÊMICO
          // a função scanf pega apenas os caracteres diferentes de '\0' e gets pega todos caracteres
          printf("Voce deseja inserir apenas uma palavra ou um texto? [p/t]: \n");
          if (!(palavra = (char *)malloc(sizeof(char)))) { // alocando variavel apenas para receber a resposta
            printf("Nao foi possível alocar a string\n");
            return;
          }
          scanf("%s", palavra);
          printf("opcao escolhida: %s\n", palavra);
          if (strcmp(palavra, "p") == 0) {
            free(palavra); // liberando espaco da resposta
            if (!(palavra = (char *)malloc(50 * sizeof(char)))) {// alocando a variavel para receber a palavra
              printf("Nao foi possível alocar a string\n");
              return;
            }
            printf("Digite a palavra\n" );
            scanf("%s", palavra);
            fprintf(f, "%s", palavra);
            printf("Terminado o lancamento\n");
            fclose(f);

            free(palavra); // liberando espaço da palavra
          }
          if (strcmp(palavra, "t") == 0) {
            free(palavra);// liberando espaco da resposta
            if (!(palavra = (char *)malloc(250 * sizeof(char)))) { // espaço maior de memória para um texto
              printf("Nao foi possível alocar a string\n");
              return;
            }
            printf("Digite o texto: \n");
            getchar();
            fgets(palavra, 250 *sizeof(char), stdin);
            fprintf(f, "%s", palavra);
            printf("Terminado o lancamento\n");
            fclose(f);
            free(palavra);// liberando todo o espaço da memória para o texto
          }
        }
        break;
      case 2:
        strncpy(tipo, "r", 1);
        printf("tipo: %s\n", tipo);
        // abrindo o arquivo
        printf("Tentando abrir\n");
        f = fopen(ptrNome, tipo);
        char c;
        do{
          c = getc(f);
          //exibe o caracter lido na tela
          printf("%c" , c);
        }while (c != EOF);
        free(c);
        break;
      default:
        printf("Algo deu errado!\n");
        return;
        break;
  }
  free(tipo);// liberando espaço da variável tipo
}

int menu(){
  printf("Esse e o programa para abrir arquivos\n");
  int r=0;

  while (r == 0) {
      printf("Escolha uma opcao\n");
      printf("1 - escrever no arquivo\n" );
      printf("2 - ler arquivo\n");
      scanf("%d",&r);
      if (r != 1 && r != 2) {
        printf("Opcao errada!\n");
        r = 0;
      }
  }
  printf("opcao escolhida: %d\n", r);
  getchar(); // limpando buffer do scanf;
  return r;
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  FILE *myFile;
  char *nome;
  int r;
  r = menu();
  if (!(nome = (char *) malloc(50 * sizeof(char)))) {
		printf("Nao foi possível alocar a string\n");
		return (0);
	}
  printf("Informe o nome do arquivo: \n");
  printf("Se esse arquivo nao existir, sera criado um novo arquivo com este nome. \n");
  scanf("%s", nome);
  printf("nome digitado: %s \n", nome);
  OpenFile(nome, r, myFile);
  free(nome);
  return 0;
}
