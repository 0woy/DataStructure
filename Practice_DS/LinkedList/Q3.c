/*
�й�: 20204624
�̸�: ������
���α׷� ����: �ܼ� ���� ����Ʈ�� ��� ����� ������ ���� ����ϴ� ���α׷�
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

ListNode* insert_last(ListNode* head, element value) {	// ����Ʈ�� �� �� ���� �Լ�

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	// ���ο� ��� �޸� ���� �Ҵ�
	p->data = value;	// �Ű������� �޾ƿ� ������ ����
	p->link = NULL;		// �� �� ����̹Ƿ� link = NULL

	ListNode *tmp;	// ���� �� ����Ʈ�� �� �� ��带 ã�� ���� ����

	if (!head) {	// ����Ʈ�� ������ ��� 
		head = p;	// ���ο� ��尡 ��尡 ��
		return;		// �Լ� ����
	}
	else {								// ����Ʈ�� ������� ���� ���	
		tmp = head;						// head���� ����
		while (tmp->link != NULL)		// ������ ������ �ݺ�
			tmp = tmp->link;
		tmp->link = p;	// ������ ����� link�� ���ο� ��带 ����Ű���� ��
	}
	return head;
}

int sum(ListNode* head) {	// ���Ḯ��Ʈ ��� ������ ���� �Լ�
	ListNode* tmp;			// �ӽ� ��� tmp ���� ����
	int sum = 0;			// ����� �հ踦 �� ���� ����

	for (tmp = head; tmp != NULL; tmp = tmp->link)	// head���� ����Ʈ ������ �ݺ�
		sum += tmp->data;							// ����� ������ �� sum�� ����

	return sum;	// ��� �հ� ��ȯ
}

void print_list(ListNode *head) {						// ����Ʈ ���
	for (ListNode *p = head; p != NULL; p = p->link)	// ����Ʈ�� ������ �ݺ�
		printf("%d-> ", p->data);						// ����� ������ ���
	printf("NULL\n");
}

int main() {

	printf("�̸�:������\n�й�:20204624\n\n");

	ListNode* head = NULL;	// ��� ������ �ʱ�ȭ

	int n;	// ����� �� ����
	printf("����� ����: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {		// �Է� ���� ��� ������ŭ �ݺ�
		int num;
		printf("��� #%d ������: ", i);
		scanf("%d", &num);
		head = insert_last(head, num);	// �� �ڿ� ��� ����

	}

	printf("���� ����Ʈ ������ �� = %d\n", sum(head));
	printf("������ ���� ����Ʈ : ");
	print_list(head);	// ����Ʈ ���
	return 0;
}