#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool broken[10];
int n, m, s;

// 이동하려는 채널으로 갈때 리모컨 클릭 횟수
int clickNum(int n) {
	if (n == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	// 몇번 눌렀는지 판단을 위해 초기화
	// 나머지 연산을 통해 한자리씩 고장났는지 확인, 고장이 아니라면 리모컨 클릭 횟수 증가
	int len = 0; 
	while (n > 0) {
		if (broken[n % 10]) return 0;
		n = n / 10;
		len += 1;
	}
	return len;
}

int main() {
	scanf("%d", &n); 
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &s);
		//고장이면 true
		broken[s] = true; 
	}

	//처음시작 위치 100, n-100의 절대값을 result에 저장(몇번 눌러야 이동가능한지).
	int result = abs(n - 100); 
	
	for (int i = 0; i <= 1000000; i++) { //0번을 눌렀을때 이동해야되는 수 ~1000000을 눌렀을때 이동해야되는수
		
		int c = i;
		int len = clickNum(c); //숫자를 누를 때 눌러야되는 수. 만약 고장났다면 return 0
		if (len > 0) {
			int press = abs(c - n); // 내가 누른 번호에서 이동하려는 채널까지 눌러야하는 횟수
			if (result > press + len) // press+len한게 result보다 작으면
				result = press + len; // result를 press+len으로 초기화해준다
		} 
	}

	printf("%d", result);

	return 0;
}