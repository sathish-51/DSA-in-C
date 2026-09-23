#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int left,int mid,int right){
    int i = left, j = mid+1, k = 0;
    int *b = (int *)malloc((right - left + 1) * sizeof(*b));
    while(i<=mid && j<=right){
        if(a[i]<=a[j])b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=right){
        b[k++]=a[j++];
    }
    for(int s=0;s<right-left+1;s++){
        a[left+s]=b[s];
    }
    free(b);
}

void MergeSort(int a[],int left,int right){
    if(left<right){
        int mid = left+(right-left)/2;
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

void print(int n,int a[]){
    for(int i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[] = {5,3,7,1,6,4,9,2,8};
    printf("Sorted array:  ");
    MergeSort(a,0,8);    
    print(9,a);

    return 0;
}
