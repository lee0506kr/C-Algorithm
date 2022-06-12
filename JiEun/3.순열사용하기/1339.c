/**
 * 백준 1339.단어수학
 * 2022.05.31
 * https://www.acmicpc.net/problem/1339
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;

    scanf("%d", &n);

    int ascii[100] = {
        0,
    }; // 알파벳(아스키코드 'A' to 'Z')

    int strCnt = 0; // 필요한 숫자의 개수
    char str[10];   // 입력받는 단어

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &str);

        int strLen = strlen(str);
        for (int j = 0; j < strLen; j++)
        {
            int idx = str[j] - 0; // convert 'A' to 65

            // MinGX때문에 값이 잘못나와 round함수 사용
            ascii[idx] += (int)round(pow(10.0, strLen - j - 1)); // ascii[65] = 10000
        }
    }

    // 내림차순 정렬
    int temp = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 99 - i; j++)
        {
            if (ascii[j] < ascii[j + 1])
            {
                temp = ascii[j];
                ascii[j] = ascii[j + 1];
                ascii[j + 1] = temp;
            }
        }
    }

    int value = 9, result = 0;
    // 각 단어에 숫자 9부터 대입하며 최대값 계산
    for (int i = 0; i <= 90; i++)
    {
        if (ascii[i] == 0)
            break;

        result += ascii[i] * value;
        value--;
    }

    printf("%d", result);

    return 0;
}