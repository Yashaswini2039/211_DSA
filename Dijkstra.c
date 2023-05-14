#include <stdio.h>
#include <stdlib.h>
#define INFINITY 999999

void Dijkstra(int v,int graph[v][v],int src)
{
    int cost[v][v],visited[v],path[v],distance[v];
    int nextnode;
    int count;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(graph[i][j]==0)
            {
                cost[i][j]=INFINITY;

            }
            else
            {

                cost[i][j]=graph[i][j];
            }
        }
    }
    int mindistance;

    for(int i=0;i<v;i++)
    {
        distance[i]=cost[src][i];
        path[i]=src;
        visited[i]=0;

    }
    distance[src]=0;
    visited[src]=1;
    count=1;

    while(count<v)
    {
        mindistance=INFINITY;
        for(int i=0;i<v;i++)
        {
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;

        for(int i=0;i<v;i++)
        {
            if(mindistance+cost[nextnode][i]<distance[i]&&!visited[i])
            {
                distance[i]=mindistance+cost[nextnode][i];
                path[i]=nextnode;
            }
        }
        count++;

    }
    int sum=0;
    for(int i=0;i<v;i++)
    {
        if(i!=src && distance[i]!=INFINITY)
        {
            printf("distance from source to %d : %d\n",i,distance[i]);
            sum=sum+distance[i];
        }
    }
    printf("%d\n",sum);
}

int main()
{
    int v;
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    int graph[v][v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            graph[i][j]=0;
        }
    }
    int edges;
    printf("Enter the number of edges\n");
    scanf("%d",&edges);
    for(int i=0;i<edges;i++)
    {
        printf("Enter the edges\n");
        int s,d,w;
        scanf("%d %d %d",&s,&d,&w);
        graph[s][d]=w;
    }
    int source;
    printf("Enter the source vertex\n");
    scanf("%d",&source);
    Dijkstra(v,graph,source);
    return 0;
}
