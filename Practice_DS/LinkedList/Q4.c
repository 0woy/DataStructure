/*
학번: 20204624
이름: 박윤아
프로그램 설명: 단순 연결 리스트에서 특정한 데이터 값을 갖는 노드의 개수 계산
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

ListNode* insert_last(ListNode* head, element value) {	// 리스트의 맨 뒤 삽입 함수

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	// 새로운 노드 메모리 동적 할당
	p->data = value;	// 매개변수로 받아온 데이터 저장
	p->link = NULL;		// 맨 뒤 노드이므로 link = NULL

	ListNode *tmp;	// 삽입 전 리스트의 맨 뒤 노드를 찾기 위한 변수

	if (!head) {	// 리스트가 공백인 경우 
		head = p;	// 새로운 노드가 헤드가 됨
		return;		// 함수 종료
	}
	else {								// 리스트가 비어있지 않은 경우	
		tmp = head;						// head부터 시작
		while (tmp->link != NULL)		// 마지막 노드까지 반복
			tmp = tmp->link;
		tmp->link = p;	// 마지막 노드의 link가 새로운 노드를 가리키도록 함
	}
	return head;
}

int find_data(ListNode* head, element value) {		// 연결리스트 노드 개수를 세는 함수
	ListNode* tmp;	// 임시 노드 tmp 변수 선언
	int count = 0;	// 특정 데이터를 갖는 노드 개수를 셀 변수 선언

	for (tmp = head; tmp != NULL; tmp = tmp->link)	// head부터 리스트 끝까지 반복
		if(tmp->data == value)
			count++;	// 노드 개수 증가

	return count;		// 노드 개수 반환
}

void print_list(ListNode *head) {						// 리스트 출력
	for (ListNode *p = head; p != NULL; p = p->link)	// 리스트의 끝까지 반복
		printf("%d-> ", p->data);						// 노드의 데이터 출력
	printf("NULL\n");
}

int main() {

	printf("이름:박윤아\n학번:20204624\n\n");

	ListNode* head = NULL;	// 헤드 포인터 초기화
	int n, find;	// 노드의 총 개수
	printf("노드의 개수: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {		// 입력 받은 노드 개수만큼 반복
		int num;
		printf("노드 #%d 데이터: ", i);
		scanf("%d", &num);
		head = insert_last(head, num);	// 맨 뒤에 노드 삽입
	}

	printf("탐색할 값을 입력하시오: ");
	scanf("%d", &find);
	printf("%d는 연결 리스트에서 %d번 나타납니다.\n",find, find_data(head, find));
	
	printf("생성된 연결 리스트 : ");
	print_list(head);	// 리스트 출력
	return 0;
}