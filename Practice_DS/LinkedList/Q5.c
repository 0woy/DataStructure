/*
�̸�: ������
�й�: 20204624
data.txt ���Ͽ� �ִ� ���ڵ��� �о� ���Ḯ��Ʈ�� �߰� �� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {		
	element data;	
	struct ListNode *link;
}ListNode;	// ���Ḯ��Ʈ ����ü ����

// ����Ʈ �� �ڿ� �����ϴ� �Լ�
ListNode* insert(ListNode* head, element value) {	
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));	// ��� ���� �Ҵ�
	p->data = value;	// ���� value ����
	p->link = NULL;		// �� �� ����̹Ƿ� link�� Null ����

	ListNode *tmp;		// ���� �� ����Ʈ �� ������ ��� ã�� ���� ����

	if (head==NULL) {	// ����Ʈ�� ����ִ� ���
		head = p;		// p�� �� ó�� ��尡 ��
		return head;	// head ��ȯ �� �Լ� ����
	}
	else {							// ����Ʈ�� ������� ���� ���
		tmp = head;					// tmp�� head�� ����Ű���� ��(�� ó������ ��ȸ�ϱ� ����)
		while (tmp->link != NULL)	// ������ ������ �̵�
			tmp = tmp->link;	
		tmp->link = p;				// ���� ������ ��尡 ����Ű�� link�� p�� ����Ű���� ��
	}
	return head;					// head ��ȯ �� �Լ� ����
}

// ���� ����Ʈ ���
void print_list(ListNode* head) {
	printf("< ");
	for (ListNode* i = head; i != NULL; i = i->link) {	// ����Ʈ�� ó������ ������ ��ȸ
		printf("%d ", i->data);		// ��尡 ���� data �� ���
	}
	printf(">\n");

}

// ���� �Լ�
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;			// ������ ��� ���� ����
	if (!head) return NULL;		// ����Ʈ�� ����ִ� ��� NULL ��ȯ �� �Լ� ����
	removed = pre->link;		// pre�� link�� ����Ű�� ��尡 ������ ���
	pre->link = removed->link;	// pre�� link�� ���� ����� ���� ��带 ����Ű���� ��
	free(removed);				// removed �޸� ��ȯ�Ͽ� ��� ����
	return head;				// ������ �Ϸ�� ���Ḯ��Ʈ ��ȯ
}

// ¦�� ��° ��� ����
ListNode* delete_even(ListNode* head) {
	ListNode* p = head;		// p ������ ���� ���Ḯ��Ʈ ��ȸ
	int idx = 0;			// ¦������ �Ǻ��ϴ� ����

	ListNode *tmp = NULL;	// ���� �� ���� ������ ������ ��带 ���� �ϴ� ����

	while(p != NULL) {		// ����Ʈ�� ������ �ݺ�
		if (idx == 0) {		// �� ó�� ����� ���

			ListNode* removed;		// ������ ��带 �����ϴ� ����
			if (!head) return;		// ���Ḯ��Ʈ�� ����ִ� ��� ����
			removed = head;			// ������ ��� = head
			head = removed->link;	// ���� ���� �� head�� �� ��° ��尡 ��(removed->link)
			p = removed->link;		// p�� ���� ����Ʈ�� ��ȸ �ϹǷ� head�� ���� �� ��° ��� ����
			free(removed);			// ��� ����
			idx++;
			continue;
		}
		
		if (idx % 2 != 0) {	// Ȧ���� ��� 1, 3, 5 . . 
			tmp = p;		// ���� ��� tmp�� ����
			head = delete(head, p);	// ���� ����(���� �� ����� ���� ��带 �Ű������� �ѱ�)
		}
		idx++;			// idx ����
		p = tmp->link;	// ���� ���� �̵�
	}

	return head;
}

// ����Ʈ�� �����ϴ� ���� ���� ����
void findNum(ListNode* head, element num) {
	int count = 0;	// ���� ���� ���� ����
	for (ListNode* p = head; p != NULL; p = p->link) {	// ����Ʈ ��ȸ
		if (p->data == num) count++;	// ã�� ���� �����ϸ� count ����
	}
	printf("%d�� ����Ʈ�� %d�� �ֽ��ϴ�.\n", num, count);	// ���� ���
}

// ����Ʈ �� �ִ�, �ּ� �� ã��
void findMiniMax(ListNode* head) {
	element max=head->data, min=head->data;	// max, min ������ ù��° ����� data �� ����
	for (ListNode* p = head->link; p != NULL; p = p->link) {	// ����Ʈ ������ ��ȸ
		if (p->data > max) max = p->data;	// ���� ����� data���� max���� ū ��� max �� ����
		if (p->data < min) min = p->data;	// ���� ����� data���� min���� ���� ��� min �� ����
	}
	printf("�ִ밪�� %d\n�ּҰ��� %d\n", max, min);	// �ִ밪, �ּҰ� ���
}

int main() {

	FILE *fp;				// ������ �о���� ���� ���� ������ ����
	ListNode *head = NULL;	// ���Ḯ��Ʈ head ����
	
	fp = fopen("LinkedList.txt", "r");	// ���� �о����

	if (!fp) {									// ������ �о���� ���� ���
		fprintf(stderr, "CAN NOT OPEN FILE");	// �����޼��� ���
		return;									// ���α׷� ����
	}

	element tmp;				// ����� data���� �����ϴ� ����
	while (!feof(fp)) {			// ������ ������ �ݺ�
		fscanf(fp,"%d", &tmp);	// data �о�� tmp�� ����
		head=insert(head, tmp);	// ���Ḯ��Ʈ�� ����
	}

	print_list(head);	// ���Ḯ��Ʈ ���

	while (1) {	
		int n;	// Ž���� ���� �����ϴ� ����
		printf("���� �Է��ϼ���<0: ����>: ");
		scanf("%d", &n);	
		if (n == 0) break;		// 0�� �Է��� ��� while�� ����
		else 
			findNum(head, n);	// �Է��� ���� ����Ʈ�� �� �� �ִ��� Ž��
	}

	findMiniMax(head);			// �ִ밪, �ּҰ� ã�� �Լ�
	
	head= delete_even(head);	// ¦�� ��°�� �ִ� ��� ����
	print_list(head);			// ���Ḯ��Ʈ ���

	fclose(fp);					// ���� ������ ��ȯ
	return 0;
}