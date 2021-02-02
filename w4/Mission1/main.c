#include <stdio.h>
#define SIZE 10

//배열의 크기가 10인 table를 선언
int table[SIZE];

void add(int *arr, int cnt);
void del(int *arr, int cnt);
int chkAnagram(int *arr1, int *arr2, int arrCnt);


int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 3, 1};

    int flag = chkAnagram(arr1, arr2, 5);

    if(flag){
        printf("TRUE");
    } else{
        printf("FALSE");
    }

    return 0;
}


void add(int *arr, int cnt){
    for(int i = 0; i<cnt; i++){
        table[arr[i]] += 1; //arr에 있는 원소를 index로 사용하여 table의 해당 원소를 1씩 추가
    }
}

void del(int *arr, int cnt){
    for(int i = 0; i<cnt; i++){
        table[arr[i]] -= 1; //arr에 있는 원소를 index로 사용하여 table의 해당 원소를 1씩 제거
    }
}

int chkAnagram(int *arr1, int *arr2, int arrCnt) {
    add(arr1, arrCnt);
    del(arr2, arrCnt);

    int flag = 1; // flag 1: TRUE, flag 0 : FALSE
    for(int i = 0; i < SIZE; i++){
        if(table[i] != 0){  //table의 원소 중 0이 아닌 값이 있으면 flag = 0
            flag = 0;
            break;
        }
    }

    return flag;
}
