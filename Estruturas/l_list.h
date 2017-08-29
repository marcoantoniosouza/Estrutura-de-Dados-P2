#include "l_list.c"

typedef struct _node node;
node* createList(); // returns a NULL pointer
int isEmpty(node *head); // returns 1 if the list is empty or 0 if not
node* clearList(node *head); // free all the nodes of the list and returns a NULL pointer
node* addToHead(node *head, int item); // add a node to the head of the list
node* addToTail(node *head, int item); // add a node to the tail of the list
node* removeByPointer(node *head, node *prev, node *current);
node* removeFromHead(node *head);
node* search(node *head, int item);
node* invertList(node *head);
node* tailOfList(node *head);
void printList(node *head);