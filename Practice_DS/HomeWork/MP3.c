/*
아이팟 플레이리스트 구현
- 원형 이중 연결 리스트를 이용하여 구현
- 아이팟 플레이어의 최대 용량 128MB
- 한 곡의 용량 4MB
- MP3는 제목과 가수를 입력 받음
- MP3 추가는 기본모드는 현재 플레이되는 곡의 다음 위치에 곡을 추가
- 추가적으로 플레이리스트의 가장 앞에 추가하는 기능 제공
- isFull(): 리스트 안에 저장된 MP3 음악파일의 크기를 계산해 최대 크기를 초과했는지 체크
- 삭제는 현재 플레이 중인 곡을 삭제
- 이전곡/ 다음곡 이동 기능 제공
- 플레이리스트 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_STORAGE 128
#define ONE_STORAGE 4

// 리스트 입력모드 FLAG
#define NORMAL 0
#define FIRST 1


typedef struct ListNode {
	char* name;		// 제목
	char* singer;	// 가수
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;	// 이중연결리스트 노드 ADT

typedef struct List {
	int listSize;		// 리스트 크기
	ListNode* play;		// 현재 재생중인 곡
	ListNode* first;	// 리스트의 첫 번째 곡
}List;


void init(List* list);									// 리스트 초기화
void printList(List* list);								// 리스트 출력
int isEmpty(List* list);								// 공백 상태 검출
int isFull(List* list);									// 포화 상태 검출
void insertMusic(List* list, int mode);					// 곡 추가
void insertMusicSub(List* list, ListNode* node);		// 리스트에 노드 추가
void insertMusicFirstSub(List* list, ListNode* node);	// 리스트의 처음에 노드 추가
void deleteMusic(List* list);							// 곡 삭제
void deleteMusicSub(List* list, ListNode* node);		// 리스트에서 노드 삭제
void movePrev(List* list);								// 앞 곡으로 이동
void moveNext(List* list);								// 뒷 곡으로 이동

// 이중 연결 리스트 초기화
void init(List *list) {
	list->first = list->play = NULL;
	list->listSize = 0;
}

// 연결리스트 출력
void printList(List* list) {
	if (isEmpty(list))				// 리스트가 비어있는 경우
		printf("List is empty!\n");	// 에러메세지 출력

	else {	// 리스트가 비어있지 않은 경우
		printf("=========================================================\n");
		printf("Play : %s,\t%s\n", list->play->singer, list->play->name);	// 현재 곡 정보 출력
		printf("=========================================================\n");

		int i = 1;					// 인덱스
		ListNode* p = list->first;	// p를 이용해 리스트 전체 곡 출력
		
		do{
			printf("%d : %s,\t%s\n", i++, p->singer, p->name);	// p가 가리키는 곡 정보 출력
			p = p->next;										// 다음 곡으로 이동
		} while (p!= list->first);								// 다시 처음으로 되돌아오기 전까지 반복
		printf("\n\n");
	}
}

// 리스트 공백 검출
int isEmpty(List* list) {
	if(list->listSize ==0) return true;
	else return false;
}
// 리스트 포화 검출
int isFull(List* list) {
	if (list->listSize * ONE_STORAGE >= MAX_STORAGE) return true;
	else return false;
}

// 음악 삽입 함수
void insertMusic(List* list, int mode) {
	char singer[50];
	char name[50];
	ListNode* newMusic = (ListNode*)malloc(sizeof(ListNode));	// 노드 동적 할당
	printf("=========================================================\n");
	printf("Singer : ");
	fgets(singer, sizeof(singer), stdin);	// 최대 singer 크기만큼 입력받음
	singer[strcspn(singer, "\n")] = '\0';	// 줄바꿈 문자 제거
	newMusic->singer = (char*)malloc((strlen(singer) + 1) * sizeof(char));	// siger 크기만큼 가수 이름 동적 할당
	strcpy(newMusic->singer, singer);		// siger에 입력된 값 node의 가수 이름으로 복사

	printf("Title : ");
	fgets(name, sizeof(name), stdin);	// 최대 name 크기만큼 입력받음
	name[strcspn(name, "\n")] = '\0';	// 줄바꿈 문자 제거
	newMusic->name = (char*)malloc((strlen(name) + 1) * sizeof(char));	// name 크기만큼 노래 제목 동적 할당
	strcpy(newMusic->name, name);		// name에 입력된 값 node의 노래 제목으로 복사

	printf("\n");
	if (mode == NORMAL) insertMusicSub(list, newMusic);			// 현재 곡 다음에 삽입하는 경우
	else if(mode == FIRST) insertMusicFirstSub(list, newMusic);	// 리스트의 맨 처음에 삽입하는 경우

	
}

// 현재 곡 다음에 삽입하는 경우(원형 이중 연결리스트이므로 마지막 노드와 첫 노드를 이어줌)
void insertMusicSub(List* list, ListNode* node) {
	if (isFull(list)) printf("List is full! Can't insert\n");	// 리스트가 포화상태인 경우 에러메세지 출력
	else {
		// 리스트가 비어있는 경우
		if (isEmpty(list)) {
			list->first = node;		// 첫 번째 곡: node
			list->play = node;		// 현재 곡: node
			node->next = node;		// 다음 곡: node
			node->prev = node;		// 이전 곡: node
		}

		// 리스트의 맨 끝에 삽입 하는 경우
		else if(list->play->next==list->first) {
			node->next = list->first;		// 마지막에 삽입하므로 다음 곡은 첫번째 곡
			list->first->prev = node;		// 첫번째 곡의 이전 곡은 마지막 곡
			node->prev = list->play;		// 이전 곡은 현재 실행중인 곡
			list->play->next = node;		// 현재 실행 곡의 다음 곡은 node
			list->play = list->play->next;	// 현재 실행 곡을 node로 지정
		}

		// 리스트에 노드가 존재하는 경우(즉 play의 다음 곡이 존재하는 경우)
		else {
			node->prev = list->play;		// node의 이전 곡은 현재 실행 중인 곡	
			node->next = list->play->next;	// node의 다음 곡은 현재 실행 중인 곡의 다음 곡
			list->play->next->prev = node;	// 현재 실행 중인 다음 곡의 이전 곡은 node
			list->play->next = node;		// 현재 실행 중인 곡의 다음 곡은 node
			list->play = list->play->next;	// 현재 실행 중인 곡을 node로 변경

		}
		list->listSize++;	// 리스트 크기 증가
	}
}

// 리스트 처음에 삽입(원형 이중 연결리스트이므로 마지막 노드와 첫 노드를 이어줌)
void insertMusicFirstSub(List* list, ListNode* node) {
	if (isFull(list)) printf("List is full! Can't insert\n");	// 리스트가 포화상태인 경우 에러메세지 출력
	else {
		// 리스트가 비어있는 경우
		if (isEmpty(list)) {
			list->first = node;		// 첫 번째 곡: node
			list->play = node;		// 현재 곡: node
			node->next = node;		// 다음 곡: node
			node->prev = node;		// 이전 곡: node
		}

		// 리스트의 처음에 삽입하는 경우
		else {
			node->prev = list->first->prev;	// node의 이전 곡: 현재 첫 번째 곡의 이전 곡
			node->next = list->first;		// node의 다음 곡: 현재 첫 번째 곡
			list->first->prev->next = node;	// 마지막 노드의 다음 곡: node
			list->first->prev = node;		// 현재 첫 번째 곡의 이전 곡: node
			list->first = node;				// 첫 번째 곡: node
			
		}
		list->listSize++;	// 리스트 크기 증가
	}
}

// 현재 실행 중인 곡 삭제
void deleteMusic(List* list) {
	if (isEmpty(list)) printf("List is empty! Can't delete\n");	// 리스트가 공백인 경우 에러메세지 출력
	else {
		ListNode* removed = NULL;		// 삭제할 노드를 담을 변수
		deleteMusicSub(list, removed);	// 삭제 함수 호출
	}
}

// 리스트의 노드 삭제
void deleteMusicSub(List* list, ListNode* node) {
	
	// 리스트에 음악이 하나 밖에 없는 경우
	if(list->listSize==1){
		node = list->play;
		list->first = NULL;
		list->play = NULL;
	}
	// 삭제하려는 음악이 첫 노드인 경우
	else if (list->play == list->first) {
		node = list->play;							// 삭제될 노드 = 현재 음악
		node->next->prev = node->prev;				// 다음 곡의 이전 곡을 현재 곡의 이전 곡으로 변경
		node->prev->next = node->next;				// 이전 곡의 다음 곡을 현재 곡의 다음 곡으로 변경
		list->first->next->prev = list->first->prev;	// 리스트의 두 번째 곡의 이전 곡을 마지막 곡으로 변경(list->first->prev)
		list->first->prev->next = list->first->next;	// 마지막 곡의 다음 곡을 리스트의 두 번째 곡으로 변경(list->first->next)
		list->first = list->first->next;			// 리스트의 첫 번째 곡을 두 번째 곡으로 변경
		list->play = list->play->next;				// 현재 곡을 다음 곡으로 변경
	
	}

	// 그 외의 경우
	else {
		node = list->play;				// 삭제될 노드 = 현재 곡
		node->next->prev = node->prev;	// 다음 곡의 이전 곡을 현재 곡의 이전 곡으로 변경
		node->prev->next = node->next;	// 이전 곡의 다음 곡을 현재 곡의 다음 곡으로 변경
		list->play = list->play->next;	// 현재 곡을 다음 곡으로 변경
		
	}
	printf("Deleted song is %s's %s\n", node->singer, node->name);
	free(node);		// 현재 곡 삭제
	list->listSize--;	// 리스트 크기 감소
	
}

// 이전 곡 재생
void movePrev(List* list) {
	if (isEmpty(list)) printf("List is empty! Can't play\n");	// 리스트가 비어있는 경우 에러메세지 출력

	// 현재 곡이 리스트의 첫 번째 곡인 경우
	else if (list->play == list->first) {
		printf("The course is in the first item! Can't move.\n\n");	// 이전 곡으로 이동할 수 없다는 메세지 출력
	}

	// 그 외인 경우
	else {
		list->play = list->play->prev;	// 현재 곡을 이전 곡으로 변경
	}
}

// 다음 곡 재생
void moveNext(List* list) {
	if (isEmpty(list)) printf("List is empty! Can't play\n");	// 리스트가 비어있는 경우 에러메세지 출력

	// 현재 곡이 리스트의 마지막 곡인 경우
	else if (list->play->next == list->first) {	
		printf("The course is in the last item! Can't move.\n\n");	// 다음 곡으로 이동할 수 없다는 메세지 출력
	}
	
	// 그 외인 경우
	else {
		list->play = list->play->next;	// 현재 곡을 다음 곡으로 변경
	}
}


// 메뉴 출력 함수
void print_menu() {
	printf("********** 메뉴 **********\n");
	printf("+: MP3 현재곡 다음에 추가\n");
	printf("S: MP3 리스트 제일 앞에 추가\n");
	printf("-: 현재곡 삭제\n");
	printf("P: 이전곡 재생\n");
	printf("N: 다음곡 재생\n");
	printf("F: 용량 초과 체크\n");
	printf("E: 비어있는지 체크\n");
	printf("Q: 종료\n");
	printf("***************************\n");
	
}

int main() {
	List* list;
	char cmd;
	list = (List*)malloc(sizeof(List));
	init(list);

	do{
		print_menu();	// 메뉴 출력
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