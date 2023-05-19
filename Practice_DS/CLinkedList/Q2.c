/*
3명의 플레이어가 보드 게임을 한다.
원형 리스트를 이용해 현재 누구 순서인지 출력하시오

결과:
현재 차례 = KIM
현재 차례 = CHOI
현재 차례 = PARK
현재 차례 = KIM
현재 차례 = CHOI
현재 차례 = PARK
...
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct element{
	char name[10];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct CListType {
	ListNode *head;
	ListNode player[3];
}CListType;

ListNode* insert_first(CListType* list, char value[]) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));	// 노드 동적할당
	strcpy(node->data.name, value);	// data 필드에 value 저장

	if (list->head == NULL) {		// 리스트가 비어있는 경우
		list->head = node;			// head 포인터가 node를 가리키도록 함
		node->link = list->head;	// node의 link가 head를 가리키도록 함(자기 자신을 가리킴)
	}

	else {								// 리스트가 비어있지 않은 경우
		node->link = list->head->link;	// head의 link가 가리키는 곳을 새로운 노드의 link가 가리키도록 함
		list->head->link = node;		// 마지막에 삽입 되므로 head의 link가 새로운 노드를 가리키도록 함
	}

	return list->head;	// 삽입 후 리스트 반환
}

void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) return;		// 리스트가 비어있는 경우 함수 종료
	p = head;						// p가 head가 가리키는 곳을 가리키도록 함
	do {
		printf("%d -> ", p->data);	// 현재 노드의 data 출력
		p = p->link;				// 다음 노드로 이동
	} while (p != head);			// head가 아닐 때까지 반복

}
int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");

	CListType list = { NULL };
	insert_first(&list, "KIM");
	insert_first(&list, "CHOI");
	insert_first(&list, "PARK");

	ListNode* p = list.head;
	for (int i = 0; i < 12; i++) {
		printf("현재 차례=%s\n", p->data.name);
		p = p->link;
	}
	return 0;

}