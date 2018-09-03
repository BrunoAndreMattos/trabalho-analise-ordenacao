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

<<<<<<< HEAD
    int* arraySorted, arrayReversed, arrayRandom;
    int s = 1000;
=======
    int* array;
    int s = 100;
>>>>>>> 777f0e6ec51def25b5a75695cb609a806ad0838f
    int i;

    arraySorted = (int*) malloc(s*sizeof(int));
    arrayReversed = (int*) malloc(s*sizeof(int));
    arrayRandom = (int*) malloc(s*sizeof(int));

    printf("Tamanho %d\n\n",s);

<<<<<<< HEAD
    /** Bubble Sort **/
    printf("BUBBLE SORT\n");
    createSortedArray(arraySorted,s);
    createReversedArray(arrayReversed,s);
    createRandomArray(arrayRandom,s);

    printf("Random array\n");
    startTimer(&t);
    changes = bubbleSort(arrayRandom,s);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayRandom,s)?"sim":"nao"));
    printf("\n\n");

    printf("Reversed array\n");
    startTimer(&t);
    changes = bubbleSort(arrayReversed,s);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayReversed,s)?"sim":"nao"));
    printf("\n\n");

    printf("Sorted array\n");
    startTimer(&t);
    changes = bubbleSort(arraySorted,s);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arraySorted,s)?"sim":"nao"));
    printf("\n\n");


    /** Insertion Sort **/
    printf("INSERTION SORT\n");
    createSortedArray(arraySorted,s);
    createReversedArray(arrayReversed,s);
    createRandomArray(arrayRandom,s);

    printf("Random array\n");
    startTimer(&t);
    changes = insertionSort(arrayRandom,s);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayRandom,s)?"sim":"nao"));
    printf("\n\n");

    printf("Reversed array\n");
    startTimer(&t);
    changes = insertionSort(arrayReversed,s);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayReversed,s)?"sim":"nao"));
    printf("\n\n");

    printf("Sorted array\n");
    startTimer(&t);
    changes = insertionSort(arraySorted,s);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arraySorted,s)?"sim":"nao"));
    printf("\n\n");


    /** Binary Insertion Sort **/
    printf("BINARY INSERTION SORT\n");
    createSortedArray(arraySorted,s);
    createReversedArray(arrayReversed,s);
    createRandomArray(arrayRandom,s);

    printf("Random array\n");
    startTimer(&t);
    changes = binaryInsertionSort(arrayRandom,s);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayRandom,s)?"sim":"nao"));
    printf("\n\n");

    printf("Reversed array\n");
    startTimer(&t);
    changes = binaryInsertionSort(arrayReversed,s);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayReversed,s)?"sim":"nao"));
    printf("\n\n");

    printf("Sorted array\n");
    startTimer(&t);
    changes = binaryInsertionSort(arraySorted,s);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arraySorted,s)?"sim":"nao"));
    printf("\n\n");


    /** Insertion Shell Sort shell **/
    printf("INSERTION SHELL SORT shell\n");
    createSortedArray(arraySorted,s);
    createReversedArray(arrayReversed,s);
    createRandomArray(arrayRandom,s);
=======
    /* Bubble */
    printf("Bubble\n");
    createRandomArray(array,s);
    //printArray(array,s);
    printf("Tamanho %d\n",s);
>>>>>>> 777f0e6ec51def25b5a75695cb609a806ad0838f

    printf("Random array\n");
    startTimer(&t);
    changes = shellSort(arrayRandom,s,0);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayRandom,s)?"sim":"nao"));
    printf("\n\n");

<<<<<<< HEAD
    printf("Reversed array\n");
    startTimer(&t);
    changes = shellSort(arrayReversed,s,0);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayReversed,s)?"sim":"nao"));
    printf("\n\n");

    printf("Sorted array\n");
    startTimer(&t);
    changes = shellSort(arraySorted,s,0);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arraySorted,s)?"sim":"nao"));
    printf("\n\n");

    /** Insertion Shell Sort knuth **/
    printf("INSERTION SHELL SORT knuth\n");
    createSortedArray(arraySorted,s);
    createReversedArray(arrayReversed,s);
    createRandomArray(arrayRandom,s);

    printf("Random array\n");
    startTimer(&t);
    changes = shellSort(arrayRandom,s,1);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayRandom,s)?"sim":"nao"));
    printf("\n\n");

    printf("Reversed array\n");
    startTimer(&t);
    changes = shellSort(arrayReversed,s,1);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayReversed,s)?"sim":"nao"));
    printf("\n\n");
