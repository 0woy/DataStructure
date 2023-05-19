/*
���� ���� ����Ʈ�� �̿��ؼ� 0, 1, 2, 3, 4�� �Է��ϰ�
4, 3, 2, 1, 0�� ���� �ϰ� �� �ܰ躰�� ����Ʈ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;	// ���� ���Ḯ��Ʈ ����ü ����

// head ��� �ʱ�ȭ
void init(DListNode* head) {
	head->llink = head;	
	head->rlink = head;
}

void dinsert(DListNode* before, element value) {
	DListNode * node = (DListNode*)malloc(sizeof(DListNode));	// ��� �����Ҵ�
	node->data = value;				// data �ʵ忡 value ����
	node->llink = before;			// ����� ���� ��ũ�� before�� ����Ű���� ��
	node->rlink = before->rlink;	// ����� ������ ��ũ�� before�� ������ link�� ����Ű�� ���� ����Ű���� ��

	// head����� ������ �����̹Ƿ�, rlink(���� head�� ������ ���)�� llink�� newNode�� ����Ű���� ��
	before->rlink->llink = node;	
	before->rlink = node;			// before ����� ������ link�� newNode�� ����Ű���� ��
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;			// ����Ʈ�� ����ִ� ��� �Լ� ����

	// removed�� llink(���ʳ��)�� rlink�� removed�� rlink(������ ���)�� ����Ű���� ��
	removed->llink->rlink= removed->rlink;	

	// removed�� rlink(������ ���)�� llink�� removed�� llink(���� ���)�� ����Ű���� ��
	removed->rlink->llink = removed->llink;

	free(removed);	// ��� ����

}

void print_dlist(DListNode* head) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {	// head����� ������ ��� ���� ��ȯ
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");

	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	
	printf("�߰� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		// ��� ����� �����ʿ� ����
		dinsert(head, i);
		print_dlist(head);
	}

	printf("\n���� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}