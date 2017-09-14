#include <stdio.h>
#include <stdlib.h>

typedef struct _node node;

struct _node{
	int item;
	node* next;
};

node* createList(){
	return NULL;
}

node* addToHead(node *head, int item){
	node *newNode;
	newNode = (node*) malloc(sizeof(node));
	newNode->item = item;
	newNode->next = head;
	return newNode;
}

void printList(node *head){
	while (head!=NULL){
		printf("%d\n", head->item);	
		head = head->next;
	}
}

int hasInList(node *head, int x){
	node *current;
	current = head;
	while(current!=NULL){
		if (current->item==x){
			return 1;
		}
		current = current->next;
	}
	return 0;
}

int bCa(node *a, node *b){
	node *current;
	current = b;

	while(current!=NULL){
		if (!(hasInList(a, b->item))){
			return 0;	
		}
		current = current->next;
	}

	return 1;
}

int main(){

	node *listaA;
	node *listaB;
	int n,m,i,x;

	listaA = createList();
	listaB = createList();

	scanf("%d", &n);

	for (i = 0; i < n; ++i){
		scanf("%d", &x);
		listaA = addToHead(listaA, x);
	}

	scanf("%d", &m);

	for (i = 0; i < m; ++i){
		scanf("%d", &x);
		listaB = addToHead(listaB, x);
	}

	//printList(listaA);
	//printf("-----------\n");
	//printList(listaB);

	printf("%d\n", bCa(listaA, listaB));

	return 0;
}