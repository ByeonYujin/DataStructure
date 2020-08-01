#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void Push(char);
char Pop();
int Input(); //무한 루프 제어
void Print(char[], int); //배열 출력

//스택, 입력값, 결과값 초기화
char stack[5] = { ' ' };
char data[5] = { 'A', 'B', 'C', 'D', 'E' };
char result[5] = { ' ' };

int top = -1, i = 0, j = 0, k; //i와 j는 data와 result의 인덱스

int main()
{
	while (Input()) //k값을 입력받아 실행 여부 결정
	{
		//삽입
		if (k == 1)
			Push(data[i++]);
		//삭제(result에 입력하면서 stack에서 삭제)
		else if (k == 2)
			result[j++] = Pop();
		else
			printf("다시 입력하시오.\n");

		//스택 내부와 결과값 출력
		printf("스택 내부 : ");
		Print(stack, 5);
		printf("\n결과 : ");
		Print(result, 5);
		printf("\n");
	}
	return 0;
}

void Push(char item)
{
	if (top == 4)
		printf("overflow\n");
	else
		stack[++top] = item;
}

char Pop()
{
	if (top == -1)
		printf("underflow\n");
	else
	{
		char c = stack[top];
		stack[top--] = ' ';
		return c;
	}
}

int Input()
{
	printf("삽입:1, 삭제:2, 종료:0 >> ");
	scanf_s("%d", &k);
	return k;
}

void Print(char ary[], int n)
{
	for (int m = 0; m < n; m++)
		printf("%c", ary[m]);
}