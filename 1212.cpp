//
// Created by marble on 20. 3. 31..
//

// 간단한 문제였음에도 배울 점이 있었던 문제
// base case 설정을 잘 해주고, for문의 동작 구조에 대해서도 잘 익혀놓아야 한다.

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

char s[400000];
char out[1000005];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    bool is_one_exists = false;
    int out_idx = 0;
    int max_len = strlen(s);
    if(max_len == 1 && s[0] == '0') { // 0일 경우 출력
        cout << 0;
    }
    for(int i=0;i<max_len;i++) {
        int num = s[i] - '0';
        int first = num / 4;
        int second = num % 4 / 2;
        int third = num % 2;

        if(!((!is_one_exists) && first == 0)) { // 0이고 앞에 1이 안나왔다면 넘어감
            if(first == 1) is_one_exists = true; // 1이면 1이 나왔다고 체크
            out[out_idx++] = first + '0';
        }
        if(!((!is_one_exists) && second == 0)) { // 0이고 앞에 1이 안나왔다면 넘어감
            if(second == 1) is_one_exists = true; // 1이면 1이 나왔다고 체크
            out[out_idx++] = second + '0';
        }
        if(!((!is_one_exists) && third == 0)) { // 0이고 앞에 1이 안나왔다면 넘어감
            if(third == 1) is_one_exists = true; // 1이면 1이 나왔다고 체크
            out[out_idx++] = third + '0';
        }
    }
    cout << out;

    return 0;
}