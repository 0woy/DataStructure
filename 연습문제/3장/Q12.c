/*
���� ����: 1���� ������ �ִ� ũ�Ⱑ 20�� ���ڿ��� �̷���� ����ü�� ������ �� �ֵ���
�����޸𸮸� �Ҵ� �ް�, ���⿡ ���� 100�� ���ڿ� "just testing"�� �����Ѵ���
���� �޸𸮸� �ݳ��ϴ� ���α׷� �ۼ�

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 1���� ������ �ִ� ũ�Ⱑ 20�� ���ڿ��� ���� ����ü ����
typedef struct {
	int n;
	char str[20];
}test;

int main() {

	test *temp;						//�ش� ����ü�� ������ ���� temp ������ ����
	temp = malloc(sizeof(test));	// test ����ü�� ũ�� ��ŭ ���� �޸� �Ҵ�

	if (!temp) {					// �޸� �Ҵ��� �� �� ���� ���
		printf("���� �Ҵ� ����");	// ���� �޼��� ���
		return;						// ���α׷� ����
	}

	temp->n = 100;	// ������ 100 ����
	strcpy(temp->str, "just testing");	// ���ڿ��� just testing ����
	printf("temp�� ����: %d\ntemp�� ���ڿ�: %s", temp->n, temp->str);	// test ���

	free(temp);	// �Ҵ�� ���� �޸� �ݳ�
	
	return 0;	// ���α׷� ����
}