# include <stdio.h>
# include <stdlib.h>

typedef struct { // ��� Ÿ��
	int id;				// �� ��ȣ 
	int arrival_time;	// �� ���� �ð�
	int service_time;	// ���� �ʿ��� ���� �ð�
} element;

#define MAX_QUEUE_SIZE 5
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ����ť ��� �Լ�
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

// ���� �Լ�
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� �Լ�
element peek(QueueType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


int main(void)
{
	int minutes = 60;			// ���� ���� �ð�
	int total_wait = 0;			// ��ü ��� �ð�
	int total_customers = 0;	// �� �湮�� �� ��
	int service_time = 0;		// ���� ���� ���� �ִ��� Ȯ���ϴ� ����
	int service_customer;		// ���� ���� ���� ���� ID 

	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));	// ���� ����
	
	// clock�� 60���� �� ������ ���� �ùķ��̼� ����
	for (int clock = 0; clock < minutes; clock++) {
		printf("����ð�=%d\n", clock);	
	
		if ((rand() % 10) < 3) {	// 0~10 ���� ���� �߻�, 3�̸��� ���
			element customer;		// ���ο� �� ����
			customer.id = total_customers++;	// ���ο� ���� ��ȣ = �湮�� �� ��
			customer.arrival_time = clock;		// �մ��� ������ �ð� = ���� �ð�
			customer.service_time = rand() % 3 + 1;	// ���� �ð��� 1,2,3 �� �ϳ�
			enqueue(&queue, customer);	// ���ο� ���� ť�� ����

			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n",
				customer.id, customer.arrival_time, customer.service_time);	// ���ο� �� ���� ���
		}

		if (service_time > 0) {	// service_time�� 0���� ū ���
			printf("�� %d ����ó�����Դϴ�. \n", service_customer);	// ���� ������ ���� �� ��ȣ ���
			service_time--;	// ���� �ð� 1 ����
		}

		else {	// ������ ���� �մ��� ���� ���
			if (!is_empty(&queue)) {				// ť�� �մ��� �ִٸ�
				element customer = dequeue(&queue);	//  
				service_customer = customer.id;		// �޾ƿ� ���� ��ȣ�� service_customer���� ����
				service_time = customer.service_time;	// ���� �ð� = �ش� ���� �ʿ��� ���� �ð� 

				printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
					customer.id, clock, clock - customer.arrival_time);	// ������ ���� ���� ���� ���

				total_wait += clock - customer.arrival_time;	// ��ü ���ð� += ���� �ð� - �� ���� �ð� ����
			}
		}
	}
	printf("��ü ��� �ð�=%d�� \n", total_wait);
	return 0;
}