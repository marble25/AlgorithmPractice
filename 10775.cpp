//
// Created by marble on 20. 11. 30..
//

// 단순 greedy 방식으로 생각을 해보다가 도저히 모르겠어서 방법을 참고한 문제

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

int g;
int p;

int parent[100001];
int gi[100001];

int find(int x) { // 루트 노드를 찾는 과정
    int cur = x;
    while(x != parent[x]) {
        x = parent[x];
    }

    parent[cur] = x;
    return x;
}

void merge(int x, int y) { // 현재 노드(y)에 비행기 할당
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int ans = 0;
    cin >> g >> p;

    for(int i=0;i<=g;i++) {
        parent[i] = i;
    }

    for(int i=0;i<p;i++) {
        cin >> gi[i];
    }

    for(int i=0;i<p;i++) {
        int k = find(gi[i]); // 입력의 루트 노드
        if(k == 0) break;
        merge(k-1, k); // 앞에 노드와 합치기
        ans++;
    }

    cout << ans;

    return 0;
}