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

const int MAX = 1000000;
int num[1000005];
vector<int> p;

void precalc() {
    for(int i=2;i<=MAX;i++) {
        if(num[i] == 0) {
            if(i == 2) {
                num[i] = 2;
            } else {
                p.push_back(i);
                num[i] = 1;
            }
            for(int j=2;i*j<=MAX;j++) {
                num[i*j] = 2;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    precalc();

    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        for(auto & it : p) {
            if(num[n-it] == 1) {
                cout << n << " = " << it << " + " << n - it << '\n';
                break;
            }
        }
    }

    return 0;
}