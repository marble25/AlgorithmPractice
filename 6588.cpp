//
// Created by marble on 20. 4. 5..
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

const int MAX = 1000000;
int num[1000005];
vector<int> p;

void precalc() {
    for(int i=2;i<=MAX;i++) {
        if(num[i] == 0) { // 에라토스테네스의 체를 이용, 한번도 체크하지 않은 수라면 소수
            if(i == 2) { // 2를 제외
                num[i] = 2;
            } else {
                p.push_back(i);
                num[i] = 1;
            }
            for(int j=2;i*j<=MAX;j++) { // 소수의 배수를 모두 합성수로 체크
                num[i*j] = 2;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    precalc();

    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        for(auto & it : p) {
            if(num[n-it] == 1) { // n-it도 소수면 출력
                cout << n << " = " << it << " + " << n - it << '\n';
                break;
            }
        }
    }

    return 0;
}