#include<stdio.h>
#include<stdlib.h>
#define max 100
#include<stdbool.h>
 
typedef struct {
   int arr[max];
   int front,rear;
}Q;
 
void init(Q* q){
   q->front = q->rear =0;
}
 
bool isEmpty(Q q){
   return q.front == q.rear;
}
 
bool isFull(Q q){
   return (q.front == (q.rear+1)%max);
}
 
bool insert(Q* q,int ch){
   if(isFull(*q)) return false;
   q->rear = q->rear+1;
   q->arr[q->rear] = ch;
   return true;
}
 
bool Delete(Q* q,int* ch){
   if(isEmpty(*q)) return false;
   *ch = q->arr[q->front+1];
   q->front = q->front+1;
   return true;
}
 
void print(Q q){
 
   if(isEmpty(q)) return;
   while(q.rear!=q.front){
      q.rear = (q.rear+1)%max;
      printf("%c",q.arr[q.rear]);
   }
   printf("\n");
}
 
 
typedef struct Node{
     int vertex;
     struct Node* next;
} G;
 
G* create(int v){
     G* g = (G*)malloc(sizeof(G));
     g->vertex = v;
     g->next = NULL;
     return g;
}
 
void adjcencyList(int s,G* l[s],int g1[s][s]){
     for(int i=0;i<s;i++){
           l[i] = create(i);
        for(int j=0;j<s;j++){
          if(g1[i][j]==1){
              G* t = l[i];
            while(t->next){
                t = t->next;
            }
            t->next = create(j);
          }
       }
     }
}
 
void matrix_DFS(int s,int g[s][s],int org,int mark[s]){
    printf("%3d",org);
    mark[org] = 1;
    for(int i=0;i<s;i++){
        if(g[org][i]==1 && mark[i]==0)
            matrix_DFS(s,g,i,mark);
    }
}

void matrix_BFS(int s,int g[s][s],int org,int mark[s]){
    Q q;
    init(&q);
    insert(&q,org);
    while(!isEmpty(q)){
        int a;
        Delete(&q,&a);
        printf("%3d",a);
        mark[a]=1;
        for(int i=0;i<s;i++){
            if(mark[i]==0 && g[a][i]==1){
                insert(&q,i);
                mark[i]=1;
            }
        }
    }
}
 
void adjList_DFS(G* l[],int org,int mark[]){
    G* t;
    printf("%3d",org);
    mark[org] = 1;
    t = l[org];
        while(t){ 
            if(mark[t->vertex]==0)
            adjList_DFS(l,t->vertex,mark);
            t = t->next;
        }
}

void adjList_BFS(G* l[],int org,int mark[]){
    Q q;G* t;
    init(&q);
    insert(&q,org);
    while(!isEmpty(q)){
        int a;
        Delete(&q,&a);
        printf("%3d",a);
        mark[a]=1;
        t = l[a];
        while(t){
            if(mark[t->vertex]==0){
                insert(&q,t->vertex);
                mark[t->vertex]=1;
            }
            t = t->next;
        }
    }
}
 
void disp(int s,G* l[]){
     G* t;
     for(int i=0;i<s;i++){
            printf("vertex %d :",i);
            t = l[i];
         while(t->next){
            printf("%3d",t->next->vertex);
            t = t->next;
         }
     printf("\n");
     }
     printf("\n");
}
 
void reset(int s,int m[s]){
     for(int i=0;i<s;i++){
        m[i]=0;
     }
}
 
int main(){
    int s1=7,s2=5;
    int mark1[7]={0};
    int mark2[5]={0};
    int g1[7][7]={{0,0,1,1,0,0,0},{0,0,0,1,1,1,0},{1,0,0,0,0,1,1},
                  {1,1,0,0,0,1,0},{0,1,0,0,0,1,0},{0,1,1,1,1,0,0},
                  {0,0,1,0,0,1,0}};
    int g2[5][5]={{0,1,1,0,0},{1,0,0,0,1},{1,0,0,1,0},
                 {0,0,1,0,1},{0,1,0,1,0}};
                 
    G* l1[s1];G* l2[s2];
    adjcencyList(s1,l1,g1);
    adjcencyList(s2,l2,g2);
    
    printf("AdjacencyList Graph 1:\n");
    disp(s1,l1);
    printf("AdjacencyList Graph 2:\n");
    disp(s2,l2);
    
    printf("DFS by matrix for graph 1: ");
    matrix_DFS(s1,g1,0,mark1);
    printf("\nDFS by matrix for graph 2: ");
    matrix_DFS(s2,g2,0,mark2);
    reset(s1,mark1);
    reset(s2,mark2);
    
    printf("\nBFS by matrix for graph 1: ");
    matrix_BFS(s1,g1,0,mark1);
    printf("\nBFS by matrix for graph 2: ");
    matrix_BFS(s2,g2,0,mark2);
    reset(s1,mark1);
    reset(s2,mark2);
    
    printf("\nDFS by adjacency List for graph 1: ");
    adjList_DFS(l1,0,mark1);
    printf("\nDFS by adjacency List for graph 2: ");
    adjList_DFS(l2,0,mark2);
    reset(s1,mark1);
    reset(s2,mark2);
    
    printf("\nBFS by adjacency List for graph 1: ");
    adjList_BFS(l1,0,mark1);
    printf("\nBFS by adjacency List for graph 2: ");
    adjList_BFS(l2,0,mark2);
    reset(s1,mark1);
    reset(s2,mark2);
    
    printf("\n\n");
 
 
}
 
 
 
 
