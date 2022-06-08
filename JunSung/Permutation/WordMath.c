#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 알파벳
int eng[26];
// 최대 길이
char str[10];

int main(){

    // 단어의 개수 
    int n,i,j;
    scanf("%d",n);

    // 단어의 길이 만큼 반복문
    for(i=0; i<n;i++){
        
        // 알파벳 입력 
        scanf("%s",str);
        // 문자를 int 로 변환 하는 작업
        int length = strlen(str);        
        int check = 1;
        
        for (j = length-1; j >= 0; j--){
            eng[str[j] - 'A'] += check;
            check *= 10;
        }
    }

    // 0 ~ 9 까지 
    int idx = 9;
	int ans = 0;

    //최대 길이 10
	for (i = 1; i <= 10; i++)
	{
		int max = 0;
		for (j = 0; j < 26; j++)
		{
			if (eng[j] > max)
				max = eng[j];
		}

        // 하나 씩 줄이면서 나열 
		ans += max * idx;
		idx--;

		for (j = 0; j < 26; j++)
		{
			if (max == eng[j])
			{
				eng[j] = 0;
				break;
			}
		}
	}
	printf("%d", ans);

    return 0;
}