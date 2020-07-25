//
// Created by marble on 20. 7. 26..
//

// 생각보다 쉬운 문제에서 많이 틀리는 것 같다.
// 정밀하게 검증하는 능력이 필요하다.

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

int l;
vector<int> v;
int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> l;
    for(int i=0;i<l;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.push_back(0); // 0~처음 수까지의 구간도 표현하기 위해 0을 벡터에 추가

    cin >> n;
    sort(v.begin(), v.end()); // 정렬


    for(int i=1;i<=l;i++) {
        if(v[i] > n) { // n이 v[i-1]~v[i] 사이라면
            cout << (v[i]-n) * (n-v[i-1]) - 1; // n~v[i]에서 하나 뽑고, v[i-1]~n에서 하나 뽑아서 나오는 조합의 수에서 [n, n]을 제외해줌
            break;
        } else if(v[i] == n) { // v[i]와 같다면 어떠한 경우라도 unlucky일 수 없음
            cout << 0;
            break;
        }
    }

    return 0;
}