//#include <iostream>
#include <stdio.h>
//#include <stdlib.h>
#include <assert.h>

typedef int Elem_t;
typedef unsigned long long Bird_t;
const int LENGHT = 100;
const Elem_t POISON = -777;
bool StackInit(struct Stack_t* stack);
bool StackPush(Stack_t* stack,  Elem_t value);
Elem_t StackPop(Stack_t* stack, int* n_err);

void StackVerific(Stack_t *stack);

struct Stack_t{
    Bird_t bird1;
    Elem_t data[LENGHT];
    int size;
    Bird_t bird2;
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

//    printf("This stack ");
//    for (int i = 0; i < stack.size; ++i) {
//        printf("%d ", stack.data[i]);
//    }
//    printf("\n");


//    for (int i = 0; i < stack.size; ++i) {
//        printf("%d ", stack.data[i]);
//    }
    return 0;
}

Elem_t StackPop(Stack_t* stack, int* n_err) {
    assert(stack != nullptr);
    StackVerific(stack);

    if (stack->size < 1) *n_err = 1;
    Elem_t value = stack->data[--stack->size];
    stack->data[stack->size + 1] = POISON;

    return stack->data[--stack->size];
}

void StackVerific(Stack_t *stack) {
    if (stack->bird1 != 0xDEADBEEF){
        printf("First bird invasion!!!\nNew value bird %llX\nI refuse to work!", stack->bird1);
    }
    if (stack->bird2 != 0xDEADBEEF){
        printf("Second bird invasion!!!\nNew value bird %llX\nI refuse to work!", stack->bird2);
    }

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

    stack->bird1 = 0xDEADBEEF;
    stack->bird2 = 0xDEADBEEF;
    stack->size = 0;

    // 'POISON' it is poisonous value in my stack //
    for (int i = 0; i < LENGHT; ++i) {
        stack->data[i] = POISON;
    }
    return 1;
}
