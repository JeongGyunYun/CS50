#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(int *wInfo, int *hInfo, int left, int right);
void swap(int *arr, int id1, int id2);


int main() {

    char filePath[100];
    printf("Input the file path >> ");
    scanf("%s", filePath);

    FILE *f = fopen(filePath, "r");

    int roomWidth, roomHeight;
    fscanf(f, "%d", &roomWidth);
    fscanf(f, "%d", &roomHeight);

    int* hArray = (int *)malloc(sizeof (*hArray) * roomWidth); //상자의 높이을 저장할 배열 선언
    int* wArray = (int *)malloc(sizeof (*wArray) * roomWidth); //상자의 위치를 저장할 배열 선언

    // 상자의 높이와 위치 초기화
    for(int i = 0; i < roomWidth; i++){
        fscanf(f, "%d", &hArray[i]);
        wArray[i] = i;
    }

    // 오름차순으로 상자의 높이 정렬
    sort(wArray, hArray, 0, roomWidth - 1);


    int cntMaxValue = 0; //배열의 가장 큰 값의 갯수
    int minIndex = roomWidth; //배열의 가장 큰 값 중에서 가장 작은 index
    for(int i = roomWidth - 1; hArray[i] >= hArray[roomWidth - 1]; i--){
        if(minIndex > wArray[i]){
            minIndex = wArray[i];
        }
        cntMaxValue++;
    }

    //최대 낙하거리 = 방의 높이 - 가장 높은 높이를 갖는 박스들의 수 - 가장 높은 높이를 갖는 박스 중 가장 위에 있는 박스 위치
    int maxDropDistance = roomWidth - cntMaxValue - minIndex;

    printf("%d\n", maxDropDistance);

    free(hArray);
    free(wArray);
    fclose(f);
    return 0;
}

//unstable sort
void sort(int *wInfo, int *hInfo, int left, int right) {
    int toLeft, toRight, pivot;

    if(left < right) {
        pivot = hInfo[left];
        toRight = left;
        toLeft = right + 1;
        do {
            do toRight++; while (pivot > hInfo[toRight]);
            do toLeft--; while (pivot < hInfo[toLeft]);
            if (toRight < toLeft) {
                swap(hInfo, toRight, toLeft);
                swap(wInfo, toRight, toLeft);
            }
        } while (toRight < toLeft);
        swap(hInfo, left, toLeft);
        swap(wInfo, left, toLeft);
        sort(wInfo, hInfo, left, toLeft - 1);
        sort(wInfo, hInfo, toLeft + 1, right);
    }
}

void swap(int *arr, int id1, int id2) {
    if (id1 == id2) return;
    arr[id1] ^= arr[id2];
    arr[id2] ^= arr[id1];
    arr[id1] ^= arr[id2];
}
