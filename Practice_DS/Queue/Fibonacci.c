/*
���α׷� ����: �Ǻ���ġ ������ ȿ�������� ����ϱ� ���� ť�� �̿��� �� ����
ť�� ó������ F(0), F(1)���� ����־� ���� F(2)�� ����� ���� F(0)�� ť���� ���� ��,
��ѵ� F(b)�� �ٽ� ť�� �����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100	// ť�� ũ��
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];	
	int rear;
	int front;
}Queue;	// ����ü�� ������ ť

// ť �ʱ�ȭ �Լ�
void init(Queue* q) {
	q->front = q->rear = 0;	// rear�� front 0���� �ʱ�ȭ
}

int isEmpty(Queue* q) { return q->front == q->rear; }	// ������� ���� �Լ�: front�� rear ���� ���� ��� ����
int isFull(Queue* q) { return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; }	// ��ȭ���� ���� �Լ�: rear+1%(ť�� ��ü ũ��) ���� front ���� ���� ��� ��ȭ

// ���� �Լ�
void enque(Queue* q, element item) {
	if (isFull(q)) {						// ť�� ������ ���
		fprintf(stderr, "QUEUE IS FULL");	// �����޼��� ���
		return;								// �Լ� ����
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;	// rear ���� 1���� ��Ŵ(����ť�̹Ƿ� MAX_QUEUE_SIZE�� ����)
	q->data[q->rear] = item;	// ť�� rear �ε����� item ����
}

// ���� �Լ�
element deque(Queue* q) {
	if (isEmpty(q)) {						// ť�� ��������� ���
		fprintf(stderr, "QUEUE IS EMPTY");	// �����޼��� ���
		return;								// �Լ� ����
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;	// front�� 1���� ��Ŵ(����ť�̹Ƿ� MAX_QUEUE_SIZE�� ����)
	return q->data[q->front];					// ť�� front�ε����� �ִ� �� ��ȯ
}

// ���� �ֱٿ� ���� �� Ȯ�� �Լ�
element peek(Queue* q) {
	if (isEmpty(q)) {						// ť�� ��������� ���
		fprintf(stderr, "QUEUE IS EMPTY");	// �����޼��� ���
		return;								// �Լ� ����
	}
	return q->data[q->rear];				// ť�� rear �ε����� �ִ� �� ��ȯ
}

int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");
	Queue q;	// ť ���� q ����
	init(&q);	// q �ʱ�ȭ

	enque(&q, 0);	// ť�� 0 ����
	enque(&q, 1);	// ť�� 1 ����

	int n;	
	printf("���ڸ� �Է��ϼ���: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		element n1 = deque(&q);	//F(n-2)�� �� �޾ƿ�
		element n2 = peek(&q);	//F(n-1)�� �� �޾ƿ�
		if (i == 0) printf("%d %d ", n1, n2);	// ó���� ����� �ִ� F(0), F(1)�� ���
		printf("%d ", n1 + n2);	// F(n-2) + F(n-1) ���
		enque(&q, n1 + n2);		// F(n-2) + F(n-1) �� ť�� ����
	}

	return 0;
}