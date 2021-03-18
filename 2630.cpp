//
// Created by 이지호 on 21. 3. 18..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <string.h>

using namespace std;
int n;
int arr[200][200] = {0};
int white = 0, blue = 0;

int divide(int s_x, int s_y, int size) {
    if(size == 1) {
        return arr[s_x][s_y];
    }

    int a1 = divide(s_x, s_y, size/2);
    int a2 = divide(s_x + size / 2, s_y, size/2);
    int a3 = divide(s_x, s_y+size/2, size/2);
    int a4 = divide(s_x+size/2, s_y+size/2, size/2);

    if(a1 == a2 && a2 == a3 && a3 == a4) {
        return a1;
    } else {
        if(a1 == 1) blue++;
        else if(a1 == 0) white++;

        if(a2 == 1) blue++;
        else if(a2 == 0) white++;

        if(a3 == 1) blue++;
        else if(a3 == 0) white++;

        if(a4 == 1) blue++;
        else if(a4 == 0) white++;

        return -1;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    int x = divide(0, 0, n);
    if(x == 1) blue++;
    else if(x == 0) white++;
    cout << white << "\n" << blue;


    return 0;
}