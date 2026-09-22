#include<stdio.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void bubblesort(int n,int a[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(&a[i],&a[j]);
            }
        }
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
    bubblesort(n,a);
    printf("Bubble sort: ");
    print(n,a);
  return 0;
}
