#include <stdio.h>

void Insertion(int list[], int n);
int main()
{
	//�迭 �ʱ�ȭ, ũ�� ����
	int list[5] = { 3, 4, 1, 2, 5 };
	int size = 5;

	//�Լ� ȣ��
	Insertion(list, size);

	//����� ���
	for (int i = 0; i < 5; i++)
		printf("%d ", list[i]);

	return 0;
}

void Insertion(int list[], int n)
{
	int next;

	for (int i = 1; i < n; i++)
	{
		next = list[i];
		int j = i - 1;
		while (j >= 0 && list[j] > next) //list[i-1]�� 0�̻��̰� list[i]���� ũ�ٸ�
		{
			list[j + 1] = list[j]; //�� ��ȯ
			j -= 1; //�������� ��ġ �˻�
		}
		list[j + 1] = next; //�˻��� ��ġ�� �� ����
	}
}