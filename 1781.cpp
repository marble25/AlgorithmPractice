// 한번에 딱 맞을 수 있어서 기분이 좋다.
// Greedy 문제에 parent 개념을 써서 시간초과 안나게 조절했다.

//
// Created by marble on 20. 6. 16..
//

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
vector<pair<int, int>> assign; // 과제를 입력받아서 정렬해주는 벡터
int parent[200005] = {0}; // 과제의 부모를 저장해주는 배열

int find_root(int x) { // 이 과제의 deadline까지 중 안 채워진 것을 찾아주는 함수(root가 바로 그 값)
    int y = parent[x];
    while(y != parent[y]) {
        y = parent[y];
    }
    parent[x] = y;
    return y;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        assign.push_back({y, x});
    }
    sort(assign.begin(), assign.end(), greater<>()); // 큰 순서대로 정렬

    for(int i=1;i<=n;i++) { // parent를 i로 초기화
        parent[i] = i;
    }

    int ans = 0;

    for(auto &it:assign) {
        int cup = it.first, dead = it.second;

        int root = find_root(dead);
        if(root != 0) { // deadline까지 중의 수 중에서 값이 채워질 수 있는 수가 있다면
            ans += cup; // 답에다 더해줌
            parent[root] = find_root(root-1); // root의 parent를 바꿔줌
        }
    }

    cout << ans;

    return 0;
}