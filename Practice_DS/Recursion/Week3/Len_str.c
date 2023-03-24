/*
이름: 박윤아
학번: 20204624

프로그램 설명: 문자열의 길이 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int length(char str[], int count) {
	if (str[count] == '\0') return count;
	else return length(str, count+1);
}

int main() {
	int count = 0;
	char str[] = "Hello World";
	
	int res = length(str, count);
	printf("문자열의 길이는: %d", res);
	return 0;
}