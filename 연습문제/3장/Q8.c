/*
���� ����: ũ�Ⱑ n�� �迭 array ���� ������ ��ġ loc�� ���� value�� �����ϴ� �Լ� insert()�� �ۼ�
������ ���ԵǸ� �� �ڿ��ִ� �������� �� ĭ�� �ڷ� �з��� �Ѵ�.
���� �迭�� ����ִ� ������ ������ items����� ����(���⼭ items<<n��� ����)

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int items = 0;	// ������ ����
int n;			//�迭�� ũ��
void insert(int array[], int loc, int value) {
	for (int i = loc; i < n; i++) {
		array[i + 1] = array[i];
	}
	array[loc] = value;
	items++;
}