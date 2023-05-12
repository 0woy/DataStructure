/*
학번: 20204624
이름: 박윤아

프로그램 설명: 단순 연결 리스트에 사용자가 입력하는 값을 저장했다가 출력하는 프로그램 작성
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

ListNode* reverse(ListNode *head) {
	ListNode *r, *p, *q;	// 역순으로 만들기 위한 포인터 변수
	q = NULL;	// q: 역순으로 변환된 리스트
	p = head;	// p: 역순으로 변환할 리스트

	while (p != NULL) {	// 리스트의 끝까지 반복
		r = q;			// r이 가리키는 주소 = q가 가리키는 주소
		q = p;			// q가 가리키는 주소 = p가 가리키는 주소
		p = p->link;	// 다음 노드로 이동
		q->link = r;	// q의 link = r이 가리키는 주소
	}
	return q;	// 역순으로 변환된 리스트 반환
}

void print_list(ListNode *head) {						// 리스트 출력
	for (ListNode *p = head; p != NULL; p = p->link)	// 리스트의 끝까지 반복
		printf("%d-> ", p->data);						// 노드의 데이터 출력
	printf("NULL\n");
}

int main() {

	printf("이름:박윤아\n학번:20204624\n\n");

	ListNode* head = NULL;	// 헤드 포인터 초기화

	int n;	// 노드의 총 개수
	printf("노드의 개수: ");
	scanf("%d", &n);

	for (int i = 0; i <n; i++) {		// 입력 받은 노드 개수만큼 반복
		int num;
		printf("노드 #%d 데이터: ", i);	
		scanf("%d", &num);
		head = insert_first(head, num);	// 맨 앞에 노드 삽입
	}
	head = reverse(head);
	printf("생성된 연결 리스트 : ");
	print_list(head);	// 리스트 출력
	return 0;
}