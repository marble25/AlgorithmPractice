//
// Created by 이지호 on 21. 2. 28..
//

#include <cstdlib>
#include <cstdio>

#define SIZE 10

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[]) {
    for(int i=0;i<SIZE;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// x노드 부모 또는 형제 노드들은 다 heap이라고 가정하고, x 노드에 대해 heapify
void heapify(int arr[], int n, int x) {
    int largest = x;
    int left = x*2 + 1;
    int right = x*2 + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(x != largest) {
        swap(&arr[x], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[]) {
    // 리프 노드를 제외한 노드들에서 heapify(하단에서부터 진행)
    for (int i = SIZE / 2 - 1; i >= 0; i--)
        heapify(arr, SIZE, i);

    // 하나씩 뺌(가장 큰 값을 제일 뒤로)
    for (int i = SIZE - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);

        // 루트 노드가 변경되었으므로 heapify
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {3, 5, 1, 10, 2, 7, 9, 4, 6, 8};
    heapSort(arr);
    print(arr);
    return 0;
}