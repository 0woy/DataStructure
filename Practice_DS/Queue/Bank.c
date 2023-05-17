# include <stdio.h>
# include <stdlib.h>

typedef struct { // 요소 타입
	int id;				// 고객 번호 
	int arrival_time;	// 고객 도착 시간
	int service_time;	// 고객이 필요한 서비스 시간
} element;

#define MAX_QUEUE_SIZE 5
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType *q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element peek(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


int main(void)
{
	int minutes = 60;			// 은행 업무 시간
	int total_wait = 0;			// 전체 대기 시간
	int total_customers = 0;	// 총 방문한 고객 수
	int service_time = 0;		// 업무 보는 고객이 있는지 확인하는 변수
	int service_customer;		// 현재 업무 보는 고객의 ID 

	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));	// 난수 생성
	
	// clock이 60분이 될 때까지 은행 시뮬레이션 진행
	for (int clock = 0; clock < minutes; clock++) {
		printf("현재시각=%d\n", clock);	
	
		if ((rand() % 10) < 3) {	// 0~10 사이 난수 발생, 3미만인 경우
			element customer;		// 새로운 고객 생성
			customer.id = total_customers++;	// 새로운 고객의 번호 = 방문한 고객 수
			customer.arrival_time = clock;		// 손님이 도착한 시간 = 현재 시간
			customer.service_time = rand() % 3 + 1;	// 서비스 시간은 1,2,3 중 하나
			enqueue(&queue, customer);	// 새로운 고객을 큐에 삽입

			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",
				customer.id, customer.arrival_time, customer.service_time);	// 새로온 고객 정보 출력
		}

		if (service_time > 0) {	// service_time이 0보다 큰 경우
			printf("고객 %d 업무처리중입니다. \n", service_customer);	// 현재 업무를 보는 고객 번호 출력
			service_time--;	// 서비스 시간 1 감소
		}

		else {	// 업무를 보는 손님이 없는 경우
			if (!is_empty(&queue)) {				// 큐에 손님이 있다면
				element customer = dequeue(&queue);	//  
				service_customer = customer.id;		// 받아온 고객의 번호를 service_customer으로 갱신
				service_time = customer.service_time;	// 서비스 시간 = 해당 고객이 필요한 서비스 시간 

				printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					customer.id, clock, clock - customer.arrival_time);	// 업무를 보는 고객의 정보 출력

				total_wait += clock - customer.arrival_time;	// 전체 대기시간 += 현재 시간 - 고객 도착 시간 갱신
			}
		}
	}
	printf("전체 대기 시간=%d분 \n", total_wait);
	return 0;
}