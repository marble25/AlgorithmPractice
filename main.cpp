// 입력이 계속된다는 사실을 간과해서 여러번 틀린 문제
// 이런 조건도 나올 수 있다는 것을 깨달았다.

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

char input_data[32][10];
char op[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true) {
        int acc = 0;
        int pc = 0;
        char acc_string[10] = {0};

        for(int i=0;i<32;i++) {
            cin >> input_data[i];
        }

        if(cin.eof()) {
            break;
        }

        while(pc < 32) {
            char *input = input_data[pc];
            if(strncmp(input, op[0], 3) == 0) {
                int address = (input[3]-'0') * 16 + (input[4]-'0') * 8 + (input[5]-'0') * 4
                              + (input[6]-'0') * 2 + (input[7]-'0') * 1;

                int d = 128;
                for(int i=0;i<8;i++) {
                    acc_string[i] = (acc  % (d * 2) / d) + '0';
                    d /= 2;
                }

                pc ++;
                strncpy(input_data[address], acc_string, 8);
            } else if(strncmp(input, op[1], 3) == 0) {
                int address = (input[3]-'0') * 16 + (input[4]-'0') * 8 + (input[5]-'0') * 4
                              + (input[6]-'0') * 2 + (input[7]-'0') * 1;
                pc ++;

                acc = 0;
                int d = 128;
                for(int i=0;i<8;i++) {
                    acc += (input_data[address][i] - '0') * d;
                    d /= 2;
                }
            } else if(strncmp(input, op[2], 3) == 0) {
                int address = (input[3]-'0') * 16 + (input[4]-'0') * 8 + (input[5]-'0') * 4
                              + (input[6]-'0') * 2 + (input[7]-'0') * 1;

                pc++;
                if(acc == 0) {
                    pc = address;
                }
            } else if(strncmp(input, op[3], 3) == 0){
                pc++;
            } else if(strncmp(input, op[4], 3) == 0) {
                pc++;
                acc--;
            } else if(strncmp(input, op[5], 3) == 0) {
                pc++;
                acc++;
            } else if(strncmp(input, op[6], 3) == 0) {
                int address = (input[3]-'0') * 16 + (input[4]-'0') * 8 + (input[5]-'0') * 4
                              + (input[6]-'0') * 2 + (input[7]-'0') * 1;
                pc = address;
            } else if(strncmp(input, op[7], 3) == 0) {
                break;
            }

            if(pc == 32) {
                pc = 0;
            }

            if(pc < 0) {
                pc += 32;
            }

            if(acc == 256) {
                acc = 0;
            }

            if(acc < 0) {
                acc += 256;
            }
        }

        int d = 128;
        for(int i=0;i<8;i++) {
            cout << acc % (d * 2) / d;
            d /= 2;
        }
        cout << '\n';
    }



    return 0;
}