#include <stdio.h>

void ADDQ(char);
char DELQ();

//큐, rear, front 초기화
char queue[100] = { ' ' };
int rear = -1, front = -1;

void ADDQ(char item)
{
	if (rear == 99)
		printf("overflow\n");
	else
		queue[++rear] = item;
}

char DELQ()
{
	if (front == rear)
		printf("underflow\n");
	return	queue[++front];
}

int main()
{
	ADDQ('a');
	ADDQ('b');
	ADDQ('c');

	printf("%c\n", DELQ());
	printf("%c\n", DELQ());
	printf("%c\n", DELQ());
	printf("%c\n", DELQ());

	return 0;
}