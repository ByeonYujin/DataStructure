#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ���Ḯ��Ʈ ����ü�� ���� �� NODE�� ������, ��� Ÿ���� NODE�� ������ LINK���� */
typedef struct linked_list
{
	char* name;
	struct linked_list* next;
};
typedef struct linked_list NODE;
typedef NODE* LINK;

/* ��� ���� */
LINK createNode(char* name)
{
	LINK cur;
	cur = (LINK)malloc(sizeof(NODE));
	cur->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
	strcpy(cur->name, name);
	cur->next = NULL;

	return cur;
}

/* �� �ڿ� ��� ���� */
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
/* Ư�� ����� ���� ��ġ�� ���ο� ��� ���� */
void insert(LINK cur, LINK nextNode)
{
	nextNode->next = cur->next;
	cur->next = nextNode;
}

/* Ư�� ����� ���� ��带 ���� */
void delete(LINK cur)
{
	if (cur->next != NULL)
	{
		cur->next = cur->next->next;
		free(cur->next);
	}
}

/* ���Ḯ��Ʈ ���, ��� ������ cnt�� ��ȯ */
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

	/* data 1~4��� ���� �� 1~3�� ���Ḯ��Ʈ�� �߰� */
	LINK data1 = createNode("Data 1");
	head = append(head, data1);
	LINK data2 = createNode("Data 2");
	head = append(head, data2);
	LINK data3 = createNode("Data 3");
	head = append(head, data3);
	LINK data4 = createNode("Data 4");

	printList(head);

	printf("\ndata2 ���� ��� ����\n");
	delete(data2);
	printList(head);

	printf("\ndata1 �ڿ� data4 ����\n");
	insert(data1, data4);
	printList(head);

	return 0;
}
