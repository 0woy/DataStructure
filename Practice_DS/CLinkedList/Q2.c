/*
3���� �÷��̾ ���� ������ �Ѵ�.
���� ����Ʈ�� �̿��� ���� ���� �������� ����Ͻÿ�

���:
���� ���� = KIM
���� ���� = CHOI
���� ���� = PARK
���� ���� = KIM
���� ���� = CHOI
���� ���� = PARK
...
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct element{
	char name[10];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct CListType {
	ListNode *head;
	ListNode player[3];
}CListType;

ListNode* insert_first(CListType* list, char value[]) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));	// ��� �����Ҵ�
	strcpy(node->data.name, value);	// data �ʵ忡 value ����

	if (list->head == NULL) {		// ����Ʈ�� ����ִ� ���
		list->head = node;			// head �����Ͱ� node�� ����Ű���� ��
		node->link = list->head;	// node�� link�� head�� ����Ű���� ��(�ڱ� �ڽ��� ����Ŵ)
	}

	else {								// ����Ʈ�� ������� ���� ���
		node->link = list->head->link;	// head�� link�� ����Ű�� ���� ���ο� ����� link�� ����Ű���� ��
		list->head->link = node;		// �������� ���� �ǹǷ� head�� link�� ���ο� ��带 ����Ű���� ��
	}

	return list->head;	// ���� �� ����Ʈ ��ȯ
}

void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) return;		// ����Ʈ�� ����ִ� ��� �Լ� ����
	p = head;						// p�� head�� ����Ű�� ���� ����Ű���� ��
	do {
		printf("%d -> ", p->data);	// ���� ����� data ���
		p = p->link;				// ���� ���� �̵�
	} while (p != head);			// head�� �ƴ� ������ �ݺ�

}
int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");

	CListType list = { NULL };
	insert_first(&list, "KIM");
	insert_first(&list, "CHOI");
	insert_first(&list, "PARK");

	ListNode* p = list.head;
	for (int i = 0; i < 12; i++) {
		printf("���� ����=%s\n", p->data.name);
		p = p->link;
	}
	return 0;

}