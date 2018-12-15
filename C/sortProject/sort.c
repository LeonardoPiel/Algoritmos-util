#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "sort.h"
#include<time.h>

void my_swap(int *a, int *b){
    int *aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
void SortPrint(int v[], int n){
   int i;
   for (i=0; i < n; i++)
       printf("[%d] ", v[i]);
   printf("\n");
}

int *bubbleSort(int *x, int n){
   int aux, i, j;
    for(i = 0; i< n; i++){
        for(j = i+1; j <n; j++){
            if(x[i] > x[j]){
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }
    return x;
}
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

int *insertionSort(int *v, int n){
    int i, key, j;

    for(i = 1; i < n; i++){
        key = v[i];
        j = j-1;

        while(j>= 0 && v[j] > key){
            v[j+1] = v[j];
            j = j-1;
        }
        v[j+1] = key;
    }
    return v;
}

void mergeSort(int *v, int esq, int dir){
    if (esq < dir){
        int m = esq+(dir-esq)/2;


        mergeSort(v, esq, m);
        mergeSort(v, m+1, dir);

        merge_s(v, esq, m, dir);
    }
}
void merge_s(int v[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }
        else{
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}
int * criaVetor(int *number, int n){
    int i;
    number = (int *) malloc(n *sizeof(int));
    if(number == NULL){
        return number;
    }
    for(i=0;i<n;i++){
        number[i] = rand() % 100;
    }
    printf("teste");
    return number;
}
void menu(){
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    int i, count, resp;
    int *number;
    char r[1];
    printf("\nQuantos elementos você quer sortear?: ");
    scanf("%d",&count);
    number = criaVetor(number, count);
    if(number == NULL) return printf("overFlow!!");
    resp = 1;
	while(resp != 0){
        tempoFinal = 0;
        tempoGasto = 0;
        tempoInicial = 0;
		printf("Escolha o método que deseja fazer a ordenação: \n");
		printf("1 - bubbleSort\n");
		printf("2 - quickSort\n");
		printf("3 - selectionSort\n");
		printf("4 - insertionSort\n");
        printf("5 - mergeSort\n");
		printf("0 - sair\n");

		scanf("%d", &resp);
			switch(resp){
			case 1:
			    tempoInicial = clock();
                /*number = criaVetor(number, count);
                if(number == NULL){
                    return printf("overFlow!!");
                }*/
                SortPrint(number, count);
				number = bubbleSort(number, count);
				tempoFinal = clock();
				tempoGasto = (tempoFinal - tempoInicial)/CLOCKS_PER_SEC;
				printf("Tempo gasto = > %f \n", tempoGasto);
				printf("fim do lançamento\n");
				SortPrint(number, count);
				getch();
				free(number);
				system("CLS");
				break;
			case 2:
			    tempoInicial = clock();
			    /*number = criaVetor(number, count);
			    if(number == NULL){
                    return printf("overFlow!!");
                }*/
			    SortPrint(number, count);
				quicksort(number, 0,count-1);
				tempoFinal = clock();
				/*tempoGasto = (tempoFinal - tempoInicial)/CLOCKS_PER_SEC;*/
				printf("Tempo gasto = > %f \n", tempoGasto);
				printf("fim do lançamento\n");
				SortPrint(number, count);
				getch();
				free(number);
				system("CLS");
				break;
            case 3:
                tempoInicial = clock();
                /*number = criaVetor(number, count);
                if(number == NULL){
                    return printf("overFlow!!");
                }*/
                SortPrint(number, count);
                number = selectionSort(number, count);
                tempoFinal = clock();
                /*tempoGasto = (tempoFinal - tempoInicial)/CLOCKS_PER_SEC;*/
				printf("Tempo gasto = > %f \n", tempoGasto);
				printf("fim do lançamento\n");
				SortPrint(number, count);
				getch();
				free(number);
				system("CLS");
				break;
            case 4:
                tempoInicial = clock();
                /*number = criaVetor(number, count);
                if(number == NULL){
                    return printf("overFlow!!");
                }*/
                SortPrint(number, count);
                number = insertionSort(number, count);
                tempoFinal = clock();
                tempoGasto = (tempoFinal - tempoInicial)/CLOCKS_PER_SEC;
				printf("Tempo gasto = > %f \n", tempoGasto);
				printf("fim do lançamento\n");
				SortPrint(number, count);
                getch();
				free(number);
				system("CLS");
				break;
            case 5:
                tempoInicial = clock();
                /*number = criaVetor(number, count);
                if(number == NULL){
                    return printf("overFlow!!");
                }*/
                SortPrint(number, count);
                mergeSort(number, 0, count-1);
                tempoFinal = clock();
                tempoGasto = (tempoFinal - tempoInicial)/CLOCKS_PER_SEC;
				printf("Tempo gasto = > %f \n", tempoGasto);
				printf("fim do lançamento\n");
				SortPrint(number, count);
				getch();
				free(number);
				system("CLS");
				break;
			default:
				printf("aplicação encerrada");
				resp = 0;
        }
	}
}








