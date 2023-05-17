/*
�̸�: ������
�й�: 20204624

���α׷� ����: ���� ǥ�� ������ ���� ǥ�� �������� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_STACK_SIZE 50	// ������ �ִ� ũ��

typedef char element;	// �������� �ڷ���
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//���� �ʱ�ȭ �Լ�
void init(StackType *s) {
	s->top = -1;
}

// ���� ���� ����
int is_empty(StackType *s) {
	return(s->top == -1);
}

// ��ȭ ���� ����
int is_full(StackType *s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(StackType *s, element item) {
	if (is_full(s)) {						//������ ��ȭ������ ���
		fprintf(stderr, "���� ��ȭ ����");	// ���� �޼��� ���
		return;								// �Լ� ����
	}
	else s->data[++(s->top)] = item;		// ������ �� ���� ���� ����
}

// ���� �Լ�
element pop(StackType *s) {
	if (is_empty(s)) {						// ������ ��������� ���
		fprintf(stderr, "���� ���� ����");	// �����޼��� ���
		exit(1);							// �Լ� ����
	}
	else return(s->data[(s->top)--]);		//������ �� �� ��� ���� �� ��ȯ
}

// ��� Ȯ�� �Լ�
element peek(StackType *s) {
	if (is_empty(s)) {						// ��������� ���
		fprintf(stderr, "���� ���� ����");	// �����޼��� ���
		exit(1);							// �Լ� ����
	}
	else return(s->data[s->top]);			// ������ �� �� ��� ��ȯ
}

// �������� �켱������ �����ϴ� �Լ�
int prec(char op) {
	switch (op)
	{
	case '(': case ')': return 0;	// (, )�� ��� 0 ��ȯ
	case '+': case '-': return 1;	// +, -�� ��� 1 ��ȯ
	case '*': case '/': return 2;	// *, /�� ��� 2 ��ȯ
	}
	return -1;						// �� ���� ��� -1 ��ȯ
}

int is_operator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// ���� ǥ�� -> ���� ǥ�� ��ȯ
void IntoPre(const char *infix_expression) {	// ��ȯ�� ���ڿ��� �Ű������� �޾ƿ�
	int len = strlen(infix_expression);

	// ���� �ʱ�ȭ
	StackType s;
	init(&s);


	// ����� ������ ���ڿ� �迭 ���� �Ҵ�
	char* prefix_expression = (char*)malloc(sizeof(char) * (len + 1));
	int j = 0;

	// �Էµ� ���� ǥ��� ���ڿ��� �Ųٷ� ��ĵ�ϸ鼭 ���ÿ� push
	for (int i = len - 1; i >= 0; i--) {
		char c = infix_expression[i];
		if (isalnum(c)) {  // ���ĺ��̳� ������ ��� �״�� ��� �迭�� �߰�
			prefix_expression[j++] = c;
		}
		else if (is_operator(c)) {
			while (!is_empty(&s) && prec(peek(&s)) > prec(c)) {
				// ���ÿ� �ִ� �������� �켱������ ���� �������� �켱�������� ���� ��� pop
				prefix_expression[j++] = pop(&s);
			}
			push(&s, c);  // ���� ������ ���ÿ� push
		}
		else if (c == ')') {
			push(&s, c);  // ')' ���ÿ� push
		}
		else if (c == '(') {
			// ')'�� ���� ������ ���ÿ��� pop�Ͽ� ��� �迭�� �߰�
			while (peek(&s) != ')') {
				prefix_expression[j++] = pop(&s);
			}
			pop(&s);  // '(' ���ÿ��� pop
		}
	}

	// ���ÿ� ���� �ִ� �����ڵ� pop�Ͽ� ��� �迭�� �߰�
	while (!is_empty(&s)){
		prefix_expression[j++] = pop(&s);
	}
	prefix_expression[j] = '\0';

	for (int i = strlen(prefix_expression) - 1; i >= 0; i--)
		printf("%c", prefix_expression[i]);
	printf("\n");

}

int main() {
	printf("�̸�: ������\n�й�: 20204624\n\n");

	FILE *fp;									// ������ �о���� ���� ���� ���� ����
	fp = fopen("InToPost.txt", "r");			// ������ �о�� fp�� ����
	if (!fp) {									// ������ �о�� �� ���� ���
		fprintf(stderr, "CAN NOT OPEN FILE");	// �����޼��� ���
		return;									// ���α׷� ����
	}
	char buffer[50];	// ���ϵ����͸� �� �پ� �о���� ���� ����

	while (!feof(fp)) {				// ������ ������ �ݺ�
		fscanf(fp, "%s", buffer);	// buffer�� �� �پ� ����
		IntoPre(&buffer);		// ���� ǥ��� ���
	}
	fclose(fp);	// ���������� ��ȯ
	return 0;	// ���α׷� ����
}