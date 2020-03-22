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

    int n;
    cin >> n;
    for(int i=2;i<=n;i++) {
        if(n % i == 0) {
            cout << i << "\n";
            n /= i;
            i--;
        }
    }
    return 0;
}