#include <stdio.h>
#include <locale.h>
#include "ListaE.h"
/*
	Autor: Leonardo Piel;
	Email: leonardo.piel@outlook.com;
*/
struct LSE_SampleList{
	int info;
	struct LSE_SampleList *prox;
};
struct LSE_Research{
    int myData;
    int positionInTheList;
    struct LSE_list *p;
};

struct LSE_ConfigMessage{
    int code;
    char something[20];
};

void LSE_init(LSE_list **p){
	*p = NULL;
}

/*insere no início*/
LSE_list* LSE_insertInTheBegin(LSE_list *head, int k){

	LSE_list *p = (LSE_list *) malloc(sizeof(LSE_list));

    p->info = k;
    p->prox = head;

    return p;
}
/*insere no fim*/
void LSE_insertInTheEnd(LSE_list **head, int k){
    LSE_list *p = (LSE_list *) malloc(sizeof(LSE_list));
    if(LSE_isEmpty(*head)){
        p->info = k;
        p->prox = NULL;
        *head = p;
        return;
    }
    LSE_list *aux;
    aux = *head;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    /*setando os novos valores*/
    p->info = k;
    p->prox = NULL;

    /*conectando na lista*/
    aux->prox = p;
    return;
}

/*verifica se a lista está vazia*/
int LSE_isEmpty(LSE_list *head){
	return (head == NULL);
}

/*imprime a lista*/
void LSE_print(LSE_list *head){
    if (LSE_isEmpty(head)) return; /*verifica se a lista está vazia*/

	LSE_list *aux;/*ponteiro auxiliar*/
	aux = head;

    while(aux != NULL){
        printf("%d\n", aux->info);
        aux = aux->prox; /*avança*/
    }
}
void sortInsert(){
}
/*busca*/
tResponse LSE_find(LSE_list *head, int k){
    tResponse response;
    if(LSE_isEmpty(head)){
        response.myData = -1;
        return response;
    }

    LSE_list *aux;
    aux = head;
    int c = 1;
    while(aux != NULL && k != aux->info){
        aux = aux->prox; /*avança*/
        c++;
    }
    if(aux == NULL){
        response.myData = -1;
        return response;
    }
    response.myData = aux->info;
    response.positionInTheList = c;
    response.p = aux;
    return response;
}
/*remove no início*/
LSE_list* LSE_RemoveInTheBegin(LSE_list **head){
    if(LSE_isEmpty(*head)){
        printf("lista vazia!\n");
        return NULL;
    }

    LSE_list *aux;
    aux = *head;

    free(head);

    return aux->prox;
}
/*remove no fim*/
void LSE_RemoveInTheEnd(LSE_list **head){
    if(LSE_isEmpty(*head)) return printf("lista vazia!\n");

    LSE_list* aux, *auxPre;
    int c = 0;
    aux = *head;
    auxPre = aux;

    while(aux != NULL){
        auxPre = aux;
        aux = aux->prox;
        c++;
    }
    if(c == 1){
        *head = NULL;
        free(aux);
        free(auxPre);
        return;
    }
    free(aux);
    auxPre->prox = NULL;
}
/*remove número específico*/
void LSE_Remove(LSE_list **head, int k){
    if(LSE_isEmpty(*head)) return;

    LSE_list *aux, *auxPre;
    aux = *head;
    int c = 0;
    while( aux != NULL && aux->info != k){
        auxPre = aux;
        aux = aux->prox;
        c++;
    }
    if(c == 0){
        printf("para isso utilize a opcao 4\n");
        return;
    }
    if(aux->info != k){
        printf("\n----- Numero nao encontrado ----- \n");
        return;
    }
    auxPre->prox = aux->prox;
    free(aux);
}

