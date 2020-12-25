//
// Created by marble on 20. 12. 25..
//

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
int n;
vector<long long> tree, arr;
int h[1000010];

void update(int node, int start, int end, int idx, int diff) {
    if(idx < start || idx > end) return;
    tree[node] += diff;
    if(start != end) {
        update(node*2, start, (start+end)/2, idx, diff);
        update(node*2+1, (start+end)/2+1, end, idx, diff);
    }
}

long long sum(int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return 0;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }

    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    arr = vector<long long>(n+10);
    tree = vector<long long>(4*n+10);

    for(int i=1;i<=n;i++) {
        long long t;
        cin >> t;
        h[t] = i;
    }

    for(int i=1;i<=n;i++) {
        long long t;
        cin >> t;
        arr[i] = h[t];
    }

    long long ans = 0;

    for(int i=1;i<=n;i++) {
        int x = arr[i];
        ans += sum(1, 1, n, x+1, n);
        update(1, 1, n, x, 1);
    }

    cout << ans;
    return 0;
}