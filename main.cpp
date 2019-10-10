
#include "my_stack.h"

int main() {
    struct Stack_t stack = {};
    StackInit(&stack);

    StackPush(&stack, 40);
    StackPush(&stack, 1);
    StackPush(&stack, 1);

    int num = 0;
    StackPop(&stack, &num);

    StackDump(&stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    return 0;
}