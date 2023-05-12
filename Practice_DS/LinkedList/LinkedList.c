/*
이름: 박윤아
학번: 20204624

프로그램 설명: 단순 연결리스트 구현
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

// 리스트 맨 앞에 삽입 함수
ListNode* insert_first(ListNode* head, int value) {		
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));	// 새로운 노드 메모리 동적 할당
	p->data = value;	// 데이터 = value
	p->link = head;		// 맨 앞에 삽입하므로 link = head가 가리키는 주소

	head = p;	// 헤드포인터를 p로 설정
	return head;
}

// 리스트 중간 삽입 함수
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));	// 새로운 노드 메모리 동적 할당
	p->data = value;		// 데이터 = value
	p->link = pre->link;	// p의 link = p의 이전 노드(pre)의 link를 가리킴
	pre->link = p;			// pre의 link는 p를 가리킴
	return head;
}


// 리스트 맨 앞 삭제 함수
ListNode* delete_first(ListNode *head) {
	ListNode* removed;		// 삭제할 노드를 임시 저장할 포인터 변수
	if (!head) return NULL;	// 리스트가 공백인 경우 NULL return
	removed = head;			// removed가 가리키는 주소 = head가 가리키는 주소(처음 노드)
	head = removed->link;	// head는 removed(현재 head가 가리키는 주소)의 link(두 번째 노드)
	free(removed);			// 메모리 할당 해제 (= 삭제)
	return head;

}

// 리스트 중간 노드 삭제 함수
ListNode* delete(ListNode* head, ListNode *pre) {
	ListNode* removed;		// 삭제할 노드를 임시 저장할 포인터 변수
	if (!head) return NULL;	// 리스트가 공백인 경우 NULL return
	removed = pre->link;		// removed가 가리키는 주소 = pre의 link(pre의 다음 노드)
	pre->link = removed->link;	// pre의 link = removed의 link(삭제할 노드 다음 노드)
	free(removed);				// 메모리 할당 해제 (= 삭제)
	return head;
}

// 현재 리스트 출력 함수
void print_list(ListNode *head) {
	for (ListNode *p = head; p != NULL; p = p->link)	// 리스트의 처음부터 끝까지 반복
		printf("%d-> ", p->data);	// 노드의 데이터 출력
	printf("NULL\n");
}

int main() {

	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);	// 0~4까지 노드 삽입
		print_list(head);				// 한 번 삽입할 때마다 리스트 상태 출력
	}

	for (int i = 0; i < 5; i++) {
		head = delete_first(head);	// 리스트의 맨 앞 노드 삭제
		print_list(head);			// 한 번 삭제할 때마다 리스트 상태 출력
	}
	return 0;
}