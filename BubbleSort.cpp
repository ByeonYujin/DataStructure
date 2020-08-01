#include <stdio.h>

void BUBSORT(int list[], int n);

int main()
{
	int a[] = { 1, 6, 23, 3, 16 }; //리스트 생성 및 초기화
	BUBSORT(a, 5); //함수 호출

	//정렬된 리스트 출력
	for (int i = 0; i < 5; i++)
		printf(" %d", a[i]);
	return 0;
}

void BUBSORT(int list[], int n) //함수 정의
{
	int k = 0, j;
	int flag = 1; //이미 정렬되어 있는지 여부 확인

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