#ifndef LISTADE_H_INCLUDED
#define LISTADE_H_INCLUDED


typedef struct LDE_List LDE_list;
typedef struct LDE_ListInfo LDE_listInfo;


int LDE_isEmpty(LDE_list *head);
void LDE_Throw(int errorCode, const char *text);
void LDE_init(LDE_list **head, LDE_listInfo *listInfo);
void LDE_print(LDE_list *head, LDE_listInfo *listInfo);
void LDE_insertInTheEnd(LDE_list **head, int k, LDE_listInfo *listInfo);
void LDE_removeInTheEnd(LDE_list **head, LDE_listInfo *listInfo);
void LDE_selectionSort(LDE_list **head, LDE_listInfo *listInfo);
void LDE_switch(int *a, int *b);
void LDE_reversePrint(LDE_listInfo **listInfo);

LDE_list* LDE_insertInTheBegin(LDE_list *head, int k, LDE_listInfo *listInfo);
LDE_list* LDE_removeInTheBegin(LDE_list **head, LDE_listInfo *listInfo);

#endif // LISTADE_H_INCLUDED
