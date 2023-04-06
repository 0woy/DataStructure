/*
�̸�: ������
�й�: 20204624

���α׷� ����: �й��� �̸��� ����Ǿ� �ִ� ������ �о� �鿩
���� ť ����ü �迭�� �����ϰ� ����ϴ� ���α׷� �ۼ�

CircularQue_std.txt
20041111 �����ð�
20042222 Ʈ����
20043333 ��������
20044444 ������
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int id;
	char name[100];
}QueueObject;

QueueObject queue[MAX_SIZE];
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
int isEmpty() { return (front == rear); }

// ��ȭ ����
int isFull() { return (rear + 1) % MAX_SIZE == front; }

// ���� �Լ�
void enqueue(QueueObject item) {
	
	if (isFull()) error("ť�� ��ȭ�����Դϴ�"); 
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = item;
}

//���� �Լ�
QueueObject deque() {
	if (isEmpty()) error("ť�� ������� �Դϴ�.");
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

int get_count() {
	return (rear - front + MAX_SIZE) % MAX_SIZE;
}

int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");
	FILE *fp;
	int nCount;

	QueueObject tmp;

	fp = fopen("CircularQue_std.txt", "r");
	if (!fp) {
		fprintf(stderr, "CAN NOT OPEN FILE");
		exit(1);
	}
	nCount = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d%s", &tmp.id, tmp.name);
		enqueue(tmp);
		nCount++;
	}
	printf("front =%d, rear =%d\n", front, rear);
	for (int i = 0; i < nCount; i++) {
		int pCount;
		pCount = get_count();
		printf("���� ť�� ���� �ִ� ��� ����: %d\n", pCount);

		tmp = deque();
		printf("%2d | %2s \n\n", tmp.id, tmp.name);
	}
	printf("front =%d, rear =%d\n", front, rear);

	fclose(fp);
	return;

}


