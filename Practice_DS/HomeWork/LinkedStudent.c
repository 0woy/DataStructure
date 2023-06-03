/*
 연결리스트로 구현된 리스트에
 - 학번, 이름, 국,영,수,총점,평균의 값을 저장하고 출력할 수 있도록 하라
 - 최고점수를 찾아 출력할 수 있도록 하라

 이름: 박윤아
 학번: 20204624
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
	int id;				// 학번
	char name[10];		// 이름
	int kor, math, eng;	// 국,영,수
	int totoal;			// 총점
	double avg;			// 평균

}element;	// 학생 정보를 저장하는 구조체 선언

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;	// 연결리스트 ADT

void  print_list(ListNode* head, bool check);	// 함수 원형 작성

// 공백 상태 검출 함수
int is_empty(ListNode* head) {
	return head == NULL;	// head가 NULL 인경우 해당 리스트는 비어있음
}

// 삽입 함수
ListNode* insert_last(ListNode* head, element data) {
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));	// 노드 동적할당
	newNode->data = data;	// 매개변수로 받아온 학생 정보 data 필드에 저장
	newNode->link = NULL;	// 리스트의 맨 뒤에 삽입하므로 linke 필드는 NULL

	if (is_empty(head)) {	// 리스트가 비어있는 경우
		head = newNode;		// head가 새로 들어온 노드를 가리키도록 함
	}
	else {										// 리스트가 비어있지 않은 경우
		ListNode* p = head;						// p를 이용해 리스트의 맨 뒤 노드를 찾기 위함
		for (; p->link != NULL; p = p->link)	// 리스트의 마지막 노드까지 이동
			;
		p->link = newNode;	// 마지막 노드의 link가 새로운 노드를 가리키도록 함
	}

	return head;	// 새로운 노드가 삽입된 head 반환
}

// 삭제 함수
ListNode* delete_All(ListNode* head) {
	if (is_empty(head)) {	// 리스트가 비어있는 경우 에러메세지 출력 및 함수 종료
		fprintf(stderr, "리스트가 공백입니다.\n");
		exit(1);
	}
	else {							// 리스트가 비어있지 않은 경우
		ListNode* p = head;			// 리스트를 순회하기 위해 p 사용
		while(p != NULL) {			// 연결리스트 끝까지 반복
			ListNode* removed = p;	// removed에 현재 p가 가리키는 노드 저장
			p = p->link;			// p는 다음 노드로 이동
			free(removed);			// removed에 저장된 현재 노드 삭제
		}
	}
	head = NULL;	// 전체 삭제됐으므로 head에 NULL 저장
	return head;	// 모든 노드가 삭제된 head 반환
}

// 최고점을 가진 학생 찾는 함수
void find_1st(ListNode* head) {
	ListNode* max = head;		// 최고점을 가진 학생을 가리키는 max에 첫번째 노드 저장
	ListNode* p = head->link;	// p를 이용해 리스트 전제 순회
	for (; p != NULL; p = p->link)						// 리스트 끝까지 반복
		if (max->data.totoal < p->data.totoal) max = p;	// 현재 노드의 총점이 max의 총점보다 높은 경우 max에 현재 노드 저장
	print_list(max, 0);	// 최고점을 가진 학생 정보 출력

}

/*
// 한 개의 학생 정보를 출력하는 함수
void print_one(ListNode *p) {
	printf("|========|======|====|====|====|====|======|\n");
	printf("|  학번  | 이름 |국어|영어|수학|총점| 평균 |\n");
	printf("|========|======|====|====|====|====|======|\n");
	printf("|%4d|%2s|%4d|%4d|%4d|%4d|%6.2f|\n", p->data.id, p->data.name,
			p->data.kor, p->data.eng, p->data.math, p->data.totoal, p->data.avg);	
	printf("|========|======|====|====|====|====|======|\n");
}*/

// 전체 학생 정보를 출력하는 함수
void print_list(ListNode* head, bool check) {
	ListNode* p = head;	// 리스트 전체를 순회하는 p
	printf("|========|======|====|====|====|====|======|\n");
	printf("|  학번  | 이름 |국어|영어|수학|총점| 평균 |\n");
	printf("|========|======|====|====|====|====|======|\n");


	while (p != NULL) {	// 리스트 끝까지 반복
		printf("|%4d|%2s|%4d|%4d|%4d|%4d|%6.2f|\n", p->data.id, p->data.name,
			p->data.kor, p->data.eng, p->data.math, p->data.totoal, p->data.avg);
		if (check)
			p = p->link;	// 다음 노드로 이동
		else break;
	}
	printf("|========|======|====|====|====|====|======|\n");
}

int main() {
	printf("이름: 박윤아\n학번: 2024624\n\n");

	FILE *fp;	// 파일을 읽어오기 위한 파일 포인터
	fp = fopen("LinkedStudent.txt", "r");	// 파일 읽기
	ListNode* head =NULL;
	
	if (!fp) {	// 파일을 읽어오지 못한 경우 에러메세지 출력 및 프로그램 종료
		fprintf(stderr, "CAN NOT OPEN FILE");
		return;
	}

	while (!feof(fp)) // 파일의 끝까지 읽기
	{
		element tmp; // 파일의 데이터를 읽어오는 변수
		fscanf(fp, "%d %s %d %d %d", &tmp.id, tmp.name, &tmp.kor, &tmp.eng, &tmp.math);	// 읽어온 데이터를 tmp에 저장
		tmp.totoal = tmp.kor + tmp.eng + tmp.math;	// 총점 저장
		tmp.avg = (double)tmp.totoal / 3.0;			// 성적 평균 저장
		head =insert_last(head, tmp);
	}

	print_list(head,1);	// 연결리스트 출력

	printf("\n\n최고점수는?\n");
	find_1st(head);		// 최고 점수를 가진 학생 정보 출력

	printf("\n\n삭제된 후 출력\n");
	head =delete_All(head);	// 리스트 전체 노드 삭제
	print_list(head,1);		// 삭제 후 리스트 출력

	fclose(fp);	// 파일 포인터 반환
	return 0;
}