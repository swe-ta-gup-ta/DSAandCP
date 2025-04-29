#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r){
    
}

void mergeSort(int arr[], int l, int r){
    if(l >= r) return ;
    int m = l + (r - l) /2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main(){
    int arr = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, n - 1);
}