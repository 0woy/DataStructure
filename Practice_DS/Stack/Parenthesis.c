/*
이름: 박윤아
학번: 20204624

프로그램 설명: 괄호검사 프로그램

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

// 괄호 검사 함수
int check_matching(const char *str) {	// 검사할 문자열을 매개변수로 받아옴
	StackType s;			// 스택 변수
	char ch, open_ch;		// ch: 문자열의 문자를 받는 변수, open_ch: 여는 괄호 저장 변수
	int i, n = strlen(str);	// i: 문자열 인덱스, n: 문자열 크기
	init(&s);				// 스택 초기화

	for (i = 0; i < n; i++) {	// 문자열 끝까지 검사
		ch = str[i];	// i번째 문자를 ch에 저장
		switch (ch)
		{
		// ch가 여는 괄호인 경우
		case '(':
		case '{':
		case '[':
			push(&s, ch);	// 스택에 저장
			break;
		// ch가 닫는 괄호인 경우
		case ')':
		case '}':
		case ']':
			if (is_empty(&s)) return 0;	// 스택이 비어있는 경우 검사 실패
			else {					// 스택이 비어있지 않은 경우
				open_ch = pop(&s);	// 스택의 최상위 괄호를 open_ch에 저장

				// open_ch와 ch가 짝이 맞지 않는 경우
				if((open_ch=='(' && ch!=')')||	
					(open_ch=='{' && ch!='}')||
					(open_ch=='[' && ch!=']'))
					return 0;	// 괄호 검사 실패
			}
			break;
		}
	}
	if (!is_empty(&s)) return 0;	// 스택이 비어있지 않은 경우 검사 실패
	return 1;	// 괄호 검사 성공
}

int main() {
	printf("이름: 박윤아\n학번: 20204624\n\n");

	FILE *fp;									// 파일을 읽어오기 위한 파일 포인터 선언
	fp = fopen("Parenthesis.txt", "r");			// 파일을 읽어와 fp에 저장
	if (!fp) {									// 파일을 읽어올 수 없다면
		fprintf(stderr, "CAN NOT OPEN FILE");	// 에러메세지 출력
		return;									// 프로그램 종료
	}
	char buffer[50];	// 파일데이터를 한 줄씩 읽어오기 위한 변수
	
	while (!feof(fp)) {							// 파일의 끝까지 반복
		fscanf(fp,"%s", buffer);				// buffer에 한 줄씩 저장
		if (check_matching(&buffer) == 1)		// 괄호검사에 성공한 경우
			printf("%s 괄호검사성공\n", buffer);// 성공 출력
		else									// 괄호검사에 실패한 경우
			printf("%s 괄호검사실패\n", buffer);// 실패 출력
	}

	fclose(fp);	// 파일포인터 반환
	return 0;	// 프로그램 종료
}