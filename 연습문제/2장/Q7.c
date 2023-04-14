/*
이름: 박윤아
학번: 20204624

프로그램 설명: 다음 코드를 sum(5)로 호출하였을 때, 화면에 출력 되는 내용과 함수의 반환값
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 문제에 제시된 코드
int sum(int n) {
	printf("%d\n", n);				// 매개변수 n 출력
	if (n == 1) return 1;			// n이 1미만인 경우 1 반환
	else return(n + sum(n - 1));	// 그 외의 경우 n + (n-1) 값을 매개변수로 재귀호출
}
int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");

	int res = sum(5);					// SUM(5)의 반환값
	printf("함수의 반환 값: %d", res);	// 반환값 출력
	return 0;
}