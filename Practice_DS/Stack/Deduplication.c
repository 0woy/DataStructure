#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;
#define MAX_STACK_SIZE 50	// 스택의 최대 크기

typedef struct {
	element data[MAX_STACK_SIZE];	// MAX_STACK_SIZE의 스택 배열
	int top;						// 스택의 Index
}Stack;	// 구조체로 선언된 Stack

// 스택 초기화 함수
void init(Stack* s) {
	s->top = -1;	// top을 -1로 저장
}

// 공백 상태 검출 함수
int isEmpty(Stack* s) {
	return s->top == -1;	// top이 -1인 경우 True(1)
}

// 포화 상태 검출 함수
int isFull(Stack* s) {
	return (s->top == (MAX_STACK_SIZE - 1));	// top이 MAX_STACK_SIZE-1 값과 같은 경우 True(1)
}

// 삽입 함수
void push(Stack* s, element item) {
	if (isFull(s)) {						// 스택이 가득 찬 경우
		fprintf(stderr, "STACK IS FULL");	// 에러메세지 출력
		return;								// 함수 종료
	}
	s->data[++s->top] = item;	// top 인덱스를 1증가한 후 스택에 item 삽입
}

// 삭제 함수
element pop(Stack* s) {
	if (isEmpty(s)) {						// 스택이 공백인 경우
		fprintf(stderr, "STACK IS EMPTY");	// 에러메세지 출력
		return;								// 함수 종료
	}
	return s->data[s->top--];				// top Index에 있는 값 return 및 top 1감소
}

// 최근 들어온 값 반환 함수
element peek(Stack* s) {
	return s->data[s->top];	// top Index에 있는 값 반환
}

int main() {
	Stack s;		// 스택 변수
	char line[100];	// 입력 받기 위한 line 문자열
	init(&s);		// 스택 초기화
	printf("정수를 입력하시오: ");
	gets(line, 100);	// line의 크기 만큼 입력 받음

	for (int i = 0; i < strlen(line); i++) {
		if (isEmpty(&s)) {			// 스택이 비어있는 경우
			push(&s, line[i]);		// i번째 인덱스의 문자 삽입
			printf("%c", line[i]);	// i번째 인덱스의 문자 출력
		}
		else {							// 스택이 비어있지 않은 경우
			if (peek(&s) != line[i]) {	// 가장 최근에 들어온 값과 i번째 문자가 같지 않은 경우
				push(&s, line[i]);		// i번째 인덱스의 문자 삽입
				printf("%c", line[i]);	// i번째 인덱스의 문자 출력
			}
		}
	}

	return 0;
}