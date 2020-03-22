//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

// vector를 사용하지 않고 출력하면 틀리는데, 왜 그런지 이유는 잘 모르겠다.
// 답 자체는 진즉에 맞췄는데... C++에 적응한다고 생각해야겠다.

vector<pair<int, int>> v;

void hanoi(int start, int end, int size) {
    if(size != 1) {
        hanoi(start, 6-start-end, size-1); // size-1블럭을 중간 저장소(6-start-end)에 보냄
    }
    v.push_back(make_pair(start, end)); // size 블럭을 start에서 end로 보냄
    if(size != 1) {
        hanoi(6-start-end, end, size-1); // size-1블럭을 중간 저장소(6-start-end)에서 end로 보냄
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    hanoi(1, 3, n);
    cout << v.size() << '\n';
    for(int i=0;i<v.size();i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}