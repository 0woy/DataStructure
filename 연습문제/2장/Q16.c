/*
�̸�: ������
�й�: 20204624

���α׷� ����: �־��� ��ȯ���� ���α׷��� �ݺ� ������ ����� ���ȯ�� ���α׷����� �ۼ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// ������ ���õ� �ڵ�
int sum(float n) {
	if(n == 1) return 1;
	else return(n + sum(n - 1));
}

// �ݺ� ������ ��ȯ�� �ڵ�
int iter_sum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++)	//1���� n���� �ݺ�
		sum += i;					// 1���� n������ �� ����
	return sum;						// ��� �� ��ȯ
}
int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");

	printf("n�� �Է�: ");
	int n;
	scanf("%d", &n);

	int r_res = sum(n);					// sum(n)�� ��ȯ��
	int iter_res = iter_sum(n);			// iter_sum(n)�� ��ȯ��

	printf("��ȯ ���α׷��� ��ȯ ��: %d\n", r_res);	// ��ȯ ���� ��ȯ�� ���
	printf("�ݺ� ���α׷��� ��ȯ ��: %d\n", iter_res);	// �ݺ� ���� ��ȯ�� ���
	return 0;
}