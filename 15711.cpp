//
// Created by marble on 20. 9. 13..
//

// 골드바흐의 추측 등 다양한 정수론 이론을 사용해서 풀어보았다.
// 처음에는 당황했지만, 이내 차분히 문제를 풀 수 있었다.
// 소스코드의 실수로 여러번 틀렸던 것이 아쉽다.

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

int T;
long long a, b;
bool checked[2000005] = {false};
vector<long long> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(long long i=2;i<=2000000;i++) { // 에라토스테네스의 체를 이용해서 소수를 모두 집어넣음
        if(!checked[i]) {
            v.push_back(i);
            for(long long j=i;i*j<=2000000;j++) {
                checked[i*j] = true;
            }
        }
    }
    int sz = v.size();

    cin >> T;
    while(T--) {
        cin >> a >> b;
        long long sum = a + b;
        if(sum < 4) { // 4보다 작으면 항상 안됨
            cout << "NO\n";
        } else if(sum % 2 == 0) { // 골드바흐의 추측에 의해 짝수면 소수 2개로 쪼갤 수 있음
            cout << "YES\n";
        } else { // 홀수면 2와 소수로 구성되어 있어야 함(다른 짝수는 모두 합성수이므로)
            sum -= 2;
            bool flag = true;

            for(int i=0;i<sz && v[i] * v[i] <= sum;i++) { // 다른 한 수가 소수인지 체크하는 알고리즘
                if(sum % v[i] == 0) {
                    flag = false;
                    break;
                }
            }

            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }


    return 0;
}