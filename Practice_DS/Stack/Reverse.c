#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;	
typedef struct {
	element* data;	// ���� �迭
	int length;		// ������ ũ��
	int top;		// Index
}Stack;	// ����ü�� ������ Stack

// ���� �ʱ�ȭ �Լ�
void init(Stack* s, int length) {	
	s->top = -1;		// top = -1
	s->length = length;	// ������ ũ�� = length
	s->data = (element*)malloc(sizeof(element) * length);	// ������ ũ�� ��ŭ ���� �Ҵ�
}

// ���� ���� ����
int isEmpty(Stack* s) {
	return s->top == -1;	// top�� -1�� ��� True(1)
}

// ��ȭ ���� ����
int isFull(Stack* s) {
	return (s->top + 1 == s->length);	// top+1�� ���� ������ ũ��� ���� ��� True(1)
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

int main() {

	element* arr;	// ���� �迭 ����
	Stack s;		// ���� ����ü ���� ����
	int length;		// ũ�⸦ ������ length ����
	printf("���� �迭�� ũ��: ");
	scanf("%d", &length);
	init(&s, length);	// ���� ������ length ������ �Ű������� ���� �ʱ�ȭ �Լ� ȣ��
	arr = (element*)malloc(sizeof(element) * length);	// �迭�� ũ�⸸ŭ arr �迭 ���� �Ҵ�

	printf("������ �Է��Ͻÿ�: ");
	for (int i = 0; i < length; i++) {
		scanf("%d", &arr[i]);	// �迭�� ũ�⸸ŭ ���� �Է¹޾� arr[i]�� �Ҵ�
		push(&s, arr[i]);		// ���ÿ� �迭 ���� ����
	}

	printf("������ ���� �迭: ");
	for (int i = 0; i < length; i++) {
		arr[i] = pop(&s);	// ���� �Լ� ȣ�� �� arr[i]�� ����
	}
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);	// ������ ���� �迭 ���

	// �Ҵ� ���� �޸� ��ȯ
	free(s.data);
	free(arr);


	return 0;
}