#include <stdio.h>
#include <stdlib.h>

#define STRSIZE 10000
#define DEBUG if(0)

typedef struct{
	char item;
	struct node* tail;
	struct node* next;
}node;

node* createList(){
	return NULL;
}

int isEmpty(node *head){
	return (head==NULL);
}

node* clearList(node *head){
	node* aux = NULL;
	while (head->next != NULL){
		aux = head;
		head = head->next;
		aux->next = NULL;
		free(aux);
	}

	return NULL;
}

node* addToHead(node *head, char item){
	node *newNode;
	newNode = malloc(sizeof(node));
	newNode->item = item;
	newNode->next = head;
	if (isEmpty(head)) newNode->tail = newNode;
	else newNode->tail = head->tail;
	return newNode;
}

node* addToTail(node *head, char item){
	node *newNode;
	newNode = malloc(sizeof(node));
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty(head)) return (addToHead(head, item));

	node* tail = head->tail;
	tail->next = newNode;
	head->tail = newNode;
	return head;
}

node* removeByPointer(node *head, node *prev, node *current){
	prev->next = current->next;
	free(current);
	return head;
}

node* search(node *head, char item){
	while(head!=NULL){
		if (head->item==item) return head;
		else head = head->next;
	}
	return NULL;
}

node* invertList(node *head){
	int x;
	node *prev, *current;
	prev = head;
	current = head->next;
	while (current!=NULL){
		x = current->item;
		head = removeByPointer(head, prev, current);
		head = addToHead(head, x);
		current = prev->next;
	}
	return head;
}

void printList(node *head){
	if (isEmpty(head)) printf("List Underflow");
	else while (!isEmpty(head)){
		printf("%c ", head->item);
		head = head->next;
	}
	printf("\n");
	return;
}

void tratamentoDaEntrada(node* lista){
	char c, ant1, ant2;

	c = fgetc(stdin);
	ant1 = '.';
	ant2 = '.';
	
	while ((!((c=='\n')&&(ant1=='0')&&(ant2=='\n')))){
		if (ant1 != '.'){
			if (ant1!='\n') lista = addToTail(lista, ant1);
			else{
				DEBUG{printList(lista);}
				maiorIntervalo(lista);
				lista = clearList(lista);
				DEBUG{printList(lista);}
			}
		}
		

		ant2 = ant1;
		ant1 = c;

		if ((c = fgetc(stdin))==EOF) break;
	}
}

void maiorIntervalo(node* head){
	int a,b;
	int pos = 0;
	int max = 0;
	int maxPOS[2] = {0,0};
	int atual = 0;
	a = pos;
	b = pos;
	while (head!=NULL){
		DEBUG{printf("%c - ", head->item);}

		if (head->item == '0') {

			DEBUG{printf(" IF ");}

			atual++;

			DEBUG{printf("a = %d b = %d max = %d atual = %d\n", a,b,max,atual);}

			if (atual!=1) b++;

			if (atual>max){
				max = atual;
				maxPOS[0] = a;
				maxPOS[1] = b;
			}
		}else{

			DEBUG{printf(" ELSE ");}

			atual = 0;
			
			DEBUG{printf("a = %d b = %d max = %d atual = %d\n", a,b,max,atual);}

			if (atual>max){
				max = atual;
				maxPOS[0] = a;
				maxPOS[1] = b;
			}

			a = pos + 1;
			b = a;
		}
		head = head->next;
		pos++;
	}
	a = maxPOS[0];
	b = maxPOS[1];

	printf("%d %d\n", a,b);
}

int main(){

	node *lista;

	lista = createList();

	tratamentoDaEntrada(lista);

	return 0;
}
