#include<stdio.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void insertionSort(int n,int a[]){
    for(int i=0;i<n-1;i++){
            int flag = 0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag=1;
            }
        }
        if(flag==0)return;  //flag is used for optimization
    }    
}

void print(int n,int a[]){
    for(int i=0;i<n;i++){
        printf("%3d",a[i]);
    }
    printf("\n");
}

int main(){
    int n=9;
    int a[9] = {5,3,7,4,2,9,8,1,6};
    insertionSort(n,a);
    printf("Bubble sort: ");
    print(n,a);
  return 0;
}
