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

// ���� ǥ�� -> ���� ǥ�� ��ȯ
void IntoPostfix(const char *str) {	// ��ȯ�� ���ڿ��� �Ű������� �޾ƿ�
	StackType s;				// ���� ����
	char ch;					// ���ڿ��� ���ڸ� ��� ����
	int i, n = strlen(str);		// i: ���ڿ� �ε���, n: ���ڿ� ����
	char top_op;				// ���� �ֻ����� ����� ������
	init(&s);					// ���� �ʱ�ȭ

	for (i = 0; i < n; i++) {	// ���ڿ� ������ �˻�
		ch = str[i];			// ���ڿ��� i��° ���ڸ� ch�� ����
		switch (ch)
		{
		case '+': case '-': case '*': case '/':	// ch�� �������� ���

			// ������ ������� �ʰ�, ���� �������� �켱������ ���� �ֻ��� �������� �켱�������� ���ų� ���� ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) 
				printf("%c", pop(&s));	// ������ �ֻ��� ������ ���
			push(&s, ch);				// ���� ������ ����
			break;
		case '(': push(&s, ch); break;	// ch�� ���� �Ұ�ȣ�� ��� ���ÿ� ����
		case ')':						// ch�� �ݴ� �Ұ�ȣ�� ���
			top_op = pop(&s);			// ������ �ֻ��� �����ڸ� top_op�� ����
			while (top_op != '(') {		// top_op�� ���� �Ұ�ȣ�� ���� ������ �ݺ�
				printf("%c", top_op);	// �ش� ������ ���
				top_op = pop(&s);		// ������ �ֻ��� ������ top_op�� ����
			}
			break;
		default:				// ch�� �ǿ������� ���
			printf("%c", ch);	// ch ���
			break;
		}
	}
	while (!is_empty(&s))		// ���ÿ� �����ִ� ��Ұ� ���� ������ �ݺ�
		printf("%c", pop(&s));	// ������ �ֻ��� ��� ���
	printf("\n");				// �ٹٲ�
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
		IntoPostfix(&buffer);		// ���� ǥ��� ���
	}
	fclose(fp);	// ���������� ��ȯ
	return 0;	// ���α׷� ����
}