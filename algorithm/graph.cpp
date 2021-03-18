//
// Created by 이지호 on 21. 3. 14..
//

#include <cstdio>
#include <queue>

using namespace std;

int linked[10][10] = {0};
int visited[10] = {0};

queue<int> q;
void dfs(int x) {
    printf("%d ", x);
    visited[x] = 1;
    for(int i=0;i<10;i++) {
        if(visited[i] == 0 && linked[x][i] == 1) {
            dfs(i);
        }
    }
}

void bfs(int x) {
    q.push(x);
    visited[x] = 1;
    while(q.empty() == 0) {
        x = q.front();
        q.pop();
        printf("%d ", x);

        for(int i=0;i<10;i++) {
            if(visited[i] == 0 && linked[x][i] == 1) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    linked[0][1] = 1;
    linked[1][5] = 1;
    linked[0][3] = 1;
    linked[1][2] = 1;
    linked[3][7] = 1;
    linked[3][4] = 1;
    linked[4][2] = 1;
    linked[7][5] = 1;
    linked[5][8] = 1;
    linked[3][6] = 1;
    linked[6][9] = 1;
    linked[9][10] = 1;

    dfs(0);
    printf("\n");

    for(int i=0;i<10;i++) {
        visited[i] = 0;
    }

    bfs(0);
}
