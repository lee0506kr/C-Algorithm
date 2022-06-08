#include<stdio.h>
#include<string.h>
char arr[20];
char num[11];
char max[11];
char min[11];
int visited[10];
int a = 0;
int k;

void findmax() {
	for (int i = 0; i <= k; i++) {
		if (num[i] > max[i])
			strcpy(max, num);
	}
}

void findmin() {
	for (int i = 0; i <= k; i++) {
		if (num[i] > min[i]) 
			return;
	}
	strcpy(min, num);
}

void dfs(int prev, int cnt) {   // 이전값, 현재값 비교
	if (cnt == k) {
		findmax();
		findmin();
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {
			if (arr[cnt * 2] == '>') {
				if (prev <= i)
					continue;
			}
			else {
				if (prev >= i)
					continue;
			}
			num[cnt + 1] = i + '0';
			visited[i] = 1;
			dfs(i, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main(void) {
	scanf("%d", &k);
	for (int i = 0; i <= k; i++) {
		max[i] = '0', min[i] = '9';
	}
	getchar();
	scanf("%[^\n]s", arr);  // 공백이 있는 문자를 입력 받을때
	for (int i = 0; i <= 9; i++) {
		num[0] = i + '0';
		visited[i] = 1;
		dfs(i, 0);
		visited[i] = 0;
	}
	printf("%s\n%s", max, min);
}