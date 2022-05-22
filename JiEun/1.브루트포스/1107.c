/*  백준 1107.리모컨
 2022.05.16
 https://www.acmicpc.net/problem/1107
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n, m;

    scanf("%d", &n); // 5457
    scanf("%d", &m); // 3

    bool broken[10] = {
        false,
    }; // 고장난 숫자  6 7 8

    for (int i = 0; i < m; i++)
    {
        int b;
        scanf("%d", &b);
        broken[b] = true;
    }

    int min = abs(n - 100); // 숫자 버튼을 누르지않고, 이동할 채널로 이동하는 횟수

    for (int i = 0; i <= 1000000; i++)
    {
        int num = i;
        int cnt = 0;
        int numLen = 0;    // 이동할 채널 자리수
        bool flag = false; // 이동할 채널버튼중 고장난 숫자 존재 여부

        // 이동할 채널 중 고장난 버튼이 있는지 한 자리수씩 체크
        if (num == 0)
        {
            // 이동할 채널이 0번인 경우
            if (broken[num])
            {
                numLen = 0;
                flag = true;
            }
            else
            {
                numLen = 1;
            }
        }
        else
        {
            while (num > 0)
            {
                // 5455
                if (broken[num % 10])
                {
                    flag = true;
                    break;
                }
                num = num / 10;
                numLen += 1;
            }
        }

        // 이동할 채널에 고장난 버튼이 있으면, 다음 숫자로 건너뛴다
        if (flag == true)
            continue;

        // 고장난 버튼이 없으면, 채널까지 더해야할 버튼 개수 카운트
        cnt = abs(n - i) + numLen;

        // 최소값 비교
        min = min > cnt ? cnt : min;
    }

    printf("%d", min);

    return 0;
}