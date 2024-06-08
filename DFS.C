#include<stdio.h>
#define MAX 5
void search(int adj[][MAX],int visit[],int start)
{
    int s[MAX];
    int top=-1,i;
    printf("%c->",start+65);
    visit[start]=1;
    s[++top]=start;
    while(top!=-1)
    {
        start=s[top];
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i] && visit[i]==0)
            {
                s[++top]=i;
                printf("%c->",i+65);
                visit[i]=1;
                break;
            }
        }
        if(i==MAX)
            top--;
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
