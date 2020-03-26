//
// Created by marble on 20. 3. 26..
//

// dp로 풀어보려 했으나 dp로는 쉽지 않아 보이는 문제

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true) {
        int n;
        cin >> n;

        if(n == 0) break;
        int cnt = 0;

        for(int i=1;i<=sqrt(n);i++) {
            if(i*i == n) { // i로만 구성
                cnt++;
                break;
            }
            for(int j=i;j<=sqrt(n);j++) {
                if(i*i+j*j > n) break; // 범위 넘어가면 cut
                if(i*i+j*j == n) { // i와 j로 구성
                    cnt++;
                    break;
                }
                for(int k=j;k<=sqrt(n);k++) {
                    if(i*i+j*j+k*k>n) break; // 범위 넘어가면 cut
                    if(i*i+j*j+k*k == n) { // i, j, k로 구성
                        cnt++;
                        break;
                    }
                    double s = n - (i*i+j*j+k*k);
                    if(sqrt(s) >= k && sqrt(s) == (int)sqrt(s)) { // 지금껏 나온 수들보다 크고 n에서 나머지 수들 합 뺀 것이 제곱수일 때
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}