void LSE_Menu(LSE_list **head){
    int c;
    c = 1;
    while(c != 0){
        printf("1 - inserir no inicio\n");
        printf("2 - inserir no fim\n");
        printf("3 - remover no fim\n");
        printf("4 - remover no inicio\n");
        printf("5 - remover numero especifico\n");
        printf("6 - ver a lista\n");
        printf("7 - encontrar na lista\n");
        printf("8 - inserir ordenadamente\n");
        printf("9 - ordenar a lista (bubble sort)\n");
        printf("10 - ordenar a lista (insertion sort)\n");
        printf("11 - ordenar a lista (selection sort)\n");
        printf("0 para sair\n");
        printf("Escolha uma opcao do menu: ");
        scanf("%d", &c);
        int k;
        switch(c){
        case 1:
            printf("digite um numero:");
            scanf("%d", &k);
            *head = LSE_insertInTheBegin(*head, k);
            LSE_print(*head);
            k = 0;
            break;
        case 2:
            printf("digite um numero:");
            scanf("%d", &k);
            LSE_insertInTheEnd(head, k);
            LSE_print(*head);
            k = 0;
            break;
        case 3:
            LSE_RemoveInTheEnd(head);
            LSE_print(*head);
            break;
        case 4:
            *head = LSE_RemoveInTheBegin(head);
            LSE_print(*head);
            break;
        case 5:
            printf("digite um numero para ser excluido:");
            scanf("%d", &k);
            LSE_Remove(head, k);
            LSE_print(*head);
            break;
        case 6:
            printf("---------------------------------------\n");
            printf("lista:\n");
            LSE_print(*head);
            printf("---------------------------------------\n");
            break;
        case 7:
            printf("digite um numero: ");
            scanf("%d", &k);
            tResponse r = LSE_find(*head, k);

            if(r.myData != -1){
                printf("---------------------------------------\n");
                printf("Numero encontrado: %d\n", r.myData);
                printf("Posicao do numero: %d\n", r.positionInTheList);
                printf("---------------------------------------\n");
            }
            else{
                printf("Numero nao econtrado\n");
            }
            break;
        case 8:
            printf("digite um numero:");
            scanf("%d", &k);
            LSE_insertByOrder(head, k);
            LSE_print(*head);
            break;
        case 9:
            LSE_bubbleSort(head);
            LSE_print(*head);
            break;
        case 10:
            *head = LSE_insertionSort(head);
            LSE_print(*head);
            break;
        case 11:
            LSE_seletionSort(head);
            LSE_print(*head);
            break;
        case 0:
            printf("Programa encerrado!");
            break;
        default:
            printf("Opcao errada!!!\n");
            break;
        }
    }
}

