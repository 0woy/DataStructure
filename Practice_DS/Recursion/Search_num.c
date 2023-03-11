/*
작성일: 2023.03.10.
학번: 20204624
이름: 박윤아

프로그램 설명: Data.txt 파일에 랜덤 숫자 15개를 배열로 읽은 후
사용자에게 숫자를 입력 받아 해당 숫자가 배열에 몇 번 나오는지 검색하여 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	printf("학번: 20204624\n이름: 박윤아\n\n");
	FILE *fp;			// 파일을 읽어오기 위한 변수
	int arr[15];		// 15개의 숫자를 담을 배열 선언
	int num, i, count;	// num: 사용자 입력 /  i: 배열 index / count: 찾는 숫자 개수
	i = count = 0;		// index와 count 0으로 초기화

	fp = fopen("Search_num.txt", "r"); // 15개의 숫자가 담긴 파일 읽어오기

	if (!fp) {							// 파일을 읽어올 수 없다면
		printf("CAN NOT OPEN FILE");	// 에러메세지 출력
		return;							// 프로그램 종료
	}

	while (!feof(fp)) {					// 파일 끝까지 반복
		fscanf(fp, "%d", &arr[i++]);	// 숫자를 읽어와 배열에 저장
	}

	printf("찾으실 숫자를 입력하세요: ");
	scanf("%d", &num);	// 사용자에게 숫자 입력 받음

	for (int i = 0; i < 15; i++) {	// 배열 전체 순회
		if (num == arr[i])			// 사용자가 입력한 숫자가 배열에 존재하면
			count++;				// count 1증가
		else continue;				// 존재하지 않는다면 다음으로 반복
	}

	if (count > 0)	// 숫자가 존재하는 경우
		printf("입력한 %d는 %d개 있습니다.\n", num, count);

	else			// 숫자가 존재하지 않는 경우
		printf("입력한 %d는 없습니다.\n", num);

	return 0;	// 프로그램 종료
}