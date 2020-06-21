//
// Created by marble on 20. 6. 21..
//

// 만만하게 보다가 여러번 틀렸던 문제
// long long의 범위를 넘어갈 줄은 몰랐다.

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

int disk;

void hanoi(int n, int x, int y, int z) { // 하노이 경로를 출력해주는 함수
    if(n == 1) {
        cout << x << " " << z << "\n";
        return;
    }
    hanoi(n-1, x, z, y);
    cout << x << " " << z << "\n";
    hanoi(n-1, y, x, z);
}

string count_num(int n) { // 횟수를 string으로 바꿔주는 함수
    string re;
    long long a=0, b=0;
    for (int i = 0; i < n; i++) {
        b *= 2;
        a = a * 2 + 1;
        b += a / 1000000000000000000;
        a %= 1000000000000000000;
    }
    re = (b == 0 ? to_string(a) : to_string(b) + to_string(a));
    return re;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> disk;

    cout << count_num(disk) << "\n";
    if(disk <= 20) // 20보다 작은 경우만 경로를 출력
        hanoi(disk, 1, 2, 3);

    return 0;
}