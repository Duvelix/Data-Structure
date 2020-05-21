#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 101
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))
void sort(int [], int);  /* 선택 정렬 */
int main(){
    int i, n;
    int list[MAX_SIZE];
    
    printf("생성할 숫자의 갯수를 입력하시오 : ");
    scanf("%d", &n);
    
    srand((unsigned int)time(NULL));    /* 난수 시드 생성 */
    
    if( (n < 1) || n > MAX_SIZE) {      /* 비정상적인 입력에 대한 예외처리 */
        fprintf(stderr, "적절하지 않은 n값입니다.");
        exit(EXIT_FAILURE);
    }
    
    printf("정렬 전 : ");
    for(i = 0; i < n; i++){             /* 입력한 수 만큼 0부터 999까지의 난수 생성 */
        list[i] = rand() % 1000 ;
        printf("%d ", list[i]);
    }
    
    sort(list, n);                      /* 선택 정렬 수행 */
    
    printf("\n정렬 후 : ");               /* 정렬 결과 출력 */
    for(i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
    
    return 0;
}

void sort(int list[], int n){
    int i, j, min, temp;
    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++){
            if (list[j] < list[min])
                min = j;
        }
        SWAP(list[i], list[min], temp);
    }
}
