//
// Created by marble on 20. 11. 2..
//

// 세그먼트 트리의 개념에 대해 다시 짚고 넘어갈 수 있었다.
// 세그먼트 트리의 기초적인 좋은 문제

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

int n, m, k;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) { // 값을 할당
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) { // 해당 index가 속해있는 모든 노드를 업데이트
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) { // 해당 범위가 포함되는 노드의 값을 합산
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    m += k;

    init(a, tree, 1, 0, n-1); // 트리의 값을 default 값으로 세팅
    while(m--) {
        long long t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (t1 == 1) { // update
            t2-=1;
            long long diff = t3-a[t2];
            a[t2] = t3;
            update(tree, 1, 0, n-1, t2, diff);
        } else if (t1 == 2) { // sum 구하기
            cout << sum(tree, 1, 0, n-1, t2-1, t3-1) << "\n";
        }
    }

    return 0;
}