/*
�̸�: ������
�й�: 20204624

���α׷� ����: ����ǥ����� ���
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

// ����ǥ����� ��� �Լ�
int Postfix(const char *str) {	// ������ ��� ���ڿ��� �Ű������� �޾ƿ�
	StackType s;				// ���� ����
	int op1, op2, value, i = 0;	// op1,op2,value: �ǿ�����, i: ���ڿ� �ε���
	char ch;					// ���ڿ��� ���ڸ� �޴� ����
	int n = strlen(str);		// ���ڿ� ����

	init(&s);	// ���� �ʱ�ȭ

	for (i = 0; i < n; i++) {	// ���ڿ��� ������ �˻�
		ch = str[i];	// i��° ���ڸ� ch�� ����
		if (ch != '+' &&ch != '-' && ch != '*'&& ch != '/') {	// ch�� �ǿ������� ���
			value = ch - '0';	// �ǿ�����(����)�� ���ڷ� ��ȯ
			push(&s, value);	// ���ÿ� ����
		}
		else {				// ch�� �������� ���
			op2 = pop(&s);	// ��꿡 ����� �� ��° �ǿ����� op2�� ����
			op1 = pop(&s);	// ��꿡 ����� ù ��° �ǿ����� op1�� ����
			switch (ch)		// �����ڿ� ���� ������� ���ÿ� ����
			{
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2);  break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);	// ���ÿ� �����ִ� ���� ����� ��ȯ
}

int main() {
	printf("�̸�: ������\n�й�: 20204624\n\n");

	FILE *fp;									// ������ �о���� ���� ����������
	fp = fopen("Postfix.txt", "r");				// ������ �о�� fp�� ����
	if (!fp) {									// ������ �о�� �� ���ٸ�
		fprintf(stderr, "CAN NOT OPEN FILE");	// �����޼��� ���
		return;									// ���α׷� ����
	}
	char buffer[50];	// ���ϵ����͸� �� �پ� �о���� ���� ����

	while (!feof(fp)) {							// ������ ������ �ݺ�
		fscanf(fp, "%s", buffer);				// buffer�� �� �پ� ����
		printf("����ǥ����� %s\n", buffer);	// ���� ǥ��� ���
		int res = Postfix(buffer);				// ���� ǥ�� ���� ��� ��� res�� ����
		printf("������� %d\n\n",res);			// ��� ��� ���
	}
	fclose(fp);	// ���������� ��ȯ
	return 0;	// ���α׷� ����
}