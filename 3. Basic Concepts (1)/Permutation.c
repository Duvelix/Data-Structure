#include <stdio.h>
#include <stdlib.h>
#define ALPHABET 26
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))
void perm(char *, int, int);
int main(){
    int i, n;
    char list[ALPHABET];
    
    printf("집합 원소의 갯수를 입력하시오 : ");
    scanf("%d", &n);
    
    if( (n < 1) || n > ALPHABET) {      /* 비정상적인 입력에 대한 예외처리 */
        fprintf(stderr, "적절하지 않은 n값입니다.");
        exit(EXIT_FAILURE);
    }
    
    printf("주어진 집합 : ");
    for(i = 0; i < n; i++){             /* a부터 차례대로 list에 삽입 및 출력 */
        list[i] = 'a' + i;
        printf("%c ", list[i]);
    }
    printf("\n순열의 집합 : ");
    
    perm(list, 0, n - 1);
    
    printf("\n");
    return 0;
}

void perm(char *list, int i, int n){
    /* list[i]부터 list[n]까지의 모든 순열을 생성 */
    int j, temp;
    if (i == n) {
        for (j = 0; j <= n; j++){
            printf("%c", list[j]);
        }
        printf("   ");
    }
    else {
        /* list[i]부터 list[n]까지 한 개 이상의 순열이 존재한다면, 재귀를 통해 생성 */
        for(j = i; j <= n; j++) {
            SWAP(list[i], list[j], temp);
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}
