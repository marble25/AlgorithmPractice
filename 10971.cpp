//
// Created by marble on 20. 9. 25..
//

// 간단하게 Permutation으로 풀어보았다가 시간을 줄여보려고 많은 시도를 했던 문제
// DFS로 푸니 훨씬 시간이 많이 줄었다.

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

int n;
int arr[10][10] = {0};
int ans = 987654321;

int start = 0;
int visited[10] = {0};

void dfs(int x, int stage, int cost) {
    if(cost > ans) return; // cost가 더 커지는 경우를 가지치기
    if(stage == n-1) {
        if(arr[x][start] == 0) return; // 끝이 연결이 되어 있지 않으면 무시
        ans = min(ans, cost + arr[x][start]); // 비용 업데이트
        return;
    }

    for(int i=0;i<n;i++) {
        if(visited[i] == 0 && arr[x][i] != 0) { // 연결되어 있고, 방문하지 않았으면
            visited[i] = 1;
            dfs(i, stage+1, cost+arr[x][i]); // 다음 stage
            visited[i] = 0;
        }
    }
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

    visited[0] = 1; // 어차피 0으로 돌아가므로(싸이클이므로) 0에서 시작해도 상관 없다
    dfs(0, 0, 0);

    cout << ans;

    return 0;
}