// backtracking으로 풀려고 했다가 가지치기할 경우가 너무 많아서 TLE 떴다.
// DP로 변경해서 풀었더니 간단하게 풀렸다.

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

char s[55];
char re[55];
int employee[3] = {0};
int dp[55][55][55][3][3] = {0}; // 사용한 A개수, B개수, C개수, 이전 알파벳, 그 이전 알파벳

void simulate(int x, int y, int z, int past, int pastpast) {
    if(x+y+z == strlen(s)) { // 끝까지 왔으면 출력 후 종료
        re[x+y+z] = 0;
        cout << re;
        exit(0);
    }

    if(dp[x][y][z][past][pastpast] != 0) return; // 가능하지 않은 경우(이미 탐사해봄)이므로 return

    dp[x][y][z][past][pastpast] = 1; // 체크

    if(z+1 <= employee[2] && past != 2 && pastpast != 2) { // C가 남아 있고 이전과 그 이전이 C가 아니면 가능
        re[x+y+z] = 'C';
        simulate(x, y, z+1, 2, past);
    }

    if(y+1 <= employee[1] && past != 1) { // B가 남아 있고 이전이 B가 아니면 가능
        re[x+y+z] = 'B';
        simulate(x, y+1, z, 1, past);
    }

    if(x+1 <= employee[0]) { // A가 남아 있으면 가능
        re[x+y+z] = 'A';
        simulate(x+1, y, z, 0, past);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    for(int i=0;i<strlen(s);i++) { // 직원의 출근 횟수 더해줌
        employee[s[i] - 'A'] ++;
    }

    simulate(0, 0, 0, 0, 0);
    cout << -1;

    return 0;
}