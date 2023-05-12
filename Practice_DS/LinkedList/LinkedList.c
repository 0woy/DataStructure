/*
�̸�: ������
�й�: 20204624

���α׷� ����: �ܼ� ���Ḯ��Ʈ ����
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

// ����Ʈ �߰� ���� �Լ�
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));	// ���ο� ��� �޸� ���� �Ҵ�
	p->data = value;		// ������ = value
	p->link = pre->link;	// p�� link = p�� ���� ���(pre)�� link�� ����Ŵ
	pre->link = p;			// pre�� link�� p�� ����Ŵ
	return head;
}


// ����Ʈ �� �� ���� �Լ�
ListNode* delete_first(ListNode *head) {
	ListNode* removed;		// ������ ��带 �ӽ� ������ ������ ����
	if (!head) return NULL;	// ����Ʈ�� ������ ��� NULL return
	removed = head;			// removed�� ����Ű�� �ּ� = head�� ����Ű�� �ּ�(ó�� ���)
	head = removed->link;	// head�� removed(���� head�� ����Ű�� �ּ�)�� link(�� ��° ���)
	free(removed);			// �޸� �Ҵ� ���� (= ����)
	return head;

}

// ����Ʈ �߰� ��� ���� �Լ�
ListNode* delete(ListNode* head, ListNode *pre) {
	ListNode* removed;		// ������ ��带 �ӽ� ������ ������ ����
	if (!head) return NULL;	// ����Ʈ�� ������ ��� NULL return
	removed = pre->link;		// removed�� ����Ű�� �ּ� = pre�� link(pre�� ���� ���)
	pre->link = removed->link;	// pre�� link = removed�� link(������ ��� ���� ���)
	free(removed);				// �޸� �Ҵ� ���� (= ����)
	return head;
}

// ���� ����Ʈ ��� �Լ�
void print_list(ListNode *head) {
	for (ListNode *p = head; p != NULL; p = p->link)	// ����Ʈ�� ó������ ������ �ݺ�
		printf("%d-> ", p->data);	// ����� ������ ���
	printf("NULL\n");
}

int main() {

	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);	// 0~4���� ��� ����
		print_list(head);				// �� �� ������ ������ ����Ʈ ���� ���
	}

	for (int i = 0; i < 5; i++) {
		head = delete_first(head);	// ����Ʈ�� �� �� ��� ����
		print_list(head);			// �� �� ������ ������ ����Ʈ ���� ���
	}
	return 0;
}