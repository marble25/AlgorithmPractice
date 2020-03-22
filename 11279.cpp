//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    priority_queue<int, vector<int>, less<int>> pq;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(x == 0) {
            cout << (pq.empty()?0:pq.top()) << '\n';
            if(!pq.empty()) pq.pop();
        } else {
            pq.push(x);
        }
    }
    return 0;
}