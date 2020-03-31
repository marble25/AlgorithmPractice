//
// Created by marble on 20. 3. 31..
//

// 먼저 맞추고 시간복잡도도 계산해 본 문제
// 기존에 1.2초 나오던 것을 0.03초로 개선

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

int inorder[100000], inidx[100000];
int postorder[100000];

vector<int> v;

void preorder(int in_l, int in_r, int pos_l, int pos_r) {
    if(in_l > in_r) {
        return;
    } else if(in_l == in_r) {
        v.push_back(inorder[in_r]);
        return;
    }
    int root = postorder[pos_r];
    int in_mid = inidx[root];

    int left_len = in_mid - in_l - 1;
    v.push_back(root);
    preorder(in_l, in_mid-1, pos_l, pos_l + left_len);
    preorder(in_mid+1, in_r, pos_l + left_len + 1,pos_r-1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> inorder[i];
        inidx[inorder[i]] = i;
    }

    for(int i=0;i<n;i++) {
        cin >> postorder[i];
    }

    v.reserve(n+5);

    preorder(0, n-1, 0, n-1);
    for(int & it: v) {
        cout << it << ' ';
    }
    return 0;
}