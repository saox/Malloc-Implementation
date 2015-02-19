

#ifndef _ArrayList_h
#define _ArrayList_h
#include <stdlib.h>

#ifndef al_data
#define al_data double
#endif

typedef struct array_list ArrayList;

void add_al(ArrayList * al, al_data i);
void expandOrReduce_al(ArrayList * al, int size);
int size_al(ArrayList * al);
void remove_al(ArrayList * al, int index);
void insert_al(ArrayList * al, int index, al_data element);
void set_al(ArrayList * al, int index, al_data element);

struct array_list {
    int arraySize;
    int position;
    al_data * array;
};

/* Inserts an elements at the given position */
void insert_al(ArrayList * al, int index, al_data element){
	int i;
    if(index>=size_al(al) || index<0){
        printf("ERROR: ARRAY INDEX OUT OF BOUNDS: %d", index);
        exit(1);
    }
    
    if(al->position >= al->arraySize)
        expandOrReduce_al(al,al->arraySize*2);

    for (i = index; i<al->position; i++) {
        al->array[index+1] = al->array[index];
    }
    
    al->array[index] = element;
    
    al->position++;
    
}

/* removes the specified element */
void remove_al(ArrayList * al, int index){
	int i;
    if(index>=size_al(al) || index<0){
        printf("ERROR: ARRAY INDEX OUT OF BOUNDS: %d", index);
        exit(1);
    }
    
    
    if (al->position < al->arraySize/2 && al->arraySize > 10)
        expandOrReduce_al(al,al->arraySize/2);
    
    
    for (i = index; i<al->position-1; i++) {
        al->array[i] = al->array[i+1];
    }

al->position--;

}

/* Adds an element to the end of the list */
void add_al(ArrayList * al, al_data i){

    if(al->position >= al->arraySize)
        expandOrReduce_al(al,al->arraySize*2);
    
    al->array[al->position] = i;
    
    
    
    al->position++;
}

/* sets the value of the given index */
void set_al(ArrayList * al, int index, al_data element){
    if(index>=size_al(al) || index<0){
        printf("ERROR: ARRAY INDEX OUT OF BOUNDS: %d", index);
        exit(1);
    }
    
    al->array[index] = element;
    
}

/* returns specified element */
al_data get_al(ArrayList * al, int index){
    if(index>=size_al(al) || index<0){
        printf("ERROR: ARRAY INDEX OUT OF BOUNDS: %d", index);
        exit(1);
    }
    
    return al->array[index];
}

/* returns size */
int size_al(ArrayList * al){
    return al->position;
}

/* FOR INTERNAL USE ONLY! */
void expandOrReduce_al(ArrayList * al, int size){
        int i;
    al->arraySize = size;
    al_data * array = (al_data *) malloc(sizeof(al_data)*size);
    
    for (i = 0; i<al->position; i++) {
        array[i] = al->array[i];
    }
    
    free(al->array);
    
    al->array = array;
    
}

/* prints values */
void print_al(ArrayList * al){
	int i;
    printf("[");
    for (i = 0; i<al->position - 1; i++) {
        printf("%f, ", get_al(al, i));
    }
    
    printf("%f]\n", al->array[al->position-1]);
}

void destroy_al(ArrayList * al){
    free(al->array);
    free(al);
}

int indexOf_al(ArrayList * al, al_data element){
	int i;
    for (i = 0; i<size_al(al); i++) {
        if (get_al(al, i) == element)
            return i;
    }
    return -1;
}

int contains_al(ArrayList * al, al_data element){
    return indexOf_al(al, element) != -1;
}

al_data mean_al(ArrayList * al){
	int i;
	al_data acc = 0;
    for (i = 0; i<size_al(al); i++) {
        acc += get_al(al, i);
    }
    
    return acc / size_al(al);
}

ArrayList * newArrayList(int size){
    al_data * array = (al_data *) malloc(sizeof(al_data)*size);
    ArrayList * al = (ArrayList *) malloc(sizeof(ArrayList));
    al->arraySize = size;
    al->position = 0;
    al->array = array;
    return al;
}




#endif
