#include <stdio.h>
#define MAX_SIZE 101
#define COMPARE(x, y)  (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)
int binsearch(int [], int, int, int);  /* 이진 탐색 */
int main(){
    int i, n;
    int list[MAX_SIZE], result;
    
    for(i = 0; i < MAX_SIZE; i++){     /* list에 0부터 (MAX_SIZE-1) * 2까지의 짝수 대입 */
        list[i] = i * 2;
    }
    
    printf("찾는 숫자를 입력하시오 : ");
    scanf("%d", &n);
    
    result = binsearch(list, n, 0, MAX_SIZE - 1);  /* 이진 탐색 수행 후 결과를 저장 */
    if(result == -1)    /* 탐색 결과 출력 */
        printf("해당 숫자는 list에 존재하지 않습니다.\n");
    else
        printf("해당 숫자는 list[%d]에 존재합니다.\n", result);
    
    return 0;
}

int binsearch(int list[], int searchnum, int left, int right){
/* 오름차순으로 정렬된 list에서 searchnum을 탐색 후, 찾으면 그 위치를 반환하고 그렇지 않으면 -1을 반환 */
    int middle;
    while (left <= right) {
        middle = (left + right)/2;
        switch (COMPARE(list[middle], searchnum)) {
            case -1 : left = middle + 1;
                break;
            case 0 : return middle;
            case 1 : right = middle - 1;
        }
    }
    return -1;
}
