//
// Created by 이지호 on 21. 3. 30..
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
int arr[1000005] = {0};
vector<int> p = {2, 3, 5, 7};
bool is_palendrom(int x) {
    int reversed = 0;
    int origin = x;
    while(x) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed == origin;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=11;i<=1000;i++) {
        if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && arr[i] == 0) {
            if(is_palendrom(i)) {
                p.push_back(i);
            }
            for(int j=1;i*j<=1000000;j++) {
                arr[i*j] = 1;
            }
        }
    }
    for(int i=1001;i<=1000000;i++) {
        if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && arr[i] == 0) {
            if(is_palendrom(i)) {
                p.push_back(i);
            }
        }
    }
    p.push_back(1003001);
    int n;
    cin >> n;

    int size = p.size();
    for(int i=0;i<size;i++) {
        if(p[i] >= n) {
            cout << p[i];
            break;
        }
    }
}