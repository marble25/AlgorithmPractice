//
// Created by marble on 20. 4. 29..
//

// 위상정렬 복습 문제
// 간단한 문제였다.

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

int n, m;
queue<int> q;
vector<int> linked[1005];
vector<int> result;
int arr[1005] = {0};
int visited[1005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, temp[1005];
        cin >> x;
        for(int j=0;j<x;j++) {
            cin >> temp[j];
            if(j > 0) {
                linked[temp[j-1]].push_back(temp[j]);
                arr[temp[j]] ++;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(arr[i] == 0) {
            q.push(i);
            result.push_back(i);
            visited[i] = 1;
        }
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto &it : linked[x]) {
            arr[it] --;
            if(arr[it] == 0) {
                q.push(it);
                result.push_back(it);
                visited[it] = 1;
            }
        }
    }

    if(result.size() != n) {
        cout << 0;
    } else {
        for(auto &it : result) {
            cout << it << ' ';
        }
    }


    return 0;
}