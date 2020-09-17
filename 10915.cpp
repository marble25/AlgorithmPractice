//
// Created by marble on 20. 9. 17..
//

// 풀이방법을 생각하기까지 쉽지 않았지만 실제로는 굉장히 간단한 문제
// modular 연산의 특징을 이용해서 풀 수 있었음

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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;

    if(n % 2 == 0) cout << n-1; // 짝수이면 n-1
    else cout << n/2; // 홀수이면 n/2
    return 0;
}