/*
학번: 20204624
이름: 박윤아
작성일: 2023.03.10.

프로그램 설명: 학생별 학번, 국어, 영어, 수학의 점수가 파일에 저장되어 있다.
해당 파일의 데이터를 읽어들여 배열에 저장하고, 학생 별 총점과 평균, 각 과목별 평균 등을 평균으로 출력하는
프로그램을 작성. 2중 배열을 동적으로 생성하여 저장하고 계산
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
	printf("학번: 20204624\n이름: 박윤아\n\n");

	FILE *fp;		// 파일을 읽어오기 위한 변수
	int i = 0;		// 배열의 index로 사용할 변수
	Student arr[5];

	fp = fopen("Grade.txt", "r");		// 학생 정보가 담긴 파일 읽어오기
	if (!fp) {							// 파일을 읽어오지 못했다면
		printf("CAN NOT OPEN FILE");	// 에러메세지 출력
		return;							// 프로그램 종료
	}

	while (!feof(fp)) {	// 파일 끝까지 반복
		fscanf(fp, "%d %d %d %d", &arr[i].id, &arr[i].kor, &arr[i].eng, &arr[i].math);	// 학생 정보를 읽어봐 구조체에 저장
		i++;			 // index 증가
	}

	printf("=================================================================\n");
	printf(" 학번\t\t국어\t영어\t수학\t총점\t평균\t\n");

	i = 0;
	while (i < 5) {										
		arr[i].total = arr[i].kor + arr[i].eng + arr[i].math;	
		arr[i].avg = arr[i].total / 3.0;
		printf("%d\t%d\t%d\t%d\t%d\t%.2f\n", arr[i].id, arr[i].kor, arr[i].eng, arr[i].math,arr[i].total,arr[i].avg);	// 학번, 국,영,수,총점,평균 출력
		i++;	//index 증가
	}

	printf("=================================================================\n");
	printf(" 평균\t\t");

	float t_kor, t_eng, t_math, t_total, t_avg;		//영역별 평균을 구하기 위한 변수
	t_kor = t_eng = t_math = t_total = t_avg = 0;	// 0으로 초기화
	for (int i = 0; i < 5; i++) {					//학생들의 국어, 영어, 수학, 총점, 평균의 평균 구하기 위한 반복분
		t_kor += arr[i].kor;
		t_eng += arr[i].eng;
		t_math += arr[i].math;
		t_total += arr[i].total;
		t_avg += arr[i].avg;		
	}

	int num = 5;
	printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t", t_kor/num, t_eng / num, t_math / num, t_total / num, t_avg / num);
	printf("\n=================================================================\n");

	return 0;	// 프로그램 종료
}