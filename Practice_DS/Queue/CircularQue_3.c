/*
이름: 박윤아
학번: 20204624

프로그램 설명: 학번과 이름이 저장되어 있는 파일을 읽어 들여
원형 큐 구조체 배열에 저장하고 출력하는 프로그램 작성

CircularQue_std.txt
20041111 자유시간
20042222 트윅스
20043333 옥스포드
20044444 박윤아
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

// 초기화
void init() {
	front = rear = 0;
}

// 공백 검출
int isEmpty() { return (front == rear); }

// 포화 검출
int isFull() { return (rear + 1) % MAX_SIZE == front; }

// 삽입 함수
void enqueue(QueueObject item) {
	
	if (isFull()) error("큐가 포화상태입니다"); 
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = item;
}

//삭제 함수
QueueObject deque() {
	if (isEmpty()) error("큐가 공백상태 입니다.");
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

int get_count() {
	return (rear - front + MAX_SIZE) % MAX_SIZE;
}

int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");
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
		printf("원형 큐에 남아 있는 요소 개수: %d\n", pCount);

		tmp = deque();
		printf("%2d | %2s \n\n", tmp.id, tmp.name);
	}
	printf("front =%d, rear =%d\n", front, rear);

	fclose(fp);
	return;

}


