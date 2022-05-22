/*
    강의 : 브루트 포스 
    모든 경우의 수 
    1. for문
    2. 순열
    3. 재귀 함수
    4. 비트 마스크
*/

#include <iostream>
using namespace std;
/*
    1. 이동할 채널 C를 정한다.
    0에서 100만
    2. C에 포함되어이쓴 숫자 중에 고장난 버튼이 있는지 확인 한다. 
    이동할 채널 -> 고장난 버튼을 구하는 로직을 하는 이유는 좀 더 쉽기 때문??
    . 수를 문자열로 바꾼 다음 한 글자씩 검사
    . 수를 10으로 계속해서 나누면서 하나씩 검사하는 방법
    3. +- 몇번 눌러야 하는지
*/

bool broken[10]; // 버튼이 고장나 있으면 true, 아니면 false

// 불가능 하면 0 가능 하면 버튼을 눌러야 하는 횟수 return 수의 자릿수
int chck(int c){    

    // c가 0 이거고 고장난 버튼이면 불가능
    c == 0 && broken[0] ? 0 : 1;

    int len = 0;
    while (c > 0)
    {
        broken[c % 10] && 0;
        
        len += 1;
        c /= 10;
    }
    // 자릿수 반환 
    return len;
}

int main(){
    // cin 입력 
    int n,m;
    cin >> n;    
    cin >> m;

    // 고장난 부분 체크 
    for(int i=0; i< m; i++){
        int x;
        cin >> x;
        broken[x] = true;
    }

    // 절대 값으로 대체 하여서 if문 제거
    int ans = abs(n-100);
    
    for(int i = 0; i <= 1000000; i++){
        int len = chck(i);

        if(len > 0){
            // 절대 값으로 대체 하여서 if문 제거
            int press = abs(i - n);
            
            if(ans > len + press){
                ans = len + press;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}