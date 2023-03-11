/*

이름: 박윤아
학번: 20204624
작성일: 2023.03.11.

프로그램 설명
2000년 부터 2007년까지 월별 연도별 데이터가 Statistics.txt 파일에 저장돼 있다.
2차원 배열을 통해 데이터를 읽어서 8년간 월별 평균값과 연도별 합계 구하기
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	printf("학번: 20204624\n이름: 박윤아\n\n");

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
	printf("| 년도 \t 1월\t2월 \t3월\t4월\t5월\t6월\t7월\t8월\t9월\t10월\t11월\t12월\t년별총합|\n");
	for (int i = 0; i < 8; i++) {
		int total = 0;
		printf("|%4d년|", year++);
		for (int j = 0; j < 12; j++) {
			printf("%3d \t", stat[i][j]);
			total += stat[i][j];
		}
		printf("%8d|\n", total);
	}
	printf("|===============================================================================================================|\n");
	printf("|월평별\t");
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