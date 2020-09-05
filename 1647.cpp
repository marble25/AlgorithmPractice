//
// Created by marble on 20. 9. 5..
//

// MST를 크루스칼 알고리즘을 적용해서 간단히 풀어낸 문제
// 두 개의 마을로 어떻게 분할하는게 최적일까 생각하다가 MST를 만들고 가장 큰 간선을 자르면 2개의 마을이 나뉜다는 것을 깨달음

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

int n, m;
vector<pair<int, pair<int, int>>> v;

int rnk[100005] = {0};
int parent[100005] = {0};

int get_root(int x) { // 루트 노드를 구함
    int org = x;
    int y = parent[x];
    while(y != -1) { // 루트 노드(부모가 -1이 나올 때)까지 올라감
        x = y;
        y = parent[y];
    }

    if(org != x) parent[org] = x; // 자기 자신이 아니면 parent를 루트로 재설정
    return x;
}

void merge(int x, int y) {
    x = get_root(x);
    y = get_root(y);

    if(x == y) { // 같은 그룹이면 할 필요 없음
        return;
    }

    if(rnk[x] < rnk[y]) { // x의 높이가 y의 높이보다 작으면
        parent[x] = y; // x가 y 밑으로 들어감
    } else { // 반대면
        parent[y] = x; // y가 x 밑으로 들어감
    }

    if(rnk[x] == rnk[y]) { // 높이가 같으면 x 높이 추가
        rnk[x]++;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({z, {x, y}});
    }

    sort(v.begin(), v.end());

    for(int i=0;i<=n;i++) { // 랭크와 parent 초기화
        rnk[i] = 1;
        parent[i] = -1;
    }

    int total = 0;
    int big = 0;
    int cnt = 0;
    for(int i=0;i<m;i++) {
        int cost = v[i].first, x = v[i].second.first, y = v[i].second.second;
        int x_root = get_root(x), y_root = get_root(y);
        if(x_root == -1 || y_root == -1) { // 둘중 하나라도 그룹에 포함되지 않은 것이 있다면 merge
            merge(x_root, y_root);
            total += cost;
            big = max(big, cost);
        } else if(x_root != y_root) { // 둘의 조상이 같지 않으면(둘이 다른 그룹이면) merge
            merge(x_root, y_root);
            total += cost;
            big = max(big, cost);
        }
    }
    cout << total - big; // 전체 비용 합에서 가장 긴 간선을 뺌
    return 0;
}