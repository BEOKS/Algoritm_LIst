#include <stdio.h>
#include <stdlib.h>
int main(void){
    int *array,array_size,target;
    //malloc
    scanf("%d",&array_size);
    array=(int*)malloc(sizeof(int)*array_size);
    //get data
    int i;
    for(i=0;i<array_size;i++){
        scanf("%d",&array[i]);
    }
    scanf("%d",&target);
    //find
    int start=0,end=array_size-1;
    int location = 0;
    //loop
    while(start<=end){
        int middle=(start+end)/2;
        //check middle
        if(array[middle]==target){
            location=middle;
            break;
        }
        // else if smaller
        else if(array[middle]>target){
            end=middle-1;
        }
        // else if bigger
        else{
            start=middle+1;
        }
    }
    //can't find
    if(start>end){
        location=-1;
    }
    
    printf("%d\n",location);
    
}

