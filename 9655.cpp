//
// Created by marble on 20. 8. 24..
//

// 간단하게 풀 수 있던 문제

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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    if(n%2 == 0) cout << "CY";
    else cout << "SK";

    return 0;
}