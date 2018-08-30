#include <stdio.h>      /* printf */
#include <stdlib.h>     /* srand, malloc, free */
#include <math.h>       /* ceil */
#include <unistd.h>     /* usleep */
#include <string.h>     /* memcpy, strcmp */
#include <time.h>       /* time */
#include <sys/time.h>   /* struct timeval, gettimeofday */

/* HEADERS */
long long int bubbleSort(int* C, int n);

long long int insertionSort(int* C, int n);

long long int binaryInsertionSort(int* C, int n);

long long int shellSort(int* C, int n, int typeSequence);

typedef struct{
    struct timeval start;
    struct timeval end;
} Timer;

void startTimer(Timer* t);
float stopTimer(Timer* t);

void createSortedArray(int* C, int size);
void createReversedArray(int* C, int size);
void createRandomArray(int* C, int size);
int isArraySorted(int* C, int size);
void printArray(int* C, int size);

/* MAIN */
int main()
{
    srand(time(NULL));

    Timer t;
    float time;
    long long int changes;

    int* array;
    int s = 10000;
    int i;

    array = (int*) malloc(s*sizeof(int));

    /* Gera configuracao do array */
    // createSortedArray(array,s);
    // createReversedArray(array,s);

    printf("Bubble\n");
    createRandomArray(array,s);

    //printArray(array,s);

    printf("Tamanho %d\n",s);

    startTimer(&t);
    changes = bubbleSort(array,s);
    time = stopTimer(&t);

    printf("trocas %lld, tempo %f\n",changes,time);
    printf("ordenado? %s\n",(isArraySorted(array,s)?"sim":"nao"));
    //printArray(array,s);

    printf("\n\n");

    printf("Insertion\n");
    createRandomArray(array,s);

    //printArray(array,s);

    printf("Tamanho %d\n",s);

    startTimer(&t);
    changes = insertionSort(array,s);
    time = stopTimer(&t);

    printf("trocas %lld, tempo %f\n",changes,time);
    printf("ordenado? %s\n",(isArraySorted(array,s)?"sim":"nao"));
    //printArray(array,s);

    // changes = binaryInsertionSort(array,s);
    // changes = shellSort(array,s,0); // usando sequencia de Shell,1959
    // changes = shellSort(array,s,1); // usando sequencia de Knuth,1971
    // changes = shellSort(array,s,2); // usando sequencia de Tokuda,1992


    free(array);

    return 0;
}

/* SORTING Methods */
long long int bubbleSort(int *C, int n)
{
    long long int changes = 0;

    /* TODO: implementar codigo do bubbleSort */

    int i, t, j = n, s = 1;
    while(s) {
        s = 0;
        for (i = 1; i < j; i++) {
            if (C[i] < C[i - 1]) {
                t = C[i];
                C[i] = C[i - 1];
                C[i - 1] = t;
                s = 1;
                changes++;
            }
        }
        j--;
    }
    return changes;
}

long long int insertionSort(int* C, int n)
{
    long long int changes = 0;

    for(size_t i = 1; i < n; ++i) {
		int tmp = C[i];
		size_t j = i;
		while(j > 0 && tmp < C[j - 1]) {
			C[j] = C[j - 1];
			changes++;
			--j;
		}
		C[j] = tmp;
	}

    return changes;
}

int binarySearch(int* data, int inf, int sup, int key)
{
    int half;
    if (inf == sup)
        return inf;
    half = inf + ((sup-inf)/2);
    if (key > data[half])
        return binarySearch(data, half+1, sup, key);
    else if (key < data [half])
        return binarySearch(data, inf, half, key);
    return half;
}

long long int binaryInsertionSort(int *C, int n)
{
    long long int changes = 0;

    /* TODO: implementar codigo do binaryInsertionSort
       Usar funcao binarySearch para achar posicao onde inserir cada chave
       ex: posicao = binarySearch(C, 0, ultimoElementoOrdenado, chave)
    */



    return changes;
}

long long int insertionShellSort(int *C, int n, int h, int f)
{
    long long int changes = 0;

    /* TODO: implementar codigo do insertionShellSort */



    return changes;
}

int* generateGapSequence(int maxElem, int type, int* seqSize)
{
    int* seq;
    int i,e=1,numElems=1;
    if(type==0){
        /* (Shell,1959) - sequencia 1, 2, 4, 8, 16, 32, ...*/
        while(e<maxElem){
            e *= 2;
            numElems++;
        }
        numElems--;
        seq = (int*) malloc(numElems*sizeof(int));
        e=1;
        for(i=0;i<numElems;i++){
            seq[i] = e;
            e *= 2;
        }
    }else if(type==1){
        /* (Knuth,1971) - sequencia 1, 4, 13, 40, 121, 364, ...*/
        while(e<maxElem){
            e = e*3+1;
            numElems++;
        }
        numElems--;
        seq = (int*) malloc(numElems*sizeof(int));
        e=1;
        for(i=0;i<numElems;i++){
            seq[i] = e;
            e = e*3 + 1;
        }
    }else if(type==2){
        /* (Tokuda,1992) - sequencia 1, 4, 9, 20, 46, 103, ...*/
        numElems=0;
        while(e<maxElem){
            e = (ceil((9.0 * pow(9.0,numElems)/pow(4.0,numElems) - 4.0)/5.0));
            numElems++;
        }
        numElems--;
        seq = (int*) malloc(numElems*sizeof(int));
        for(i=0;i<numElems;i++){
            e = (ceil((9.0 * pow(9.0,i)/pow(4.0,i) - 4.0)/5.0));
            seq[i] = e;
        }
    }

    *seqSize = numElems;
    return seq;
}

long long int shellSort(int *C, int n, int typeSequence)
{
    int numElems;
    int* sequence = generateGapSequence(n,typeSequence,&numElems);

    printf("Sequencia ");
    printArray(sequence,numElems);

    long long int changes = 0;
    int i, h, f;

    for(i=numElems-1; i>=0; i--){
        h = sequence[i];
        for(f=0; f<h; f++){
            changes += insertionShellSort(C,n,h,f);
        }
    }

    free(sequence);

    return changes;
}

/* TIMER Methods */
void startTimer(Timer* t)
{
    gettimeofday(&(t->start), NULL);
}

float stopTimer(Timer *t)
{
    gettimeofday(&(t->end), NULL);

    if (t->start.tv_usec > t->end.tv_usec) {
        t->end.tv_usec += 1000000;
        t->end.tv_sec--;
    }

    return (float)(t->end.tv_sec - t->start.tv_sec) +
           ((float)t->end.tv_usec - (float)t->start.tv_usec)/1000000.0;
}

/* ARRAY Methods */
void createSortedArray(int* C, int size)
{
    int i;
    for(i=0; i<size; i++)
        C[i] = i;
}

void createReversedArray(int* C, int size)
{
    int i, j=size-1;
    for(i=0; i<size; i++){
        C[i] = j--;
    }
}

void createRandomArray(int* C, int size)
{
    int i;
    for(i=0; i<size; i++)
        C[i] = i;

    int s;
    for(s=size; s>0; s--){
        int index = rand()%s;

        /* troca C[index] com C[s-1] */
        int temp = C[s-1];
        C[s-1] = C[index];
        C[index] = temp;
    }
}

int isArraySorted(int* C, int size)
{
    int i;
    for(i=0; i<size-1; i++){
        if(C[i]>C[i+1])
            return 0;
    }
    return 1;
}

void printArray(int* C, int size)
{
    if(size>0){
        int i;
        printf("[");
        for(i=0; i<size; i++)
            printf("%d ",C[i]);
        printf("]\n");
    }
}

