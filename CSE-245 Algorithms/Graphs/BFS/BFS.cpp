#include<bits/stdc++.h>
#define SIZE 50
using namespace std;
int mat[SIZE][SIZE];
struct Node
{
    int color;
    int d;
    int parant;
};
struct Node G[SIZE];
int Q[SIZE];
int rear=0,front=0;
void ENQUEUE(int t)
{
    Q[rear]=t;
    rear ++;
}
int DEQUEUE()
{
    return Q[front++];
}
void BFS(int n,int s)
{
    int i,u,v;
    for(i=1;i<=n;i++)
    {
        G[i].color=0;
        G[i].d=INT_MAX;
        G[i].parant=-1;
    }
    G[s].color=1;
    G[s].d=0;
    G[s].parant=-1;
    ENQUEUE(s);
    while(rear!=front)
    {
        u=DEQUEUE();
        for(v=1;v<=SIZE;v++)
        {
            if(G[v].color==0&&mat[u][v]==1)
            {
                G[v].color=1;
                G[v].d=G[u].d+1;
                G[v].parant=u;
                ENQUEUE(v);
            }
        }
        G[u].color=2;
    }
}
void show(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<G[i].d<<" "<<G[i].parant<<endl;
    }
}
int main()
{
    int i,j,k,a,b,n,p;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cin>>p;
    cout<<endl;
    BFS(n,p);
    show(n);
    return 0;
}
