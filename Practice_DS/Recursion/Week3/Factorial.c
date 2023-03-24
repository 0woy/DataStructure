/*
이름: 박윤아
학번: 20204624

프로그램 설명: 입력받은 n의 n! 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int factorial(int n) {
	if (n == 1) return 1;
	else return  n*factorial(n - 1);
}


int main() {

	int n;
	printf("n 입력 >> ");
	scanf("%d", &n);

	int result = factorial(n);
	printf("%d!은 %d",n, result);
	

	return 0;
}