#include <stdio.h>

void SELSORT(int list[], int size);

int main()
{
	int a[] = { 2, 6, 1, 4, 7 }; //����Ʈ ���� �� �ʱ�ȭ
	SELSORT(a, 5); //�Լ� ȣ��

	//���ĵ� ����Ʈ ���
	for (int i = 0; i < 5; i++)
		printf(" %d", a[i]);

	return 0;
}

void SELSORT(int list[], int size) //�Լ� ����
{
	for (int i = size - 1; i > 0; i--)
	{
		int m = 0;
		//�ִ��� ã�� �ε����� m�� ����
		for (int j = 1; j <= i; j++)
		{
			if (list[m] < list[j])
				m = j;
		}

		//�ִ񰪰� ���� ��ġ�� ���� ��ȯ
		int temp = list[m];
		list[m] = list[i];
		list[i] = temp;
	}
}
