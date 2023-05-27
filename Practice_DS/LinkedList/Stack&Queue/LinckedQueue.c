/*
���Ḯ��Ʈ�� �̿��� ť �ۼ�
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;// ��� Ÿ��
typedef struct QueueNode {	
	element data;
	struct QueueNode *link;
}QueueNode;			// ť�� ��� Ÿ��

typedef struct {
	QueueNode* front, *rear;
}LinkedQueueType;	// ť ADT ����

// ť �ʱ�ȭ �Լ�
void init_queue(LinkedQueueType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType* q) {
	return q->front == NULL;
}

// ���� �Լ�
void enqueue(LinkedQueueType* q, element data) {
	QueueNode *tmp = (QueueNode*)malloc(sizeof(QueueNode));	// ��� ���� �Ҵ�
	tmp->data = data;	// ������ ����
	tmp->link = NULL;	// ������ ����̹Ƿ� ��ũ NULL
	if (is_empty(q)) {	// ť�� ���� ������ ���
		q->front = tmp;
		q->rear = tmp;
	}	
	else {				// ť�� ���� ���°� �ƴ� ���
		q->rear->link = tmp;
		q->rear = tmp;
	}
}

// ���� �Լ�
element dequeue(LinkedQueueType* q) {
	QueueNode * removed = q->front;
	element data;
	if (is_empty(q)) {	// ������ ���� ������ ��� �����޼��� ��� �� ����
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		data = removed->data;		// ��ȯ�� ������ ����
		q->front = q->front->link;	// fron�� ���� ��带 ����Ŵ
		if (q->front == NULL) q->rear = NULL;	// ���� ������ ��� rear NULL
		free(removed);				// ���� �޸� ����
		return data;				// ������ ��ȯ
	}
}

void print_queue(LinkedQueueType* q) {
	QueueNode* p = q->front;
	for (; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL\n");
}
int main() {
	printf("�̸�: ������\n�й�: 20204624\n\n");

	LinkedQueueType q;
	init_queue(&q);

	enqueue(&q, 1);	print_queue(&q);
	enqueue(&q, 2);	print_queue(&q);
	enqueue(&q, 3);	print_queue(&q);
	dequeue(&q);	print_queue(&q);
	dequeue(&q);	print_queue(&q);
	dequeue(&q);	print_queue(&q);


	return 0;
}

