#include <stdio.h>

void Insertion(int list[], int n);
int main()
{
	//배열 초기화, 크기 설정
	int list[5] = { 3, 4, 1, 2, 5 };
	int size = 5;

	//함수 호출
	Insertion(list, size);

	//결과값 출력
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
		while (j >= 0 && list[j] > next) //list[i-1]이 0이상이고 list[i]보다 크다면
		{
			list[j + 1] = list[j]; //값 교환
			j -= 1; //역순으로 위치 검색
		}
		list[j + 1] = next; //검색된 위치에 값 삽입
	}
}