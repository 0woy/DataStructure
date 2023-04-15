#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;	
typedef struct {
	element* data;	// 스택 배열
	int length;		// 스택의 크기
	int top;		// Index
}Stack;	// 구조체로 선언한 Stack

// 스택 초기화 함수
void init(Stack* s, int length) {	
	s->top = -1;		// top = -1
	s->length = length;	// 스택의 크기 = length
	s->data = (element*)malloc(sizeof(element) * length);	// 스택의 크기 만큼 동적 할당
}

// 공백 상태 검출
int isEmpty(Stack* s) {
	return s->top == -1;	// top이 -1인 경우 True(1)
}

// 포화 상태 검출
int isFull(Stack* s) {
	return (s->top + 1 == s->length);	// top+1의 값이 스택의 크기와 같은 경우 True(1)
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

int main() {

	element* arr;	// 정수 배열 선언
	Stack s;		// 스택 구조체 변수 선언
	int length;		// 크기를 저장할 length 변수
	printf("정수 배열의 크기: ");
	scanf("%d", &length);
	init(&s, length);	// 스택 변수와 length 변수를 매개변수로 스택 초기화 함수 호출
	arr = (element*)malloc(sizeof(element) * length);	// 배열의 크기만큼 arr 배열 동적 할당

	printf("정수를 입력하시오: ");
	for (int i = 0; i < length; i++) {
		scanf("%d", &arr[i]);	// 배열의 크기만큼 정수 입력받아 arr[i]에 할당
		push(&s, arr[i]);		// 스택에 배열 정수 삽입
	}

	printf("반전된 정수 배열: ");
	for (int i = 0; i < length; i++) {
		arr[i] = pop(&s);	// 삭제 함수 호출 및 arr[i]에 저장
	}
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);	// 반전된 정수 배열 출력

	// 할당 받은 메모리 반환
	free(s.data);
	free(arr);


	return 0;
}