/*
�̸�: ������
�й�: 20204624
int data[] = { 1,2,3,4,5,6,7,8,9,10 };
���α׷� ����: ���ڿ� ��� �� �����
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int length(char str[], int count) {
	if (str[count] == '\0') return count;
	else return length(str, count + 1);
}

void print(char str[], int count) {
	if (str[count] == '\0') return;
	else {
		printf("%c", str[count++]);
		return print(str, count);
	}
}

void reverse(char str[], int len) {
	if (len < 0) return;
	else {
		printf("%c", str[len]);
		return reverse(str, len-1);
	}
}

int main() {
	int count = 0;
	char str[] = "Hello World";
	int len = length(str, count) - 1;
	printf("���ڿ� ���: "); print(str, count);
	printf("\n���ڿ� �����: "); reverse(str, len);
	return 0;
}