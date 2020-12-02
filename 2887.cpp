//
// Created by marble on 20. 12. 2..
//

// MST를 오랜만에 풀어봐서 감회가 새롭다.
// 크루스칼 및 프림 알고리즘을 계속 연습해야겠다.

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

typedef struct Point {
    int num;
    int x;
    int y;
    int z;
} point;

typedef struct Edge {
    int n1;
    int n2;
    int weight;
    bool operator < (const Edge& other) const { return weight < other.weight; }
} edge;

int n;
vector<point> p;
vector<edge> e;

int rnk[100001] = {0};
int parent[100001] = {0};

int ans = 0;
int cnt = 0;

bool compDis(edge e1, edge e2) {
    return e1.weight < e2.weight;
}

bool compX(point p1, point p2) {
    return p1.x < p2.x;
}

bool compY(point p1, point p2) {
    return p1.y < p2.y;
}

bool compZ(point p1, point p2) {
    return p1.z < p2.z;
}

// 크루스칼은 union & find 방식으로 푸는 것이다.

int find(int node) {
    int cur = node;
    while(cur != parent[cur]) {
        cur = parent[cur];
    }

    return parent[node] = cur;
}

void merge(edge e1) {
    int num1 = find(e1.n1);
    int num2 = find(e1.n2);

    if(num1 != num2) {
        if(rnk[num1] < rnk[num2]) {
            parent[num1] = num2;
        } else if(rnk[num1] > rnk[num2]) {
            parent[num2] = num1;
        } else {
            parent[num1] = num2;
            rnk[num2]++;
        }
        ans += e1.weight;
        cnt ++;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y, z;
        cin >> x >> y >> z;

        p.push_back({i, x, y, z});
    }

    // x, y, z좌표로 정렬해서 인접한 정점을 edge로 추가(이 것보다 더 가까운 정점은 존재하지 않음)

    sort(p.begin(), p.end(), compX);

    for(int i=0;i<n-1;i++) {
        e.push_back({p[i].num, p[i+1].num, abs(p[i].x - p[i+1].x)});
    }

    sort(p.begin(), p.end(), compY);

    for(int i=0;i<n-1;i++) {
        e.push_back({p[i].num, p[i+1].num, abs(p[i].y - p[i+1].y)});
    }

    sort(p.begin(), p.end(), compZ);

    for(int i=0;i<n-1;i++) {
        e.push_back({p[i].num, p[i+1].num, abs(p[i].z - p[i+1].z)});
    }

    sort(e.begin(), e.end(), compDis); // distance를 기준으로 정렬

    for(int i=0;i<n;i++) {
        parent[i] = i;
    }

    for(int i=0;;i++) { // 짧은 것부터 추가 가능하면 추가
        merge(e[i]);
        if(cnt == n-1) break;
    }

    cout << ans;

    return 0;
}