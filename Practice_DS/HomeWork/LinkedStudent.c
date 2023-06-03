/*
 ���Ḯ��Ʈ�� ������ ����Ʈ��
 - �й�, �̸�, ��,��,��,����,����� ���� �����ϰ� ����� �� �ֵ��� �϶�
 - �ְ������� ã�� ����� �� �ֵ��� �϶�

 �̸�: ������
 �й�: 20204624
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
	int id;				// �й�
	char name[10];		// �̸�
	int kor, math, eng;	// ��,��,��
	int totoal;			// ����
	double avg;			// ���

}element;	// �л� ������ �����ϴ� ����ü ����

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;	// ���Ḯ��Ʈ ADT

void  print_list(ListNode* head, bool check);	// �Լ� ���� �ۼ�

// ���� ���� ���� �Լ�
int is_empty(ListNode* head) {
	return head == NULL;	// head�� NULL �ΰ�� �ش� ����Ʈ�� �������
}

// ���� �Լ�
ListNode* insert_last(ListNode* head, element data) {
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));	// ��� �����Ҵ�
	newNode->data = data;	// �Ű������� �޾ƿ� �л� ���� data �ʵ忡 ����
	newNode->link = NULL;	// ����Ʈ�� �� �ڿ� �����ϹǷ� linke �ʵ�� NULL

	if (is_empty(head)) {	// ����Ʈ�� ����ִ� ���
		head = newNode;		// head�� ���� ���� ��带 ����Ű���� ��
	}
	else {										// ����Ʈ�� ������� ���� ���
		ListNode* p = head;						// p�� �̿��� ����Ʈ�� �� �� ��带 ã�� ����
		for (; p->link != NULL; p = p->link)	// ����Ʈ�� ������ ������ �̵�
			;
		p->link = newNode;	// ������ ����� link�� ���ο� ��带 ����Ű���� ��
	}

	return head;	// ���ο� ��尡 ���Ե� head ��ȯ
}

// ���� �Լ�
ListNode* delete_All(ListNode* head) {
	if (is_empty(head)) {	// ����Ʈ�� ����ִ� ��� �����޼��� ��� �� �Լ� ����
		fprintf(stderr, "����Ʈ�� �����Դϴ�.\n");
		exit(1);
	}
	else {							// ����Ʈ�� ������� ���� ���
		ListNode* p = head;			// ����Ʈ�� ��ȸ�ϱ� ���� p ���
		while(p != NULL) {			// ���Ḯ��Ʈ ������ �ݺ�
			ListNode* removed = p;	// removed�� ���� p�� ����Ű�� ��� ����
			p = p->link;			// p�� ���� ���� �̵�
			free(removed);			// removed�� ����� ���� ��� ����
		}
	}
	head = NULL;	// ��ü ���������Ƿ� head�� NULL ����
	return head;	// ��� ��尡 ������ head ��ȯ
}

// �ְ����� ���� �л� ã�� �Լ�
void find_1st(ListNode* head) {
	ListNode* max = head;		// �ְ����� ���� �л��� ����Ű�� max�� ù��° ��� ����
	ListNode* p = head->link;	// p�� �̿��� ����Ʈ ���� ��ȸ
	for (; p != NULL; p = p->link)						// ����Ʈ ������ �ݺ�
		if (max->data.totoal < p->data.totoal) max = p;	// ���� ����� ������ max�� �������� ���� ��� max�� ���� ��� ����
	print_list(max, 0);	// �ְ����� ���� �л� ���� ���

}

/*
// �� ���� �л� ������ ����ϴ� �Լ�
void print_one(ListNode *p) {
	printf("|========|======|====|====|====|====|======|\n");
	printf("|  �й�  | �̸� |����|����|����|����| ��� |\n");
	printf("|========|======|====|====|====|====|======|\n");
	printf("|%4d|%2s|%4d|%4d|%4d|%4d|%6.2f|\n", p->data.id, p->data.name,
			p->data.kor, p->data.eng, p->data.math, p->data.totoal, p->data.avg);	
	printf("|========|======|====|====|====|====|======|\n");
}*/

// ��ü �л� ������ ����ϴ� �Լ�
void print_list(ListNode* head, bool check) {
	ListNode* p = head;	// ����Ʈ ��ü�� ��ȸ�ϴ� p
	printf("|========|======|====|====|====|====|======|\n");
	printf("|  �й�  | �̸� |����|����|����|����| ��� |\n");
	printf("|========|======|====|====|====|====|======|\n");


	while (p != NULL) {	// ����Ʈ ������ �ݺ�
		printf("|%4d|%2s|%4d|%4d|%4d|%4d|%6.2f|\n", p->data.id, p->data.name,
			p->data.kor, p->data.eng, p->data.math, p->data.totoal, p->data.avg);
		if (check)
			p = p->link;	// ���� ���� �̵�
		else break;
	}
	printf("|========|======|====|====|====|====|======|\n");
}

int main() {
	printf("�̸�: ������\n�й�: 2024624\n\n");

	FILE *fp;	// ������ �о���� ���� ���� ������
	fp = fopen("LinkedStudent.txt", "r");	// ���� �б�
	ListNode* head =NULL;
	
	if (!fp) {	// ������ �о���� ���� ��� �����޼��� ��� �� ���α׷� ����
		fprintf(stderr, "CAN NOT OPEN FILE");
		return;
	}

	while (!feof(fp)) // ������ ������ �б�
	{
		element tmp; // ������ �����͸� �о���� ����
		fscanf(fp, "%d %s %d %d %d", &tmp.id, tmp.name, &tmp.kor, &tmp.eng, &tmp.math);	// �о�� �����͸� tmp�� ����
		tmp.totoal = tmp.kor + tmp.eng + tmp.math;	// ���� ����
		tmp.avg = (double)tmp.totoal / 3.0;			// ���� ��� ����
		head =insert_last(head, tmp);
	}

	print_list(head,1);	// ���Ḯ��Ʈ ���

	printf("\n\n�ְ�������?\n");
	find_1st(head);		// �ְ� ������ ���� �л� ���� ���

	printf("\n\n������ �� ���\n");
	head =delete_All(head);	// ����Ʈ ��ü ��� ����
	print_list(head,1);		// ���� �� ����Ʈ ���

	fclose(fp);	// ���� ������ ��ȯ
	return 0;
}