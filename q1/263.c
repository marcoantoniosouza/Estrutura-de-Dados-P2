#include <stdio.h>
#define ARRAYSIZE 20
#define DEBUG if(0)

void swap(int *a, int *b){
	int x;
	x = *b;
	*b = *a;
	*a = x;
}

void quicksort(int *v, int size) {
	if (size <= 1) {
		return;
	} else {
		int pivot = v[size / 2];
		int a = 0; int b = size - 1;
		while (a < b) {
			while (v[a] < pivot) a++;
			while (v[b] > pivot) b--;

			if (a < b) {
				swap(&v[a], &v[b]);
				a++;
			}
		}
	
	quicksort(v, a);
	quicksort(v+a, size - a);

	}
}

void bubblesort(int *v, int size){
	int i,j;
	for (i = 0; i < size; ++i){
		for (j = i+1; j < size; ++j){
			if (v[j]<v[i]){
				swap(&v[j],&v[i]);
			}
		}
	}
}

int binarySearchRec(int *arr, int begin, int end, int element){
	int m;
	int pos = -1;

	m = (begin+end)/2;
	if (begin>end){
		return -1;
	}
	if (arr[m]==element){
		return m;
	}else if (arr[m]>element){
		end = m - 1;
		pos = binarySearchRec(arr, begin, end, element);
	}else {
		begin = m + 1;
		pos = binarySearchRec(arr, begin, end, element);
	}
	return pos;
}

int binarySearch(int *arr, int size, int element){
	return binarySearchRec(arr, 0, size, element);
}

int linearSearch(int *arr, int size, int element){
	int i;
	for (i = 0; i < size; ++i){
		DEBUG{printf("count: %d\n", i+1);}
		if (arr[i] == element){
			return i;
		} 
	}
	return -1;
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

void printList(node *head){
	while (head!=NULL){
		printf("%d\n", head->item);	
		head = head->next;
	}
	return;
}

int main(){
	int i,prev;

	int a[ARRAYSIZE];
	int b[ARRAYSIZE];

	for (i = 0; i < ARRAYSIZE; ++i){
		scanf("%d", &a[i]);
	}

	for (i = 0; i < ARRAYSIZE; ++i){
		scanf("%d", &b[i]);
	}

	quicksort(a,ARRAYSIZE);
	quicksort(b,ARRAYSIZE);

	node *list;
	list = createList();

	prev = a[ARRAYSIZE-1] + 1;

	for (i = ARRAYSIZE-1; i >= 0; --i){
		if ((prev!=a[i])&&(binarySearch(b, ARRAYSIZE, a[i])!=-1)){
			list = addToHead(list, a[i]);
			prev = a[i];
		}
	}

	if (list==NULL) printf("VAZIO\n");
	else printList(list);
	
	return 0;
}