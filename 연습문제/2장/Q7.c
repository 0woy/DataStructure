/*
�̸�: ������
�й�: 20204624

���α׷� ����: ���� �ڵ带 sum(5)�� ȣ���Ͽ��� ��, ȭ�鿡 ��� �Ǵ� ����� �Լ��� ��ȯ��
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// ������ ���õ� �ڵ�
int sum(int n) {
	printf("%d\n", n);				// �Ű����� n ���
	if (n == 1) return 1;			// n�� 1�̸��� ��� 1 ��ȯ
	else return(n + sum(n - 1));	// �� ���� ��� n + (n-1) ���� �Ű������� ���ȣ��
}
int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");

	int res = sum(5);					// SUM(5)�� ��ȯ��
	printf("�Լ��� ��ȯ ��: %d", res);	// ��ȯ�� ���
	return 0;
}