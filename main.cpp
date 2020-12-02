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
    point p1;
    point p2;
    int weight;
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

int distance(point p1, point p2) {
    int x_dis = abs(p1.x - p2.x);
    int y_dis = abs(p1.y - p2.y);
    int z_dis = abs(p1.z - p2.z);

    return min(x_dis, min(y_dis, z_dis));
}

int find(int node) {
    int cur = parent[node];
    int past = node;
    while(cur != past) {
        past = cur;
        cur = parent[cur];
    }

    return parent[node] = cur;
}

void merge(edge e1) {
    int num1 = find(e1.p1.num);
    int num2 = find(e1.p2.num);

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

    sort(p.begin(), p.end(), compX);

    for(int i=0;i<n-1;i++) {
        int dis = distance(p[i], p[i+1]);
        e.push_back({p[i], p[i+1], dis});
    }

    sort(p.begin(), p.end(), compY);

    for(int i=0;i<n-1;i++) {
        int dis = distance(p[i], p[i+1]);
        e.push_back({p[i], p[i+1], dis});
    }

    sort(p.begin(), p.end(), compZ);

    for(int i=0;i<n-1;i++) {
        int dis = distance(p[i], p[i+1]);
        e.push_back({p[i], p[i+1], dis});
    }

    sort(e.begin(), e.end(), compDis);

    for(int i=0;i<n;i++) {
        parent[i] = i;
        rnk[i] = 1;
    }

    for(int i=0;i<e.size();i++) {
        merge(e[i]);
        if(cnt == n) break;
    }

    cout << ans;

    return 0;
}