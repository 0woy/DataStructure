/*
���� ���� ����Ʈ�� �̿��� ������ �����ϰ�
����� ��ɿ� ���� ���� �����ϴ� ���α׷� �ۼ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[20];
}element;

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

DListNode* current;

void dinsert(DListNode* before, char value[]) {
	DListNode * node = (DListNode*)malloc(sizeof(DListNode));	// ��� �����Ҵ�
	strcpy(node->data.name, value);				// data �ʵ忡 value ����
	node->llink = before;			// ����� ���� ��ũ�� before�� ����Ű���� ��
	node->rlink = before->rlink;	// ����� ������ ��ũ�� before�� ������ link�� ����Ű�� ���� ����Ű���� ��

	// head����� ������ �����̹Ƿ�, rlink(���� head�� ������ ���)�� llink�� newNode�� ����Ű���� ��
	before->rlink->llink = node;
	before->rlink = node;			// before ����� ������ link�� newNode�� ����Ű���� ��
}

void print_dlist(DListNode* head) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {	// head����� ������ ��� ���� ��ȯ
		if(p == current) printf("<-| #%s# |-> ", p->data.name);	// ���� ����Ǵ� ������ ��� # �߰�
		else printf("<-| %s |-> ", p->data.name);				// �׷��� ���� ��� �׳� ���
	}
	printf("\n");
}


int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "Mamamaia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");

	current = head->rlink;
	print_dlist(head);

	do {
		printf("\n��ɾ �Է��Ͻÿ� (<, >, q):");
		ch = getchar();
		switch (ch) {
		case '<':
			current = current->llink;
			if (current == head) current = current->llink;
			break;
		case '>':
			current = current->rlink;
			if (current == head) current = current->rlink;
			break;
		}
		print_dlist(head);
		getchar();
	} while (ch != 'q');

	free(head);
	return 0;
}