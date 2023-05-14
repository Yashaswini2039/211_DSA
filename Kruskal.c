//kruskal algorithm
#include<stdio.h>
typedef struct node
{
    int s,d,w;
}node;
void sort(int e,node a[e])
{
    for(int i=0;i<e-1;i++)
    {
        for(int j=0;j<e-i-1;j++)
        {
            if(a[j].w>a[j+1].w)
            {
                node temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void nion(int e,int ar[],int u,int v)
{
    int temp=ar[u];
    for(int i=0;i<e;i++)
    {
        if(temp==ar[i])
        {
            ar[i]=ar[v];
        }
    }

}

void krus(int e,node a[],int ar[])
{
    int sum=0;
   for(int i=0;i<e;i++)
   {
     int j;
     j=find(ar,a[i].s,a[i].d);
     if(j==0)
     {
         sum=sum+a[i].w;
         printf("%d-%d:%d\n",a[i].s,a[i].d,a[i].w);
         nion(e,ar,a[i].s,a[i].d);
     }
   }
   printf("SHORTEST PATH=%d",sum);
}
int find(int ar[],int u,int v)
{
    if(ar[u]==ar[v])
    {
       return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    int v,e;
    printf("ENTER THE NUMBER OF VERTICES and edges\n");
    scanf("%d %d",&v,&e);
     node a[e];
     int ar[e];
     int i;
     for( i=0;i<e;i++)
     {
         ar[i]=i;
     }
    int arr[v][v];
    int d,b,c;
    for(int i=0;i<e;i++)
    {
        scanf("%d %d %d",&d,&b,&c);
        a[i].s=d;
        a[i].d=b;
        a[i].w=c;
        arr[d][b]=c;
    }
    sort(e,a);
    krus(e,a,ar);


}