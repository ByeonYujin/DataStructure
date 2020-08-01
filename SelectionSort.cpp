#include <stdio.h>

void SELSORT(int list[], int size);

int main()
{
	int a[] = { 2, 6, 1, 4, 7 }; //리스트 생성 및 초기화
	SELSORT(a, 5); //함수 호출

	//정렬된 리스트 출력
	for (int i = 0; i < 5; i++)
		printf(" %d", a[i]);

	return 0;
}

void SELSORT(int list[], int size) //함수 정의
{
	for (int i = size - 1; i > 0; i--)
	{
		int m = 0;
		//최댓값을 찾아 인덱스를 m에 대입
		for (int j = 1; j <= i; j++)
		{
			if (list[m] < list[j])
				m = j;
		}

		//최댓값과 현재 위치의 값을 교환
		int temp = list[m];
		list[m] = list[i];
		list[i] = temp;
	}
}
