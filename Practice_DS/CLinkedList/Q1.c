/*
원형 리스트를 이용해서 리스트에 10,20,30,40 순서대로 삽입하고
리스트를 출력하는 프로그램 작성

결과: 10->20->30->40->
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_last(ListNode* head, element value) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));	// 노드 동적할당
	node->data = value;	// data 필드에 value 저장

	if (head == NULL) {		// 리스트가 비어있는 경우
		head = node;		// head 포인터가 node를 가리키도록 함
		node->link = head;	// node의 link가 head를 가리키도록 함(자기 자신을 가리킴)
	}

	else {							// 리스트가 비어있지 않은 경우
		node->link = head->link;	// head의 link가 가리키는 곳을 새로운 노드의 link가 가리키도록 함
		head->link = node;			// 마지막에 삽입 되므로 head의 link가 새로운 노드를 가리키도록 함
		head = node;				// 원형리스트의 head는 맨 끝에 있으므로 새로운 노드를 head가 가리키도록 함
	}

	return head;	// 삽입 후 리스트 반환
}

void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) return;
	p = head;
	do {
		printf("%d -> ", p->data);
		p = p->link;
	} while (p != head);

}
int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");

	ListNode* head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_last(head, 10);

	print_list(head);
	return 0;
}