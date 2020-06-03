#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10000
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))
void sort(int [], int);  /* 선택 정렬 */
int main(){
    int i, n;
    int list[MAX_SIZE];
    clock_t start, end;
    double duration;
    
    printf("생성할 숫자의 갯수를 입력하시오 : ");
    scanf("%d", &n);
    
    
    if( (n < 1) || n > MAX_SIZE) {      /* 비정상적인 입력에 대한 예외처리 */
        fprintf(stderr, "적절하지 않은 n값입니다.");
        exit(EXIT_FAILURE);
    }
    
    printf("정렬 전 : ");
    for(i = 0; i < n; i++){             /* 입력한 수 만큼 역순으로 데이터 생성 */
        list[i] = n - i;
        printf("%d ", list[i]);
    }
    
    start = clock();                    /* 시작 시간 체크 */
    sort(list, n);                      /* 선택 정렬 수행 */
    end = clock();                      /* 종료 시간 체크 */
    
    printf("\n정렬 후 : ");               /* 정렬 결과 출력 */
    for(i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
    
    duration = ((double)(end - start))/CLOCKS_PER_SEC;      /* 소요 시간 초 단위로 변환 */
    printf("소요 시간 : %f\n", duration);       /* 소요 시간 출력 */
    
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
