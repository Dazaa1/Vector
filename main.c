#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int *value;
    int32_t capacity;
    int32_t length;
} Vector;

// a function that help append new elements
void append(Vector* vector, int value) {
    if (vector->length >= vector->capacity) {
        if (vector->capacity ==0) vector->capacity = 2;
        else {
            vector->capacity *= 2;
        }
        
        vector->value = realloc(vector->value, vector->capacity * sizeof(vector->value[0]));
        printf("resized\n");
    }

    vector->value[vector->length++] = value;
}

int main() {
    Vector vector = {0};
    
    for (int32_t i = 1; i <= 10; i++) {
        append(&vector, i);
    }

    for (int32_t i = 0; i < vector.length; i++) {
        printf("%d\n", vector.value[i]);
    }

    return (0);
}