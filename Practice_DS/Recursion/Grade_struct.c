/*
�й�: 20204624
�̸�: ������
�ۼ���: 2023.03.10.

���α׷� ����: �л��� �й�, ����, ����, ������ ������ ���Ͽ� ����Ǿ� �ִ�.
�ش� ������ �����͸� �о�鿩 �迭�� �����ϰ�, �л� �� ������ ���, �� ���� ��� ���� ������� ����ϴ�
���α׷��� �ۼ�. 2�� �迭�� �������� �����Ͽ� �����ϰ� ���
*/

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

typedef struct Student {
	int id;
	int kor;
	int eng;
	int math;
	int total;
	float avg;
}Student;

int main() {
	printf("�й�: 20204624\n�̸�: ������\n\n");

	FILE *fp;		// ������ �о���� ���� ����
	int i = 0;		// �迭�� index�� ����� ����
	Student arr[5];

	fp = fopen("Grade.txt", "r");		// �л� ������ ��� ���� �о����
	if (!fp) {							// ������ �о���� ���ߴٸ�
		printf("CAN NOT OPEN FILE");	// �����޼��� ���
		return;							// ���α׷� ����
	}

	while (!feof(fp)) {	// ���� ������ �ݺ�
		fscanf(fp, "%d %d %d %d", &arr[i].id, &arr[i].kor, &arr[i].eng, &arr[i].math);	// �л� ������ �о�� ����ü�� ����
		i++;			 // index ����
	}

	printf("=================================================================\n");
	printf(" �й�\t\t����\t����\t����\t����\t���\t\n");

	i = 0;
	while (i < 5) {										
		arr[i].total = arr[i].kor + arr[i].eng + arr[i].math;	
		arr[i].avg = arr[i].total / 3.0;
		printf("%d\t%d\t%d\t%d\t%d\t%.2f\n", arr[i].id, arr[i].kor, arr[i].eng, arr[i].math,arr[i].total,arr[i].avg);	// �й�, ��,��,��,����,��� ���
		i++;	//index ����
	}

	printf("=================================================================\n");
	printf(" ���\t\t");

	float t_kor, t_eng, t_math, t_total, t_avg;		//������ ����� ���ϱ� ���� ����
	t_kor = t_eng = t_math = t_total = t_avg = 0;	// 0���� �ʱ�ȭ
	for (int i = 0; i < 5; i++) {					//�л����� ����, ����, ����, ����, ����� ��� ���ϱ� ���� �ݺ���
		t_kor += arr[i].kor;
		t_eng += arr[i].eng;
		t_math += arr[i].math;
		t_total += arr[i].total;
		t_avg += arr[i].avg;		
	}

	int num = 5;
	printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t", t_kor/num, t_eng / num, t_math / num, t_total / num, t_avg / num);
	printf("\n=================================================================\n");

	return 0;	// ���α׷� ����
}