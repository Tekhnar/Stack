#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Elem_t;
typedef unsigned long long Bird_t;

bool StackInit(struct Stack_t* stack, int DEFAULT_LENGHT = 10, int DEFAULT_HYSTER = 3);
bool StackPush(Stack_t* stack,  Elem_t value);
Elem_t StackPop(Stack_t* stack, int* n_err);
unsigned MyHash(Stack_t* stack);
void StackVerific(Stack_t* stack);
void NewPointInStack(Stack_t* stack);
int AutoLenghtIncrease(Stack_t* stack);
int AutoLenghtDecrease(Stack_t* stack);
//unsigned int MurmurHashData (Stack_t* stack, unsigned int len);
unsigned int MurmurHash (Stack_t* stack, unsigned int len, unsigned int last_hash);
//unsigned int MurmurHashStack (Stack_t* stack, unsigned int len);
void StackDump(Stack_t* stack, const char welcome[], const char name_file[], const int line_prog, const char which_func[]);
void NewHash(Stack_t* stack);

//const int DEFAULT_LENGHT = 10;
const Elem_t POISON = -777;
const int FACTOR_DYNAMIC = 2;

struct Stack_t{
    Bird_t st_bird1;

    Elem_t* data;
    void* buffer; // 'void *' for show that it is not data

    Bird_t* buf_bird1; // or better do with 'void *'
    Bird_t* buf_burd2;

    int size;
    int lenght;

//    int last_max;
    int hyster;
    unsigned int hash_data;
    unsigned int hash_stack;

    Bird_t st_bird2;
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
//    StackDump(&stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);

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

