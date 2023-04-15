#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100	// 큐의 크기
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];	
	int rear;
	int front;
}Queue;	// 구조체로 구현된 큐

// 큐 초기화 함수
void init(Queue* q) {
	q->front = q->rear = 0;	// rear와 front 0으로 초기화
}

int isEmpty(Queue* q) { return q->front == q->rear; }	// 공백상태 검출 함수: front와 rear 값이 같은 경우 공백
int isFull(Queue* q) { return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; }	// 포화상태 검출 함수: rear+1%(큐의 전체 크기) 값과 front 값이 같은 경우 포화

// 삽입 함수
void enque(Queue* q, element item) {
	if (isFull(q)) {						// 큐가 가득찬 경우
		fprintf(stderr, "QUEUE IS FULL");	// 에러메세지 출력
		return;								// 함수 종료
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;	// rear 값을 1증가 시킴(원형큐이므로 MAX_QUEUE_SIZE로 나눔)
	q->data[q->rear] = item;	// 큐의 rear 인덱스에 item 삽입
}

// 삭제 함수
element deque(Queue* q) {
	if (isEmpty(q)) {						// 큐가 공백상태인 경우
		fprintf(stderr, "QUEUE IS EMPTY");	// 에러메세지 출력
		return;								// 함수 종료
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;	// front를 1증가 시킴(원형큐이므로 MAX_QUEUE_SIZE로 나눔)
	return q->data[q->front];					// 큐의 front인덱스에 있는 값 반환
}

// 가장 최근에 들어온 값 확인 함수
element peek(Queue* q) {
	if (isEmpty(q)) {						// 큐가 공백상태인 경우
		fprintf(stderr, "QUEUE IS EMPTY");	// 에러메세지 출력
		return;								// 함수 종료
	}
	return q->data[q->rear];				// 큐의 rear 인덱스에 있는 값 반환
}

int main() {

	Queue q;	// 큐 변수 q 선언
	init(&q);	// q 초기화

	enque(&q, 0);	// 큐에 0 삽입
	enque(&q, 1);	// 큐에 1 삽입

	int n;	
	printf("숫자를 입력하세요: ");
	scanf("%d", &n);
	printf("0 1 ");
	for (int i = 0; i < n; i++) {
		element n1 = deque(&q);	//F(n-2)의 값 받아옴
		element n2 = peek(&q);	//F(n-1)의 값 받아옴
		printf("%d ", n1 + n2);	// F(n-2) + F(n-1) 출력
		enque(&q, n1 + n2);		// F(n-2) + F(n-1) 값 큐에 삽입
	}

	return 0;
}