#include <stdio.h>
#include <locale.h>
#include "listaDE.h"
#include "..\LSE\ListaE.h"

/*
	Autor: Leonardo Piel;
	Email: leonardo.piel@outlook.com;
*/

struct LDE_List{
    int data;/*LSE*/
	struct LDE_List *prox;
	struct LDE_List *ant;
};

struct LDE_poligono{

};

struct LDE_ListInfo{
	int size;
    struct LDE_list *last;
    struct LDE_list *first;
};

int LDE_isEmpty(LDE_list *head){
	return (head == NULL);
}

void LDE_init(LDE_list **head, LDE_listInfo *listInfo){
	*head = NULL;
	listInfo->first = *head;
    listInfo->last = *head;
    listInfo->size = 0;
}

void LDE_insertInTheEnd(LDE_list **head, int k, LDE_listInfo *listInfo){
    LDE_list *last, *aux;
    aux = (LDE_list *) malloc(sizeof(LDE_list));/*alocando memória para armazenar o novo elemento*/

    if(LDE_isEmpty(*head)){
        aux->data = k;
        aux->prox = NULL;
        *head = aux;
        aux->ant = aux;
        listInfo->size++;
        listInfo->last = aux;
        listInfo->first = aux;
        return;
    }

    last = listInfo->last; /*pegando o último elemento da lista*/

    aux->data = k;
    aux->prox = NULL;
    aux->ant = last;

    last->prox = aux; /*adicionando o novo elemento na lista*/
    /*last->ant = last; dizendo que o antigo anterior é o novo */
    listInfo->last = aux; /*indicando que o novo elemento também é o final da lista*/
    listInfo->size++;
    return;
}


LDE_list* LDE_insertInTheBegin(LDE_list *head, int k, LDE_listInfo *listInfo){
    LDE_list *aux;
    aux = (LDE_list *) malloc(sizeof(LDE_list));

    aux->data = k;
    aux->prox = head;
    aux->ant = NULL;

    listInfo->size++;
    listInfo->first = aux;
    /*caso a lista venha vazia o último elemento é o primeiro a ser inserido*/
    if(LDE_isEmpty(head)){
        head = (LDE_list *) malloc(sizeof(LDE_list));
        listInfo->last = aux;
        head->ant = aux;
    }else{
        head->ant = aux;
    }

    return aux;
}

void LDE_removeInTheEnd(LDE_list **head, LDE_listInfo *listInfo){
    if(LDE_isEmpty(*head)) return LDE_Throw(2, "Nao e possivel remover no fim de uma lista inexistente\n");

    LDE_list *aux, *last, *newLast;
    aux = (LDE_list*) malloc(sizeof(LDE_list));
    newLast = (LDE_list*) malloc(sizeof(LDE_list));

    last = listInfo->last; /*armazenando o último elemento da lista*/
    newLast = last->ant; /*pegando o anterior ao último*/
    newLast->prox = NULL; /*retirando da lista o último*/

    free(last); /*desalocando a memória do último elemento*/
    listInfo->last = newLast;/*atualizando a informação do último elemento*/
    listInfo->size--;
    return;
}

LDE_list* LDE_removeInTheBegin(LDE_list **head, LDE_listInfo *listInfo){
    if(LDE_isEmpty(*head)) return head/*LDE_Throw(2, "erro no método de remover no inicio")*/;

    LDE_list *aux, *auxProx, *primeiro;
    auxProx = (LDE_list *) malloc(sizeof(LDE_list));
    aux = *head;

    auxProx = aux->prox;
    /*auxProx->ant = NULL;
    printf("teste");*/
    *head = NULL;
    free(aux);

    listInfo->size--;
    listInfo->first = auxProx;
    return auxProx;
}


void LDE_print(LDE_list *head, LDE_listInfo *listInfo){

    if(LDE_isEmpty(head)) return LDE_Throw(2, "");

    LDE_list *aux, *last, *first;

    aux =(LDE_list *) malloc(sizeof(LDE_list));
    last = (LDE_list *) malloc(sizeof(LDE_list));
    first = (LDE_list *) malloc(sizeof(LDE_list));

    aux = head;
    printf("\n-------------\n");
    while(aux != NULL){
        printf("[%d]\n", aux->data);
        aux = aux->prox;
    }
    last = listInfo->last;
    first = listInfo->first;
    printf("\n-------------\n");
    printf("\ninformacoes extras:\nultimo elemento-> %d\nprimeiro elemento-> %d\nqtd-> %d\n", last->data, first->data, listInfo->size);
}

void LDE_reversePrint(LDE_listInfo **listInfo){
    LDE_list *aux;
    LDE_listInfo *auxInfo;

    auxInfo = listInfo;
    aux = auxInfo->last;
    if(LDE_isEmpty(aux)) return;

    while(aux != NULL){
        printf("[%d]\n", aux->data);
        aux = aux->ant;
    }
}

void LDE_selectionSort(LDE_list **head, LDE_listInfo *listInfo){
    int lowest, i, j;
    for(i = 0; i <= (listInfo->size) - 2; i++){
        lowest = i;
        for(j = i+1; j <= (listInfo->size) - 1; j++){
            if((*head + j)->data < (*head+lowest)->data){
                lowest = j;
            }
        }
        if(lowest != i){
            printf("\nteste switch i: =%d | j=%d | lowest=%d\n", i, j, lowest);
            LDE_switch(&(*head+lowest)->data, &(*head+i)->data);
            printf("\n&head+lowest: %p head+lowest: %d\n",(&head+lowest), (*head+lowest)->data);
            printf("\n&head+i: %p head+i: %d\n", (&head+i), (*head+i)->data);
        }
    }
}

void LDE_Throw(int MessageCode, const char *text){
    switch(MessageCode){
	case 1:
		printf("Erro cod: %d \nlista duplamente encadeada ja existente ou ja esta preenchida",MessageCode);
		break;
    case 2:
        printf("Lista vazia. Verifique novamente a head da lista!\n %s\n", text);
        break;
	default:
		printf("\nErro inesperado!\n");
		break;
    }
}

void LDE_switch(int *a, int *b){
    printf("a=%d\nb=%d", *a, *b);
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
/*
void LDE_menu(){
    int choice;
    choice = 0;
    do{
        printf("Escolha uma opcao\n");
        printf("1 - inserir no inicio\n");
        printf("2 - inserir no fim\n");
        printf("3 - remover no inicio\n");
        printf("4 - remover no fim\n");
        printf("0 - sair\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:

        }
    }while(choice != 0);
}
*/
