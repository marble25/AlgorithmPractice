//
// Created by marble on 20. 7. 14..
//

// 간단한 문제이다.
// 시간복잡도를 더 줄여봐야겠다.

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

int n;
int s[20][20] = {0};
int team[20] = {0};
int ans = 987654321;

int calc_score(int t) {
    int start = 0;
    int score = 0;
    while(start < n) {
        if(team[start] == t) {
            for(int i=0;i<n;i++) {
                if(team[i] == t) {
                    score += s[start][i];
                }
            }
        }
        start++;
    }
    return score;
}

void f(int stage) {
    if(stage == n) {
        int sc1 = calc_score(0); // 0 팀의 score 계산
        int sc2 = calc_score(1); // 1 팀의 score 계산
        if(sc1 != 0 && sc2 != 0) { // 둘다 0이 아니면
            ans = min(ans, abs(sc1-sc2)); // 답에 포함시킴
        }
        return;
    }

    team[stage] = 1;
    f(stage+1);
    team[stage] = 0;
    f(stage+1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> s[i][j];
        }
    }

    f(0);
    cout << ans;

    return 0;
}