/*
문제 설명: 크기가 n인 배열 array에서 임의의 위치 loc에 있는 정수를 삭제하는 delete()함수 작성
정수가 삭제되면 그 뒤에 있는 정수들은 한 칸 씩 앞으로 이동

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int items = 0;	// 원소의 개수
int n;			//배열의 크기

int delete(int array[], int loc) {
	int res = array[loc];	// loc위치에 있는 값 res에 저장
	for (int i = loc; i < n; i++) {		// loc부터 끝까지
		array[i] = array[i+1];			// 앞으로 한 칸씩 이동
	}
	
	return res;	//res 값 반환
}