#include <stdio.h>
#include <stdlib.h>
#define size 9
#define MAX_COL 6
#define MAX_ROW 6
/*
term: ����� ��,�� �׸��� �ش� ���� ����
*/
typedef struct term {
	int row;
	int col;
	int value;
}term;

term *transposing(term A[]);
int main(void) {
	term A[9] = { { 6,6,8 },{ 0,0,15 },{ 0,3,22 },{ 0,5,-15 },{ 1,1,11 },{ 1,2,3 },{ 2,3,-6 },{ 4,0,91 },{ 5,2,28 } };
	term *B = transposing(A);
	system("pause");
}

term *transposing(term A[]) {
	//setting 
	int rowTerms[MAX_COL] = { 0 }, startPoint[MAX_COL] = { 0 };
	term B[size];
	B[0].col = A[0].row; B[0].row = A[0].col; B[0].value = A[0].value;
	//get row Terms
	for (int i = 1; i < size; i++) {
		rowTerms[A[i].col]++;
	}

	//get startpoint
	startPoint[0] = 1;
	for (int i = 1; i <MAX_COL; i++) {
		startPoint[i] = startPoint[i - 1] + rowTerms[i - 1];
	}

	//transport to B
	for (int i = 1; i < size; i++) {
		int j = startPoint[A[i].col]++;
		B[j].row = A[i].col;
		B[j].col = A[i].row;
		B[j].value = A[i].value;
	}

	return B;
}a