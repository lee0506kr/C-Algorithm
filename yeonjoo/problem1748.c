#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    // flag:자리수
    int n, i, sum=0, flag=1;
    scanf("%d", &n);
    
    // n까지 반복 돌면서 길이 구하기(1~9: 9, 10~99: 180, 100~999:2700...)
    for(i = 1; i <= n; i*=10){
        sum += flag * (i * 10 - i);
        flag++;
    }

    // n이 120이라면 위의 for문에서 1000까지 반복문 실행되니 1000에서 n만큼 빼주어야한다.
    // i를 10으로 나누고(n의 자리수만큼 맞추기위해) flag(자리수)를 하나 낮추기
    i /= 10;
    flag--;
    sum = sum - flag * (i * 10 - n-1);

    printf("%d", sum);
    return 0;
}