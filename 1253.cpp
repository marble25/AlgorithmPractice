//
// Created by marble on 20. 8. 31..
//

// 투 포인터를 사용할 거라고는 쉽게 생각하지 못했다.
// 투 포인터를 잘 사용하는 연습을 해야겠다.

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
int arr[2005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n); // 정렬

    int cnt = 0;
    for(int i=0;i<n;i++) {
        int st=0, en=n-1; // 투 포인터
        while(st < en) {
            if(arr[st] + arr[en] < arr[i]) { // 합이 더 작으면 앞을 올려서 더 큰 합을 만듦
                st++;
            } else if(arr[st] + arr[en] > arr[i]) { // 합이 더 크면 뒤를 줄여서 더 작은 합을 만듦
                en--;
            } else {
                if(st != i && en != i) { // 다른 두 수의 합이므로 그 수를 포함하지 않도록 함
                    cnt++;
                    break;
                }

                if(en == i) { // 뒤가 그 수면 뒤를 줄임
                    en--;
                } else if(st == i) { // 앞이 그 수면 앞을 늘림
                    st++;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}