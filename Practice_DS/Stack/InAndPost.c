/*
�̸�: ������
�й�: 20204624

���α׷� ����: ���� ǥ�� ������ ���� ǥ�� �������� ���� �� ���� ǥ�� ���� ���
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

// ��� Ȯ�� �Լ�
element peek(StackType *s) {
	if (is_empty(s)) {						// ��������� ���
		fprintf(stderr, "���� ���� ����");	// �����޼��� ���
		exit(1);							// �Լ� ����
	}
	else return(s->data[s->top]);			// ������ �� �� ��� ��ȯ
}

// ����ǥ����� ��� �Լ�
void Postfix(const char *str, const int length) {	// ������ ��� ���ڿ�, ���ڿ� ���� �Ű������� ����
	StackType s;				// ���� ����
	int op1, op2, value, i = 0;	// op1,op2,value: �ǿ�����, i: ���ڿ� �ε���
	char ch;					// ���ڿ��� �ִ� ���ڸ� �޴� ����
	init(&s);	// ���� �ʱ�ȭ

	for (i = 0; i < length; i++) {	// ���ڿ� �˻�
		ch = str[i];			// i��° ���ڸ� ch�� ����
		if (ch != '+' &&ch != '-' && ch != '*'&& ch != '/') {	// ch�� �����ڰ� �ƴ� ���
			value = ch - '0';	// �ش� �ǿ�����(����)�� ���ڷ� ��ȯ
			push(&s, value);	// �ش� ���ڸ� ���ÿ� ����
		}
		else {	// ch�� �������� ���
			op2 = pop(&s);	// ��꿡 ����� �� ��° �ǿ����� op2�� ����
			op1 = pop(&s);	// ��꿡 ����� ù ��° �ǿ����� op1�� ����

			switch (ch)	// �����ڿ� ���� ��� ����� ���ÿ� ����
			{
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2);  break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	int res = pop(&s);	// ���ÿ� �����ִ� ����� ������� res ������ ����
	printf("��� ����: %d\n\n", res);	// ����� ���
}

// ����ǥ�� -> ����ǥ�� ��ȯ
void IntoPostfix(const char *str) {	// ��ȯ�� ���ڿ��� �Ű������� �޾ƿ�
	StackType s;	// ���� ����
	char ch;		// ���ڿ���	���ڸ� ��� ����
	int i, n = strlen(str);	// i: ���ڿ� �ε���, n: ���ڿ� ����
	char top_op, temp[50];	// top_op: ���� �ֻ����� ����� ������, temp:���� ǥ�� ������ �����ϴ� �迭
	int tmp_pos = 0;		// temp�� �ε���
	init(&s);				// ���� �ʱ�ȭ

	for (i = 0; i < n; i++) {	// ���ڿ� ������ �˻�
		ch = str[i];			// ���ڿ��� i��° ���ڸ� ch�� ����

		switch (ch)
		{
		case '+': case '-': case '*': case '/':	// ch�� �������� ���
			// ������ ������� �ʰ�, ���� ������ �켱������ ������ �� ���� �ִ� �켱�������� �۰ų� ���� ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {	
				temp[tmp_pos] = pop(&s);		// temp �迭�� �� �� ���� ����
				printf("%c", temp[tmp_pos++]);	// �ش� ���� ��� 
			}
			push(&s, ch);	// ������ ch ���ÿ� ����
			break;
		case '(': push(&s, ch); break;	// ch�� ���� �Ұ�ȣ�� ���
		case ')':						// ch�� �ݴ� �Ұ�ȣ�� ���
			top_op = pop(&s);			// ������ �� ���� �ִ� �����ڸ� top_op�� ����
			while (top_op != '(') {		// top_op�� ���� �Ұ�ȣ�� ���� ������ �ݺ�
				printf("%c", top_op);		// �ش� ������ ���
				temp[tmp_pos++] = top_op;	// temp �迭�� ����
				top_op = pop(&s);			// �� �� ������ top_op�� ����
			}
			break;
		default:					// ch�� �ǿ������� ���
			printf("%c", ch);		// ch ���
			temp[tmp_pos++] = ch;	// temp�� ch ����
			break;
		}
	}
	while (!is_empty(&s)) {				// ���ÿ� �����ִ� ��Ұ� ���� ������
		temp[tmp_pos] = pop(&s);		// temp�� ������ �ֻ��� ��� ����
		printf("%c", temp[tmp_pos++]);	// �ش� ��� ���
	}

	printf("\n");			// �ٹٲ�
	Postfix(temp, tmp_pos);	// temp�� ����� ���� ���� ǥ�� ��� �Լ� ȣ��

}

int main() {
	printf("�̸�: ������\n�й�: 20204624\n\n");
	FILE *fp;									// ������ �о���� ���� ���� ���� ����
	fp = fopen("InAndPost.txt", "r");			// ������ �о�� fp�� ����
	if (!fp) {									// ������ �о�� �� ���ٸ�	
		fprintf(stderr, "CAN NOT OPEN FILE");	// �����޼��� ���
		return;									// ���α׷� ����
	}
	char buffer[50];	//���ϵ����͸� �� �پ� �о���� ���� ����

	while (!feof(fp)) {							// ������ ������ �ݺ�
		fscanf(fp, "%s", buffer);				// buffer�� �� �پ� ����
		printf("���� ǥ����� %s\n", buffer);	// ���� ǥ��� ���
		printf("���� ǥ����� ");				
		IntoPostfix(buffer);					// ���� ǥ��� ���
	}
	fclose(fp);	// ���������� ��ȯ
	return 0;	// ���α׷� ����
}