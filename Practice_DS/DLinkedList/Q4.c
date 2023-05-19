/*
이중 연결 리스트를 이용해 음악을 저장하고
사용자 명령에 따라 곡을 선택하는 프로그램 작성
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[20];
}element;

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

DListNode* current;

void dinsert(DListNode* before, char value[]) {
	DListNode * node = (DListNode*)malloc(sizeof(DListNode));	// 노드 동적할당
	strcpy(node->data.name, value);				// data 필드에 value 저장
	node->llink = before;			// 노드의 왼쪽 링크가 before를 가리키도록 함
	node->rlink = before->rlink;	// 노드의 오른쪽 링크가 before의 오른쪽 link가 가리키는 곳을 가리키도록 함

	// head노드의 오른쪽 삽입이므로, rlink(기존 head의 오른쪽 노드)의 llink가 newNode를 가리키도록 함
	before->rlink->llink = node;
	before->rlink = node;			// before 노드의 오른쪽 link가 newNode를 가리키도록 함
}

void print_dlist(DListNode* head) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {	// head노드의 오른쪽 노드 부터 순환
		if(p == current) printf("<-| #%s# |-> ", p->data.name);	// 현재 재생되는 음악인 경우 # 추가
		else printf("<-| %s |-> ", p->data.name);				// 그렇지 않은 경우 그냥 출력
	}
	printf("\n");
}


int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "Mamamaia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");

	current = head->rlink;
	print_dlist(head);

	do {
		printf("\n명령어를 입력하시오 (<, >, q):");
		ch = getchar();
		switch (ch) {
		case '<':
			current = current->llink;
			if (current == head) current = current->llink;
			break;
		case '>':
			current = current->rlink;
			if (current == head) current = current->rlink;
			break;
		}
		print_dlist(head);
		getchar();
	} while (ch != 'q');

	free(head);
	return 0;
}