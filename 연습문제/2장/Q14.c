/*
이름: 박윤아
학번: 20204624

프로그램 설명: 1 + 1/2 + 1/3 + ... + 1/n을 계산하는
순환적인 프로그램 작성
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 문제에 제시된 코드
float sum(float n) {
	printf("%f\n", 1/n);			// 매개변수 1/n 출력
	
	if (n <= 1) return 1;			// n이 1미만인 경우 1 반환
	else return(1/n + sum(n - 1));	// 그 외의 경우 1/n + (n-1) 값을 매개변수로 재귀호출
}
int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");

	printf("n값 입력: ");
	float n;
	scanf("%f", &n);

	float res = sum(n);					// sum(n)의 반환값
	printf("함수의 반환 값: %f", res);	// 반환값 출력
	return 0;
}