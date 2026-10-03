#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int reg_no;
    int credits;
    double cgpa;
} STUD;

void merge(STUD a[],int left,int mid,int right){
    int i = left, j = mid+1, k = 0;
    STUD *b = (STUD *)malloc((right - left + 1) * sizeof(STUD));
    while(i<=mid && j<=right){
        if(a[i].reg_no<=a[j].reg_no)b[k++]=a[i++];
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

void MergeSort(STUD a[],int left,int right){
    if(left<right){
        int mid = left+(right-left)/2;
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

void print(int n,STUD a[]){
    for(int i=0;i<n;i++){
        printf("%d  ",a[i].reg_no);
        printf("%d  ",a[i].credits);
        printf("%.2f  \n",a[i].cgpa);
    }
    printf("\n");
}

int main()
{   
    STUD *s = (STUD*)malloc(sizeof(STUD)*4);
    s[0] = (STUD){3503,100,10.0};
    s[1] = (STUD){3502,56,6.0};
    s[2] = (STUD){3504,90,9.0};
    s[3] = (STUD){3501,88,8.0};
    MergeSort(s,0,3);
    print(4,s);
    return 0;
}

