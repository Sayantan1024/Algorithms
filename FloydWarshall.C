#include<stdio.h>
#define SIZE 10
#define INF 999

int minimum(int a, int b){
    return (a<b)?a:b;
}

void display(int mat[SIZE][SIZE], int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, adj[SIZE][SIZE], path[SIZE][SIZE];
    printf("enter no. of vertices: "); scanf("%d",&n);
    printf("enter weighted matrix\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
        printf("\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==INF)
                path[i][j]=INF;
            else
                path[i][j]=adj[i][j];
        }
    }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                path[i][j]=minimum(path[i][j],(path[i][k]+path[k][j]));
    printf("output\n");
    display(path,n);
    return 0;
}
