#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct co {
     int x1,y1,x2,y2;
     double length;
}Line;

double len(Line l)
{
    return sqrt(pow((l.x2-l.x1),2)+pow((l.y2-l.y1),2));
}

void swap(Line *a,Line *b){
    Line temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Line a[],int n,int i){
    int largest = i;
    int left =  2*i+1;
    int right =  2*i+2;
    if(left<n && a[left].length>a[largest].length){
        largest = left;
    }
    if(right<n && a[right].length>a[largest].length){
        largest = right;
    }
    if(i!=largest){
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);}
}

void HeapSort(int n,Line a[]){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&a[i],&a[0]);
        heapify(a,i,0);
    }
}

void print(int n,Line a[]){
    for(int i=0;i<n;i++){
        printf("%.2f  ",a[i].length);
    }
    printf("\n");
}


int main()
{
    Line l[5];
    l[0] = (Line){4,0,7,9,0};
    l[1]=(Line){5,8,6,2,0};
    l[2] =(Line){4,1,7,8,0};
    l[3]=(Line){2,5,9,3,0};
    l[4] = (Line){1,0,2,0,0};
    for(int i=0;i<5;i++)
        l[i].length = len(l[i]);
    HeapSort(5,l);
    print(5,l);
  return 0;
}

