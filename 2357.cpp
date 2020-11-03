//
// Created by marble on 20. 11. 3..
//

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

// 세그먼트 트리를 연습한다고 풀어본 문제
// 최소값 default가 10억이 넘는줄 알았는데 안넘어서 한번 틀린 문제

int n, m;
int arr[100005];

pair<int, int> init(vector<pair<int, int>> &tree, int node, int start, int end) {
    if(start == end) { // 더 이상 줄어들 수 없으면 min, max 모두 해당 값
        return tree[node] = {arr[start], arr[start]};
    } else { // 왼쪽과 오른쪽을 비교해서 min, max 세팅
        pair<int, int> left = init(tree, node*2, start, (start+end) / 2);
        pair<int, int> right = init(tree, node*2+1, (start+end)/2+1, end);
        return tree[node] = {min(left.first, right.first), max(left.second, right.second)};
    }
}

pair<int, int> get_minmax(vector<pair<int, int>> &tree, int node, int left, int right, int start, int end) {
    if(left > end || right < start) { // left와 right가 포함되지 않는 범위라면 default값 리턴
        return {1987654321, 0};
    }

    if(left <= start && end <= right) { // start와 end를 left와 right가 포함하고 있다면 해당 노드 리턴
        return tree[node];
    }

    pair<int, int> l = get_minmax(tree, node*2, left, right, start, (start+end)/2);
    pair<int, int> r = get_minmax(tree, node*2+1, left, right, (start+end)/2+1, end);
    return {min(l.first, r.first), max(l.second, r.second)}; // 왼쪽과 오른쪽 비교해서 min, max 리턴
}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int p = (int)ceil(log2(n));
    int size = (1 << (p+1));

    vector<pair<int, int>> tree(size);

    init(tree, 1, 0, n-1);

    for(int i=0;i<m;i++) {
        int l, r;
        cin >> l >> r;
        pair<int, int> ans = get_minmax(tree, 1, l-1, r-1, 0, n-1);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}