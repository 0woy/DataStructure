/*
�й�: 20204624
�̸�: ������

���α׷� ����: data01.txt ���Ͽ� ����� x,y ���� �迭�� ����,
�� ���� ������ �Ÿ��� �Ҽ��� 5�ڸ����� ��� �� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {

	printf("�̸�: ������\n�й�: 20204624\n\n");
	FILE *fp;						// ������ �о���� ���� ���� ������
	fp = fopen("data01.txt", "r");	// data01.txt ���� �о�� fp�� ����

	int x,y,count = 0;
	int i = 0;
	int *xArr, *yArr;
	
	if (!fp) {									// ������ �о���� ���� ���
		fprintf(stderr, "CAN NOT OPEN FILE");	//���� �޼��� ���
		return;									// ���α׷� ����
	}

	while (!feof(fp)) {					// ������ ������ �ݺ�
		fscanf(fp, "%d %d", &x, &y);	// x, y���� �о�� x,y������ ����
		count++;						// ������ �� ����
	}
	rewind(fp);	// ������ ó������ �̵�

	xArr = (int*)malloc(sizeof(int)*count); // ������ �� ��ŭ �迭 ũ�� ���� �Ҵ�
	yArr = (int*)malloc(sizeof(int)*count);	// ������ �� ��ŭ �迭 ũ�� ���� �Ҵ�
	
	while (!feof(fp)) {							// ������ ������ �ݺ�
		fscanf(fp, "%d %d", &xArr[i],&yArr[i]);	//x,y ���� xArr, yArr�� ����
		i++;									// �迭 �ε��� ����
	}

	int tmp = 1;	// �ٹ�ȣ�� �ű�� ���� ����
	for (i = 0; i < count-1; i++) {	
		for (int j = i+1; j < count; j++) {
																				// �� �������� �Ÿ� ���ϴ� ����: (x2-x1)^2 + (y2-y1)^2
			int res = pow((xArr[i] - xArr[j]),2) + pow((yArr[i] - yArr[j]),2);	// ������ ��ȯ�ϴ� pow�Լ��� �̿��� res�� ����
			printf("%d. (%d, %d)�� (%d, %d)�� ������ �Ÿ��� %.5f �Դϴ�.\n",
				tmp++, xArr[i], yArr[i], xArr[j], yArr[j], sqrt(res));			// sqrt(res)�� ���� res�� ������, �� �� �� ���� �Ÿ� ���
		}
	}

	free(xArr);	// ���� �޸� ��ȯ
	free(yArr);	// ���� �޸� ��ȯ
	fclose(fp);	// ���� ������ ��ȯ

	return 0;

}