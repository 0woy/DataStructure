/*
�� ���� ����Ʈ�� �ϳ��� ��ġ�� �Լ�
������
30 -> 20 -> 10 -> NULL
50 -> 40 -> NULL
30 -> 20 -> 10 -> 50 -> 40 -> NULL
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p; 
	return head;
}

ListNode* connect_list(ListNode* first, ListNode* second) {
	if (!first) return second;
	else if (!second) return first;
	else {
		ListNode* p;
		for (p = first; p->link != NULL; p = p->link);
		p->link = second;
	return first;
	}
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
}


int main() {
	ListNode* first = NULL;
	ListNode* second = NULL;
	element data = 0;

	printf("ù ��° ����Ʈ\n");
	while (1) {	
		printf("������ �� (����: -1) >> ");
		scanf("%d", &data);
		if (data == -1) break;
		first= insert_first(first, data);	
	}
	
	printf("�� ��° ����Ʈ\n");
	while (1) {
		printf("������ �� (����: -1) >> ");
		scanf("%d", &data);
		if (data == -1) break;
		second = insert_first(second, data);
	}
	print_list(first);
	print_list(second);

	ListNode* total;
	total=connect_list(first, second);
	print_list(total);


	return 0;
}