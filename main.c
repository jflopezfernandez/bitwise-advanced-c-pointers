
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


#define N 3


typedef struct _listitem {
	int data;
	struct _listitem *next;
	struct _listitem *prev;
} LISTITEM;


typedef struct {
	struct _listitem *first;
	struct _listitem *last;
} LISTHDR;


LISTHDR head;


void enqueue(LISTITEM *item);
LISTITEM *dequeue();


int main()
{
	system("cls");

    struct _listitem 	head,
						*temp;
	
	// Head struct is not treated as a normal node
	head.next = (struct _listitem *) &head;
	head.prev = (struct _listitem *) &head;
	head.data = -1;

	// Populate the list
	for (int i = 0; i < N; ++i) {
		temp = malloc(sizeof(struct _listitem));
		temp->data = i;
		temp->next = head.next;
		head.next = temp;
		temp->prev = &head;
		temp->next->prev = temp;
	}

	temp = head.next;
	while (temp != &head) {
		printf("forward list item:\n");
		printf("\tcurrent is %p\n", temp);
		printf("\tnext is %p\n", temp->next);
		printf("\tprev is %p\n", temp->prev);
		printf("\tdata is %d\n", temp->data);

		temp = temp->next;
	}

	
	temp = head.prev;
	while (temp != &head) {
		printf("backward list item:\n");
		printf("\tcurrent is %p\n", temp);
		printf("\tnext is %p\n", temp->next);
		printf("\tprev is %p\n", temp->prev);
		printf("\tdata is %d\n", temp->data);

		temp = temp->prev;
	}
	

	return EXIT_SUCCESS;
}


void enqueue(LISTITEM *item) {
	LISTITEM *temp;

	temp = head.last;
	head.last = item;
	item->prev = temp;
	item->next = (LISTITEM *) &head;
	temp->next = item;
}


LISTITEM* dequeue() {
	LISTITEM *temp;

	temp = head.first;

	if (temp == (LISTITEM *) &head) {
		temp = NULL;
	} else {
		head.first = temp->next;
		head.last->prev = (LISTITEM *) &head;
	}

	return temp;
}
