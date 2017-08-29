#define INT_MAX 255

typedef struct _node node_t;

struct _node {  
	int value;
	node_t *bot;
};

struct _stack {
	int size;
	int cap;
	node_t *top;
};

node_t* newNode(int value) {
	node_t *temp = (node_t*) malloc(sizeof(node_t));
	temp->value = value;
	temp->bot = NULL;
	return temp;
}

stack_t* newStack() {
	stack_t *temp = (stack_t*) malloc(sizeof(stack_t));
	temp->size = 0;
	temp->cap  = INT_MAX;
	return temp;
}

int  cap(stack_t *stack) {
	return stack->cap;
}

int  size(stack_t *stack) {
	return (stack->size);
}

int  peek(stack_t *stack) {
	if(isEmpty(stack)) return INT_MIN;
	return (stack->top->value);
}

int isEmpty(stack_t *stack) {
	return(!stack->size);
}

int isFull(stack_t *stack) {
	return(!(stack->size != stack->cap));
}

void pop(stack_t *stack) {
	if(isEmpty(stack)) return;
	node_t *temp = stack->top->bot;
	DEBUG printf("pop %d\n", stack->top->value);
	free(stack->top);
	stack->top = temp;
	--stack->size;
}

void destroy(stack_t *stack) {
	while(!isEmpty(stack))
		pop(stack);
	free(stack); 
}

void push(stack_t *stack, int value) {
	if(isFull(stack)) return;
	node_t *temp = newNode(value);
	if(isEmpty(stack))
		stack->top = temp;
	else {
		temp->bot  = stack->top;
		stack->top = temp;
	}

	DEBUG printf("push %d\n", temp->value);

	++stack->size;
}