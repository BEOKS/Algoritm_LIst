#include <stdio.h>
#include <stdlib.h>
typedef struct poly {

	int coef;

	int exp;

}poly;

poly* padd(poly Ax[], poly Bx[]);

int ax_size = 3, bx_size = 3, cx_size = 0;

int main(void) {

	poly Ax[3] = { { 5,10 },{ 4,5 },{ 3,0 } };

	poly Bx[3] = { { 3,5 },{ 8,2 },{ 5,0 } };

	poly *Cx = padd(Ax, Bx);

	for (int i = 0; i < cx_size; i++) {
		printf("%d %d\n", Cx[i].coef, Cx[i].exp);
	}
	system("pause");
}



poly* padd(poly Ax[], poly Bx[]) {

	// ax_index=0 , bx_index=0, make Cx[100]
	int ax_index = 0, bx_index = 0;
	poly *Cx = (poly*)malloc(sizeof(poly));
	//우선 각 다항식에서 체크할 위치를 정해줍시다. 





	//loop (ax_index<a end) && bx_index<b end)
	while (ax_index < ax_size && bx_index < bx_size) {
		//항 다항식의 끝을 확인할때까지 반복합니다.

		//Cx_size++
		cx_size++;
		Cx = (poly*)realloc(Cx, sizeof(poly)*cx_size);
		// ax_index_exp > bx_index_exp
		// ax 쪽이 bx보다 큰 지수를 가질때
		if (Ax[ax_index].exp > Bx[bx_index].exp) {
			// cx+=ax[ax_index],  ax_index++
			Cx[cx_size - 1] = Ax[ax_index++];
		}
		// ax 와 bx가 같은 지수를 가질때
		else if (Ax[ax_index].exp == Bx[bx_index].exp) {
			//cx+=ax[ax_index]+bx[bx_index],  ax_index++,  bx_index++
			Cx[cx_size - 1] = Bx[bx_index++];
			Cx[cx_size - 1].coef += Ax[ax_index++].coef;
		}
		// ax_index_exp < bx_index_exp
		// ax 쪽이 bx보다 작은 지수를 가질때
		else {
			// cx+=bx[bx_index], bx_index++
			Cx[cx_size - 1] = Bx[bx_index++];
		}
	}

	//남은 것들을 더함


	//for i=ax_index ~ ax_size
	for (int i = ax_index; i < ax_size; i++) {
		// cx+= ax[i]
		cx_size++;
		Cx = (poly*)realloc(Cx, sizeof(poly)*cx_size);
		Cx[cx_size - 1] = Ax[i];
	}

	//for i=bx_index ~ bx_size
	for (int i = bx_index; i < bx_size; i++) {
		// cx+=bx[i]
		cx_size++;
		Cx = (poly*)realloc(Cx, sizeof(poly)*cx_size);
		Cx[cx_size - 1] = Bx[i];
	}

	return Cx;
}