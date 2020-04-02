//
// Created by marble on 20. 4. 2..
//

// 질문에 제시된 아이디어를 참고해서 풀었다.
// Backtracking의 기본 문제 같은데 시간 줄이는 테크닉이 익숙하지 않은 것 같다.
// 연습해야겠다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int n;
int arr[12][12];
int right_top[22] = {0};
int right_bot[22] = {0};
int max_val1 = 0;
int max_val2 = 0;

void bishop(int x, int y, int len) {
    if(x >= n) {
        if(y%2 == 0) { // 검은 색 칸일 때
            max_val1 = max(len, max_val1);
        } else { // 흰색 칸일 때
            max_val2 = max(len, max_val2);
        }

        return;
    }
    if(y >= n) {
        bishop(x+1, (1 - (y % 2)), len); // 홀수였다면 짝수로, 짝수였다면 홀수로 바뀐다.
        return;
    }
    if(arr[x][y] == 1) {
        int r_b_idx = y-x + (n-1); // 오른쪽 아래로 향하는 대각선
        int r_t_idx = y+x; // 오른쪽 위로 향하는 대각선
        if(right_top[r_t_idx] == 0 && right_bot[r_b_idx] == 0) { // 두 대각선 모두 속하지 않았다면 채워넣는 경우
            right_top[r_t_idx] = 1;
            right_bot[r_b_idx] = 1;
            bishop(x, y+2, len+1); // 두칸 뒤를 탐색(len 더함)
            right_top[r_t_idx] = 0;
            right_bot[r_b_idx] = 0;
        }

    }
    bishop(x, y+2, len); // 이 칸을 방문하지 않는 경우
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    // 중요한 테크닉은 검은색 칸과 흰색 칸을 분리해서 더해주는 것이다.
    bishop(0, 0, 0);
    bishop(0, 1, 0);
    cout << max_val1+max_val2;

    return 0;
}