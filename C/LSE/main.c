#include <stdio.h>
#include <stdlib.h>
#include "ListaE.h"
#include "myutil.h"

int main()
{
    LSE_list *s/*, *t, *f*/;
    LSE_init(&s); /*inicializa a lista*/
    LSE_Menu(&s); /*menu*/

    //s = LSE_insertionSort(s);
    //LSE_init(&t); /*inicializa a lista*/
    //LSE_Menu(&t); /*menu*/
    //LSE_print(s);
    //LSE_print(t);

    //f = LSE_Merge(s, t);

    LSE_print(s);

   // printf("\nLiberando espaco da memoria...");
   // LSE_DeleteFromMemory(&s); /*desalocando memória*/
    return 0;
}
