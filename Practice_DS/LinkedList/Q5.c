/*
이름: 박윤아
학번: 20204624
data.txt 파일에 있는 숫자들을 읽어 연결리스트에 추가 및 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {		
	element data;	
	struct ListNode *link;
}ListNode;	// 연결리스트 구조체 정의

// 리스트 맨 뒤에 삽입하는 함수
ListNode* insert(ListNode* head, element value) {	
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));	// 노드 동적 할당
	p->data = value;	// 값에 value 삽입
	p->link = NULL;		// 맨 뒤 노드이므로 link에 Null 삽입

	ListNode *tmp;		// 삽입 전 리스트 맨 마지막 노드 찾기 위한 변수

	if (head==NULL) {	// 리스트가 비어있는 경우
		head = p;		// p가 맨 처음 노드가 됨
		return head;	// head 반환 및 함수 종료
	}
	else {							// 리스트가 비어있지 않은 경우
		tmp = head;					// tmp가 head를 가리키도록 함(맨 처음부터 순회하기 위함)
		while (tmp->link != NULL)	// 마지막 노드까지 이동
			tmp = tmp->link;	
		tmp->link = p;				// 현재 마지막 노드가 가리키는 link가 p를 가리키도록 함
	}
	return head;					// head 반환 및 함수 종료
}

// 연결 리스트 출력
void print_list(ListNode* head) {
	printf("< ");
	for (ListNode* i = head; i != NULL; i = i->link) {	// 리스트의 처음부터 끝까지 순회
		printf("%d ", i->data);		// 노드가 가진 data 값 출력
	}
	printf(">\n");

}

// 삭제 함수
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;			// 삭제될 노드 저장 변수
	if (!head) return NULL;		// 리스트가 비어있는 경우 NULL 반환 및 함수 종료
	removed = pre->link;		// pre의 link가 가리키는 노드가 삭제될 노드
	pre->link = removed->link;	// pre의 link가 삭제 노드의 다음 노드를 가리키도록 함
	free(removed);				// removed 메모리 반환하여 노드 삭제
	return head;				// 삭제가 완료된 연결리스트 반환
}

// 짝수 번째 노드 삭제
ListNode* delete_even(ListNode* head) {
	ListNode* p = head;		// p 변수를 통해 연결리스트 순회
	int idx = 0;			// 짝수인지 판별하는 변수

	ListNode *tmp = NULL;	// 삭제 전 다음 연산을 진행할 노드를 저장 하는 변수

	while(p != NULL) {		// 리스트의 끝까지 반복
		if (idx == 0) {		// 맨 처음 노드인 경우

			ListNode* removed;		// 삭제될 노드를 저장하는 변수
			if (!head) return;		// 연결리스트가 비어있는 경우 종료
			removed = head;			// 삭제될 노드 = head
			head = removed->link;	// 삭제 진행 후 head는 두 번째 노드가 됨(removed->link)
			p = removed->link;		// p를 통해 리스트를 순회 하므로 head와 같이 두 번째 노드 저장
			free(removed);			// 노드 삭제
			idx++;
			continue;
		}
		
		if (idx % 2 != 0) {	// 홀수인 경우 1, 3, 5 . . 
			tmp = p;		// 현재 노드 tmp에 저장
			head = delete(head, p);	// 삭제 진행(삭제 될 노드의 이전 노드를 매개변수로 넘김)
		}
		idx++;			// idx 증가
		p = tmp->link;	// 다음 노드로 이동
	}

	return head;
}

// 리스트에 존재하는 숫자 개수 세기
void findNum(ListNode* head, element num) {
	int count = 0;	// 숫자 개수 세는 변수
	for (ListNode* p = head; p != NULL; p = p->link) {	// 리스트 순회
		if (p->data == num) count++;	// 찾는 값이 존재하면 count 증가
	}
	printf("%d는 리스트에 %d개 있습니다.\n", num, count);	// 개수 출력
}

// 리스트 내 최대, 최소 값 찾기
void findMiniMax(ListNode* head) {
	element max=head->data, min=head->data;	// max, min 변수에 첫번째 노드의 data 값 삽입
	for (ListNode* p = head->link; p != NULL; p = p->link) {	// 리스트 끝까지 순회
		if (p->data > max) max = p->data;	// 현재 노드의 data값이 max보다 큰 경우 max 값 변경
		if (p->data < min) min = p->data;	// 현재 노드의 data값이 min보다 작은 경우 min 값 변경
	}
	printf("최대값은 %d\n최소값은 %d\n", max, min);	// 최대값, 최소값 출력
}

int main() {

	FILE *fp;				// 파일을 읽어오기 위한 파일 포인터 선언
	ListNode *head = NULL;	// 연결리스트 head 선언
	
	fp = fopen("LinkedList.txt", "r");	// 파일 읽어오기

	if (!fp) {									// 파일을 읽어오지 못한 경우
		fprintf(stderr, "CAN NOT OPEN FILE");	// 에러메세지 출력
		return;									// 프로그램 종료
	}

	element tmp;				// 노드의 data값을 저장하는 변수
	while (!feof(fp)) {			// 파일의 끝까지 반복
		fscanf(fp,"%d", &tmp);	// data 읽어와 tmp에 저장
		head=insert(head, tmp);	// 연결리스트에 삽입
	}

	print_list(head);	// 연결리스트 출력

	while (1) {	
		int n;	// 탐색할 값을 저장하는 변수
		printf("값을 입력하세요<0: 종료>: ");
		scanf("%d", &n);	
		if (n == 0) break;		// 0을 입력한 경우 while문 종료
		else 
			findNum(head, n);	// 입력한 값이 리스트에 몇 개 있는지 탐색
	}

	findMiniMax(head);			// 최대값, 최소값 찾는 함수
	
	head= delete_even(head);	// 짝수 번째에 있는 노드 삭제
	print_list(head);			// 연결리스트 출력

	fclose(fp);					// 파일 포인터 반환
	return 0;
}