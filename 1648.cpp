//
// Created by marble on 20. 3. 26..
//

// 나는 혼자서 이런 방법을 생각해내지 못랗 것 같다.
// 한칸씩 미는 비트마스크라니. 참신하기 그지없다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

const int MAX = 14;
const int MOD = 9901;

int n, m;
int cache[MAX*MAX][1<<MAX];

int tiling(int board, int bit) {
    if(board == n * m && bit == 0) { // 모두 채워졌을 때 1 리턴
        return 1;
    }
    if(board >= n*m) { // 끝까지 갔음에도 다 채워지지 않았을 때 0 리턴
        return 0;
    }
    int &ret = cache[board][bit];
    if(ret != -1) return ret; // 캐시값 리턴

    if(bit & 1) { // 현재 칸이 채워져 있다면 다음칸으로 넘어감
        ret = tiling(board+1, bit >> 1);
    } else {
        ret = tiling(board+1, (bit >> 1) | (1 << (m-1))); // 현재칸에서 아래로 1*2를 놓는 방법
        if((board % m) != (m-1) && (bit & 2) == 0) { // 현재칸이 오른쪽 끝 칸이 아니고 현재칸 옆칸도 비어있다면
            ret += tiling(board+2, bit >> 2); // 현재칸 옆으로 2*1 놓는 방법
        }
    }
    return ret %= MOD;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    memset(cache, -1, sizeof(cache));
    cout << tiling(0, 0) << '\n';
    return 0;
}