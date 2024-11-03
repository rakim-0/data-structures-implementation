/*
    Code for writing a vector in C
    i.e a variable sized array.

    implement
        add
        resize
        clear
        delete
        find?
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    int size;    // cur number of elements
    int maxSize; // max number of elements
    int *first;  // pointer to first element
} vector;

vector *init()
{
    vector *vec = calloc(1, sizeof(vector));
    vec->first = malloc(sizeof(int));
    vec->size = 0;
    vec->maxSize = 1;
    return vec;
}

void print(vector *vec)
{
    if (vec == NULL || vec->first == NULL) {
        printf("NULL VECTOR");
        return;
    }
    printf("Vector: ");
    for (int i = 0; i < vec->size; i++) {
        printf("%d ", vec->first[i]);
    }
    return;
}

void resize(vector *vec)
{
    vec->maxSize = 2 * vec->maxSize;
    vec->first = realloc(vec->first, sizeof(int)*vec->maxSize);
}
void add(vector *vec, int element)
{
    if (vec == NULL) {
        vec = init();
    }
    if (vec->size+1 > vec->maxSize) {
        resize(vec);
    }
    *(vec->first+vec->size) = element;
    vec->size++;
}

int main()
{
    vector *vec = NULL;
    vec = init();
    for (int i = 0; i < 100; i++) {
        add(vec, i);
    }
    print(vec);
}