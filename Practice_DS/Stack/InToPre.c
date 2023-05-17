/*
이름: 박윤아
학번: 20204624

프로그램 설명: 중위 표기 수식을 전위 표기 수식으로 변경
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

// 요소 확인 함수
element peek(StackType *s) {
	if (is_empty(s)) {						// 공백상태인 경우
		fprintf(stderr, "스택 공백 에러");	// 에러메세지 출력
		exit(1);							// 함수 종료
	}
	else return(s->data[s->top]);			// 스택의 맨 위 요소 반환
}

// 연산자의 우선순위를 결정하는 함수
int prec(char op) {
	switch (op)
	{
	case '(': case ')': return 0;	// (, )인 경우 0 반환
	case '+': case '-': return 1;	// +, -인 경우 1 반환
	case '*': case '/': return 2;	// *, /인 경우 2 반환
	}
	return -1;						// 그 외인 경우 -1 반환
}

int is_operator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// 중위 표기 -> 후위 표기 변환
void IntoPre(const char *infix_expression) {	// 변환할 문자열을 매개변수로 받아옴
	int len = strlen(infix_expression);

	// 스택 초기화
	StackType s;
	init(&s);


	// 결과를 저장할 문자열 배열 동적 할당
	char* prefix_expression = (char*)malloc(sizeof(char) * (len + 1));
	int j = 0;

	// 입력된 중위 표기식 문자열을 거꾸로 스캔하면서 스택에 push
	for (int i = len - 1; i >= 0; i--) {
		char c = infix_expression[i];
		if (isalnum(c)) {  // 알파벳이나 숫자인 경우 그대로 결과 배열에 추가
			prefix_expression[j++] = c;
		}
		else if (is_operator(c)) {
			while (!is_empty(&s) && prec(peek(&s)) > prec(c)) {
				// 스택에 있는 연산자의 우선순위가 현재 연산자의 우선순위보다 높은 경우 pop
				prefix_expression[j++] = pop(&s);
			}
			push(&s, c);  // 현재 연산자 스택에 push
		}
		else if (c == ')') {
			push(&s, c);  // ')' 스택에 push
		}
		else if (c == '(') {
			// ')'를 만날 때까지 스택에서 pop하여 결과 배열에 추가
			while (peek(&s) != ')') {
				prefix_expression[j++] = pop(&s);
			}
			pop(&s);  // '(' 스택에서 pop
		}
	}

	// 스택에 남아 있는 연산자들 pop하여 결과 배열에 추가
	while (!is_empty(&s)){
		prefix_expression[j++] = pop(&s);
	}
	prefix_expression[j] = '\0';

	for (int i = strlen(prefix_expression) - 1; i >= 0; i--)
		printf("%c", prefix_expression[i]);
	printf("\n");

}

int main() {
	printf("이름: 박윤아\n학번: 20204624\n\n");

	FILE *fp;									// 파일을 읽어오기 위한 파일 변수 선언
	fp = fopen("InToPost.txt", "r");			// 파일을 읽어와 fp에 저장
	if (!fp) {									// 파일을 읽어올 수 없는 경우
		fprintf(stderr, "CAN NOT OPEN FILE");	// 에러메세지 출력
		return;									// 프로그램 종료
	}
	char buffer[50];	// 파일데이터를 한 줄씩 읽어오기 위한 변수

	while (!feof(fp)) {				// 파일의 끝까지 반복
		fscanf(fp, "%s", buffer);	// buffer에 한 줄씩 저장
		IntoPre(&buffer);		// 후위 표기식 출력
	}
	fclose(fp);	// 파일포인터 반환
	return 0;	// 프로그램 종료
}