    Elem_t value = StackPop(&stack, &n_err);

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

#define LEN_STACK (unsigned int)(stack->st_bird2 -  stack->st_bird1  + sizeof(stack->st_bird1))
#define LEN_DATA  (unsigned int)(stack->buf_burd2 -  stack->buf_bird1 + sizeof(*stack->buf_burd2))

Elem_t StackPop(Stack_t* stack, int* n_err) {
    StackVerific(stack);

    if (stack->size < 0) *n_err = 1;
    assert(stack->size != 0);

    Elem_t value = stack->data[--stack->size];

    stack->data[stack->size] = POISON;

    AutoLenghtDecrease(stack);

    NewHash(stack);
    StackVerific(stack);
    return value;
}

void NewPointInStack(Stack_t* stack){
    assert(stack != nullptr);
    assert(stack->buffer != nullptr);

    stack->data = (Elem_t*) ((char*)stack->buffer + sizeof(Bird_t));
    stack->buf_bird1 = (Bird_t*) stack->buffer;
    stack->buf_burd2 = (Bird_t*) ((char*)stack->buffer + stack->lenght * sizeof(Elem_t) + sizeof(Bird_t));

    assert(stack->data != nullptr);
    assert(stack->buf_bird1 != nullptr);
    assert(stack->buf_burd2 != nullptr);
}

bool StackPush(Stack_t* stack,  Elem_t value) {
    StackVerific(stack);
//    printf("hash_data %u\n", stack->hash_data);
//    printf("hash_data %u\n", MurmurHashData(stack));

    AutoLenghtIncrease(stack);

    if (stack->size > stack->lenght - 1) return false;
    stack->data[stack->size++] = value;
//
//    printf("Value - %d\n", value);
//    printf("Stack - %d", stack->data[stack->size - 1]);

    NewHash(stack);
    StackVerific(stack);

    //StackDump(stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);
    return true;
}

void NewHash(Stack_t *stack) {
    assert(stack != nullptr);
    assert(stack->buffer != nullptr);

    stack->hash_data  = MurmurHash(stack, LEN_DATA, stack->hash_data);
    stack->hash_stack = MurmurHash(stack, LEN_STACK, stack->hash_stack);
}

void StackVerific(Stack_t *stack) {
    assert(stack != nullptr);
    assert(stack->buffer != nullptr);
    assert(stack->hash_data  == MurmurHash(stack, LEN_DATA, stack->hash_data));
    assert(stack->hash_stack == MurmurHash(stack, LEN_STACK, stack->hash_stack));

    //StackDump(stack, "Debug", __FILE__, __LINE__, __PRETTY_FUNCTION__);
    if (stack->st_bird1 != stack->st_bird2){
        printf("Error in birds of stack\nI refuse to work!\n");
        assert(stack->st_bird1 == stack->st_bird2);
    }

    if (stack->size < 0){
        printf("Size of stack < 0\nI refuse to work!\n");
        assert(stack->size < 0);
    }

    for (int i = stack->size; i < stack->lenght; i++){
        if (stack->data[i] != POISON){
            printf("Error in poison number\nI refuse to work!\n");
            assert(stack->data[i] == POISON);
        }
    }
    //printf("hash_data - %u\n", MyHash(stack));
}


bool StackInit(struct Stack_t* stack, int DEFAULT_LENGHT ,int DEFAULT_HYSTER) {
    assert(stack != nullptr);

    stack->lenght = 10;
    stack->st_bird1 = 0xDEADBEEF;
    stack->st_bird2 = stack->st_bird1;
    stack->size = 0;
    //stack->last_max = 0;
    stack->hyster = DEFAULT_HYSTER;
    stack->lenght = DEFAULT_LENGHT;

    stack->buffer = (void*) calloc(stack->lenght * sizeof(Elem_t) + 2 * sizeof(Bird_t), sizeof(char));
    assert(stack->buffer != nullptr);
    NewPointInStack(stack);

    // 'POISON' it is poisonous value in my stack //
    for (int i = stack->size; i < stack->lenght; ++i) {
        stack->data[i] = POISON;
    }
    stack->hash_data  = MurmurHash(stack, LEN_DATA, stack->hash_stack);
    stack->hash_stack = MurmurHash(stack, LEN_STACK, stack->hash_data);
    return true;
}

/*unsigned MyHash(Stack_t* stack){
    unsigned int sum = 0;
    int size = (int)(&stack->st_bird2 - &stack->st_bird1 + sizeof(stack->st_bird2));
    for (int i = 0; i < size; ++i) {
        sum = sum * 33 + (unsigned int) *(((const unsigned char *) &stack->st_bird1) + i);
        // printf("sum - %u\n", sum);
    }
    return sum;
}*/

unsigned int MurmurHash (Stack_t* stack, unsigned int len, unsigned int last_hash)
{
    const unsigned int m = 0x5bd1e995;
    const unsigned int seed = 0;
    const int r = 24;

    const unsigned char * data = (const unsigned char *) &stack->st_bird1;
    //unsigned int len = stack->st_bird2 - stack->st_bird1 + sizeof(stack->st_bird1);
    unsigned int h = seed ^ len;

   last_hash = stack->hash_stack;
    stack->hash_stack  = 0;
    // const unsigned char * data = (const unsigned char *)key;
    unsigned int k = 0;

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

    stack->hash_stack = last_hash;
    return h;
}

int AutoLenghtIncrease(Stack_t *stack) {
    assert(stack != nullptr);
    assert(stack->buffer != nullptr);

    if ((stack->lenght) == stack->size) {
        void *point = nullptr;

        //printf("%lu", FACTOR_DYNAMIC * stack->lenght * sizeof(Elem_t) + FACTOR_DYNAMIC * sizeof(Bird_t));
        point = realloc((stack->buffer), (FACTOR_DYNAMIC * stack->lenght * sizeof(Elem_t) + FACTOR_DYNAMIC * sizeof(Bird_t)));
        if (point == nullptr) {
            printf("Error in realloc()\n");
            assert(point != nullptr);
        }
        stack->buffer = point;
        stack->lenght *= FACTOR_DYNAMIC;

        NewPointInStack(stack);

        for (int i = stack->size; i < stack->lenght; ++i) {
            stack->data[i] = POISON;
        }
        //stack->last_max;
    }
    return 0;
}

void StackDump(Stack_t *stack, const char welcome[], const char name_file[], const int line_prog, const char which_func[]){
    assert(stack != nullptr);

    printf("Dump (%s) From %s (%d) %s\n", welcome, name_file, line_prog, which_func);
    printf("\tStack[%p]\n", stack);
    printf("\t{\n");
    printf("\tst_bird1 = %llX\n", stack->st_bird1);
    printf("\tsize = %d\n", stack->size);
    printf("\tdata [%d][%p]\n", stack->lenght, &stack->data);
    printf("\t\t{\n");
    for (int i = 0; i < stack->lenght; ++i) {
        if (i < stack->size){
            printf("\t\t*[%d] = %d\n", i, stack->data[i]);

        } else{
            printf("\t\t [%d] = %d(POISON)\n", i, stack->data[i]);
        }
    }
    printf("\t\t}\n");
    //printf("\t\tError = %d\n", err);
    printf("\t\tst_bird2 = %llX\n", stack->st_bird2);
    printf("\t\thash_data = %u\n", stack->hash_data);
    printf("\t}\n");
}

int AutoLenghtDecrease(Stack_t *stack) {
    assert(stack != nullptr);
    assert(stack->buffer != nullptr);

    if ((stack->lenght / FACTOR_DYNAMIC - stack->hyster) >=  stack->size){
        void *point = nullptr;

        point = realloc(stack->buffer, (stack->lenght / FACTOR_DYNAMIC * sizeof(Elem_t) + FACTOR_DYNAMIC * sizeof(Bird_t)));
        if (point == nullptr) {
            printf("Error in realloc()\n");
            assert(point != nullptr);
        }

        stack->buffer = point;
        stack->lenght /= FACTOR_DYNAMIC;

        NewPointInStack(stack);
    }
    return 0;
}

#undef LEN_STACK
#undef LEN_DATA
