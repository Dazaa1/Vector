#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
    int32_t *value;
    size_t capacity;
    size_t length;
} Vector;

// a function that help append new elements
void append(Vector* vector, int32_t value) {
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

// function to remove the last element
void pop(Vector* vector) {
    assert(vector->length >0 && "vector length should be higher than 0 to pop");
    vector->value[vector->length--] = 0;
}

void shift(Vector* vector) {
    assert(vector->length >0 && "vector length should be higher than 0 to pop");
    memmove(vector->value[0], vector->value[1], vector->capacity * sizeof(vector->value[0]));
    vector->length--;
}

int main() {
    Vector vector = {0};
    
    for (int32_t i = 1; i <= 10; i++) {
        append(&vector, i);
    }
    // poping three times
    for (int32_t i = 0; i < 3; i++) {
        pop(&vector);
    }


    for (int32_t i = 0; i < vector.length; i++) {
        printf("%d\n", vector.value[i]);
    }

    return (0);
}