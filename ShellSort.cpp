#include <stdio.h>

void ShellSort(int list[], int n, int t, int distance[]);
void PrintList(int list[], int n);

int main()
{
	int array[] = { 5, 9, 35, 72, 21, 78, 13, 23, 41, 10, 2, 66 }; //������ �迭 ����
	int d[] = { 1, 2, 3, 4, 5 }; //���� ������ �Ÿ� �迭 ����

	//�ʱ� ���� ���
	printf("�ʱ� ���� ");
	PrintList(array, 12);
	printf("\n");

	//������ �Լ� ȣ��
	ShellSort(array, 12, 5, d);

	return 0;
}

void ShellSort(int list[], int n, int t, int distance[]) //������ �Լ� ����
{
	int k, h, j, i, temp;
	for (k = t - 1; k >= 0; k--)
	{
		h = distance[k]; //�迭 d�� ���ҵ��� �������� �Ÿ����� ��
		for (j = h; j < n; j++)
		{
			i = j - h;
			while ((i >= 0) && (list[i] > list[j]))
			{
				//list[j]���� h��ŭ �տ� ��ġ�� list[i]�� list[j]���� Ŭ ��� ���� ��ȯ
				temp = list[i + h];
				list[i + h] = list[i];
				list[i] = temp;
				i -= h;
			}
		}
		//h(�Ÿ�)�� ���� ���� ��� ���
		printf("(h = %d) >>", h);
		PrintList(list, n);
		printf("\n");
	}
}

void PrintList(int list[], int n) //��� �Լ� ����
{
	for (int i = 0; i < n; i++)
		printf("  %d", list[i]);
}
