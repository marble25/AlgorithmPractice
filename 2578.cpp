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
int arr[5][5];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin >> arr[i][j];
        }
    }

    int count = 0;
    for(int i=1;i<=25;i++) {
        int x;
        cin >> x;

        int s_x=-1, s_y=-1;
        bool lower_left_diagonal = false;
        bool lower_right_diagonal = false;
        for(int j=0;j<5;j++) {
            for(int k=0;k<5;k++) {
                if(arr[j][k] == x) {
                    arr[j][k] = 0;
                    s_x = j;
                    s_y = k;

                    if(j == k) lower_right_diagonal = true;
                    if(j+k == 4) lower_left_diagonal = true;
                    break;
                }
            }
            if(s_x != -1 && s_y != -1) break;
        }

        int x_count = 0, y_count = 0, lower_left_count = 0, lower_right_count = 0;
        for(int j=0;j<5;j++) {
            if(arr[j][s_y] == 0) {
                x_count++;
            }
            if(arr[s_x][j] == 0) {
                y_count++;
            }

            if(lower_right_diagonal && arr[j][j] == 0) {
                lower_right_count++;
            }
            if(lower_left_diagonal && arr[4-j][j] == 0) {
                lower_left_count++;
            }
        }

        if(x_count == 5) count++;
        if(y_count == 5) count++;
        if(lower_left_count == 5) count++;
        if(lower_right_count == 5) count++;

        if(count >= 3) {
            cout << i;
            break;
        }
    }
    return 0;
}