/*
�̸�: ������
�й�: 20204624

���α׷� ����: �Է� ���� n�� �Ǻ���ġ�� ���� ���
if) 5�Է½� 0,1,1,2,3,
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

// ��� ����
int Fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	else return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

// �ݺ� ����
int Iter_Fibonacci(int n) {
	int pp = 0;
	int p = 1;
	int res = 0;
	for (int i = 2; i <= n; i++) {
		res = pp + p;
		pp = p;
		p = res;
	}
	return res;
}

int main() {
	clock_t start, end;
	int n;
	printf("n �Է� >> ");
	scanf("%d", &n);

	start = clock();
	int res = Iter_Fibonacci(n);
	end = clock();
	printf("[time: %f]\n", (float)(end - start) / CLOCKS_PER_SEC);

	printf("���: %d", res);

	return 0;
}