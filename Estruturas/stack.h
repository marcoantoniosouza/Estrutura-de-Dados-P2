#include "stack.c"

typedef struct _stack stack;

stack* createStack(); //
int cap(stack *stack);
int size(stack *stack); //
int peek(stack *stack);
int stackIsEmpty(stack *s); //
int stackisFull(stack *stack); //
void pop(stack *stack); //
void destroy(stack *stack);
void push(stack *stack, int value); //