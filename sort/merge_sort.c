/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：merge_sort.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：
*
================================================================*/


#include "tools.h"

typedef struct _HArray {
    int *p;
    int size;
} harray;

harray merge(harray left, harray right) {
    int size = left.size + right.size, i=0;
    int *start_p = left.p;
    int *tarr = malloc(sizeof(int)*size);
    while(left.size && right.size) {
        if (*left.p > *right.p) {
            tarr[i++] = *right.p;
            (right.p)++;
            right.size--;
        }
        else {
            tarr[i++] = *left.p;
            (left.p)++;
            left.size--;
        }
    }
    while(left.size) {
        tarr[i++] = *left.p;
        (left.p)++;
        left.size--;
    }
    while(right.size) {
        tarr[i++] = *right.p;
        (right.p)++;
        right.size--;
    }
    if(i!=size)
        printf("some error!\n");
    for(i=0;i<size;i++)
        *(start_p+i) = tarr[i];
    free(tarr);
    left.size = size;
    left.p = start_p;
    return left;
}

harray _mergeSort(harray harr) {
    if (harr.size < 2)
        return harr;
    harray left, right;
    int mid = harr.size/2;
    left.p = harr.p;
    left.size = mid;
    right.p = harr.p + mid;
    right.size = harr.size - mid;
    return merge(_mergeSort(left), _mergeSort(right));
}

void mergeSort(int arr[], int size) {
    harray harr;
    harr.p = arr;
    harr.size = size;
    _mergeSort(harr);
}

int main() {
    int array[SIZE];
    commonTest(array, SIZE, mergeSort);
    return 0;
}
