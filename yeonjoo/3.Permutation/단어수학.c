#include<stdio.h>
#include<string.h>
#include <stdbool.h>

int A[26];  // 알파벳
bool visited[26];

int main()
{
	int n; 
    scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		char s[10]; 
        scanf("%s", &s);
        int len = strlen(s);
		int mul = 1;
		for (int j = len-1; j >= 0; --j)
		{
			A[s[j] - 'A'] += mul;
			mul *= 10;
		}
	}
	
	int num = 9;
	for (int i = 0; i < 26; ++i)
	{
		int max_val = 0;
		int max_idx = 0;
		for (int j = 0; j < 26; ++j)
		{
			if (visited[j])continue;
			if (A[j] >= max_val)
			{
				max_val = A[j];
				max_idx = j;
			}
		}
		A[max_idx] *= num;
		visited[max_idx] = true;
		--num;
	}
	int ans = 0;
	
	for (int i = 0; i < 26; ++i)
	{
		ans += A[i];
	}
    printf("%d\n", ans);
}