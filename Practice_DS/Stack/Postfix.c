/*
이름: 박윤아
학번: 20204624

프로그램 설명: 후위표기수식 계산
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_STACK_SIZE 50	// 스택의 최대 크기

typedef char element;	// 데이터의 자료형
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화 함수
void init(StackType *s) {
	s->top = -1;
}

// 공백 상태 검출
int is_empty(StackType *s) {
	return(s->top == -1);
}

// 포화 상태 검출
int is_full(StackType *s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType *s, element item) {
	if (is_full(s)) {						//스택이 포화상태인 경우
		fprintf(stderr, "스택 포화 에러");	// 에러 메세지 출력
		return;								// 함수 종료
	}
	else s->data[++(s->top)] = item;		// 스택의 맨 위에 원소 삽입
}

// 삭제 함수
element pop(StackType *s) {
	if (is_empty(s)) {						// 스택이 공백상태인 경우
		fprintf(stderr, "스택 공백 에러");	// 에러메세지 출력
		exit(1);							// 함수 종료
	}
	else return(s->data[(s->top)--]);		//스택의 맨 위 요소 삭제 및 반환
}

// 후위표기수식 계산 함수
int Postfix(const char *str) {	// 수식이 담긴 문자열을 매개변수로 받아옴
	StackType s;				// 스택 변수
	int op1, op2, value, i = 0;	// op1,op2,value: 피연산자, i: 문자열 인덱스
	char ch;					// 문자열의 문자를 받는 변수
	int n = strlen(str);		// 문자열 길이

	init(&s);	// 스택 초기화

	for (i = 0; i < n; i++) {	// 문자열의 끝까지 검사
		ch = str[i];	// i번째 문자를 ch에 저장
		if (ch != '+' &&ch != '-' && ch != '*'&& ch != '/') {	// ch가 피연산자인 경우
			value = ch - '0';	// 피연산자(문자)를 숫자로 변환
			push(&s, value);	// 스택에 저장
		}
		else {				// ch가 연산자인 경우
			op2 = pop(&s);	// 계산에 사용할 두 번째 피연산자 op2에 저장
			op1 = pop(&s);	// 계산에 사용할 첫 번째 피연산자 op1에 저장
			switch (ch)		// 연산자에 따른 결과값을 스택에 저장
			{
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2);  break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);	// 스택에 남아있는 최종 결과값 반환
}

int main() {
	printf("이름: 박윤아\n학번: 20204624\n\n");

	FILE *fp;									// 파일을 읽어오기 위한 파일포인터
	fp = fopen("Postfix.txt", "r");				// 파일을 읽어와 fp에 저장
	if (!fp) {									// 파일을 읽어올 수 없다면
		fprintf(stderr, "CAN NOT OPEN FILE");	// 에러메세지 출력
		return;									// 프로그램 종료
	}
	char buffer[50];	// 파일데이터를 한 줄씩 읽어오기 위한 변수

	while (!feof(fp)) {							// 파일의 끝까지 반복
		fscanf(fp, "%s", buffer);				// buffer에 한 줄씩 저장
		printf("후위표기식은 %s\n", buffer);	// 후위 표기식 출력
		int res = Postfix(buffer);				// 후위 표기 수식 계산 결과 res에 저장
		printf("결과값은 %d\n\n",res);			// 계산 결과 출력
	}
	fclose(fp);	// 파일포인터 반환
	return 0;	// 프로그램 종료
}