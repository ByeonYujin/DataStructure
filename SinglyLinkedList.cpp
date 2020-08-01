#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 연결리스트 구조체를 생성 후 NODE로 재정의, 대상 타입이 NODE인 포인터 LINK생성 */
typedef struct linked_list
{
	char* name;
	struct linked_list* next;
};
typedef struct linked_list NODE;
typedef NODE* LINK;

/* 노드 생성 */
LINK createNode(char* name)
{
	LINK cur;
	cur = (LINK)malloc(sizeof(NODE));
	cur->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
	strcpy(cur->name, name);
	cur->next = NULL;

	return cur;
}

/* 맨 뒤에 노드 삽입 */
LINK append(LINK head, LINK cur)
{
	LINK nextNode = head;
	if (head == NULL)
	{
		head = cur;
		return head;
	}
	while (nextNode->next != NULL)
	{
		nextNode = nextNode->next;
	}
	nextNode->next = cur;

	return head;
}
/* 특정 노드의 다음 위치에 새로운 노드 삽입 */
void insert(LINK cur, LINK nextNode)
{
	nextNode->next = cur->next;
	cur->next = nextNode;
}

/* 특정 노드의 다음 노드를 삭제 */
void delete(LINK cur)
{
	if (cur->next != NULL)
	{
		cur->next = cur->next->next;
		free(cur->next);
	}
}

/* 연결리스트 출력, 노드 개수를 cnt로 반환 */
int printList(LINK head)
{
	int cnt = 0;
	LINK nextNode = head;
	while (nextNode != NULL)
	{
		printf("Node %d : %s\n", ++cnt, nextNode->name);
		nextNode = nextNode->next;
	}
	return cnt;
}

int main()
{
	LINK head = NULL;

	/* data 1~4노드 생성 후 1~3은 연결리스트에 추가 */
	LINK data1 = createNode("Data 1");
	head = append(head, data1);
	LINK data2 = createNode("Data 2");
	head = append(head, data2);
	LINK data3 = createNode("Data 3");
	head = append(head, data3);
	LINK data4 = createNode("Data 4");

	printList(head);

	printf("\ndata2 다음 노드 삭제\n");
	delete(data2);
	printList(head);

	printf("\ndata1 뒤에 data4 삽입\n");
	insert(data1, data4);
	printList(head);

	return 0;
}
