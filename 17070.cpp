//
// Created by marble on 20. 9. 19..
//

// 깔끔하게 DP로 풀리는 문제
// 생각보다 고려할 사항이 많지 않아서 쉬웠던 문제

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
int arr[20][20] = {0};
int visited[20][20][3] = {0}; // 세로, 가로, 대각선
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    visited[0][1][1] = 1; // 가로로 파이프가 놓여 있음을 알려줌

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i > 0) { // 세로 파이프가 가능하면 이전 칸의 대각선과 세로를 합해줌
                if(arr[i][j] == 0) {
                    visited[i][j][0] += visited[i-1][j][0];
                    visited[i][j][0] += visited[i-1][j][2];
                }
            }

            if(j > 0) { // 가로 파이프가 가능하면 이전 칸의 대각선과 가로를 합해줌
                if(arr[i][j] == 0) {
                    visited[i][j][1] += visited[i][j-1][1];
                    visited[i][j][1] += visited[i][j-1][2];
                }
            }

            if(i > 0 && j > 0) { // 대각선 파이프가 가능하면 이전 칸의 대각선과 가로, 세로를 합해줌
                if(arr[i][j] == 0 && arr[i][j-1] == 0 && arr[i-1][j] == 0) {
                    visited[i][j][2] += visited[i-1][j-1][0];
                    visited[i][j][2] += visited[i-1][j-1][1];
                    visited[i][j][2] += visited[i-1][j-1][2];
                }
            }
        }
    }

    cout << visited[n-1][n-1][0] + visited[n-1][n-1][1] + visited[n-1][n-1][2]; // 대각선, 가로, 세로의 총합 출력
}