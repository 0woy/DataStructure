/*
문제 설명:typedef을 이용하여 complex라고 하는 새로운 자료형을 정의
complex자료형은 구조체로서 float형인 real 변수와 역시 float형인 imaginary 변수를 가즌ㄴ다.
complex 자료형으로 변수 c1, c2를 선언 하라.
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

	printf("c1의 real: %f, imaginary: %f\n", c1.real, c1.imaginary);
	printf("c2의 real: %f, imaginary: %f\n", c2.real, c2.imaginary);

	return 0;
}