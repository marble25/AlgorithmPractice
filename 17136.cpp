//
// Created by marble on 20. 5. 12..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int mp[10][10];
int paper_left[6] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1;i<=5;i++) {
        paper_left[i] = 5;
    }

    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            cin >> mp[i][j];
        }
    }

    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            if(mp[i][j] ==)
        }
    }

    return 0;
}