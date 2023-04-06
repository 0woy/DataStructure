/*
�̸�: ������
�й�: 20204624

���α׷� ����: ���Ͽ��� ������ �����͸� �о� �鿩
�迭�� ������ ���� ť�� addq, deleteq �ϴ� ���α׷� �ۼ�

CircularQue_1.txt
56
45
3
46
57
12
74

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int element;
element queue[MAX_SIZE];
int front, rear;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ
void init() {
	front = rear = 0;
}

// ���� ����
int isEmpty() {return (front == rear);}

// ��ȭ ����
int isFull() { return (rear + 1) % MAX_SIZE == front; }

// ���� �Լ�
void enqueue(element item) {
	if (isFull()) error("ť�� ��ȭ �����Դϴ�.");
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = item;
}

//���� �Լ�
element deque() {
	if(isEmpty()) error("ť�� ������� �Դϴ�.");
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");
	FILE *fp;
	int data;
	fp = fopen("CircularQue_1.txt", "r");
	if (!fp) {
		fprintf(stderr, "CAN NOT OPEN FILE");
		exit(1);
	}
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);
		enqueue(data);
	}
	printf("front = %d, rear= %d\n", front, rear);
	while (!isEmpty()) {
		printf("deleteq() = %d\n", deque());
	}
	printf("front = %d, rear= %d\n", front, rear);

	fclose(fp);
	return;

}


