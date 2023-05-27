/*
연결리스트를 이용한 큐 작성
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;// 요소 타입
typedef struct QueueNode {	
	element data;
	struct QueueNode *link;
}QueueNode;			// 큐의 노드 타임

typedef struct {
	QueueNode* front, *rear;
}LinkedQueueType;	// 큐 ADT 구현

// 큐 초기화 함수
void init_queue(LinkedQueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(LinkedQueueType* q) {
	return q->front == NULL;
}

// 삽입 함수
void enqueue(LinkedQueueType* q, element data) {
	QueueNode *tmp = (QueueNode*)malloc(sizeof(QueueNode));	// 노드 동적 할당
	tmp->data = data;	// 데이터 저장
	tmp->link = NULL;	// 마지막 노드이므로 링크 NULL
	if (is_empty(q)) {	// 큐가 공백 상태인 경우
		q->front = tmp;
		q->rear = tmp;
	}	
	else {				// 큐가 공백 상태가 아닌 경우
		q->rear->link = tmp;
		q->rear = tmp;
	}
}

// 삭제 함수
element dequeue(LinkedQueueType* q) {
	QueueNode * removed = q->front;
	element data;
	if (is_empty(q)) {	// 스택이 공백 상태인 경우 에러메세지 출력 및 종료
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		data = removed->data;		// 반환할 데이터 저장
		q->front = q->front->link;	// fron가 다음 노드를 가리킴
		if (q->front == NULL) q->rear = NULL;	// 공백 상태인 경우 rear NULL
		free(removed);				// 동적 메모리 해제
		return data;				// 데이터 반환
	}
}

void print_queue(LinkedQueueType* q) {
	QueueNode* p = q->front;
	for (; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL\n");
}
int main() {
	printf("이름: 박윤아\n학번: 20204624\n\n");

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

