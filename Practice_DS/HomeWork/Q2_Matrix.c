/*
이름: 박윤아
학번: 20204624

프로그램 설명: 두 개의 행렬 데이터를 data02.txt 파일에서 입력 받아,
두 행렬의 +,-,*  연산을 수행하는 프로그램 작성
단, 동적 할당으로 2차원 배열을 생성하여 작성
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 동적으로 할당된 메모리를 해제하는 함수
void FreeAllocate(int **matrix, int row) {
	for (int i = 0; i < row; i++)
		free(matrix[i]);
	free(matrix);
}

// flag 값에 따라 두 행렬의 연산을 수행하는 함수
int** Calc(int **a, int **b, int arow, int acol,int brow, int bcol, int flag) {
	int **res; // 계산된 결과를 반환할 2차원 배열
	if (flag != 2) {	//행렬의 덧셈 || 뺄셈을 수행하는 경우
		res = (int**)malloc(sizeof(int*)*arow);
		for (int i = 0; i < arow; i++)
			res[i] = (int*)malloc(sizeof(int)*acol);
	}

	else {	// 행렬의 곱을 수행하는 경우
		res = (int**)malloc(sizeof(int*)*arow);
		for (int i = 0; i < bcol; i++)
			res[i] = (int*)malloc(sizeof(int)*bcol);
	}

	// 0: 행렬의 합, 1: 행렬의 차, 2: 행렬의 곱
	switch (flag) {
	case 0:
		for (int i = 0; i < arow; i++) 
			for (int j = 0; j < acol; j++) 
				res[i][j] = a[i][j] + b[i][j];		// 각 행/열의 합을 res에 저장
		break;

	case 1:
		for (int i = 0; i < arow; i++)
			for (int j = 0; j < acol; j++)
				res[i][j] = a[i][j] - b[i][j];		// 각 행/열의 차를 res에 저장
		break;

	case 2:
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < acol; j++) {
				res[i][j] = 0;						// 덧셈을 수행하기 위해 0으로 초기화
				for (int k = 0; k < bcol; k++)
					res[i][j] += a[i][k] * b[k][j];	// 행렬의 곱을 res에 저장
			}
		}
		break;
	}
	return res;
}

// 행렬 값을 출력하는 함수
void Print_matrix(int **matrix, int row, int col){
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("[%2d] ", matrix[i][j]);
		printf("\n");
	}
}
int main() {

	printf("이름: 박윤아\n학번: 20204624\n\n");

	FILE *fp;						// 파일을 읽어오기 위한 파일 포인터
	int **a, **b;					// 두 행렬을 저장하기 위한 2차원 배열
	int arow, acol, brow, bcol;		// 두 행렬의 행,열 크기를 저장하는 변수
	fp = fopen("data02.txt", "r");	// data02.txt 파일을 읽어와 fp에 저장

	if (!fp) {									// 파일을 읽어오지 못한 경우
		fprintf(stderr, "CAN NOT OPEN FILE");	// 에러 메세지 출력
		return;									// 프로그램 종료
	}
	
	// 첫 번째 행렬 동적 할당
	fscanf(fp, "%d %d", &arow, &acol);			// 행렬의 크기 읽어오기
	a = (int**)malloc(sizeof(int*)*arow);		// 행의 크기에 따른 동적할당	
	for (int i = 0; i < arow; i++)			
		a[i] = (int*)malloc(sizeof(int)*acol);	// 열의 크기에 따른 동적할당

	// 첫 번째 행렬 데이터 읽어오기
	for (int i = 0; i < arow; i++) {
		for (int j = 0; j < acol; j++) {
			fscanf(fp, "%d", &a[i][j]);			// 2차원 배열 A에 행렬 데이터 저장
		}
	}
	
	char buffer[256];		//공백 줄을 건너뛰기 위한 변수
	fgets(buffer, 256, fp);	//빈 줄 건너 뛰기

	// 두 번째 행렬 동적 할당
	fscanf(fp, "%d %d", &brow, &bcol);			// 행렬의 크기 읽어오기
	b= (int**)malloc(sizeof(int*)*brow);		// 행의 크기에 따른 동적할당	
	for (int i = 0; i < arow; i++)
		b[i] = (int*)malloc(sizeof(int)*bcol);	// 열의 크기에 따른 동적할당

	// 두 번째 행렬 데이터 읽어오기
	for (int i = 0; i < brow; i++) {
		for (int j = 0; j < bcol; j++) {
			fscanf(fp, "%d", &b[i][j]);			// 2차원 배열 B에 행렬 데이터 저장
		}
	}

	// 행렬의 덧셈, 뺄셈, 곱셈 출력
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
		
		int ** res =Calc(a, b, arow, acol, brow, bcol, i);	// 합, 차, 곱을 차례로 받아옴
		Print_matrix(res, arow, bcol);	// 행렬 출력
		FreeAllocate(res, arow);		// 동적 메모리 반환
		printf("\n\n");	
	}

	FreeAllocate(a, arow);	// 동적 메모리 반환
	FreeAllocate(b, brow);	// 동적 메모리 반환
	fclose(fp);				// 파일 포인터 반환

	return 0;
}