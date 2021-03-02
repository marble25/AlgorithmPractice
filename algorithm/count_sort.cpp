//
// Created by 이지호 on 21. 3. 2..
//

#include <cstdio>

int table[1000000] = {0};
int main() {
    int arr[10] = {2, 7, 3, 1, 4, 9, 23, 1, 5, 8};
    for(int i=0;i<10;i++) {
        table[arr[i]]++;
    }

    for(int i=0;i<100000;i++) {
        while(table[i] > 0) {
            printf("%d ", i);
            table[i]--;
        }
    }
    return 0;
}