/*
이름: 박윤아
학번: 20204624

프로그램 설명: 파일에서 정수형 데이터를 읽어 들여
배열로 구현된 원형 큐에 addq, deleteq 하는 프로그램 작성

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

// 초기화
void init() {
	front = rear = 0;
}

// 공백 검출
int isEmpty() {return (front == rear);}

// 포화 검출
int isFull() { return (rear + 1) % MAX_SIZE == front; }

// 삽입 함수
void enqueue(element item) {
	if (isFull()) error("큐가 포화 상태입니다.");
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = item;
}

//삭제 함수
element deque() {
	if(isEmpty()) error("큐가 공백상태 입니다.");
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");
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


