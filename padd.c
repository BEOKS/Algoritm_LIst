#include <stdio.h>
typedef struct poly{
    int coef;
    int exp;
}poly;
// Ax= 2x^3+x^2 + 1


poly* padd(poly Ax[],poly Bx[]){
    // ax_index=0 , bx_index=0, make Cx[100]
    
    
    
    
    //loop (ax_index<a end) && bx_index<b end)
        // ax_index_exp > bx_index_exp
    
            // cx+=ax[ax_index],  ax_index++
    
        // ax_index_exp == bx_index_exp
    
            //cx+=ax[ax_index]+bx[bx_index],  ax_index++,  bx_index++
    
        // ax_index_exp < bx_index_exp
    
            // cx+=bx[bx_index], bx_index++
    
        //Cx_size++
    
    
    
    
    //남은 것들을 더함
    
    //for i=ax_index ~ ax_size
        // cx+= ax[i]
    
    //for i=bx_index ~ bx_size
    // cx+= bx[i]
    
}


int main(void){
    poly Ax[2]={{2,1000},{1,0}};
    poly Bx[4]={{1,4},{10,3},{3,2},{1,0}};
}

