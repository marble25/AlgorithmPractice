//
// Created by marble on 20. 12. 31..
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
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int sum = 0, x;
    for(int i=0;i<5;i++) {
        cin >> x;
        sum += x;
    }

    cout << sum;


    return 0;
}