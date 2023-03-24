/*
이름: 박윤아
학번: 20204624

프로그램 설명: 이진 검색
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
	printf("찾으려는 수>> ");
	scanf("%d", &n);
	search(data, n, 0, 9);
	if (find) printf("배열에 찾는 수 %d가 존재합니다.",n);
	else printf("배열에 찾는 수 %d(이)가 존재하지 않습니다.", n);

	return 0;
}