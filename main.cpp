#include <iostream>
#include <stdio.h>
//#include <stdlib.h>
#include <assert.h>

typedef int Elem_t;

const int LENGHT = 100;
bool StackInit(struct Stack_t* stack);
bool StackPush(Stack_t* stack,  Elem_t value);
Elem_t StackPop(Stack_t* stack, int* n_err);

struct Stack_t{
    Elem_t data[LENGHT];
    int size;
};

int main() {
    struct Stack_t stack = {};
    StackInit(&stack);

    StackPush(&stack, 40);
//    printf("This old stack ");
//    for (int i = 0; i < stack.size; ++i) {
//        printf("%d ", stack.data[i]);
//    }
//    printf("\n");

    int n_err = 0;
    Elem_t value = StackPop(&stack, &n_err);

    printf("This stack ");
    for (int i = 0; i < stack.size; ++i) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");


//    for (int i = 0; i < stack.size; ++i) {
//        printf("%d ", stack.data[i]);
//    }
    return 0;
}

Elem_t StackPop(Stack_t* stack, int* n_err) {
    assert(stack != nullptr);

    if (stack->size < 1) *n_err = 1;
    return stack->data[--stack->size];
}

bool StackPush(Stack_t* stack,  Elem_t value) {
    assert(stack != nullptr);

    if (stack->size >= LENGHT - 1) return false;
    stack->data[stack->size++] = value;
//    printf("Value - %d\n", value);
//    printf("Stack - %d", stack->data[stack->size - 1]);
    return true;
}

bool StackInit(struct Stack_t* stack) {
    assert(stack != nullptr);

    stack->size = 0;
    return 0;
}


