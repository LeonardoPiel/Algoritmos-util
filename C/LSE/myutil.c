#include <stdio.h>
#include <locale.h>
#include "myutil.h"
#define RAND_MAX 20
/*
	Autor: Leonardo Piel;
	Email: leonardo.piel@outlook.com;
*/
int myU_getAnumber(int limit) {
    int divisor = RAND_MAX/(limit+1);
    int retval;
    do {
        retval = rand() / divisor;
    } while (retval > limit);
	/*srand(time(NULL));*/
    return retval;
}
