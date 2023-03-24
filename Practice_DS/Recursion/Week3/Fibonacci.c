/*
이름: 박윤아
학번: 20204624

프로그램 설명: 입력 받은 n의 피보나치의 수열 출력
if) 5입력시 0,1,1,2,3,
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

// 재귀 버전
int Fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	else return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

// 반복 버전
int Iter_Fibonacci(int n) {
	int pp = 0;
	int p = 1;
	int res = 0;
	for (int i = 2; i <= n; i++) {
		res = pp + p;
		pp = p;
		p = res;
	}
	return res;
}

int main() {
	clock_t start, end;
	int n;
	printf("n 입력 >> ");
	scanf("%d", &n);

	start = clock();
	int res = Iter_Fibonacci(n);
	end = clock();
	printf("[time: %f]\n", (float)(end - start) / CLOCKS_PER_SEC);

	printf("결과: %d", res);

	return 0;
}