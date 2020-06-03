//
// Created by marble on 20. 6. 4..
//

// 간단하게 dfs로 맞은 문제
// cycle 감지가 생각대로 되지 않아서 약간 헤맸던 문제

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
int arr[105];
int visited[105] = {0};
int ans[105] = {0};

void put_ans(int x) {
    int y = arr[x]; // x에서 가는 값을 y로
    ans[x] = 1;
    while(y != x) { // x와 같은 값이 될때까지 arr 타보기
        ans[y] = 1;
        y = arr[y];
    }
}

void dfs(int x) { // cycle이 있을 때까지
    if(visited[x] == 1) { // cycle이 있다면
        put_ans(x);
        visited[x] = 0;
        return;
    }
    visited[x] = 1;
    dfs(arr[x]);
    visited[x] = 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    for(int i=1;i<=n;i++) { // 모든 정점에서 탐색 돌려봄
        dfs(i);
    }

    int cnt = 0;
    for(int i=1;i<=n;i++) { // cycle 존재하는 개수 합
        cnt += ans[i];
    }

    cout << cnt << "\n";
    for(int i=1;i<=n;i++) {
        if(ans[i] != 0) cout << i << "\n";
    }

    return 0;
}