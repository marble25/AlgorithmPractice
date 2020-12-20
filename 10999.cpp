//
// Created by marble on 20. 12. 20..
//

// segment 트리의 변형인 lazy propagation을 적용
// 새로운 개념 배우기 + segment tree 복습
// 아직 segment 트리를 혼자 짜는거는 어렵다

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

typedef struct {
    long long value;
    long long lazy = 0;
} Tree;

int n, m, k;
long long arr[1000005];
Tree segtree[3000000];

long long init(int node, int start, int end) {
    if(start == end) {
        return segtree[node].value = arr[start];
    }

    long long left = init(node*2, start, (start+end)/2);
    long long right = init(node*2+1, (start+end)/2+1, end);
    return segtree[node].value = left + right;
}

void update(int node, int left, int right, int start, int end, long long value) {
    if(segtree[node].lazy != 0) { // lazy가 있으면 lazy를 아래 노드에 업데이트 + value에 더해줌
        segtree[node].value += (end-start+1) * segtree[node].lazy;
        if(start != end) {
            segtree[node*2].lazy += segtree[node].lazy;
            segtree[node*2+1].lazy += segtree[node].lazy;
        }

        segtree[node].lazy = 0;
    }

    if(left > end || right < start) {
        return;
    }

    if(left <= start && end <= right) { // 사이의 값이면 해당 value 업데이트 + lazy를 아래 노드에 업데이트
        segtree[node].value += (end-start+1)*value;
        if(start != end) {
            segtree[node*2].lazy += value;
            segtree[node*2+1].lazy += value;
        }

        return;
    }

    update(node*2, left, right, start, (start+end)/2, value);
    update(node*2+1, left, right, (start+end)/2+1, end, value);

    segtree[node].value = segtree[node*2].value + segtree[node*2+1].value;
}

long long get(int node, int left, int right, int start, int end) {
    if(segtree[node].lazy != 0) { // lazy가 있으면 lazy를 아래 노드에 업데이트 + value에 더해줌
        segtree[node].value += (end-start+1) * segtree[node].lazy;
        if(start != end) {
            segtree[node*2].lazy += segtree[node].lazy;
            segtree[node*2+1].lazy += segtree[node].lazy;
        }

        segtree[node].lazy = 0;
    }


    if(left > end || right < start) {
        return 0;
    }

    if(left <= start && end <= right) {
        return segtree[node].value;
    }

    long long l = get(node*2, left, right, start, (start+end)/2);
    long long r = get(node*2+1, left, right, (start+end)/2+1, end);
    return l + r;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    init(1, 1, n);

    for(int i=0;i<m+k;i++) {
        long long a, b, c, d;
        cin >> a >> b >> c;
        if(a == 1) {
            cin >> d;

            update(1, b, c, 1, n, d);
        } else {
            cout << get(1, b, c, 1, n) << "\n";
        }
    }


    return 0;
}