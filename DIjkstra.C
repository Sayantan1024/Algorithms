#include<stdio.h>
#include<stdbool.h>
#define INF 999
#define V 5

int minDist(int dist[], bool sptSet[]) {
    int min = INF, idx;
    for(int v=0;v<V;v++)
    if(sptSet[v]==false && dist[v]<min) {
        min = dist[v]; idx = v;
    }
    return idx;
}

void print(int dist[])
{
    printf("Vertex \t Distance\n");
    for(int i=0;i<V;i++)
        printf("%d \t %d\n",i,dist[i]);
}

void dijkstra(int graph[V][V], int s) {
    int dist[V]; bool sptSet[V];
    for(int v=0;v<V;v++)
    {
        dist[v]=INF; sptSet[v]=false;
    }
    dist[s]=0;
    for(int i=0;i<V-1;i++)
    {
        int u = minDist(dist,sptSet);
        sptSet[u]=true;
        for(int j=0;j<V;j++)
            if(!sptSet[j] && graph[u][j] && dist[u]!=INF && dist[u]+graph[u][j]<dist[j])
                dist[j] = dist[u]+graph[u][j];
    }
    print(dist);
}

int main()
{
    int graph[V][V];
    printf("enter adjacency matrix\n");
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    dijkstra(graph,0);
    return 0;
}
