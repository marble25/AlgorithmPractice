//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true) {
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) {
            break;
        }
        if(x % y == 0) {
            cout << "multiple\n";
        } else if(y % x == 0) {
            cout << "factor\n";
        } else {
            cout << "neither\n";
        }
    }
    return 0;
}