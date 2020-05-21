#include <stdio.h>

#define MAX_SIZE 101
#define COMPARE(x, y)  (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)

int binsearch(int [], int, int, int);
int main(){
    int i, n;
    int list[MAX_SIZE], result;
    
    for(i = 0; i < MAX_SIZE; i++){
        list[i] = i * 2;
    }
    
    printf("찾는 숫자를 입력하시오 : ");
    scanf("%d", &n);
    
    result = binsearch(list, n, 0, MAX_SIZE - 1);
    if(result == -1)
        printf("해당 숫자는 list에 존재하지 않습니다.\n");
    else
        printf("해당 숫자는 list[%d]에 존재합니다.\n", result);
    
    return 0;
}

int binsearch(int list[], int searchnum, int left, int right){
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
