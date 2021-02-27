//
// Created by 이지호 on 21. 2. 28..
//

#include <cstdlib>
#include <cstdio>

#define SIZE 10
int temp[SIZE];

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[], int p, int q, int r) {
    int i = p;
    int j = q+1;
    int k = p;

    while(i <= q && j <= r) {
        if(arr[i] > arr[j]) {
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }

    if(i > q) {
        for(int l=j;l<=r;l++) {
            temp[k++] = arr[l];
        }
    } else {
        for(int l=i;l<=q;l++) {
            temp[k++] = arr[l];
        }
    }

    for(int l=p;l<=r;l++) {
        arr[l] = temp[l];
    }
}

void mergeSort(int arr[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void mergeSort(int arr[]) {
    mergeSort(arr, 0, SIZE-1);
}

void print(int arr[]) {
    for(int i=0;i<SIZE;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 1, 10, 2, 7, 9, 4, 6, 8};
    mergeSort(arr);
    print(arr);
    return 0;
}