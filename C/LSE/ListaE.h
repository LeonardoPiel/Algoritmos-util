#ifndef LISTAE_H_INCLUDED
#define LISTAE_H_INCLUDED

/* definindo o tipo*/
typedef struct LSE_SampleList LSE_list;
typedef struct LSE_Research tResponse;
typedef struct LSE_ConfigMessage tThrow;
/*fun��es e procedimentos*/
void LSE_Menu(LSE_list **head);
void LSE_init(LSE_list **p); /* fun��o de inicializa��o da lista vazia. Passagem por refer�ncia*/
void LSE_print(LSE_list *head); /*imprime a lista*/
int LSE_isEmpty(LSE_list *head);/*verifica se a lista est� vazia*/
tResponse LSE_find(LSE_list *head, int k);/*busca valor na lista*/
void LSE_Remove(LSE_list **head, int k); /*remove n�mero espec�fico*/
LSE_list* LSE_RemoveInTheBegin(LSE_list **head); /*remove no come�o*/
void LSE_RemoveInTheEnd(LSE_list **head); /*remove no fim*/
LSE_list* LSE_insertInTheBegin(LSE_list *head, int k); /*fun��o de inser��o no inicio*/
void LSE_insertInTheEnd(LSE_list **head, int k); /*fun��o de inser��o no fim. Passagem por refer�ncia*/
void LSE_DeleteFromMemory(LSE_list **head);/*desaloca da mem�ria toda a lista encadeada*/
void LSE_ThrowMessage(tThrow config); /*configura mensagens de erro e retornos psdr�es*/

void LSE_insertByOrder(LSE_list **head, int num); /*insere ordenadamente*/
void LSE_bubbleSort(LSE_list **head);

LSE_list* LSE_Merge(LSE_list *s, LSE_list *t);
LSE_list* LSE_insertionSort(LSE_list **head);
void LSE_insertionSort_2(LSE_list **head);
void LSE_seletionSort(LSE_list **head);

#endif // LISTAE_H_INCLUDED
