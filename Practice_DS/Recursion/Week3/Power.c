/*
이름: 박윤아
학번: 20204624

프로그램 설명: 입력 받은 x의 n승 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int power(int x, int n) {
	if (n == 0) return 1;
	else if(n%2==0)return power(x*x, n/2);
	else return x*power(x*x, (n-1) / 2);
}


int main() {

	int x,n;
	printf("밑 입력 >> ");
	scanf("%d", &x);

	printf("지수 입력 >> ");
	scanf("%d", &n);

	int res = power(x, n);
	printf("%d의 %d 승은 %d", x, n, res);

	return 0;
}