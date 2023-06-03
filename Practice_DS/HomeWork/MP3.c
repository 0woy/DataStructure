/*
������ �÷��̸���Ʈ ����
- ���� ���� ���� ����Ʈ�� �̿��Ͽ� ����
- ������ �÷��̾��� �ִ� �뷮 128MB
- �� ���� �뷮 4MB
- MP3�� ����� ������ �Է� ����
- MP3 �߰��� �⺻���� ���� �÷��̵Ǵ� ���� ���� ��ġ�� ���� �߰�
- �߰������� �÷��̸���Ʈ�� ���� �տ� �߰��ϴ� ��� ����
- isFull(): ����Ʈ �ȿ� ����� MP3 ���������� ũ�⸦ ����� �ִ� ũ�⸦ �ʰ��ߴ��� üũ
- ������ ���� �÷��� ���� ���� ����
- ������/ ������ �̵� ��� ����
- �÷��̸���Ʈ ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_STORAGE 128
#define ONE_STORAGE 4

// ����Ʈ �Է¸�� FLAG
#define NORMAL 0
#define FIRST 1


typedef struct ListNode {
	char* name;		// ����
	char* singer;	// ����
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;	// ���߿��Ḯ��Ʈ ��� ADT

typedef struct List {
	int listSize;		// ����Ʈ ũ��
	ListNode* play;		// ���� ������� ��
	ListNode* first;	// ����Ʈ�� ù ��° ��
}List;


void init(List* list);									// ����Ʈ �ʱ�ȭ
void printList(List* list);								// ����Ʈ ���
int isEmpty(List* list);								// ���� ���� ����
int isFull(List* list);									// ��ȭ ���� ����
void insertMusic(List* list, int mode);					// �� �߰�
void insertMusicSub(List* list, ListNode* node);		// ����Ʈ�� ��� �߰�
void insertMusicFirstSub(List* list, ListNode* node);	// ����Ʈ�� ó���� ��� �߰�
void deleteMusic(List* list);							// �� ����
void deleteMusicSub(List* list, ListNode* node);		// ����Ʈ���� ��� ����
void movePrev(List* list);								// �� ������ �̵�
void moveNext(List* list);								// �� ������ �̵�

// ���� ���� ����Ʈ �ʱ�ȭ
void init(List *list) {
	list->first = list->play = NULL;
	list->listSize = 0;
}

// ���Ḯ��Ʈ ���
void printList(List* list) {
	if (isEmpty(list))				// ����Ʈ�� ����ִ� ���
		printf("List is empty!\n");	// �����޼��� ���

	else {	// ����Ʈ�� ������� ���� ���
		printf("=========================================================\n");
		printf("Play : %s,\t%s\n", list->play->singer, list->play->name);	// ���� �� ���� ���
		printf("=========================================================\n");

		int i = 1;					// �ε���
		ListNode* p = list->first;	// p�� �̿��� ����Ʈ ��ü �� ���
		
		do{
			printf("%d : %s,\t%s\n", i++, p->singer, p->name);	// p�� ����Ű�� �� ���� ���
			p = p->next;										// ���� ������ �̵�
		} while (p!= list->first);								// �ٽ� ó������ �ǵ��ƿ��� ������ �ݺ�
		printf("\n\n");
	}
}

// ����Ʈ ���� ����
int isEmpty(List* list) {
	if(list->listSize ==0) return true;
	else return false;
}
// ����Ʈ ��ȭ ����
int isFull(List* list) {
	if (list->listSize * ONE_STORAGE >= MAX_STORAGE) return true;
	else return false;
}

// ���� ���� �Լ�
void insertMusic(List* list, int mode) {
	char singer[50];
	char name[50];
	ListNode* newMusic = (ListNode*)malloc(sizeof(ListNode));	// ��� ���� �Ҵ�
	printf("=========================================================\n");
	printf("Singer : ");
	fgets(singer, sizeof(singer), stdin);	// �ִ� singer ũ�⸸ŭ �Է¹���
	singer[strcspn(singer, "\n")] = '\0';	// �ٹٲ� ���� ����
	newMusic->singer = (char*)malloc((strlen(singer) + 1) * sizeof(char));	// siger ũ�⸸ŭ ���� �̸� ���� �Ҵ�
	strcpy(newMusic->singer, singer);		// siger�� �Էµ� �� node�� ���� �̸����� ����

	printf("Title : ");
	fgets(name, sizeof(name), stdin);	// �ִ� name ũ�⸸ŭ �Է¹���
	name[strcspn(name, "\n")] = '\0';	// �ٹٲ� ���� ����
	newMusic->name = (char*)malloc((strlen(name) + 1) * sizeof(char));	// name ũ�⸸ŭ �뷡 ���� ���� �Ҵ�
	strcpy(newMusic->name, name);		// name�� �Էµ� �� node�� �뷡 �������� ����

	printf("\n");
	if (mode == NORMAL) insertMusicSub(list, newMusic);			// ���� �� ������ �����ϴ� ���
	else if(mode == FIRST) insertMusicFirstSub(list, newMusic);	// ����Ʈ�� �� ó���� �����ϴ� ���

	
}

// ���� �� ������ �����ϴ� ���(���� ���� ���Ḯ��Ʈ�̹Ƿ� ������ ���� ù ��带 �̾���)
void insertMusicSub(List* list, ListNode* node) {
	if (isFull(list)) printf("List is full! Can't insert\n");	// ����Ʈ�� ��ȭ������ ��� �����޼��� ���
	else {
		// ����Ʈ�� ����ִ� ���
		if (isEmpty(list)) {
			list->first = node;		// ù ��° ��: node
			list->play = node;		// ���� ��: node
			node->next = node;		// ���� ��: node
			node->prev = node;		// ���� ��: node
		}

		// ����Ʈ�� �� ���� ���� �ϴ� ���
		else if(list->play->next==list->first) {
			node->next = list->first;		// �������� �����ϹǷ� ���� ���� ù��° ��
			list->first->prev = node;		// ù��° ���� ���� ���� ������ ��
			node->prev = list->play;		// ���� ���� ���� �������� ��
			list->play->next = node;		// ���� ���� ���� ���� ���� node
			list->play = list->play->next;	// ���� ���� ���� node�� ����
		}

		// ����Ʈ�� ��尡 �����ϴ� ���(�� play�� ���� ���� �����ϴ� ���)
		else {
			node->prev = list->play;		// node�� ���� ���� ���� ���� ���� ��	
			node->next = list->play->next;	// node�� ���� ���� ���� ���� ���� ���� ���� ��
			list->play->next->prev = node;	// ���� ���� ���� ���� ���� ���� ���� node
			list->play->next = node;		// ���� ���� ���� ���� ���� ���� node
			list->play = list->play->next;	// ���� ���� ���� ���� node�� ����

		}
		list->listSize++;	// ����Ʈ ũ�� ����
	}
}

// ����Ʈ ó���� ����(���� ���� ���Ḯ��Ʈ�̹Ƿ� ������ ���� ù ��带 �̾���)
void insertMusicFirstSub(List* list, ListNode* node) {
	if (isFull(list)) printf("List is full! Can't insert\n");	// ����Ʈ�� ��ȭ������ ��� �����޼��� ���
	else {
		// ����Ʈ�� ����ִ� ���
		if (isEmpty(list)) {
			list->first = node;		// ù ��° ��: node
			list->play = node;		// ���� ��: node
			node->next = node;		// ���� ��: node
			node->prev = node;		// ���� ��: node
		}

		// ����Ʈ�� ó���� �����ϴ� ���
		else {
			node->prev = list->first->prev;	// node�� ���� ��: ���� ù ��° ���� ���� ��
			node->next = list->first;		// node�� ���� ��: ���� ù ��° ��
			list->first->prev->next = node;	// ������ ����� ���� ��: node
			list->first->prev = node;		// ���� ù ��° ���� ���� ��: node
			list->first = node;				// ù ��° ��: node
			
		}
		list->listSize++;	// ����Ʈ ũ�� ����
	}
}

// ���� ���� ���� �� ����
void deleteMusic(List* list) {
	if (isEmpty(list)) printf("List is empty! Can't delete\n");	// ����Ʈ�� ������ ��� �����޼��� ���
	else {
		ListNode* removed = NULL;		// ������ ��带 ���� ����
		deleteMusicSub(list, removed);	// ���� �Լ� ȣ��
	}
}

// ����Ʈ�� ��� ����
void deleteMusicSub(List* list, ListNode* node) {
	
	// ����Ʈ�� ������ �ϳ� �ۿ� ���� ���
	if(list->listSize==1){
		node = list->play;
		list->first = NULL;
		list->play = NULL;
	}
	// �����Ϸ��� ������ ù ����� ���
	else if (list->play == list->first) {
		node = list->play;							// ������ ��� = ���� ����
		node->next->prev = node->prev;				// ���� ���� ���� ���� ���� ���� ���� ������ ����
		node->prev->next = node->next;				// ���� ���� ���� ���� ���� ���� ���� ������ ����
		list->first->next->prev = list->first->prev;	// ����Ʈ�� �� ��° ���� ���� ���� ������ ������ ����(list->first->prev)
		list->first->prev->next = list->first->next;	// ������ ���� ���� ���� ����Ʈ�� �� ��° ������ ����(list->first->next)
		list->first = list->first->next;			// ����Ʈ�� ù ��° ���� �� ��° ������ ����
		list->play = list->play->next;				// ���� ���� ���� ������ ����
	
	}

	// �� ���� ���
	else {
		node = list->play;				// ������ ��� = ���� ��
		node->next->prev = node->prev;	// ���� ���� ���� ���� ���� ���� ���� ������ ����
		node->prev->next = node->next;	// ���� ���� ���� ���� ���� ���� ���� ������ ����
		list->play = list->play->next;	// ���� ���� ���� ������ ����
		
	}
	printf("Deleted song is %s's %s\n", node->singer, node->name);
	free(node);		// ���� �� ����
	list->listSize--;	// ����Ʈ ũ�� ����
	
}

// ���� �� ���
void movePrev(List* list) {
	if (isEmpty(list)) printf("List is empty! Can't play\n");	// ����Ʈ�� ����ִ� ��� �����޼��� ���

	// ���� ���� ����Ʈ�� ù ��° ���� ���
	else if (list->play == list->first) {
		printf("The course is in the first item! Can't move.\n\n");	// ���� ������ �̵��� �� ���ٴ� �޼��� ���
	}

	// �� ���� ���
	else {
		list->play = list->play->prev;	// ���� ���� ���� ������ ����
	}
}

// ���� �� ���
void moveNext(List* list) {
	if (isEmpty(list)) printf("List is empty! Can't play\n");	// ����Ʈ�� ����ִ� ��� �����޼��� ���

	// ���� ���� ����Ʈ�� ������ ���� ���
	else if (list->play->next == list->first) {	
		printf("The course is in the last item! Can't move.\n\n");	// ���� ������ �̵��� �� ���ٴ� �޼��� ���
	}
	
	// �� ���� ���
	else {
		list->play = list->play->next;	// ���� ���� ���� ������ ����
	}
}


// �޴� ��� �Լ�
void print_menu() {
	printf("********** �޴� **********\n");
	printf("+: MP3 ����� ������ �߰�\n");
	printf("S: MP3 ����Ʈ ���� �տ� �߰�\n");
	printf("-: ����� ����\n");
	printf("P: ������ ���\n");
	printf("N: ������ ���\n");
	printf("F: �뷮 �ʰ� üũ\n");
	printf("E: ����ִ��� üũ\n");
	printf("Q: ����\n");
	printf("***************************\n");
	
}

int main() {
	List* list;
	char cmd;
	list = (List*)malloc(sizeof(List));
	init(list);

	do{
		print_menu();	// �޴� ���
		printList(list);
		printf("Command: ");
		cmd = getchar();
		getchar();

		cmd = toupper(cmd);
		putchar(cmd);
		printf("\n");
		
		switch (cmd){
		case '+':
			insertMusic(list, NORMAL);
			break;
		case 'S':
			insertMusic(list, FIRST);
			break;
		case '-':
			deleteMusic(list);
			break;
		case 'P':
			movePrev(list);
			break;
		case 'N':
			moveNext(list);
			break;
		case 'F':
			if(isFull(list)) printf("List is full!\n\n");
			else printf("List isn't full\n\n");
			break;
		case 'E':
			if (isEmpty(list)) printf("List is empty!\n\n");
			else printf("List isn't empty\n\n");
			break;
		default:
			printf("\nWrong command! Retry!\n\n");
		}
	}while (cmd!='Q');

	return 0;
}