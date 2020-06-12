//
// Created by marble on 20. 6. 13..
//

// 전에는 쉽지 않았을 텐데 크루스칼 알고리즘을 잘 익혀서 쉽게 풀었던 문제

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

int n, m;
int price[1005][1005] = {0};

int rnk[1005] = {0};
int p[1005] = {0};
int re = 0;

void init() { // 자신의 부모를 자기 자신으로 설정하고 rnk도 1로 설정해줌
    for(int i=1;i<=n;i++) {
        rnk[i] = 1;
        p[i] = i;
    }
}

int get_root(int x) { // root를 찾음
    int y = p[x];
    while(y != p[y]) {
        y = p[y];
    }
    p[x] = y; // x의 parent를 y로 다이렉트로 연결
    return y;
}

bool merge(int x, int y) {
    x = get_root(x);
    y = get_root(y);

    if(x == y) { // x와 y의 부모가 같으면 이미 같은 그룹에 있으므로 더이상 처리 안함
        return false;
    } else {
        if(rnk[x] < rnk[y]) { // 랭크가 더 작은 쪽이 큰 쪽의 아래로 들어감
            p[x] = y;
        } else {
            p[y] = x;
        }

        if(rnk[x] == rnk[y]) { // 랭크가 같으면 루트의 랭크를 증가
            rnk[x]++;
        }

        return true;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i=0;i<m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x == y) continue;

        if(price[x][y] == 0 || price[x][y] > z) { // 기존 값보다 더 작은 값이 들어왔을 때 변경해줌
            price[x][y] = z;
            price[y][x] = z;

            pq.push({-z, {x, y}});
        }
    }
    init();

    while(!pq.empty()) {
        int z = -pq.top().first;
        int x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();

        if(merge(x, y)) { // 기존에 없던 노드들이라면
            re += z;
        }
    }
    cout << re;
    return 0;
}