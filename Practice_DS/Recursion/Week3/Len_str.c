/*
�̸�: ������
�й�: 20204624

���α׷� ����: ���ڿ��� ���� ���
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
	printf("���ڿ��� ���̴�: %d", res);
	return 0;
}