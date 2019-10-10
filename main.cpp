
#include "my_stack.h"

int main() {
    struct Stack_t stack = {};
    StackInit(&stack);

    StackPush(&stack, 40);
    StackPush(&stack, 1);
    StackPush(&stack, 11);

    int num = 0;
    StackPop(&stack, &num);

    StackPop(&stack, &num);

    //StackDump(&stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);
    //StackDump(&stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);
    //printf("This old stack ");
    /*for (int i = 0; i < stack.size; ++i) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");*/


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

    StackClose(&stack);

    return 0;
}
