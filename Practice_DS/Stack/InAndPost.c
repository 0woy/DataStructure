/*
이름: 박윤아
학번: 20204624

프로그램 설명: 중위 표기 수식을 후위 표기 수식으로 변경 및 후위 표기 수식 계산
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

// 요소 확인 함수
element peek(StackType *s) {
	if (is_empty(s)) {						// 공백상태인 경우
		fprintf(stderr, "스택 공백 에러");	// 에러메세지 출력
		exit(1);							// 함수 종료
	}
	else return(s->data[s->top]);			// 스택의 맨 위 요소 반환
}

// 후위표기수식 계산 함수
void Postfix(const char *str, const int length) {	// 수식이 담긴 문자열, 문자열 길이 매개변수로 받음
	StackType s;				// 스택 선언
	int op1, op2, value, i = 0;	// op1,op2,value: 피연산자, i: 문자열 인덱스
	char ch;					// 문자열에 있는 문자를 받는 변수
	init(&s);	// 스택 초기화

	for (i = 0; i < length; i++) {	// 문자열 검사
		ch = str[i];			// i번째 문자를 ch에 저장
		if (ch != '+' &&ch != '-' && ch != '*'&& ch != '/') {	// ch가 연산자가 아닌 경우
			value = ch - '0';	// 해당 피연산자(문자)를 숫자로 변환
			push(&s, value);	// 해당 숫자를 스택에 삽입
		}
		else {	// ch가 연산자인 경우
			op2 = pop(&s);	// 계산에 사용할 두 번째 피연산자 op2에 저장
			op1 = pop(&s);	// 계산에 사용할 첫 번째 피연산자 op1에 저장

			switch (ch)	// 연산자에 따른 계산 결과를 스택에 삽입
			{
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2);  break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	int res = pop(&s);	// 스택에 남아있는 계산의 결과값을 res 변수에 저장
	printf("결과 값은: %d\n\n", res);	// 결과값 출력
}

// 중위표기 -> 후위표기 변환
void IntoPostfix(const char *str) {	// 변환할 문자열을 매개변수로 받아옴
	StackType s;	// 스택 변수
	char ch;		// 문자열의	문자를 담는 변수
	int i, n = strlen(str);	// i: 문자열 인덱스, n: 문자열 길이
	char top_op, temp[50];	// top_op: 스택 최상위에 저장된 연산자, temp:후위 표기 수식을 저장하는 배열
	int tmp_pos = 0;		// temp의 인덱스
	init(&s);				// 스택 초기화

	for (i = 0; i < n; i++) {	// 문자열 끝까지 검사
		ch = str[i];			// 문자열의 i번째 문자를 ch에 저장

		switch (ch)
		{
		case '+': case '-': case '*': case '/':	// ch가 연산자인 경우
			// 스택이 비어있지 않고, 현재 문자의 우선순위가 스택의 맨 위에 있는 우선순위보다 작거나 같은 경우
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {	
				temp[tmp_pos] = pop(&s);		// temp 배열에 맨 위 원소 저장
				printf("%c", temp[tmp_pos++]);	// 해당 원소 출력 
			}
			push(&s, ch);	// 연산자 ch 스택에 삽입
			break;
		case '(': push(&s, ch); break;	// ch가 여는 소괄호인 경우
		case ')':						// ch가 닫는 소괄호인 경우
			top_op = pop(&s);			// 스택의 맨 위에 있는 연산자를 top_op에 저장
			while (top_op != '(') {		// top_op가 여는 소괄호가 나올 때까지 반복
				printf("%c", top_op);		// 해당 연산자 출력
				temp[tmp_pos++] = top_op;	// temp 배열에 저장
				top_op = pop(&s);			// 맨 위 연산자 top_op에 저장
			}
			break;
		default:					// ch가 피연산자인 경우
			printf("%c", ch);		// ch 출력
			temp[tmp_pos++] = ch;	// temp에 ch 저장
			break;
		}
	}
	while (!is_empty(&s)) {				// 스택에 남아있는 요소가 없을 때까지
		temp[tmp_pos] = pop(&s);		// temp에 스택의 최상위 요소 저장
		printf("%c", temp[tmp_pos++]);	// 해당 요소 출력
	}

	printf("\n");			// 줄바꿈
	Postfix(temp, tmp_pos);	// temp에 저장된 후위 수식 표기 계산 함수 호출

}

int main() {
	printf("이름: 박윤아\n학번: 20204624\n\n");
	FILE *fp;									// 파일을 읽어오기 위한 파일 변수 선언
	fp = fopen("InAndPost.txt", "r");			// 파일을 읽어와 fp에 저장
	if (!fp) {									// 파일을 읽어올 수 없다면	
		fprintf(stderr, "CAN NOT OPEN FILE");	// 에러메세지 출력
		return;									// 프로그램 종료
	}
	char buffer[50];	//파일데이터를 한 줄씩 읽어오기 위한 변수

	while (!feof(fp)) {							// 파일의 끝까지 반복
		fscanf(fp, "%s", buffer);				// buffer에 한 줄씩 저장
		printf("중위 표기식은 %s\n", buffer);	// 중위 표기식 출력
		printf("후위 표기식은 ");				
		IntoPostfix(buffer);					// 후위 표기식 출력
	}
	fclose(fp);	// 파일포인터 반환
	return 0;	// 프로그램 종료
}