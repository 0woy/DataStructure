/*
�̸�: ������
�й�: 20204624

���α׷� ����: ��ȣ�˻� ���α׷�

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

// ��ȣ �˻� �Լ�
int check_matching(const char *str) {	// �˻��� ���ڿ��� �Ű������� �޾ƿ�
	StackType s;			// ���� ����
	char ch, open_ch;		// ch: ���ڿ��� ���ڸ� �޴� ����, open_ch: ���� ��ȣ ���� ����
	int i, n = strlen(str);	// i: ���ڿ� �ε���, n: ���ڿ� ũ��
	init(&s);				// ���� �ʱ�ȭ

	for (i = 0; i < n; i++) {	// ���ڿ� ������ �˻�
		ch = str[i];	// i��° ���ڸ� ch�� ����
		switch (ch)
		{
		// ch�� ���� ��ȣ�� ���
		case '(':
		case '{':
		case '[':
			push(&s, ch);	// ���ÿ� ����
			break;
		// ch�� �ݴ� ��ȣ�� ���
		case ')':
		case '}':
		case ']':
			if (is_empty(&s)) return 0;	// ������ ����ִ� ��� �˻� ����
			else {					// ������ ������� ���� ���
				open_ch = pop(&s);	// ������ �ֻ��� ��ȣ�� open_ch�� ����

				// open_ch�� ch�� ¦�� ���� �ʴ� ���
				if((open_ch=='(' && ch!=')')||	
					(open_ch=='{' && ch!='}')||
					(open_ch=='[' && ch!=']'))
					return 0;	// ��ȣ �˻� ����
			}
			break;
		}
	}
	if (!is_empty(&s)) return 0;	// ������ ������� ���� ��� �˻� ����
	return 1;	// ��ȣ �˻� ����
}

int main() {
	printf("�̸�: ������\n�й�: 20204624\n\n");

	FILE *fp;									// ������ �о���� ���� ���� ������ ����
	fp = fopen("Parenthesis.txt", "r");			// ������ �о�� fp�� ����
	if (!fp) {									// ������ �о�� �� ���ٸ�
		fprintf(stderr, "CAN NOT OPEN FILE");	// �����޼��� ���
		return;									// ���α׷� ����
	}
	char buffer[50];	// ���ϵ����͸� �� �پ� �о���� ���� ����
	
	while (!feof(fp)) {							// ������ ������ �ݺ�
		fscanf(fp,"%s", buffer);				// buffer�� �� �پ� ����
		if (check_matching(&buffer) == 1)		// ��ȣ�˻翡 ������ ���
			printf("%s ��ȣ�˻缺��\n", buffer);// ���� ���
		else									// ��ȣ�˻翡 ������ ���
			printf("%s ��ȣ�˻����\n", buffer);// ���� ���
	}

	fclose(fp);	// ���������� ��ȯ
	return 0;	// ���α׷� ����
}