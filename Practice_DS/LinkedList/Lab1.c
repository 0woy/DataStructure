/*
단어들을 저장하는 연결 리스트
실행 결과: 
APPLE -> NULL
KIWI-> APPLE -> NULL
BANANA -> KIWI -> APPLE -> NULL
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char fruit[10];
}element;

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
		printf("%s -> ", p->data.fruit);
	}
	printf("NULL\n");
}


int main() {
	ListNode* head = NULL;

	while (1) {
		element data = { NULL };
		printf("저장할 과일 (종료:0) >> ");
		scanf("%s", data.fruit);
		if (strcmp(data.fruit, "0") == 0) break;
		head = insert_first(head, data);
		print_list(head);
	}


	return 0;
}