#include <stdio.h>
#include <stdlib.h>

struct qel {
	int v;	
	struct qel *f;	// in front of element
	struct qel *b;	// behind element	
} *HEAD, *TAIL;

init = 0;

void init()
{
	HEAD = 
		(struct qel*) malloc(sizeof(struct qel));
	HEAD->f = NULL; HEAD->b = NULL;
	TAIL = HEAD;
	init = 1;
	
	return;
}

void enqueue(int v)
{
	if(init = 0) init();

	struct qel *temp =
		(struct qel*) malloc(sizeof(struct qel));
	temp->f = TAIL;
	temp->b = NULL;
	temp->v = v;
	TAIL->b = temp;
	TAIL = temp;
}

int dequeue()
{
	if(HEAD == TAIL) {
		init = 0;
		return HEAD->v;
	}
	
	int r = HEAD->v;
	HEAD->b->f = NULL;
	HEAD = HEAD->b;
	free(HEAD);
	
	return r;	
}

int peek()
{
	return HEAD->v;
}

int main(void)
{
	int user_choice, v;
	
	while(1) {
		printf("[1: Enqueue // 2: Dequeue // 3: Peek // 4: Exit] ");
		scanf("%d", &user_choice);

		switch(user_choice) {
			case 1:
				printf("[Enter value] ");
				scanf("%d", &v);
				enqueue(v);
				break;
			case 2:
				printf("Dequeued: Got %d\n", dequeue());
				break;
			case 3:
				printf("Peeked: Got %d\n", peek());
				break;
			case 4:
				return;
			default:
				printf("Invalid choice\n");
				break;
		}
	}
}
