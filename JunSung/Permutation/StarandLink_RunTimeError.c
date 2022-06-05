#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//모인 총 사람 
int n;
// 팀 두개 
int team1[],team2[];
// 4<= N <= 20
int arr[20][20];
// 전체 팀 
int all[20];

int ans;


int main(){
    scanf("%d",n);

    // 그림 그리는 곳 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",arr[i][j]);
        }
    }

    go(0);

    printf("%d\n", ans);
} 
// 체크 로직 
int go(int idx){
    if(idx == n/2){
        team1[n/2];
        team2[n/2];
        int t1 = 0;
        int t2 = 0;

        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                if( i == j) {
                    continue;
                }

                t1 += arr[team1[i]][team1[j]];
                t2 += arr[team2[i]][team2[j]];
            }
        }
        int diff = t1 - t2;
        if(diff < 0){
            ans = diff;
        } else{
            ans = 0;
        }
    }
    return ans;
}