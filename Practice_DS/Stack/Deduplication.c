#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;
#define MAX_STACK_SIZE 50	// ������ �ִ� ũ��

typedef struct {
	element data[MAX_STACK_SIZE];	// MAX_STACK_SIZE�� ���� �迭
	int top;						// ������ Index
}Stack;	// ����ü�� ����� Stack

// ���� �ʱ�ȭ �Լ�
void init(Stack* s) {
	s->top = -1;	// top�� -1�� ����
}

// ���� ���� ���� �Լ�
int isEmpty(Stack* s) {
	return s->top == -1;	// top�� -1�� ��� True(1)
}

// ��ȭ ���� ���� �Լ�
int isFull(Stack* s) {
	return (s->top == (MAX_STACK_SIZE - 1));	// top�� MAX_STACK_SIZE-1 ���� ���� ��� True(1)
}

// ���� �Լ�
void push(Stack* s, element item) {
	if (isFull(s)) {						// ������ ���� �� ���
		fprintf(stderr, "STACK IS FULL");	// �����޼��� ���
		return;								// �Լ� ����
	}
	s->data[++s->top] = item;	// top �ε����� 1������ �� ���ÿ� item ����
}

// ���� �Լ�
element pop(Stack* s) {
	if (isEmpty(s)) {						// ������ ������ ���
		fprintf(stderr, "STACK IS EMPTY");	// �����޼��� ���
		return;								// �Լ� ����
	}
	return s->data[s->top--];				// top Index�� �ִ� �� return �� top 1����
}

// �ֱ� ���� �� ��ȯ �Լ�
element peek(Stack* s) {
	return s->data[s->top];	// top Index�� �ִ� �� ��ȯ
}

int main() {
	Stack s;		// ���� ����
	char line[100];	// �Է� �ޱ� ���� line ���ڿ�
	init(&s);		// ���� �ʱ�ȭ
	printf("������ �Է��Ͻÿ�: ");
	gets(line, 100);	// line�� ũ�� ��ŭ �Է� ����

	for (int i = 0; i < strlen(line); i++) {
		if (isEmpty(&s)) {			// ������ ����ִ� ���
			push(&s, line[i]);		// i��° �ε����� ���� ����
			printf("%c", line[i]);	// i��° �ε����� ���� ���
		}
		else {							// ������ ������� ���� ���
			if (peek(&s) != line[i]) {	// ���� �ֱٿ� ���� ���� i��° ���ڰ� ���� ���� ���
				push(&s, line[i]);		// i��° �ε����� ���� ����
				printf("%c", line[i]);	// i��° �ε����� ���� ���
			}
		}
	}

	return 0;
}