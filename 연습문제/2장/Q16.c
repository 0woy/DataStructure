/*
이름: 박윤아
학번: 20204624

프로그램 설명: 주어진 순환적인 프로그램을 반복 구조를 사용한 비순환적 프로그램으로 작성
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 문제에 제시된 코드
int sum(float n) {
	if(n == 1) return 1;
	else return(n + sum(n - 1));
}

// 반복 구조로 변환한 코드
int iter_sum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++)	//1부터 n까지 반복
		sum += i;					// 1부터 n까지의 합 저장
	return sum;						// 결과 값 반환
}
int main() {
	printf("이름: 박윤아\n학번:20204624\n\n");

	printf("n값 입력: ");
	int n;
	scanf("%d", &n);

	int r_res = sum(n);					// sum(n)의 반환값
	int iter_res = iter_sum(n);			// iter_sum(n)의 반환값

	printf("순환 프로그램의 반환 값: %d\n", r_res);	// 순환 구조 반환값 출력
	printf("반복 프로그램의 반환 값: %d\n", iter_res);	// 반복 구조 반환값 출력
	return 0;
}