#ifndef LISTAE_H_INCLUDED
#define LISTAE_H_INCLUDED

/* definindo o tipo*/
typedef struct LSE_SampleList LSE_list;
typedef struct LSE_Research tResponse;
typedef struct LSE_ConfigMessage tThrow;
/*funções e procedimentos*/
void LSE_Menu(LSE_list **head);
void LSE_init(LSE_list **p); /* função de inicialização da lista vazia. Passagem por referência*/
void LSE_print(LSE_list *head); /*imprime a lista*/
int LSE_isEmpty(LSE_list *head);/*verifica se a lista está vazia*/
tResponse LSE_find(LSE_list *head, int k);/*busca valor na lista*/
void LSE_Remove(LSE_list **head, int k); /*remove número específico*/
LSE_list* LSE_RemoveInTheBegin(LSE_list **head); /*remove no começo*/
void LSE_RemoveInTheEnd(LSE_list **head); /*remove no fim*/
LSE_list* LSE_insertInTheBegin(LSE_list *head, int k); /*função de inserção no inicio*/
void LSE_insertInTheEnd(LSE_list **head, int k); /*função de inserção no fim. Passagem por referência*/
void LSE_DeleteFromMemory(LSE_list **head);/*desaloca da memória toda a lista encadeada*/
void LSE_ThrowMessage(tThrow config); /*configura mensagens de erro e retornos psdrões*/

void LSE_insertByOrder(LSE_list **head, int num); /*insere ordenadamente*/
void LSE_bubbleSort(LSE_list **head);

LSE_list* LSE_Merge(LSE_list *s, LSE_list *t);
LSE_list* LSE_insertionSort(LSE_list **head);
void LSE_insertionSort_2(LSE_list **head);
void LSE_seletionSort(LSE_list **head);

#endif // LISTAE_H_INCLUDED
