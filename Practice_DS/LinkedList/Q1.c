/*
�й�: 20204624
�̸�: ������

���α׷� ����: �ܼ� ���� ����Ʈ�� ����ڰ� �Է��ϴ� ���� �����ߴٰ� ����ϴ� ���α׷� �ۼ�
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

// ����Ʈ �� �տ� ���� �Լ�
ListNode* insert_first(ListNode* head, int value) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));	// ���ο� ��� �޸� ���� �Ҵ�
	p->data = value;	// ������ = value
	p->link = head;		// �� �տ� �����ϹǷ� link = head�� ����Ű�� �ּ�

	head = p;	// ��������͸� p�� ����
	return head;
}

ListNode* reverse(ListNode *head) {
	ListNode *r, *p, *q;	// �������� ����� ���� ������ ����
	q = NULL;	// q: �������� ��ȯ�� ����Ʈ
	p = head;	// p: �������� ��ȯ�� ����Ʈ

	while (p != NULL) {	// ����Ʈ�� ������ �ݺ�
		r = q;			// r�� ����Ű�� �ּ� = q�� ����Ű�� �ּ�
		q = p;			// q�� ����Ű�� �ּ� = p�� ����Ű�� �ּ�
		p = p->link;	// ���� ���� �̵�
		q->link = r;	// q�� link = r�� ����Ű�� �ּ�
	}
	return q;	// �������� ��ȯ�� ����Ʈ ��ȯ
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

	for (int i = 0; i <n; i++) {		// �Է� ���� ��� ������ŭ �ݺ�
		int num;
		printf("��� #%d ������: ", i);	
		scanf("%d", &num);
		head = insert_first(head, num);	// �� �տ� ��� ����
	}
	head = reverse(head);
	printf("������ ���� ����Ʈ : ");
	print_list(head);	// ����Ʈ ���
	return 0;
}