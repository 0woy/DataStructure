/*
�̸�: ������
�й�: 20204624

���α׷� ����: �Է� ���� x�� n�� ���
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
	printf("�� �Է� >> ");
	scanf("%d", &x);

	printf("���� �Է� >> ");
	scanf("%d", &n);

	int res = power(x, n);
	printf("%d�� %d ���� %d", x, n, res);

	return 0;
}