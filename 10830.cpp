//
// Created by marble on 20. 3. 23..
//

// 간단한 분할 정복 문제였는데 C++에 익숙하지 않아서 많이 헤맸다.
// 근데 풀어보고 나니 다른 곳 문제였네???

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n;

vector<vector<int>> multiply (vector<vector<int>> a1, vector<vector<int>> a2) { // n*n 행렬 2개를 곱하는 방법
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                ans[i][j] = (ans[i][j] + a1[i][k] * a2[k][j]) % 1000;
            }
        }
    }
    return ans;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long b;
    cin >> n >> b;

    vector<vector<int>> in(n, vector<int>(n));
    vector<vector<int>> re(n, vector<int>(n));

    for(int i=0;i<n;i++) {
        re[i][i] = 1; // result를 단위행렬로 초기화
        for(int j=0;j<n;j++) {
            cin >> in[i][j];
        }
    }

    // b를 이진수로 바꾼 후 그에 해당하는 행렬을 곱하는 것으로 문제를 변형할 수 있다.
    // 예를 들어 x^10 = 0 * x^1 + 1 * x^2 + 0 * x^4 + 1 * x^8
    while(b > 0) {
        if(b % 2 == 1) { // 해당하는 이진수가 1이면 re에 곱해줌
            re = multiply(re, in);
        }
        in = multiply(in, in); // in은 x^1, x^2, x^4 이런 식으로 계속 거듭제곱으로 올라감
        b /= 2;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << re[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}