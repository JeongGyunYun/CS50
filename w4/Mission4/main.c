#include <stdio.h>
#include <stdlib.h>

void sort(int *widthArray, int *heightArray, int left, int right);
void swap(int *arr, int id1, int id2);
int chkNull(FILE *f){
    if(!f){
        fprintf(stderr, "Cannot open the file\n");
        exit(EXIT_FAILURE);
    }
    return 1;
}

int main() {

    char filePath[100];
    printf("Input the file path >> ");
    scanf("%s", filePath);

    FILE *f = fopen(filePath, "r");
    chkNull(f);

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


    int cntMaxValue = 0; //배열의 가장 큰 값의 개수
    int minIndex = roomWidth; //배열의 가장 큰 값 중에서 가장 작은 index

    //배열의 값 중 가장 큰 값을 갖는 원소의 갯수와 가장 큰 값을 갖는 원소 중 가장 작은 원소의 index를 구함
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
void sort(int *widthArray, int *heightArray, int left, int right) {
    int toLeft, toRight, pivot;

    if(left < right) {
        pivot = heightArray[left];
        toRight = left;
        toLeft = right + 1;
        do {
            do toRight++; while (pivot > heightArray[toRight]);
            do toLeft--; while (pivot < heightArray[toLeft]);
            if (toRight < toLeft) {
                swap(heightArray, toRight, toLeft);
                swap(widthArray, toRight, toLeft);
            }
        } while (toRight < toLeft);
        swap(heightArray, left, toLeft);
        swap(widthArray, left, toLeft);
        sort(widthArray, heightArray, left, toLeft - 1);
        sort(widthArray, heightArray, toLeft + 1, right);
    }
}

void swap(int *arr, int id1, int id2) {
    if (id1 == id2) return;
    arr[id1] ^= arr[id2];
    arr[id2] ^= arr[id1];
    arr[id1] ^= arr[id2];
}

