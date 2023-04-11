/*
학번: 20204624
이름: 박윤아

프로그램 설명: data01.txt 파일에 저장된 x,y 값을 배열에 저장,
각 점들 사이의 거리를 소수점 5자리까지 계산 및 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {

	printf("이름: 박윤아\n학번: 20204624\n\n");
	FILE *fp;						// 파일을 읽어오기 위한 파일 포인터
	fp = fopen("data01.txt", "r");	// data01.txt 파일 읽어와 fp에 저장

	int x,y,count = 0;
	int i = 0;
	int *xArr, *yArr;
	
	if (!fp) {									// 파일을 읽어오지 못한 경우
		fprintf(stderr, "CAN NOT OPEN FILE");	//에러 메세지 출력
		return;									// 프로그램 종료
	}

	while (!feof(fp)) {					// 파일의 끝까지 반복
		fscanf(fp, "%d %d", &x, &y);	// x, y값을 읽어와 x,y변수에 저장
		count++;						// 데이터 수 증가
	}
	rewind(fp);	// 파일의 처음으로 이동

	xArr = (int*)malloc(sizeof(int)*count); // 데이터 수 만큼 배열 크기 동적 할당
	yArr = (int*)malloc(sizeof(int)*count);	// 데이터 수 만큼 배열 크기 동적 할당
	
	while (!feof(fp)) {							// 파일의 끝까지 반복
		fscanf(fp, "%d %d", &xArr[i],&yArr[i]);	//x,y 값을 xArr, yArr에 저장
		i++;									// 배열 인덱스 증가
	}

	int tmp = 1;	// 줄번호를 매기기 위한 변수
	for (i = 0; i < count-1; i++) {	
		for (int j = i+1; j < count; j++) {
																				// 두 점사이의 거리 구하는 공식: (x2-x1)^2 + (y2-y1)^2
			int res = pow((xArr[i] - xArr[j]),2) + pow((yArr[i] - yArr[j]),2);	// 제곱을 반환하는 pow함수를 이용해 res에 저장
			printf("%d. (%d, %d)와 (%d, %d)의 사이의 거리는 %.5f 입니다.\n",
				tmp++, xArr[i], yArr[i], xArr[j], yArr[j], sqrt(res));			// sqrt(res)를 통해 res의 제곱근, 즉 두 점 사이 거리 출력
		}
	}

	free(xArr);	// 동적 메모리 반환
	free(yArr);	// 동적 메모리 반환
	fclose(fp);	// 파일 포인터 반환

	return 0;

}