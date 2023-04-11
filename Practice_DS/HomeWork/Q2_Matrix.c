/*
�̸�: ������
�й�: 20204624

���α׷� ����: �� ���� ��� �����͸� data02.txt ���Ͽ��� �Է� �޾�,
�� ����� +,-,*  ������ �����ϴ� ���α׷� �ۼ�
��, ���� �Ҵ����� 2���� �迭�� �����Ͽ� �ۼ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �������� �Ҵ�� �޸𸮸� �����ϴ� �Լ�
void FreeAllocate(int **matrix, int row) {
	for (int i = 0; i < row; i++)
		free(matrix[i]);
	free(matrix);
}

// flag ���� ���� �� ����� ������ �����ϴ� �Լ�
int** Calc(int **a, int **b, int arow, int acol,int brow, int bcol, int flag) {
	int **res; // ���� ����� ��ȯ�� 2���� �迭
	if (flag != 2) {	//����� ���� || ������ �����ϴ� ���
		res = (int**)malloc(sizeof(int*)*arow);
		for (int i = 0; i < arow; i++)
			res[i] = (int*)malloc(sizeof(int)*acol);
	}

	else {	// ����� ���� �����ϴ� ���
		res = (int**)malloc(sizeof(int*)*arow);
		for (int i = 0; i < bcol; i++)
			res[i] = (int*)malloc(sizeof(int)*bcol);
	}

	// 0: ����� ��, 1: ����� ��, 2: ����� ��
	switch (flag) {
	case 0:
		for (int i = 0; i < arow; i++) 
			for (int j = 0; j < acol; j++) 
				res[i][j] = a[i][j] + b[i][j];		// �� ��/���� ���� res�� ����
		break;

	case 1:
		for (int i = 0; i < arow; i++)
			for (int j = 0; j < acol; j++)
				res[i][j] = a[i][j] - b[i][j];		// �� ��/���� ���� res�� ����
		break;

	case 2:
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < acol; j++) {
				res[i][j] = 0;						// ������ �����ϱ� ���� 0���� �ʱ�ȭ
				for (int k = 0; k < bcol; k++)
					res[i][j] += a[i][k] * b[k][j];	// ����� ���� res�� ����
			}
		}
		break;
	}
	return res;
}

// ��� ���� ����ϴ� �Լ�
void Print_matrix(int **matrix, int row, int col){
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("[%2d] ", matrix[i][j]);
		printf("\n");
	}
}
int main() {

	printf("�̸�: ������\n�й�: 20204624\n\n");

	FILE *fp;						// ������ �о���� ���� ���� ������
	int **a, **b;					// �� ����� �����ϱ� ���� 2���� �迭
	int arow, acol, brow, bcol;		// �� ����� ��,�� ũ�⸦ �����ϴ� ����
	fp = fopen("data02.txt", "r");	// data02.txt ������ �о�� fp�� ����

	if (!fp) {									// ������ �о���� ���� ���
		fprintf(stderr, "CAN NOT OPEN FILE");	// ���� �޼��� ���
		return;									// ���α׷� ����
	}
	
	// ù ��° ��� ���� �Ҵ�
	fscanf(fp, "%d %d", &arow, &acol);			// ����� ũ�� �о����
	a = (int**)malloc(sizeof(int*)*arow);		// ���� ũ�⿡ ���� �����Ҵ�	
	for (int i = 0; i < arow; i++)			
		a[i] = (int*)malloc(sizeof(int)*acol);	// ���� ũ�⿡ ���� �����Ҵ�

	// ù ��° ��� ������ �о����
	for (int i = 0; i < arow; i++) {
		for (int j = 0; j < acol; j++) {
			fscanf(fp, "%d", &a[i][j]);			// 2���� �迭 A�� ��� ������ ����
		}
	}
	
	char buffer[256];		//���� ���� �ǳʶٱ� ���� ����
	fgets(buffer, 256, fp);	//�� �� �ǳ� �ٱ�

	// �� ��° ��� ���� �Ҵ�
	fscanf(fp, "%d %d", &brow, &bcol);			// ����� ũ�� �о����
	b= (int**)malloc(sizeof(int*)*brow);		// ���� ũ�⿡ ���� �����Ҵ�	
	for (int i = 0; i < arow; i++)
		b[i] = (int*)malloc(sizeof(int)*bcol);	// ���� ũ�⿡ ���� �����Ҵ�

	// �� ��° ��� ������ �о����
	for (int i = 0; i < brow; i++) {
		for (int j = 0; j < bcol; j++) {
			fscanf(fp, "%d", &b[i][j]);			// 2���� �迭 B�� ��� ������ ����
		}
	}

	// ����� ����, ����, ���� ���
	for (int i = 0; i < 3; i++) {
		switch (i)
		{
		case 0: printf("======= A+B =======\n");
			break;
		case 1:	printf("======= A-B =======\n");
			break;
		case 2: printf("======= AXB =======\n");
			break; 
		}
		
		int ** res =Calc(a, b, arow, acol, brow, bcol, i);	// ��, ��, ���� ���ʷ� �޾ƿ�
		Print_matrix(res, arow, bcol);	// ��� ���
		FreeAllocate(res, arow);		// ���� �޸� ��ȯ
		printf("\n\n");	
	}

	FreeAllocate(a, arow);	// ���� �޸� ��ȯ
	FreeAllocate(b, brow);	// ���� �޸� ��ȯ
	fclose(fp);				// ���� ������ ��ȯ

	return 0;
}