//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;
    stack<int> s;

    cin >> k;
    for(int i=0;i<k;i++) {
        int x;
        cin >> x;
        if(x == 0) {
            s.pop();
        } else {
            s.push(x);
        }
    }
    int sum = 0;
    while(s.size() > 0) {
        sum += s.top();
        s.pop();
    }
    cout << sum << '\n';
    return 0;
}