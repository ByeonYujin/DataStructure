#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void Push(char);
char Pop();
int Input(); //���� ���� ����
void Print(char[], int); //�迭 ���

//����, �Է°�, ����� �ʱ�ȭ
char stack[5] = { ' ' };
char data[5] = { 'A', 'B', 'C', 'D', 'E' };
char result[5] = { ' ' };

int top = -1, i = 0, j = 0, k; //i�� j�� data�� result�� �ε���

int main()
{
	while (Input()) //k���� �Է¹޾� ���� ���� ����
	{
		//����
		if (k == 1)
			Push(data[i++]);
		//����(result�� �Է��ϸ鼭 stack���� ����)
		else if (k == 2)
			result[j++] = Pop();
		else
			printf("�ٽ� �Է��Ͻÿ�.\n");

		//���� ���ο� ����� ���
		printf("���� ���� : ");
		Print(stack, 5);
		printf("\n��� : ");
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
	printf("����:1, ����:2, ����:0 >> ");
	scanf_s("%d", &k);
	return k;
}

void Print(char ary[], int n)
{
	for (int m = 0; m < n; m++)
		printf("%c", ary[m]);
}