//
// Created by marble on 20. 12. 28..
//

// fill 함수 쓰다가 엄청 틀렸다
// 그것 외에도 상당히 까다로운 Segment Tree 문제

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

int T;
int n, m;
int sz;
long long tree[800005], collection[200005];
// (n+m) 크기의 tree에 책의 위치가 0, 1로 표현되어 있어 부분합을 구하는 문제로 생각
// 기존에 n개 있고, m번의 연산을 통해 최대 m칸 앞으로 올 수 있음
// collection에 현재 책의 위치를 담아놓음

long long init(int node, int start, int end) {
    if(start == end) {
        if(start >= m) {
            collection[start-m] = start;
            tree[node] = 1;
        }

        return tree[node];
    }

    long long l = init(node*2, start, (start+end)/2);
    long long r = init(node*2+1, (start+end)/2+1, end);
    return tree[node] = l + r;
}

long long query(int node, int start, int end, int left, int right) {
    if(right < start || end < left) {
        return 0;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }

    long long l = query(node*2, start, (start+end)/2, left, right);
    long long r = query(node*2+1, (start+end)/2+1, end, left, right);
    return l + r;
}

long long update(int node, int start, int end, int idx, int val) {
    if(idx < start || end < idx) {
        return tree[node];
    }

    if(start == end) {
        return tree[node] = val;
    }

    long long l = update(node*2, start, (start+end)/2, idx, val);
    long long r = update(node*2+1, (start+end)/2+1, end, idx, val);
    return tree[node] = l + r;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while(T--) {
        cin >> n >> m;
        sz = (n+m);

        fill(tree, tree+sizeof(tree)/sizeof(long long), 0);
        fill(collection, collection+sizeof(char )/sizeof(long long), 0);

        int idx = m - 1;
        init(1, 0, sz-1); // 기존 값을 넣어 놓음
        for(int i=0;i<m;i++) {
            int x;
            cin >> x;

            cout << query(1, 0, sz-1, 0, collection[x-1]-1) << " "; // 0부터 현재 있는 책 위치까지의 부분합 구함(현재 위치보다 위에 있는)
            update(1, 0, sz-1, collection[x-1], 0); // 현재 책 위치를 0으로 설정(뺀다)
            collection[x-1] = idx; // collection에도 현재 위치 변경
            update(1, 0, sz-1, collection[x-1], 1); // 바뀐 책 위치를 1로 설정(넣는다)
            idx--; // 책 가장 높은 곳 변경
        }
        cout << "\n";
    }

    return 0;
}