// 간단한 문제지만 여러번 조건을 따져줘야 하는 문제

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
int k;
int board[105][105] = {0};
int l;
queue<pair<int, int>> q;
char change[10005] = {0};

int head_x, head_y;

int dir = 0;

const int APPLE = 1;
const int SNAKE = 2;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0;i<k;i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    cin >> l;
    for(int i=0;i<l;i++) {
        int x;
        char c;
        cin >> x >> c;
        change[x] = c;
    }

    // 시작 포인트를 (1, 1)로 초기화
    head_x = 1;
    head_y = 1;

    board[1][1] = 2;
    q.push({1, 1});

    int time = 1;
    for(;;time++) {
        switch (dir) {
            case 0: // 오른쪽
                head_y += 1;
                break;
            case 1: // 아래쪽
                head_x += 1;
                break;
            case 2: // 왼쪽
                head_y -= 1;
                break;
            case 3: // 위쪽
                head_x -= 1;
                break;
        }

        // 끝에 도달했거나 자기 자신과 만나면 끝
        if(head_x < 1 || head_y < 1 || head_x > n || head_y > n) break;
        if(board[head_x][head_y] == SNAKE) break;

        // 사과가 아닌 경우에는 queue의 마지막을 빼고, 이 좌표를 0으로 채워줌
        if(board[head_x][head_y] != APPLE) {
            int x = q.front().first, y = q.front().second;
            board[x][y] = 0;
            q.pop();
        }

        // 새로 이동한 부분을 queue에 넣음
        board[head_x][head_y] = SNAKE;
        q.push({head_x, head_y});

        // 방향 전환
        if(change[time] == 'L') {
            dir = (dir-1+4)%4;
        } else if(change[time] == 'D') {
            dir = (dir+1)%4;
        }
    }

    cout << time;

    return 0;
}