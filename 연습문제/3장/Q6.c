/*
���� ����:typedef�� �̿��Ͽ� complex��� �ϴ� ���ο� �ڷ����� ����
complex�ڷ����� ����ü�μ� float���� real ������ ���� float���� imaginary ������ ���𤤴�.
complex �ڷ������� ���� c1, c2�� ���� �϶�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct {
	float real;
	float imaginary;
}complex;
int main() {
	complex c1, c2;
	c1.real = 2.0;
	c1.imaginary = 3.0;

	c2.real = 4.0;
	c2.imaginary = 5.0;

	printf("c1�� real: %f, imaginary: %f\n", c1.real, c1.imaginary);
	printf("c2�� real: %f, imaginary: %f\n", c2.real, c2.imaginary);

	return 0;
}