void LSE_DeleteFromMemory(LSE_list **head){
    if(LSE_isEmpty(*head)) return;

    LSE_list *aux, *aux2;
    aux = *head;

    while(aux != NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    *head = NULL;
}

void LSE_ThrowMessage(tThrow conf){
    switch(conf.code){
        case 1:
            printf("\nlista vazia!\n");
            break;
        default:
            printf("\nErro inesperado. cod=> xxxx0000\n");
            break;
    }
}


LSE_list* LSE_Merge(LSE_list *s, LSE_list *t){
    if(LSE_isEmpty(s)||LSE_isEmpty(t)) return;

    LSE_list *aux_s, *aux_t, *finalList;
    aux_s = s;
    aux_t = t;
    int c1 = 0, c2 = 0, i;

    while(aux_s!= NULL){
        aux_s = aux_s->prox;
        c1++;
    }
    while(aux_t != NULL){
        aux_t = aux_t->prox;
        c2++;
    }
    aux_s = s;
    aux_t = t;
    finalList = (LSE_list*) malloc((c1+c2) * sizeof(LSE_list));
    for(i = 1; i < (c1+c2)+1; i++){
        if(i % 2 == 0){
            printf("i = %d aux_s = %d\n", i, aux_s->info);
            finalList = aux_s;
            printf("finalList = %d\n", finalList->info);
            finalList = finalList->prox;
            aux_s = aux_s->prox;
        }else{
            printf("i = %d aux_t = %d\n", i, aux_t->info);
            finalList = aux_t;
            printf("finalList = %d\n", finalList->info);
            finalList = finalList->prox;
            aux_t = aux_t->prox;
        }
    }
    return finalList;
}

LSE_list* LSE_insertionSort(LSE_list **head){
    if(LSE_isEmpty(head)) return *head;

    LSE_list *aux,*aux1, *newHead, *aux2;
    aux = *head;
    newHead = (LSE_list *) malloc(sizeof(LSE_list));

    while(aux != NULL){
        aux1 = aux;
        LSE_insertByOrder(&newHead, aux1->info);
        aux = aux->prox;
    }
    return newHead;
}

void LSE_insertionSort_2(LSE_list **head){
    LSE_list *cur, *ptr, *tmp, *aux, *aux_ant, *aux_prox;

    if(LSE_isEmpty(*head)) return;

    cur = *head;
    cur = cur->prox;

    // Tratando para o caso da lista com 2 elementos
    if( cur->prox == *head){
        if( (*head)->info > cur->info)
            (*head) = (*head)->prox;
        return;
    }

    while(cur!=*head){
        ptr=cur;
        //tmp=cur->ant;
        cur=cur->prox;

        while (tmp->prox != *head && tmp->info > ptr->info){
            //aux_ant = tmp->ant;
            aux_prox = ptr->prox;

            //aux_ant->prox = ptr;
            ptr->prox = tmp;
            tmp->prox = aux_prox;
            //aux_prox->ant = tmp;
            //tmp->ant = ptr;
            //ptr->ant = aux_ant;

            tmp = ptr;
            ptr = tmp->prox;

            if(ptr==*head)
                *head = tmp;

            //tmp=tmp->ant;
            //ptr = ptr->ant;
        }
    }
}

void LSE_insertByOrder(LSE_list **head, int num){
    LSE_list *atual, *novo, *anterior, *aux;

    novo = (LSE_list*) malloc(sizeof(LSE_list));

    atual = *head;
    anterior = NULL;
    novo->info = num;
    if(LSE_isEmpty(atual)){
        novo->prox = NULL;
        *head = novo;
    }else{
        while(atual != NULL && atual->info < num){
            anterior = atual;
            atual = atual->prox;
        }
        novo->prox = atual;
        if(anterior == NULL){
            *head = novo;
        }else{
            anterior->prox = novo;
            atual->prox = NULL;
        }
    }
}

void LSE_bubbleSort(LSE_list **head){

    if(LSE_isEmpty(*head)) return printf("lista vazia!");

    LSE_list *aux, *compare;
    aux = *head;
    int auxiliar;

    while(aux != NULL){
        compare = aux->prox;
        while(compare != NULL){
            if(aux->info > compare->info){
                auxiliar = compare->info;
                compare->info = aux->info;
                aux->info = auxiliar;
            }
            compare = compare->prox;
        }
        aux = aux->prox;
    }
}
// SELECTION SORT PROVA PS Q3
void LSE_seletionSort(LSE_list **head){
    if(LSE_isEmpty(*head)) return;

    LSE_list *aux, *auxprox;
    aux = *head;
    auxprox = aux->prox;
    int auxiliar, min = 0;
    while(aux != NULL){
        min = aux->info;
        while(auxprox != NULL){
            if(auxprox->info < auxprox->info){
                min = auxprox->info;
            }
            auxiliar = auxprox->info;
            auxprox->info = aux->info;
            aux->info = auxiliar;

            auxprox = auxprox->prox;
        }
    aux = aux->prox;
    }
}/*
int *selectionSort(int *v, int n){
    int i, j, min;

    for(i = 0; i < n-1; i++){
        min = i;

        for(j = i+1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
            my_swap(&v[min], &v[i]);
        }
    }
    return v;
}
*/




