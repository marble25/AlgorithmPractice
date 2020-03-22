//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, x, y, z, gcd_val;
    cin >> n;
    if(n == 2) {
        cin >> x >> y;
        gcd_val = gcd(x, y);
    } else {
        cin >> x >> y >> z;
        gcd_val = gcd(x, gcd(y, z));
    }
    vector<int> v;
    for(int i=1;i<=sqrt(gcd_val);i++) {
        if(gcd_val % i == 0) {
            v.push_back(i);
            if(i * i != gcd_val) {
                v.push_back(gcd_val / i);
            }
        }
    }
    sort(v.begin(), v.end());
    for(int number: v) {
        cout << number << endl;
    }
    return 0;
}