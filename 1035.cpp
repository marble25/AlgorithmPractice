//
// Created by marble on 20. 9. 9..
//

// 뭔가 아쉬움이 남는 문제
// 순열과 Brute Force를 이용했지만, 필요 없는 경우를 너무 많이 센 듯한 느낌

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <string.h>
using namespace std;

pair<int, int> point[5];
pair<int, int> target[5];

int cnt = 0;
int checked[5][5] = {0};
int ans = 987654321;

char mp[6][6];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void calc_dist() {
    vector<int> v(cnt);

    for(int i=0;i<cnt;i++) {
        v[i] = i;
    }

    do { // 가능한 모든 경우의 수를 순열을 통해 알아냄
        int temp = 0;
        for(int i=0;i<cnt;i++) {
            temp += abs(point[i].first - target[v[i]].first) + abs(point[i].second - target[v[i]].second);
        }
        ans = min(ans, temp);
    } while(next_permutation(v.begin(), v.end()));


}

void select(int stage) {
    if(stage == cnt) {
        calc_dist();
        return;
    }
    for(int past=0;past<stage;past++) { // 이전 점에 바로 붙을 수 있도록 설정
        for(int i=0;i<4;i++) {
            int mx = target[past].first + dx[i], my = target[past].second + dy[i];
            if(mx < 0 || my < 0 || mx >= 5 || my >= 5) continue;
            if(checked[mx][my] == 1) continue;

            target[stage] = {mx, my};
            checked[mx][my] = 1;
            select(stage+1);
            checked[mx][my] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<5;i++) {
        cin >> mp[i];
        for(int j=0;j<5;j++) {
            if(mp[i][j] == '*') {
                point[cnt++] = {i, j};
            }
        }
    }

    memset(checked, 0, sizeof(checked));

    if(cnt == 1) { // 1개이면 0 출력 후 종료
        cout << 0;
        return 0;
    }

    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            target[0] = {i, j}; // 시작점 설정
            checked[i][j] = 1;
            select(1); // 다음 단계로 넘어감
            checked[i][j] = 0;
        }
    }

    cout << ans;
    return 0;
}