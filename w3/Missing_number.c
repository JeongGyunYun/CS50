
#include <stdio.h>
#define SIZE 500000


int searchKey(int *arr, int n);
void quick_sort(int *arr, int left, int right); // 퀵 정렬
void swap(int *arr, int id1, int id2);

int main(int argc, char* argv[]){
    int n; // 1~n 까지의 수

    scanf("%d", &n);

    int partArr[SIZE];
    int lengthOfPartArr = n-1;

    for(int i = 0; i < lengthOfPartArr; i++){
        scanf("%d", &partArr[i]);
    }

    quick_sort(partArr, 0, lengthOfPartArr-1);
    printf("k = %d",searchKey(partArr, n));

    return 0;
}


/**
 *
 * @param arr   오름차순으로 정렬된 배열
 * @param n     배열에 들어갈 수 있는 가장 큰 숫자
 * @return      찾을 숫자 k
 */
int searchKey(int *arr, int n){ // 이진 탐색
    int left, right, mid;

    if(arr[n-2] != n){
        return n;
    }

    left = 0;
    right = n-2;

    do{
        mid = (left + right) / 2;

        if(arr[mid] == mid +1){
            left = mid+1;
        } else {
            right = mid;
        }
    }while(left < right);
    return right+1;
}


void swap(int *arr, int id1, int id2) {
    if (id1 == id2) return;
    arr[id1] ^= arr[id2];
    arr[id2] ^= arr[id1];
    arr[id1] ^= arr[id2];
}


/**
 *
 * @param arr   정렬되지 않은 배열
 * @param left  배얼의 첫 번째 index
 * @param right 배열의 두 번째 index
 */
void quick_sort(int *arr, int left, int right) {
    int toLeft, toRight, pivot;

    if(left < right) {
        pivot = arr[left];
        toRight = left;
        toLeft = right + 1;
        do {
            do toRight++; while (pivot > arr[toRight]);
            do toLeft--; while (pivot < arr[toLeft]);
            if (toRight < toLeft) swap(arr, toRight, toLeft);
        } while (toRight < toLeft);
        swap(arr, left, toLeft);
        quick_sort(arr, left, toLeft - 1);
        quick_sort(arr, toLeft + 1, right);
    }
}
