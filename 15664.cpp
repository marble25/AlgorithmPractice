//
// Created by marble on 20. 6. 10..
//

// 간단하게 맞춘 문제

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

int n, m;
int cnt = 0;
int arr[10];
int temp[10] = {0};
int re[10005][10] = {0};


void perm(int stage, int idx) { // 모든 경우를 permutation함
    if(stage == m-1) { // 끝에 도달했다면
        int equal_count = 0;
        for(int i=0;i<cnt;i++) {
            equal_count = 0;
            for(int j=0;j<m;j++) {
                if(temp[j] == re[i][j]) {
                    equal_count++;
                }
            }

            if(equal_count == m) { // 같은 답이 존재한다면
                break;
            }
        }

        if(equal_count != m) { // 같은 답이 존재하지 않으면 배열에 추가
            for(int i=0;i<m;i++) {
                re[cnt][i] = temp[i];
            }
            cnt++;
        }
        return;
    }

    for(int i=idx+1;i<n;i++) { // 모든 경우를 permute
        temp[stage+1] = arr[i];
        perm(stage+1, i);
        temp[stage+1] = 0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n); // 오름차순 정렬
    perm(-1, -1);
    for(int i=0;i<cnt;i++) {
        for(int j=0;j<m;j++) {
            cout << re[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}