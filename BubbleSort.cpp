#include <stdio.h>

void BUBSORT(int list[], int n);

int main()
{
	int a[] = { 1, 6, 23, 3, 16 }; //����Ʈ ���� �� �ʱ�ȭ
	BUBSORT(a, 5); //�Լ� ȣ��

	//���ĵ� ����Ʈ ���
	for (int i = 0; i < 5; i++)
		printf(" %d", a[i]);
	return 0;
}

void BUBSORT(int list[], int n) //�Լ� ����
{
	int k = 0, j;
	int flag = 1; //�̹� ���ĵǾ� �ִ��� ���� Ȯ��

	while ((k < n - 1) && flag)
	{
		flag = 0;
		for (j = 0; j < n - k - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				flag = 1;
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
		k++;
	}
}