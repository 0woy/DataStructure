/*
�̸�: ������
�й�: 20204624

���α׷� ����: �Է¹��� n�� n! ���
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
	printf("n �Է� >> ");
	scanf("%d", &n);

	int result = factorial(n);
	printf("%d!�� %d",n, result);
	

	return 0;
}