/*
리스트 역순으로 만드는 연산
실행 결과
30->20->10->NULL
10->20->30->NULL
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

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
}

ListNode* reverse_list(ListNode* head) {

	ListNode* p, *q, *r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

int main() {
	ListNode* head = NULL;
	element data = 0;

	while (1) {
		printf("저장할 값 (종료: -1) >> ");
		scanf("%d", &data);
		if (data == -1) break;
		head = insert_first(head, data);
	}
	print_list(head);
	printf("역순 리스트\n");
	ListNode* reversed;
	reversed= reverse_list(head);
	print_list(reversed);

	return 0;
}