//
// Created by marble on 20. 6. 29..
//

// 진짜 짜증났던 문제
// 왜 push를 int로 정의해서 계속 틀렸는지...
// 계속 TLE 뜨고, 메모리 오류 뜨고 그랬다.
// 문제 자체는 그렇게 어렵지는 않았다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <string.h>
using namespace std;

char arr[11][11];
char temp[11][11];

void push(int x, int y) { // x, y 주변의 스위치를 모두 바꿔준다.
    if(x-1 >= 0) arr[x-1][y] = (arr[x-1][y] == '#' ? 'O' : '#');
    if(x+1 < 10) arr[x+1][y] = (arr[x+1][y] == '#' ? 'O' : '#');
    if(y-1 >= 0) arr[x][y-1] = (arr[x][y-1] == '#' ? 'O' : '#');
    if(y+1 < 10) arr[x][y+1] = (arr[x][y+1] == '#' ? 'O' : '#');
    arr[x][y] = (arr[x][y] == '#' ? 'O' : '#');
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<10;i++) { // temp에 입력받기
        for(int j=0;j<10;j++) {
            cin >> temp[i][j];
        }
    }

    int ans = 987654321;

    for(int i=0;i<(1 << 10);i++) { // 스위치를 시작할 수 있는 모든 경우의 수를 따져봄
        for(int j=0;j<10;j++) { // temp값(원래 값)을 arr에 복사
            for(int k=0;k<10;k++) {
                arr[j][k] = temp[j][k];
            }
        }

        int cnt = 0;

        for(int j=0;j<10;j++) {
            if(i & (1 << j)) { // j번째 스위치가 켜져 있으면 push해서 꺼줌
                push(0, j);
                cnt++;
            }
        }

        for(int j=1;j<10;j++) { // 그다음 라인부터는 위에 스위치가 켜져 있으면 꺼준다.
            for(int k=0;k<10;k++) {
                if(arr[j-1][k] == 'O') {
                    push(j, k);
                    cnt++;
                }
            }
        }

        bool flag = false;
        for(int j=0;j<10;j++) { // 마지막 라인에서 모든 스위치가 꺼져 있으면 정답 중 하나
            if(arr[9][j] == 'O') {
                flag = true;
                break;
            }
        }

        if(!flag) {
            ans = min(ans, cnt);
        }
    }
    if(ans == 987654321) cout << -1;
    else cout << ans;

    return 0;
}