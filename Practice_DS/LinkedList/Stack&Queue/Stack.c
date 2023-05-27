/*
연결리스트를 이용한 스택 구현
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode *link;
}StackNode;	// 스택 노드 구조체 선언

typedef struct {
	StackNode *top;
}LinckedStackType;	// 스택 구조체 선언(top: 현재 최상위 노드)

// 스택 초기화 함수
void init_stack(LinckedStackType *s) { s->top = NULL; }

// 스택 공백 상태 검출 함수
int is_empty(LinckedStackType* s) {
	return s->top == NULL;
}

// 스택에 데이터 삽입 함수
void push(LinckedStackType *s, element data) {
	StackNode * newNode = (StackNode*)malloc(sizeof(StackNode));	// 새로운 노드 동적할당
	newNode->data = data;	// data 저장
	newNode->link = s->top;	// 새로운 노드가 가리키는 링크 = 현재 스택의 최상위 노드
	s->top = newNode;		// 새로운 노드로 스택의 최상위 노드 변경
}

// 스택 출력 함수
void print_stack(LinckedStackType* s) {
	printf("-- 출력 --\n");
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		printf("|(%2d)|\n", p->data);
	}
	printf("-----------\n\n");
}

// 스택 삭제 함수
element pop(LinckedStackType* s) {
	if (is_empty(s)) {	// 공백상태인 경우 에러메세지 출력 및 함수 종료
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	StackNode * remove;			// 삭제될 노드를 저장 변수
	remove = s->top;			// 삭제될 변수 = 최상위 노드 
	element data = remove->data;// 데이터를 반환하기 위해 저장
	s->top = s->top->link;		// 최상위 노드의 다음노드가 삭제 연산 후 최상위 노드가 됨
	free(remove);				// 노드 삭제

	return data;				// 저장한 데이터 반환
}

// 스택 전체 삭제 함수
void popAll(LinckedStackType* s) {
	if (is_empty(s)) {	// 공백상태인 경우 에러메세지 출력 및 함수 종료
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}

	// 스택이 공백 상태가 될 때까지 삭제 연산 반복
	while(s->top!=NULL) {
		StackNode * remove;	
		remove = s->top;
		s->top = s->top->link;
		free(remove);
	}
	printf("-- 클리어 --\n");
}

int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");
	LinckedStackType s;
	init_stack(&s);

	push(&s, 15);
	push(&s, 62);
	push(&s, 35);
	push(&s, 52);
	push(&s, 37);
	push(&s, 55);

	print_stack(&s);
	popAll(&s);
	print_stack(&s);

	return 0;
}