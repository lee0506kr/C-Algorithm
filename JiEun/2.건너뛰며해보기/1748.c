/**
 * 백준 1748.수 이어 쓰기 1
 * 2022.05.29
 * https://www.acmicpc.net/problem/1748
 */

#include <stdio.h>

int main()
{
    int n = 0, cnt = 0;

    scanf("%d", &n);

    int result = 0, i = 1;
    while (i <= n)
    {
        /* 1부터 N까지의 수를 나열할때, 각 자리수별로 총 개수를 계산한다
            15 : 1의 자리수는 총 14개
                 10의 자리수는 총 5개
        */
        result += (n - i + 1);
        i *= 10;
    }

    printf("%d", result);
    return 0;
}