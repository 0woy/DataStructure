/*
���� ����: ũ�Ⱑ n�� �迭 array���� ������ ��ġ loc�� �ִ� ������ �����ϴ� delete()�Լ� �ۼ�
������ �����Ǹ� �� �ڿ� �ִ� �������� �� ĭ �� ������ �̵�

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int items = 0;	// ������ ����
int n;			//�迭�� ũ��

int delete(int array[], int loc) {
	int res = array[loc];	// loc��ġ�� �ִ� �� res�� ����
	for (int i = loc; i < n; i++) {		// loc���� ������
		array[i] = array[i+1];			// ������ �� ĭ�� �̵�
	}
	
	return res;	//res �� ��ȯ
}