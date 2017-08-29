#include <stdio.h>

void swap(int *a, int *b){
	int x;
	x = *b;
	*b = *a;
	*a = x;
}


typedef struct{
	int item;
	struct node* next;
}node;

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

node* swapNextNode(node *head, node *prev, node *current, node *next){
	node *aux;
	aux = next->next;
	if (prev==NULL){
		next->next = current;
		current->next = aux;
		return next;
	}
	prev->next = current->next;
	next->next = current;
	current->next = aux;
	return head;
}

void printList(node *head){
	while (head!=NULL){
		printf("%d ", head->item);	
		head = head->next;
	}
	printf("\n");
	return;
}

node* search(node *head, int item){
	while(head!=NULL){
		if (head->item==item) return head;
		else head = head->next;
	}
	return NULL;
}

int lengthList(node *head){
	int l = 0;
	while (head!=NULL){
		l++;
		head = head->next;
	}
	return l;
}

node* bubblesortList(node *head){
	int l,i,j;
	l = lengthList(head);
	node *prev, *current, *next;
	prev = NULL;
	
	for (i = 0; i < l-1; ++i){
		current = head;
		prev = NULL;
		for (j = 0; j < l-1; ++j){
			if (current == NULL) break;
			next = current->next;
			if ((current->item)>(next->item)){
				head = swapNextNode(head, prev, current, next);
				prev = (node*) next;
			}else{
				prev = (node*) current;
				current = (node*) current->next;
			}
		}
	}
	return head;
}

int main(){

	node *list;
	list = createList();

	int x;
	
	while(scanf("%d", &x)!=EOF){
		list = addToHead(list, x);
	}

	list = bubblesortList(list);

	printList(list);

	return 0;
}