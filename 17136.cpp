// 시간 초과가 나올 것 같은 풀이지만 시간초과가 나오지 않았다.
// Backtracking에서 가지치기를 한 효과인가?
// 시간복잡도가 어떻게 나오는지 궁금하다.

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

int mp[10][10];
int paper_left[6] = {0};
int ans = INT32_MAX;

bool can_attach(int x, int y, int sz) { // 해당 사이즈로 색종이를 붙일 수 있는지 확인하는 함수
    for(int i=x;i<x+sz;i++) {
        for(int j=y;j<y+sz;j++) {
            if(mp[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int get_paper_left() { // 남은 색종이 갯수 반환해주는 함수
    int ret = 0;
    for(int i=1;i<=5;i++) {
        ret += paper_left[i];
    }
    return ret;
}

void update_paper(int x, int y, int sz, int is_paper) { // 해당 area를 0 혹은 1로 채워주는 함수
    for(int i=x;i<x+sz;i++) {
        for(int j=y;j<y+sz;j++) {
            mp[i][j] = is_paper;
        }
    }
}

void f(int x, int y) {
    if(x == 10) { // 끝에 도달했으면 정답값 refresh
        ans = min(ans, 25-get_paper_left());
        return;
    }
    if(y == 10) {
        f(x+1, 0);
        return;
    }
    if(mp[x][y] == 0) { // 0이면 넘어감
        f(x, y+1);
        return;
    }

    bool is_covered = false;
    for(int i=5;i>=1;i--) { // 5부터 돌면서 모든 경우를 다 해봄
        if(x+i > 10 || y+i > 10) continue;

        if(paper_left[i] > 0 && can_attach(x, y, i)) { // i번째 종이가 1개 이상 남아 있고, 붙일 수 있으면
            is_covered = true;

            paper_left[i] --; // paper 갯수 빼기
            update_paper(x, y, i, 0); // 해당 부분을 덮은 것으로 처리

            f(x, y+i);

            paper_left[i]++; // paper 갯수 원래대로
            update_paper(x, y, i, 1); // 해당 부분을 다시 채운 것으로 처리
        }
    }

    if(!is_covered) { // 이 경우에서 안채워졌으면 리턴
        return;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1;i<=5;i++) {
        paper_left[i] = 5;
    }

    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            cin >> mp[i][j];
        }
    }

    f(0, 0);
    if(ans == INT32_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}