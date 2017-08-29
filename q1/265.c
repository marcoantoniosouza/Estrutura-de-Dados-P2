#include <stdio.h>
#include <string.h>

#define STRSIZE 100000

int charToInt(char c){
	return c;
}

char intToChar(int i){
	return i;
}

int strcount(char *s, char c){
	int count = 0;
	char *occ;
	occ = strchr(s,c);
	if (occ==NULL){
		return 0;
	}else{
		count++;
		count += strcount(occ+1,c);
	}
	return count;
}

typedef struct{
	char c;
	int q;
	struct node* next;
}node;

node* createList(){
	return NULL;
}

node* addToHead(node *head, char c,int q){
	node *newNode;
	newNode = (node*) malloc(sizeof(node));
	newNode->c = c;
	newNode->q = q;
	newNode->next = head;
	return newNode;
}

void printList(node *head){
	while (head!=NULL){
		printf("%c %d\n", head->c, head->q);	
		head = head->next;
	}
}

int main(){
	int i,quant;

	char str[STRSIZE];
	fgets(str, STRSIZE, stdin);

	node *lista;

	lista = createList();
	
	printList(lista);

	for (i = 32; i < 255; ++i){
		quant = strcount(str,intToChar(i));
		if (quant>0){
			lista = addToHead(lista, intToChar(i), quant);
			quant = 0;
		}
	}

	printList(lista);

	return 0;
}