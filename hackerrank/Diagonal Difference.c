
// My very own implementation of https://www.hackerrank.com/challenges/diagonal-difference/problem

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int size,rtl = 0,ltr = 0,tmpCnt;
   scanf("%d",&size);
//    tmpCnt = size;
   int *matrix = (int*)malloc(size*size*sizeof(int));
   for(int i = 0;i<size*size;i++){
       scanf("%d",&tmpCnt);
       matrix[i] = tmpCnt;
   }
   int cnt = 0;
   for(int i = 0; i< size; i++){
       rtl +=matrix[size*cnt+cnt];
       ltr +=matrix[size*cnt+(size-cnt-1)];
       cnt++;
   }
   printf("%d\n",abs(rtl-ltr));
    return 0;
}
