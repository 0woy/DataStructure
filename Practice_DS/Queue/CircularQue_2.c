/*
�̸�: ������
�й�: 20204624

���α׷� ����: ���ڷ� �̷���� ������ �о� �鿩
���� ����Ʈ�� ������ ť�� ����(�Է½� ���� ������� ����)�ϰ� 
�̸� ����ϴ� ���α׷�

CircularQue_2.txt
30
50
10
40
20
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int nPriority;
}QueueObject;

QueueObject queue[MAX_SIZE];
int front, rear;

void error(const char *message) {
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
void enqueue(int item, int nItem) {
	int j;
	if (isFull()) error("ť�� ��ȭ�����Դϴ�"); 
	if (nItem == 0) {
		queue[nItem++].nPriority = item;
	}
	else {
		for (j = nItem - 1; j >= 0; j--) {
			if (item < queue[j].nPriority)
				queue[j + 1].nPriority = queue[j].nPriority;
			else break;
		}
		queue[j + 1].nPriority = item;
	}
	rear = (rear + 1) % MAX_SIZE;
}

//���� �Լ�
QueueObject deque() {
	if (isEmpty()) error("ť�� ������� �Դϴ�.");
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}


int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");
	FILE *fp;
	int nTemp;
	int nCount;
	QueueObject qobject;

	fp = fopen("CircularQue_2.txt", "r");
	if (!fp) {
		fprintf(stderr, "CAN NOT OPEN FILE");
		exit(1);
	}

	nCount = 1;
	while (!feof(fp)) {
		fscanf(fp, "%d", &nTemp);
		enqueue(nTemp, nCount);
		nCount++;
	}

	for (int i = 0; i < nCount-1; i++) {
		qobject = deque();
		printf("%d -> ", qobject.nPriority);
	}
	printf("\n");

	fclose(fp);
	return;

}


