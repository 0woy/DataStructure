/*
�ۼ���: 2023.03.10.
�й�: 20204624
�̸�: ������

���α׷� ����: Data.txt ���Ͽ� ���� ���� 15���� �迭�� ���� ��
����ڿ��� ���ڸ� �Է� �޾� �ش� ���ڰ� �迭�� �� �� �������� �˻��Ͽ� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	FILE *fp;			// ������ �о���� ���� ����
	int arr[15];		// 15���� ���ڸ� ���� �迭 ����
	int num, i, count;	// num: ����� �Է� /  i: �迭 index / count: ã�� ���� ����
	i = count = 0;		// index�� count 0���� �ʱ�ȭ

	fp = fopen("Search_num.txt", "r"); // 15���� ���ڰ� ��� ���� �о����

	if (!fp) {							// ������ �о�� �� ���ٸ�
		printf("CAN NOT OPEN FILE");	// �����޼��� ���
		return;							// ���α׷� ����
	}

	while (!feof(fp)) {					// ���� ������ �ݺ�
		fscanf(fp, "%d", &arr[i++]);	// ���ڸ� �о�� �迭�� ����
	}

	printf("ã���� ���ڸ� �Է��ϼ���: ");
	scanf("%d", &num);	// ����ڿ��� ���� �Է� ����

	for (int i = 0; i < 15; i++) {	// �迭 ��ü ��ȸ
		if (num == arr[i])			// ����ڰ� �Է��� ���ڰ� �迭�� �����ϸ�
			count++;				// count 1����
		else continue;				// �������� �ʴ´ٸ� �������� �ݺ�
	}

	if (count > 0)	// ���ڰ� �����ϴ� ���
		printf("�Է��� %d�� %d�� �ֽ��ϴ�.\n", num, count);

	else			// ���ڰ� �������� �ʴ� ���
		printf("�Է��� %d�� �����ϴ�.\n", num);

	return 0;	// ���α׷� ����
}