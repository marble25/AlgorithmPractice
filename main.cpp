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

int n;
vector<int> d0, d1, d2;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x;

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x;
        if(x % 3 == 0) {
            d0.push_back(x);
        } else {
            d1.push_back(x);
        }
    }

    if(n % 2 == 0) {
        if(d0.size() != d1.size()) {
            cout << -1;
            return 0;
        }

        for(int i=0;i<d0.size();i++) {
            cout << d0[i] << " " << d1[i] << " ";
        }
    } else {
        if(d0.size() == d1.size() + 1) {
            for(int i=0;i<d1.size();i++) {
                cout << d0[i] << " " << d1[i] << " ";
            }
            cout << d0[d0.size()-1];
        } else if(d0.size() + 1 == d1.size()) {
            for(int i=0;i<d0.size();i++) {
                cout << d1[i] << " " << d0[i] << " ";
            }
            cout << d1[d1.size()-1];
        } else {
            cout << -1;
            return 0;
        }
    }

    return 0;
}