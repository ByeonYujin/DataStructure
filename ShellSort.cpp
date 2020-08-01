#include <stdio.h>

void ShellSort(int list[], int n, int t, int distance[]);
void PrintList(int list[], int n);

int main()
{
	int array[] = { 5, 9, 35, 72, 21, 78, 13, 23, 41, 10, 2, 66 }; //정렬할 배열 선언
	int d[] = { 1, 2, 3, 4, 5 }; //원소 사이의 거리 배열 선언

	//초기 상태 출력
	printf("초기 상태 ");
	PrintList(array, 12);
	printf("\n");

	//쉘정렬 함수 호출
	ShellSort(array, 12, 5, d);

	return 0;
}

void ShellSort(int list[], int n, int t, int distance[]) //쉘정렬 함수 정의
{
	int k, h, j, i, temp;
	for (k = t - 1; k >= 0; k--)
	{
		h = distance[k]; //배열 d의 원소들은 역순으로 거리값이 됨
		for (j = h; j < n; j++)
		{
			i = j - h;
			while ((i >= 0) && (list[i] > list[j]))
			{
				//list[j]보다 h만큼 앞에 위치한 list[i]가 list[j]보다 클 경우 둘을 교환
				temp = list[i + h];
				list[i + h] = list[i];
				list[i] = temp;
				i -= h;
			}
		}
		//h(거리)에 따른 정렬 결과 출력
		printf("(h = %d) >>", h);
		PrintList(list, n);
		printf("\n");
	}
}

void PrintList(int list[], int n) //출력 함수 정의
{
	for (int i = 0; i < n; i++)
		printf("  %d", list[i]);
}
