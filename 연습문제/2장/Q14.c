/*
�̸�: ������
�й�: 20204624

���α׷� ����: 1 + 1/2 + 1/3 + ... + 1/n�� ����ϴ�
��ȯ���� ���α׷� �ۼ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// ������ ���õ� �ڵ�
float sum(float n) {
	printf("%f\n", 1/n);			// �Ű����� 1/n ���
	
	if (n <= 1) return 1;			// n�� 1�̸��� ��� 1 ��ȯ
	else return(1/n + sum(n - 1));	// �� ���� ��� 1/n + (n-1) ���� �Ű������� ���ȣ��
}
int main() {
	printf("�̸�: ������\n�й�:20204624\n\n");

	printf("n�� �Է�: ");
	float n;
	scanf("%f", &n);

	float res = sum(n);					// sum(n)�� ��ȯ��
	printf("�Լ��� ��ȯ ��: %f", res);	// ��ȯ�� ���
	return 0;
}