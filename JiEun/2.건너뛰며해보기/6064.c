/**
 * 백준 6064.카잉달력
 * 2022.05.28
 * https://www.acmicpc.net/problem/6064
 */

#include <stdio.h>

// 최대공약수
int gcd(int m, int n)
{
    while (n != 0)
    {
        int temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

// 최소공배수
int lcm(int m, int n)
{
    return (m * n) / gcd(m, n);
}
int main()
{
    int t = 0;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int m = 0, n = 0, x = 0, y = 0;
        int flag = 0;
        scanf("%d %d %d %d", &m, &n, &x, &y);

        // 마지막 해는 m과 n의 최소공배수이다
        int lastYear = lcm(m, n);

        // x를 기준으로 m만큼 더한 해의 y값만 비교하면 된다
        for (int j = x; j <= lastYear; j += m)
        {
            int temp = j % n == 0 ? n : j % n; // 반례 1 1 1 1
            if (temp == y)
            {
                flag = 1;
                printf("%d\n", j);
            }
        }

        if (flag == 0)
            printf("-1\n");
    }

    return 0;
}