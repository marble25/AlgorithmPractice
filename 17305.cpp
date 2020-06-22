//
// Created by marble on 20. 6. 22..
//

// 그렇게 어렵지 않았는데 구현에서 왜 이렇게 틀렸는지 모르겠다.
// 단순히 break만 넣으면 된다고 생각했는데, 그게 아니고 최소 개념을 적용해야 했던 문제였다.
// 정작 greedy 알고리즘은 쉽게 만들어 놓고, 구현에서 틀리다니 어이가 없다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int n, w;
vector<long long> candy1, candy2;
long long sum1[250005] = {0}, sum2[250005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> w;

    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        if(x == 3) candy1.push_back(y); // 3이면 candy1에 push
        else candy2.push_back(y); // 5이면 candy2에 push
    }

    sort(candy1.begin(), candy1.end(), greater<>()); // 오름차순 정렬
    sort(candy2.begin(), candy2.end(), greater<>()); // 오름차순 정렬

    int c1 = candy1.size(), c2 = candy2.size();
    for(int i=1;i<=c1;i++) { // max 구간합을 구해놓음
        sum1[i] = sum1[i-1] + candy1[i-1];
    }

    for(int i=1;i<=c2;i++) { // max 구간합을 구해놓음
        sum2[i] = sum2[i-1] + candy2[i-1];
    }

    long long ans = 0;
    for(int i=0;i<=w/3;i++) { // 3 캔디의 개수
        int j = (w-i*3) / 5; // 5 캔디의 개수
        long long temp = 0;
        temp += sum1[min(i, c1)]; // 3 캔디를 담아봄
        temp += sum2[min(j, c2)]; // 5 캔디를 담아봄
        ans = max(ans, temp);
    }
    cout << ans;

    return 0;
}