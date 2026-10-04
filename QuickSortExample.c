#include<stdio.h>
#include<stdlib.h>

typedef struct student {
    int regNo;
    int day,month,year;
} STUD;

void swap(STUD *a,STUD *b){
    STUD t=*a;
    *a=*b;
    *b=t;
}

int compare(STUD s1,STUD s2){
    if(s1.year>s2.year) return 1;
    else if(s1.year<s2.year) return 0;
    if(s1.month>s2.month) return 1;
    else if(s1.month<s2.month) return 0;
    if(s1.day>s2.day) return 1;
    else if(s1.day<s2.day) return 0;
    return 0;
}

int partition(STUD a[],int left,int right){
    STUD pivot = a[left];
      int i=left;
        for(int j=left+1;j<=right;j++){
            if(compare(pivot,a[j])){
                i++;
                swap(&a[i],&a[j]);
            }
        }
        swap(&a[left],&a[i]);
        return i;
}

void QuickSort(STUD a[],int left,int right){
    if(left<right){
        int k = partition(a,left,right);
        QuickSort(a,left,k-1);
        QuickSort(a,k+1,right);
    }
}

void print(int n,STUD a[]){
    for(int i=0;i<n;i++){
        printf("%d - %02d:%02d:%04d \n",a[i].regNo,a[i].day,a[i].month,a[i].year);
    }
    printf("\n");
}

int main(){
    STUD s[4] = { {3503,22,4,2007},{3063,22,4,2007},
                  {3035,25,11,2007},{3057,10,2,2008}};
    QuickSort(s,0,3);
    print(4,s);
  return 0;
}
