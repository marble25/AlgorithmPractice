//
// Created by marble on 20. 6. 14..
//

// 얼토당토 않은 문제로 여러번 틀렸던 문제
// 맞추고 나니 정말 황당했다.
// 꼼꼼히 잘 체크해야한다.

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

int T;
int n;

int birth[3] = {3, 5, 8};
int arr[1000005][3];

void find_smallest(int target) { // 3가지 경우 중 가장 작은 경우를 찾아서 넣어주는 함수
    int x=99999, y=99999, z=99999;
    int diff = -1;
    for(int i=0;i<3;i++) {
        int temp[3];
        for(int j=0;j<3;j++) { // 현재 값에서 3, 5, 8 뺀 값들을 temp로 불러옴
            temp[j] = arr[target-birth[i]][j];
        }

        int sum = temp[0] + temp[1] + temp[2];

        if(sum != 0) { // 대소 비교(더 작은 값을 넣어줌)
            if(sum < x+y+z) {
                x = temp[0];
                y = temp[1];
                z = temp[2];
                diff = i;
            } else if(sum == x+y+z) {
                if(temp[0] > x) {
                    x = temp[0];
                    y = temp[1];
                    z = temp[2];
                    diff = i;
                } else if(temp[0] == x && temp[1] > y) {
                    x = temp[0];
                    y = temp[1];
                    z = temp[2];
                    diff = i;
                } else if(temp[0] == x && temp[1] == y && temp[2] > z) {
                    x = temp[0];
                    y = temp[1];
                    z = temp[2];
                    diff = i;
                }
            }

        }
    }

    if(diff != -1) { // 이전 값을 찾았다면 arr에 할당
        arr[target][0] = x;
        arr[target][1] = y;
        arr[target][2] = z;
        arr[target][diff] ++; // 차이에 해당하는 것을 하나 플러스
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    arr[3][0] = 1;
    arr[6][0] = 2;
    arr[5][1] = 1;
    arr[8][2] = 1;
    for(int i=9;i<=1000000;i++) {
        find_smallest(i);
    }

    cin >> T;
    while(T--) {
        cin >> n;
        string s;
        for(int i=0;i<3;i++) { // string 만들어보기
            for(int j=0;j<arr[n][i];j++) {
                s += birth[i] + '0';
            }
        }
        if(s.empty()) { // 표현할 수 없으면 -1
            cout << -1 << "\n";
        } else {
            cout << s << "\n";
        }
    }

    return 0;
}