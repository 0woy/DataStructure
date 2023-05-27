/*
연결리스트를 이용해 스택을 구현하여
중위 표기식을 후위 표기식으로 변경하고 이를 계산하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char element;
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
element peek(LinckedStackType* s) {
	return s->top->data;
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

// 중위 표기 -> 후위 표기 변환
char* IntoPostfix(const char *str) {	// 변환할 문자열을 매개변수로 받아옴

	LinckedStackType s;			// 스택 변수
	char ch;					// 문자열의 문자를 담는 변수
	int i, n = strlen(str);		// i: 문자열 인덱스, n: 문자열 길이
	char top_op;				// 스택 최상위에 저장된 연산자
	init_stack(&s);				// 스택 초기화

	char* result;				// 변환된 후위 표기식을 저장하기 위한 변수
	int idx = 0;				// result에 문자를 저장하기위한 idx

	result = (char*)malloc(sizeof(char)*(n+1));	//null 문자를 저장하기 위해 길이+1 만큼 할당
	
	for (i = 0; i < n; i++) {	// 문자열 끝까지 검사
		ch = str[i];			// 문자열의 i번째 문자를 ch에 저장
		switch (ch)
		{
		case '+': case '-': case '*': case '/':	// ch가 연산자인 경우

			// 스택이 비어있지 않고, 현재 연산자의 우선순위가 스택 최상위 연산자의 우선순위보다 낮거나 같은 경우
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))){
				element tmp = pop(&s);
				result[idx++] =tmp;
				printf("%c", tmp);		// 스택의 최상위 연산자 출력				
			}
			push(&s, ch);				// 현재 연산자 삽입		
			break;
		case '(': 
			push(&s, ch); 			
			break;	// ch가 여는 소괄호인 경우 스택에 삽입
		case ')':						// ch가 닫는 소괄호인 경우
			top_op = pop(&s);			// 스택의 최상위 연산자를 top_op에 저장
			while (top_op != '(') {		// top_op가 여는 소괄호가 나올 때까지 반복
				result[idx++] = top_op;
				printf("%c", top_op);	// 해당 연산자 출력
				top_op = pop(&s);		// 스택의 최상위 연산자 top_op에 저장
			}
			break;
		default:				// ch가 피연산자인 경우
			result[idx++] = ch;	
			printf("%c", ch);	// ch 출력
			break;
		}
	}
	while (!is_empty(&s)) {		// 스택에 남아있는 요소가 없을 때까지 반복
		char tmp = pop(&s);
		result[idx++] = tmp;
		printf("%c", tmp);		// 스택의 최상위 요소 출력
	}				
	result[idx] = '\0';			// null 문자 추가(추가하지 않으면 쓰레기값이 들어감)
	printf("\n");				// 줄바꿈

	return result;
}

// 후위표기수식 계산 함수
int Postfix(const char *str) {	// 수식이 담긴 문자열을 매개변수로 받아옴
	LinckedStackType s;			// 스택 변수
	int op1, op2, value, i = 0;	// op1,op2,value: 피연산자, i: 문자열 인덱스
	char ch;					// 문자열의 문자를 받는 변수
	int n = strlen(str);		// 문자열 길이

	init_stack(&s);	// 스택 초기화

	for (i = 0; i < n; i++) {	// 문자열의 끝까지 검사
		ch = str[i];	// i번째 문자를 ch에 저장
		if (!ch) { break; }
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
	printf("이름: 박윤아\n학번:20204624\n\n");
	LinckedStackType s;
	FILE *fp;
	char res[100];
	fp = fopen("LinckedStack.txt", "r");
	if (!fp) {
		fprintf(stderr,"CAN NOT OPEN FILE");
		return;
	}
	char buffer[50];
	while (!feof(fp)) {
		fscanf(fp, "%s", &buffer);
		printf("중위 표기식은: %s\n", buffer);
		printf("후위 표기식은: ");
		char* post= IntoPostfix(&buffer);	// 후위 표기식 출력 및 post에 저장
		int res= Postfix(post);				// 후위 표기식 계산 결과 저장
		printf("결과값은: %d\n\n", res);
	}
	fclose(fp);
	return 0;
}