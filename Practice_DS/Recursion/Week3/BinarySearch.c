/*
�̸�: ������
�й�: 20204624

���α׷� ����: ���� �˻�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

bool find = false;
bool search(int data[], int n, int start, int end){
	if (start > end ) return;
	int tmp = (start + end)/2;
	if (data[tmp] == n) { find = true; return; }
	else if (data[tmp] < n) return search(data, n, tmp+1, end);
	else return search(data, n, start, tmp - 1);
}

int main() {

	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n;
	printf("ã������ ��>> ");
	scanf("%d", &n);
	search(data, n, 0, 9);
	if (find) printf("�迭�� ã�� �� %d�� �����մϴ�.",n);
	else printf("�迭�� ã�� �� %d(��)�� �������� �ʽ��ϴ�.", n);

	return 0;
}