=======
    printf("trocas %lld, tempo %f\n",changes,time);
    printf("ordenado? %s\n",(isArraySorted(array,s)?"sim":"nao"));
    //printArray(array,s);
    printf("\n\n");

    /* Insertion */

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
    printf("\n\n");

    /* Binary Insertion */

    printf("Binary Insertion\n");
    createRandomArray(array,s);
    //printArray(array,s);
    printf("Tamanho %d\n",s);
>>>>>>> 777f0e6ec51def25b5a75695cb609a806ad0838f

    printf("Sorted array\n");
    startTimer(&t);
<<<<<<< HEAD
    changes = shellSort(arraySorted,s,1);
=======
    changes = binaryInsertionSort(array,s);
>>>>>>> 777f0e6ec51def25b5a75695cb609a806ad0838f
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arraySorted,s)?"sim":"nao"));
    printf("\n\n");


    /** Insertion Shell Sort tokuda **/
    printf("INSERTION SHELL SORT tokuda\n");
    createSortedArray(arraySorted,s);
    createReversedArray(arrayReversed,s);
    createRandomArray(arrayRandom,s);

<<<<<<< HEAD
    printf("Random array\n");
    startTimer(&t);
    changes = shellSort(arrayRandom,s,2);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayRandom,s)?"sim":"nao"));
    printf("\n\n");

    printf("Reversed array\n");
    startTimer(&t);
    changes = shellSort(arrayReversed,s,2);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arrayReversed,s)?"sim":"nao"));
    printf("\n\n");
=======
    printf("trocas %lld, tempo %f\n",changes,time);
    printf("ordenado? %s\n",(isArraySorted(array,s)?"sim":"nao"));
    //printArray(array,s);
    printf("\n\n");

    // changes = shellSort(array,s,0); // usando sequencia de Shell,1959
    // changes = shellSort(array,s,1); // usando sequencia de Knuth,1971
    // changes = shellSort(array,s,2); // usando sequencia de Tokuda,1992
>>>>>>> 777f0e6ec51def25b5a75695cb609a806ad0838f

    printf("Sorted array\n");
    startTimer(&t);
    changes = shellSort(arraySorted,s,2);
    time = stopTimer(&t);
    printf("trocas %lld, tempo %f\n", changes, time);
    printf("ordenado? %s\n",(isArraySorted(arraySorted,s)?"sim":"nao"));
    printf("\n\n");

    free(arrayRandom);
    free(arrayReversed);
    free(arraySorted);

    return 0;
}

/* SORTING Methods */
long long int bubbleSort(int *C, int n)
{
    long long int changes = 0;
<<<<<<< HEAD
    int i, t, j = n, s = 1;

=======

    int i, t, j = n, s = 1, changed;
>>>>>>> 777f0e6ec51def25b5a75695cb609a806ad0838f
    while(s) {
        s = 0;
        for (i = 1; i < j; i++) {
            if (C[i] < C[i - 1]) {
                t = C[i];
                C[i] = C[i - 1];
                C[i - 1] = t;
                s = 1;
                changed = i;
                changes++;
            }
        }
        j = changed;
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
			--j;
			changes++;
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
<<<<<<< HEAD
    int i, j, pos, key;

    for (j = 1; j < n; ++j)
    {
        i = j - 1;
        key = C[j];
        pos = binarySearch(C, 0, j, key);
        while (i >= pos)
        {
            C[i+1] = C[i];
            changes++;
            i--;
        }
        C[pos] = key;
    }
=======

    /* TODO: implementar codigo do binaryInsertionSort
       Usar funcao binarySearch para achar posicao onde inserir cada chave
       ex: posicao = binarySearch(C, 0, ultimoElementoOrdenado, chave)
    */
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = C[i];

        loc = binarySearch(C, 0, i, selected);

        // Move all elements after location to create space
        while (j >= loc)
        {
            C[j+1] = C[j];
            j--;
            changes++;
        }
        C[j+1] = selected;
    }

>>>>>>> 777f0e6ec51def25b5a75695cb609a806ad0838f
    return changes;
}

long long int insertionShellSort(int *C, int n, int h, int f)
{
    long long int changes = 0;
    int i, j, chave;

    for (j = (f + h); j < n; j += h)
    {
        chave = C[j];
        i = j - h;
        while(i >= 0 && C[i] > chave)
        {
            C[i + h] = C[i];
            i -= h;
            changes++;
        }
        C[i + h] = chave;
    }

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

