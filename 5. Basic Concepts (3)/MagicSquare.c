#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15    /* 마방진의 최대 크기 */

int main(){
    static int square[MAX_SIZE][MAX_SIZE];
    int i, j, row, column;
    int count;
    int size;
    
    printf("마방진의 크기를 입력하시오 : ");
    scanf("%d", &size);
    
    /* 입력이 최대/최소 크기를 벗어나거나, 짝수면 오류 판정 */
    if( (size < 1) || (size > MAX_SIZE + 1) ){
        fprintf(stderr, "오류 : 크기가 범위를 벗어났습니다.");
        exit(1);
    }
    
    if ( !(size %2) ){
        fprintf(stderr, "오류 : 크기가 짝수입니다.");
        exit(1);
    }
    
    /* 마방진을 0으로 초기화 */
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++)
            square[i][j] = 0;
    }
    
    /* 첫째 행 가운데에 1을 삽입 */
    square[0][(size-1)/2] = 1;
    
    /* 첫째 행 가운데의 위치를 i, j에 저장 */
    i = 0;
    j = (size - 1) / 2;
    
    /* 반복문을 사용하여 마방진 생성 */
    for (count = 2; count <= size * size; count++){
        row = (i - 1 < 0) ? (size - 1) : (i - 1);       /* 위로 이동 */
        column = (j - 1 < 0) ? (size - 1) : (j - 1);    /* 왼쪽으로 이동 */
        if (square[row][column])                        /* 아래로 이동 */
            i = (++i) % size;
        else {              /* 현재 좌표가 0인 경우 (비어있는 경우) */
            i = row;
            j = (j - 1 < 0) ? (size - 1) : --j;
        }
        square[i][j] = count;
    }
    
    /* 생성된 마방진 출력 */
    printf("크기가 %d인 마방진 생성 결과 :\n", size);
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++)
            printf("%5d", square[i][j]);
        printf("\n");
    }
}
