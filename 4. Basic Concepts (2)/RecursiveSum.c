#include <stdio.h>
#include <stdlib.h>

float rsum(float[], int);
int count = 0;

int main(){
    float *list;
    int n, i;
    
    printf("list의 크기를 입력하시오 : ");
    scanf("%d", &n);
    
    list = (float*)malloc(sizeof(float) * n);
    
    for(i = 0; i < n; i++)
        list[i] = (float)i;
    
    rsum(list, n);
    printf("%d\n", count);
    return 0;
}

float rsum(float list[], int n){
    count++;
    if (n) {
        count++;
        return rsum(list, n-1) + list[n-1];
    }
    count++;
    return 0;
}
