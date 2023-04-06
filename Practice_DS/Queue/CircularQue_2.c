/*
이름: 박윤아
학번: 20204624

프로그램 설명: 숫자로 이루어진 파일을 읽어 들여
원형 리스트로 구현된 큐에 저장(입력시 낮은 순서대로 저장)하고 
이를 출력하는 프로그램

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

// 초기화
void init() {
	front = rear = 0;
}

// 공백 검출
int isEmpty() { return (front == rear); }

// 포화 검출
int isFull() { return (rear + 1) % MAX_SIZE == front; }

// 삽입 함수
void enqueue(int item, int nItem) {
	int j;
	if (isFull()) error("큐가 포화상태입니다"); 
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

//삭제 함수
QueueObject deque() {
	if (isEmpty()) error("큐가 공백상태 입니다.");
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}


int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");
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


