typedef struct _stack stack_t;

stack_t* newStack();
int cap(stack_t *stack);
int size(stack_t *stack);
int peek(stack_t *stack);
int isEmpty(stack_t *stack);
int isFull(stack_t *stack);
void pop(stack_t *stack);
void destroy(stack_t *stack);
void push(stack_t *stack, int value);