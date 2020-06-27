//
// Created by marble on 20. 6. 27..
//

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

int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    if(n%4 == 0 && (n%100 != 0 || n%400 == 0)) cout << 1;
    else cout << 0;
    return 0;
}