//
// Created by marble on 20. 11. 18..
//

// 아직도 세그먼트 트리에 익숙하지 않은 것 같다.
// 더 연습해봐야겠다.

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
int arr[100005];

int init(vector<int> &tree, int node, int start, int end) {
    if(start == end) {
        return tree[node] = arr[start];
    } else {
        int left = init(tree, node*2, start, (start+end)/2);
        int right = init(tree, node*2+1, (start+end)/2+1, end);
        return tree[node] = min(left, right);
    }
}

int get_value(vector<int> &tree, int node, int left, int right, int start, int end) {
    if(left > end || right < start) {
        return 1987654321;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }

    int l = get_value(tree, node*2, left, right, start, (start+end)/2);
    int r = get_value(tree, node*2+1, left, right, (start+end)/2+1, end);
    return min(l, r);
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
    vector<int> tree(size);

    init(tree, 1, 0, n-1);
    for(int i=0;i<m;i++) {
        int l, r;
        cin >> l >> r;
        int ans = get_value(tree, 1, l-1, r-1, 0, n-1);
        cout << ans << "\n";
    }

    return 0;
}