#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void add(int [][MAX_COLS], int [][MAX_COLS], int [][MAX_COLS], int, int);
int count = 0;

int main(){
    int a[MAX_ROWS][MAX_COLS], b[MAX_ROWS][MAX_COLS], c[MAX_ROWS][MAX_COLS];
    int i, j;
    
    for(i = 0; i < MAX_ROWS; i++){
        for (j = 0; j < MAX_COLS; j++){
            a[i][j] = i + j;
            b[i][j] = i * j;
        }
    }
    
    add(a, b, c, MAX_ROWS, MAX_COLS);
    printf("%d\n", count);
    
    return 0;
}

void add(int a[][MAX_COLS], int b[][MAX_COLS], int c[][MAX_COLS], int rows, int cols){
    int i, j;
    
    for(i = 0; i < rows; i++){
        count++;  /* 첫 번째 for문을 위한 연산 */
        for (j = 0; j < cols; j++){
            count++;  /* 두 번째 for문을 위한 연산 */
            c[i][j] = a[i][j] + b[i][j];
            count++;  /* 대입을 위한 연산 */
        }
        count++;  /* 두 번째 for문의 마지막 연산 */
    }
    count++;  /* 첫 번째 for문의 마지막 연산 */
}
