/*
이중 연결 리스트를 이용해서 0, 1, 2, 3, 4를 입력하고
4, 3, 2, 1, 0을 삭제 하고 각 단계별로 리스트를 출력하는 프로그램을 작성하시오
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;	// 이중 연결리스트 구조체 선언

// head 노드 초기화
void init(DListNode* head) {
	head->llink = head;	
	head->rlink = head;
}

void dinsert(DListNode* before, element value) {
	DListNode * node = (DListNode*)malloc(sizeof(DListNode));	// 노드 동적할당
	node->data = value;				// data 필드에 value 저장
	node->llink = before;			// 노드의 왼쪽 링크가 before를 가리키도록 함
	node->rlink = before->rlink;	// 노드의 오른쪽 링크가 before의 오른쪽 link가 가리키는 곳을 가리키도록 함

	// head노드의 오른쪽 삽입이므로, rlink(기존 head의 오른쪽 노드)의 llink가 newNode를 가리키도록 함
	before->rlink->llink = node;	
	before->rlink = node;			// before 노드의 오른쪽 link가 newNode를 가리키도록 함
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;			// 리스트가 비어있는 경우 함수 종료

	// removed의 llink(왼쪽노드)의 rlink가 removed의 rlink(오른쪽 노드)를 가리키도록 함
	removed->llink->rlink= removed->rlink;	

	// removed의 rlink(오른쪽 노드)의 llink가 removed의 llink(왼쪽 노드)를 가리키도록 함
	removed->rlink->llink = removed->llink;

	free(removed);	// 노드 삭제

}

void print_dlist(DListNode* head) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {	// head노드의 오른쪽 노드 부터 순환
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");

	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		// 헤드 노드의 오른쪽에 삽입
		dinsert(head, i);
		print_dlist(head);
	}

	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}