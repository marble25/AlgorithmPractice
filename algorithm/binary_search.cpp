//
// Created by 이지호 on 21. 3. 1..
//

#include <cstdlib>
#include <cstdio>


int binary_search(int arr[], int value, int start, int end) {
    if(start > end) return -1;

    int mid = (start + end) / 2;
    if(arr[mid] == value) return mid;

    if(arr[mid] > value) return binary_search(arr, value, start, mid-1);
    return binary_search(arr, value, mid+1, end);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binary_search(arr, 10, 0, 9));
    printf("%d\n", binary_search(arr, 11, 0, 9));
}