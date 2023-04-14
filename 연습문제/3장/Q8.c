/*
문제 설명: 크기가 n인 배열 array 에서 임의의 위치 loc에 정수 value를 삽입하는 함수 insert()를 작성
정수가 삽입되면 그 뒤에있는 정수들은 한 칸씩 뒤로 밀려야 한다.
현재 배열에 들어있는 원소의 개수는 items개라고 하자(여기서 items<<n라고 가정)

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int items = 0;	// 원소의 개수
int n;			//배열의 크기
void insert(int array[], int loc, int value) {
	for (int i = loc; i < n; i++) {
		array[i + 1] = array[i];
	}
	array[loc] = value;
	items++;
}