//
// Created by marble on 20. 4. 1..
//

// 이분탐색을 이용해서 조각 길이 구하는것은 정말 쉬웠으나 가장 작은 조각 찾는 것은 굉장히 까다로웠던 문제

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

int l, k, c;
int pos[10005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> l;
    cin >> k >> c;
    for(int i=0;i<k;i++) {
        cin >> pos[i];
    }
    pos[k] = 0;
    pos[k+1] = l;
    sort(pos, pos+(k+2));

    int len = INT32_MAX;
    int lo = 0, hi = l;
    while(lo <= hi) {
        int mid = (lo + hi) / 2; // 가장 긴 조각
        int past = 0;
        int count = 0;
        for (int i = 1; i <= k+1; i++) { // mid보다 작거나 같은 값으로 나눈 횟수(count)를 구함
            if (pos[i] - past > mid) { // 현재 pos와 이전 값의 차이가 mid보다 커져 버리면 i-1을 이전 조각으로 저장
                if (pos[i] - pos[i-1] > mid) { // pos[i]와 pos[i-1] 차이가 mid보다 크면 성립하지 않음
                    count = INT32_MAX;
                    break;
                } else {
                    past = pos[i - 1];
                    count++;

                    if(pos[i] - pos[i-1] > mid) { // 차이가 mid보다 큰지 체크
                        count = INT32_MAX;
                        break;
                    }
                }
            }
        }
        if (count <= c) { // 가능한 경우이므로 정답을 update하고 더 작은 값에서도 가능한지 체크
            len = min(len, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << len << ' ';

    int past = l;
    int count = 0;
    int pos_min = INT32_MAX;
    for (int i = k+1; i >= 0; i--) { // 뒤에서부터 돌림
        if (past - pos[i] > len) { // 현재 pos와 이전 값의 차이가 len보다 커져 버리면 i+1을 이전 조각으로 저장
            past = pos[i+1];
            pos_min = min(pos_min, past); // 자른 위치를 update해줌
            count++;
        }
    }
    pos_min = min(pos_min, past); // 가장 마지막에 자른 위치도 update 해봐야 함
    if(count < c) { // c보다 작으면 추가적으로 첫 번째 위치로 자를 수 있다.
        cout << pos[1];
    } else {
        cout << pos_min;
    }

    return 0;
}