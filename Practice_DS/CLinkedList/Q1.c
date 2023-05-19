/*
���� ����Ʈ�� �̿��ؼ� ����Ʈ�� 10,20,30,40 ������� �����ϰ�
����Ʈ�� ����ϴ� ���α׷� �ۼ�

���: 10->20->30->40->
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_last(ListNode* head, element value) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));	// ��� �����Ҵ�
	node->data = value;	// data �ʵ忡 value ����

	if (head == NULL) {		// ����Ʈ�� ����ִ� ���
		head = node;		// head �����Ͱ� node�� ����Ű���� ��
		node->link = head;	// node�� link�� head�� ����Ű���� ��(�ڱ� �ڽ��� ����Ŵ)
	}

	else {							// ����Ʈ�� ������� ���� ���
		node->link = head->link;	// head�� link�� ����Ű�� ���� ���ο� ����� link�� ����Ű���� ��
		head->link = node;			// �������� ���� �ǹǷ� head�� link�� ���ο� ��带 ����Ű���� ��
		head = node;				// ��������Ʈ�� head�� �� ���� �����Ƿ� ���ο� ��带 head�� ����Ű���� ��
	}

	return head;	// ���� �� ����Ʈ ��ȯ
}

void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) return;
	p = head;
	do {
		printf("%d -> ", p->data);
		p = p->link;
	} while (p != head);

}
int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");

	ListNode* head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_last(head, 10);

	print_list(head);
	return 0;
}