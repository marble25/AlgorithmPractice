//
// Created by marble on 20. 5. 28..
//

// 출력을 잘못해서 어이없게 틀린 문제
// 이런 문제도 틀리지 않도록 해야겠다.

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

int a, b;
int n, m;

char rotate_right[4] = {'E', 'S', 'W', 'N'};
char rotate_left[4] = {'E', 'N', 'W', 'S'};
int mp[105][105] = {0};

struct robot{
    int x;
    int y;
    char direction;
} ;
robot r[105];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> a >> b;
    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        cin >> r[i].x >> r[i].y >> r[i].direction;
        mp[r[i].x][r[i].y] = i; // 맵에 위치시켜줌
    }

    for(int i=0;i<m;i++) {
        int target, times;
        char op;

        cin >> target >> op >> times;
        switch (op) {
            case 'L': // 왼쪽 회전이면
                for(int j=0;j<4;j++) {
                    if(r[target].direction == rotate_left[j]) {
                        r[target].direction = rotate_left[(j+times) % 4]; // 4로 나눈 나머지 횟수만큼 돌림
                        break;
                    }
                }
                break;
            case 'R': // 오른쪽 회전이면
                for(int j=0;j<4;j++) {
                    if(r[target].direction == rotate_right[j]) {
                        r[target].direction = rotate_right[(j+times) % 4]; // 4로 나눈 나머지 횟수만큼 돌림
                        break;
                    }
                }
                break;
            case 'F': // 직진이면
                mp[r[target].x][r[target].y] = 0; // 현재 칸을 비워줌
                for(int j=0;j<times;j++) {

                    // 해당 방향으로 진행
                    if(r[target].direction == 'W') {
                        r[target].x--;
                    } else if(r[target].direction == 'E') {
                        r[target].x++;
                    } else if(r[target].direction == 'N') {
                        r[target].y++;
                    } else if(r[target].direction == 'S') {
                        r[target].y--;
                    }

                    // 맵 범위를 벗어나면 종료
                    if(r[target].x < 1 || r[target].y < 1 || r[target].x > a || r[target].y > b) {
                        cout << "Robot " << target << " crashes into the wall";
                        return 0;
                    }

                    // 움직인 칸에 다른 로봇이 있으면 종료
                    if(mp[r[target].x][r[target].y] != 0) {
                        cout << "Robot " << target << " crashes into robot " << mp[r[target].x][r[target].y];
                        return 0;
                    }
                }

                mp[r[target].x][r[target].y] = target; // 맵에 새로운 로봇 저장
                break;
        }
    }
    cout << "OK";

    return 0;
}