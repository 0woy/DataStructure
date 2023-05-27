/*
���Ḯ��Ʈ�� �̿��� ������ �����Ͽ�
���� ǥ����� ���� ǥ������� �����ϰ� �̸� ����ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char element;
typedef struct StackNode {
	element data;
	struct StackNode *link;
}StackNode;	// ���� ��� ����ü ����

typedef struct {
	StackNode *top;
}LinckedStackType;	// ���� ����ü ����(top: ���� �ֻ��� ���)
// ���� �ʱ�ȭ �Լ�
void init_stack(LinckedStackType *s) { s->top = NULL; }

// ���� ���� ���� ���� �Լ�
int is_empty(LinckedStackType* s) {
	return s->top == NULL;
}

// ���ÿ� ������ ���� �Լ�
void push(LinckedStackType *s, element data) {
	StackNode * newNode = (StackNode*)malloc(sizeof(StackNode));	// ���ο� ��� �����Ҵ�
	newNode->data = data;	// data ����
	newNode->link = s->top;	// ���ο� ��尡 ����Ű�� ��ũ = ���� ������ �ֻ��� ���
	s->top = newNode;		// ���ο� ���� ������ �ֻ��� ��� ����
}


// ���� ���� �Լ�
element pop(LinckedStackType* s) {
	if (is_empty(s)) {	// ��������� ��� �����޼��� ��� �� �Լ� ����
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	StackNode * remove;			// ������ ��带 ���� ����
	remove = s->top;			// ������ ���� = �ֻ��� ��� 
	element data = remove->data;// �����͸� ��ȯ�ϱ� ���� ����
	s->top = s->top->link;		// �ֻ��� ����� ������尡 ���� ���� �� �ֻ��� ��尡 ��
	free(remove);				// ��� ����

	return data;				// ������ ������ ��ȯ
}
element peek(LinckedStackType* s) {
	return s->top->data;
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
char* IntoPostfix(const char *str) {	// ��ȯ�� ���ڿ��� �Ű������� �޾ƿ�

	LinckedStackType s;			// ���� ����
	char ch;					// ���ڿ��� ���ڸ� ��� ����
	int i, n = strlen(str);		// i: ���ڿ� �ε���, n: ���ڿ� ����
	char top_op;				// ���� �ֻ����� ����� ������
	init_stack(&s);				// ���� �ʱ�ȭ

	char* result;				// ��ȯ�� ���� ǥ����� �����ϱ� ���� ����
	int idx = 0;				// result�� ���ڸ� �����ϱ����� idx

	result = (char*)malloc(sizeof(char)*(n+1));	//null ���ڸ� �����ϱ� ���� ����+1 ��ŭ �Ҵ�
	
	for (i = 0; i < n; i++) {	// ���ڿ� ������ �˻�
		ch = str[i];			// ���ڿ��� i��° ���ڸ� ch�� ����
		switch (ch)
		{
		case '+': case '-': case '*': case '/':	// ch�� �������� ���

			// ������ ������� �ʰ�, ���� �������� �켱������ ���� �ֻ��� �������� �켱�������� ���ų� ���� ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))){
				element tmp = pop(&s);
				result[idx++] =tmp;
				printf("%c", tmp);		// ������ �ֻ��� ������ ���				
			}
			push(&s, ch);				// ���� ������ ����		
			break;
		case '(': 
			push(&s, ch); 			
			break;	// ch�� ���� �Ұ�ȣ�� ��� ���ÿ� ����
		case ')':						// ch�� �ݴ� �Ұ�ȣ�� ���
			top_op = pop(&s);			// ������ �ֻ��� �����ڸ� top_op�� ����
			while (top_op != '(') {		// top_op�� ���� �Ұ�ȣ�� ���� ������ �ݺ�
				result[idx++] = top_op;
				printf("%c", top_op);	// �ش� ������ ���
				top_op = pop(&s);		// ������ �ֻ��� ������ top_op�� ����
			}
			break;
		default:				// ch�� �ǿ������� ���
			result[idx++] = ch;	
			printf("%c", ch);	// ch ���
			break;
		}
	}
	while (!is_empty(&s)) {		// ���ÿ� �����ִ� ��Ұ� ���� ������ �ݺ�
		char tmp = pop(&s);
		result[idx++] = tmp;
		printf("%c", tmp);		// ������ �ֻ��� ��� ���
	}				
	result[idx] = '\0';			// null ���� �߰�(�߰����� ������ �����Ⱚ�� ��)
	printf("\n");				// �ٹٲ�

	return result;
}

// ����ǥ����� ��� �Լ�
int Postfix(const char *str) {	// ������ ��� ���ڿ��� �Ű������� �޾ƿ�
	LinckedStackType s;			// ���� ����
	int op1, op2, value, i = 0;	// op1,op2,value: �ǿ�����, i: ���ڿ� �ε���
	char ch;					// ���ڿ��� ���ڸ� �޴� ����
	int n = strlen(str);		// ���ڿ� ����

	init_stack(&s);	// ���� �ʱ�ȭ

	for (i = 0; i < n; i++) {	// ���ڿ��� ������ �˻�
		ch = str[i];	// i��° ���ڸ� ch�� ����
		if (!ch) { break; }
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
	printf("�̸�: ������\n�й�:20204624\n\n");
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
		printf("���� ǥ�����: %s\n", buffer);
		printf("���� ǥ�����: ");
		char* post= IntoPostfix(&buffer);	// ���� ǥ��� ��� �� post�� ����
		int res= Postfix(post);				// ���� ǥ��� ��� ��� ����
		printf("�������: %d\n\n", res);
	}
	fclose(fp);
	return 0;
}