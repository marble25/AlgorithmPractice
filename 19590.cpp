//
// Created by marble on 20. 8. 21..
//

// 오랜만에 생각하는 문제를 풀었던것 같다.
// 간단하지만 좋은 문제이다.

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

int n;
vector<long long> v;

long long a=0, b=0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), greater<>()); // 큰 순서대로 정렬

    for(int i=0;i<n;i++) {
        if(a == 0) a = v[i]; // 첫 값은 a에 할당
        else if(b == 0) b = v[i]; // 두 번째 값은 b에 할당
        else { // 그 이후 값은 더 작은 곳에 할당
            long long diff = abs(b-a);
            if(a <= b) {
                a += min(v[i], diff);
                if(v[i] > diff) { // 차이보다 더 크면 반으로 나눠서 더해줌
                    long long remainder = v[i] - diff;
                    a += remainder / 2 + remainder % 2;
                    b += remainder / 2;
                }
            } else {
                b += min(v[i], diff);
                if(v[i] > diff) { // 차이보다 더 크면 반으로 나눠서 더해줌
                    long long remainder = v[i] - diff;
                    a += remainder / 2 + remainder % 2;
                    b += remainder / 2;
                }
            }
        }
    }

    cout << abs(a-b);

    return 0;
}