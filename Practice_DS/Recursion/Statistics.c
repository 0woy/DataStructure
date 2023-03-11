/*

�̸�: ������
�й�: 20204624
�ۼ���: 2023.03.11.

���α׷� ����
2000�� ���� 2007����� ���� ������ �����Ͱ� Statistics.txt ���Ͽ� ����� �ִ�.
2���� �迭�� ���� �����͸� �о 8�Ⱓ ���� ��հ��� ������ �հ� ���ϱ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	printf("�й�: 20204624\n�̸�: ������\n\n");

	FILE *fp;
	int stat[8][12];
	int i = 0, j = 0;
	int year = 2000;
	fp = fopen("Statistics.txt", "r");
	if (!fp) {
		printf("CAN NOT OPEN FILE");
		return;
	}

	while (!feof(fp)) {
		fscanf(fp, "%d", &stat[i][j++]);
		if (j == 12) { i++; j = 0; }
	}
	printf("|===============================================================================================================|\n");
	printf("| �⵵ \t 1��\t2�� \t3��\t4��\t5��\t6��\t7��\t8��\t9��\t10��\t11��\t12��\t�⺰����|\n");
	for (int i = 0; i < 8; i++) {
		int total = 0;
		printf("|%4d��|", year++);
		for (int j = 0; j < 12; j++) {
			printf("%3d \t", stat[i][j]);
			total += stat[i][j];
		}
		printf("%8d|\n", total);
	}
	printf("|===============================================================================================================|\n");
	printf("|����\t");
	for (int i = 0; i < 12; i++) {
		float total = 0;
		for (int j = 0; j < 8; j++) {
			total += stat[j][i];
		}
		printf("%3.0f\t", total / 8);
	}
	printf("|\n|=======================================================================================================|\n");


	return 0;
}