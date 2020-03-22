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

    int n;
    queue<int> q;

    cin >> n;
    while(n--) {
        string word;
        cin >> word;
        if(word.compare("pop") == 0) {
            if(q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if(word.compare("size") == 0) {
            cout << q.size() << '\n';
        } else if(word.compare("empty") == 0) {
            cout << (q.empty()?1:0) << '\n';
        } else if(word.compare("front") == 0) {
            cout << (q.empty()?-1:q.front()) << '\n';
        } else if(word.compare("back") == 0) {
            cout << (q.empty()?-1:q.back()) << '\n';
        } else if(word.compare("push") == 0) {
            int x;
            cin >> x;
            q.push(x);
        }
    }
    return 0;
}