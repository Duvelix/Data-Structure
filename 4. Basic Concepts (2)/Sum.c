#include <stdio.h>
#include <stdlib.h>

float sum(float[], int);
int count = 0;

int main(){
    float *list;
    int n, i;
    
    printf("list의 크기를 입력하시오 : ");
    scanf("%d", &n);
    
    list = (float*)malloc(sizeof(float) * n);
    
    for(i = 0; i < n; i++)
        list[i] = (float)i;
    
    sum(list, n);
    
    printf("%d\n", count);
    return 0;
}

float sum(float list[], int n){
    float tempsum = 0; count++;  /* 대입 연산 */
    int i;
    for (i = 0; i < n; i++){
        count++;  /* 반복문 for의 루프를 위한 연산 */
        tempsum += list[i]; count++; /* 대입 연산 */
    }
    count++; /* 반복문 for의 마지막 실행 */
    count++; /* 반환 연산 */ return tempsum;
}
