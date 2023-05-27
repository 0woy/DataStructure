/*
���Ḯ��Ʈ�� �̿��� ���� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
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

// ���� ��� �Լ�
void print_stack(LinckedStackType* s) {
	printf("-- ��� --\n");
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		printf("|(%2d)|\n", p->data);
	}
	printf("-----------\n\n");
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

// ���� ��ü ���� �Լ�
void popAll(LinckedStackType* s) {
	if (is_empty(s)) {	// ��������� ��� �����޼��� ��� �� �Լ� ����
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}

	// ������ ���� ���°� �� ������ ���� ���� �ݺ�
	while(s->top!=NULL) {
		StackNode * remove;	
		remove = s->top;
		s->top = s->top->link;
		free(remove);
	}
	printf("-- Ŭ���� --\n");
}

int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");
	LinckedStackType s;
	init_stack(&s);

	push(&s, 15);
	push(&s, 62);
	push(&s, 35);
	push(&s, 52);
	push(&s, 37);
	push(&s, 55);

	print_stack(&s);
	popAll(&s);
	print_stack(&s);

	return 0;
}