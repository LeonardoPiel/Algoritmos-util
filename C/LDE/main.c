#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"
/*
	Autor: Leonardo Piel;
	Email: leonardo.piel@outlook.com;
*/

int main()
{
    LDE_list *head;
    LDE_listInfo *listInfo;
    LDE_init(&head, &listInfo); /*Inicializando a lista*/

    head = LDE_insertInTheBegin(head, 20, &listInfo);
    head = LDE_insertInTheBegin(head, 10, &listInfo);
    head = LDE_insertInTheBegin(head, 30, &listInfo);
    LDE_insertInTheEnd(&head, 40, &listInfo);
    head = LDE_insertInTheBegin(head, 30, &listInfo);
    LDE_insertInTheEnd(&head, 50, &listInfo);
    LDE_print(head, &listInfo);
    LDE_selectionSort(&head, &listInfo);
    //LDE_reversePrint(&listInfo);
    LDE_print(head, &listInfo);
    return 0;
}
