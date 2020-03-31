//
// Created by marble on 20. 3. 31..
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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    cout << x * (y%10) << '\n';
    cout << x * (y % 100 / 10) << '\n';
    cout << x * (y / 100) << '\n';
    cout << x * y << '\n';


    return 0;
}