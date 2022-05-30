#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){
    int t, m, n, x, y;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d %d", &m, &n, &x, &y);

        // 카잉달력에 표현할 수 없는 수가 들어올 경우, 표현할 수 있는 최대의 수
        // maxXY의 수를 초과할 경우 -1 리턴(더이상 찾을 필요 없기 때문)
        int maxXY = m * n;
        int index = 0;
        int result = -1;

        if(y == n){
            y = 0;
        }

        while(true){
            // 연도를 m으로 나눈 나머지를 만족하는 수가 연도를 n으로 나눈 수도 만족한다면, result값을 해당 수로
            // m* index + x = m으로 나눴을때 x인 수
            if((m * index + x) % n == y){
                result = m * index + x;
                break;
            }
            if(m * index + x > maxXY){
                break;
            }
            index++;
        }
        printf("%d\n", result);
    }
    return 0;
}