
#include "my_stack.h"

int main() {
    struct Stack_t stack = {};
    StackInit(&stack);

    StackPush(&stack, 40);
    StackPush(&stack, 1);
    StackPush(&stack, 2);
    StackPush(&stack, 3);
    StackPush(&stack, 4);
    StackPush(&stack, 5);
    StackPush(&stack, 6);
    StackPush(&stack, 7);
    StackPush(&stack, 8);
    StackPush(&stack, 9);
    StackPush(&stack, 10);
    StackPush(&stack, 11);

    int n_err = 0;
    StackPop(&stack, &n_err);
    StackPop(&stack, &n_err);
    StackPop(&stack, &n_err);
    StackPop(&stack, &n_err);
    StackPop(&stack, &n_err);
    StackPop(&stack, &n_err);
    StackPop(&stack, &n_err);

//    StackDump(&stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);
    //StackDump(&stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);
    //printf("This old stack ");
    /*for (int i = 0; i < stack.size; ++i) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");*/

    StackPop(&stack, &n_err);

    //StackDump(&stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    //printf("This stack ");
   /* for (int i = 0; i < stack.size; ++i) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");*/

//    for (int i = 0; i < stack.size; ++i) {
//        printf("%d ", stack.data[i]);
//    }

    //printf("bird 1 - %p\ndata   - %p\nbird 1 - %p\n ", &stack.st_st_bird1, &stack.data, &stack.st_bird2);
    return 0;
}