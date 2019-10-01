#include <stdio.h>
#include <assert.h>

typedef int Elem_t;
typedef unsigned long long Bird_t;

bool StackInit(struct Stack_t* stack);
bool StackPush(Stack_t* stack,  Elem_t value);
Elem_t StackPop(Stack_t* stack, int* n_err);
unsigned MyHash(Stack_t* stack);
void StackVerific(Stack_t *stack);
//unsigned int MurmurHash2 (Stack_t* stack);

const int LENGHT = 100;
const Elem_t POISON = -777;

struct Stack_t{
    Bird_t bird1;
    Elem_t data[LENGHT];
    int size;
    unsigned int hash;
    Bird_t bird2;
};

int main() {
    struct Stack_t stack = {};
    StackInit(&stack);

    /*while (1){
        Elem_t temp = 0;
        if (scanf("push %d", &temp))
            StackPush(&stack, temp);
        int err = 0;
        int i = 0;
        if (scanf("pop %d", &i))
            StackPop(&stack, &err);
        for (int i = 0; i < stack.size; ++i) {
        printf("%d ", stack.data[i]);
        }
        while (getchar() != '\n');

    printf("\n");
    }*/
    StackPush(&stack, 40);
    StackPush(&stack, 1);
    StackPush(&stack, 2);

   // void StackDump(Stack_t *stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);
    //printf("This old stack ");
    /*for (int i = 0; i < stack.size; ++i) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");*/

    int n_err = 0;
    Elem_t value = StackPop(&stack, &n_err);

    //printf("This stack ");
   /* for (int i = 0; i < stack.size; ++i) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");*/

//    for (int i = 0; i < stack.size; ++i) {
//        printf("%d ", stack.data[i]);
//    }

    //printf("bird 1 - %p\ndata   - %p\nbird 1 - %p\n ", &stack.bird1, &stack.data, &stack.bird2);
    return 0;
}

Elem_t StackPop(Stack_t* stack, int* n_err) {
    assert(stack != nullptr);
    StackVerific(stack);

    assert(stack->hash == MyHash(stack));

    if (stack->size < 1) *n_err = 1;
    assert(stack->size != 0);
    Elem_t value = stack->data[--stack->size];
    stack->data[stack->size + 1] = POISON;

    stack->hash = MyHash(stack);

    return stack->data[stack->size];
}

bool StackPush(Stack_t* stack,  Elem_t value) {
    assert(stack != nullptr);
    StackVerific(stack);
    assert(stack->hash == MyHash(stack));


    if (stack->size >= LENGHT - 1) return false;
    stack->data[stack->size++] = value;
//    printf("Value - %d\n", value);
//    printf("Stack - %d", stack->data[stack->size - 1]);
    stack->hash = MyHash(stack);
    return true;
}

void StackVerific(Stack_t *stack) {
    if (stack->bird1 != 0xDEADBEEF){
        printf("First bird invasion!!!\nNew value bird %llX\nI refuse to work!\n", stack->bird1);
    }
    if (stack->bird2 != 0xDEADBEEF){
        printf("Second bird invasion!!!\nNew value bird %llX\nI refuse to work!\n", stack->bird2);
    }
    if (stack->size < 0){
        printf("Size of stack < 0\nI refuse to work!\n");
    }

    for (int i = stack->size; i < LENGHT; i++){
        if (stack->data[i] != POISON){
            printf("Error in poison number\nI refuse to work!\n");
        }
    }
    //printf("Hash - %u\n", MyHash(stack));
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
    stack->hash = MyHash(stack);
    return true;
}

unsigned MyHash(Stack_t* stack){
    unsigned int sum = 0;
    int size = (int)(&stack->bird2 - &stack->bird1 + sizeof(stack->bird2));
    for (int i = 0; i < size; ++i) {
        sum = sum * 33 + (unsigned int) *(((const unsigned char *) &stack->bird1) + i);
        // printf("sum - %u\n", sum);
    }
    return sum;
}

/*unsigned int MurmurHash2 (Stack_t* stack)
{
    const unsigned int m = 0x5bd1e995;
    const unsigned int seed = 0;
    const int r = 24;

    const unsigned char * data = (const unsigned char *)stack->bird1;
    unsigned int len = stack->bird2 - stack->bird1 + sizeof(stack->bird2);
    unsigned int h = seed ^ len;


    unsigned int temp = stack->hash;
    stack->hash  = 0;
   // const unsigned char * data = (const unsigned char *)key;
    unsigned int k;

    while (len >= 4)
    {
        k  = data[0];
        k |= data[1] << 8;
        k |= data[2] << 16;
        k |= data[3] << 24;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len)
    {
        case 3:
            h ^= data[2] << 16;
        case 2:
            h ^= data[1] << 8;
        case 1:
            h ^= data[0];
            h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    stack->hash = temp;
    return h;
}*/
/*
void StackDump(Stack_t *stack, const char welcome[], const char name_file, const char line_prog __LINE__, const char which_func __PRETTY_FUNCTION__){
    printf("Dumb (%s) From %s (%")
}*/

