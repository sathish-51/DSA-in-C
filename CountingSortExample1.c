#include <stdio.h>
#include <stdlib.h>

typedef struct p{
    int val;char arr[4];
}Pair;

void CountingSort(int n,Pair a[]) {
    Pair k = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].val > k.val) k = a[i];
    }
    int count[k.val + 1];
    for (int i = 0; i <= k.val; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[a[i].val]++;
    }
    for (int i = 1; i <= k.val; i++) {
        count[i] = count[i] + count[i - 1];
    }
    Pair b[n];
    for (int i = n - 1; i >= 0; i--) {
        b[count[a[i].val] - 1] = a[i];
        count[a[i].val]--;
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void print(int n, Pair a[]) {
    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", a[i].val,a[i].arr);
    }
    printf("\n");
}

int main() {
    int n = 50;
    Pair a[50];
    for(int i=0;i<n;i++)
    {
        a[i].val = rand()%25;
        a[i].arr[0]='a';
        if(i<9)
        {a[i].arr[1]='0'+((i+1)%10);a[i].arr[2]='\0';}
        else{
            a[i].arr[1]='0'+((i+1)/10);
            a[i].arr[2]='0'+((i+1)%10);
            a[i].arr[3]='\0';
        }
    }
    printf("Sorted array:  ");
    CountingSort(n, a);
    print(n, a);
    return 0;
}
