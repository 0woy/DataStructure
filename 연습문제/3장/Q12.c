/*
문제 설명: 1개의 정수와 최대 크기가 20인 문자열로 이루어진 구조체를 저장할 수 있도록
동적메모리를 할당 받고, 여기에 정수 100과 문자열 "just testing"을 저장한다음
동적 메모리를 반납하는 프로그램 작성

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 1개의 정수와 최대 크기가 20인 문자열을 갖는 구조체 선언
typedef struct {
	int n;
	char str[20];
}test;

int main() {

	test *temp;						//해당 구조체를 변수로 갖는 temp 포인터 변수
	temp = malloc(sizeof(test));	// test 구조체의 크기 만큼 동적 메모리 할당

	if (!temp) {					// 메모리 할당을 할 수 없는 경우
		printf("동적 할당 실패");	// 에러 메세지 출력
		return;						// 프로그램 종료
	}

	temp->n = 100;	// 정수에 100 저장
	strcpy(temp->str, "just testing");	// 문자열에 just testing 저장
	printf("temp의 정수: %d\ntemp의 문자열: %s", temp->n, temp->str);	// test 출력

	free(temp);	// 할당된 동적 메모리 반납
	
	return 0;	// 프로그램 종료
}