#include<stdio.h>
#include <stdlib.h>
int adj_mat[20][20],visited[20],v;
int s[20],top=-1;
int q[20],f=-1,r=-1;
void push(int d){
    top++;
    s[top]=d;
}
int pop(){
    int x=s[top];
    top--;
    return x;
}
void enq(int d){
    if (f==-1){
        f++;
    }
    r++;
    q[r]=d;
}
int deq(){
    int it=q[f];
    if (f==r){
        f=-1;
        r=-1;
    }
    else{
    f++;}
    return it;
}
void init(){
    for (int i=0;i<v;i++){
        visited[i]=0;
    }
}
void DFS(int node){
    visited[node]=1;
    push(node);
    while(top!=-1){
        int x=pop();
        printf("%d\t",x);
        int i=0;
        while(i<v){
        if(adj_mat[x][i]==1 && visited[i]==0){
            visited[i]=1;
            push(i);
        }
        i++;
    }
}
}
void BFS(int node){
    visited[node]=1;
    enq(node);
    while(f!=-1){
        int it=deq();
        printf("%d\t",it);
        int i=0;
        while(i<v){
        if(adj_mat[it][i]==1 && visited[i]==0){
            visited[i]=1;
            enq(i);
        }
        i++;
    }
}
}
int main(){
    int v,e,dg,v1,v2;
    printf("Enter v and e:");
    scanf("%d%d",&v,&e);
    printf("directed or undirected gr(0/1):");
    scanf("%d",&dg);
    for (int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            adj_mat[i][j]=0;
        }
    }

    for(int k=1;k<=e;k++){
        printf("Enter the verices of edge %d:",k);
        scanf("%d%d",&v1,&v2);
        adj_mat[v1][v2]=1;
        if(dg==1){
            adj_mat[v2][v1]=1;
        }
    }
    printf("The adj matrix:\n");
    for (int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d\t",adj_mat[i][j]);
        }
        printf("\n");
    }
    printf("DFS:\n");
    init();
    for (int k=0;k<v;k++){
       if (visited[k]==0){
        DFS(k);
       }
    }
    printf("\nBFS:\n");
    init();
    for (int k=0;k<v;k++){
       if (visited[k]==0){
        BFS(k);
       }
    }
    return 0;
   
}