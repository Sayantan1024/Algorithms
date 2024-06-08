#include<stdio.h>
#define MAX 5
void search(int adj[MAX][MAX],int visit[],int start)
{
    int q[MAX],rear=-1,front=-1;
    q[++rear]=start;
    visit[start]=1;
    while(rear!=front)
    {
        start=q[++front];
        if(start==5)
            break;
        else
            printf("%c ",start+65);

        for(int i=0;i<MAX;i++)
        {
            if(adj[start][i]==1 && visit[i]==0)
            {
                q[++rear]=i;
                visit[i]=1;
            }
        }
    }
}

int main()
{
    int visited[MAX]={0};
    int adj[MAX][MAX];
    printf("enter matrix\n");
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
            scanf("%d",&adj[i][j]);
        printf("\n");
    }
    search(adj,visited,0);
    return 0;
}
