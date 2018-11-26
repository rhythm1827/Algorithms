#include<bits/stdc++.h>
#define str1 1007
#define str2 1006
#define left 1
#define upp 2
#define NWD 3
using namespace std;
int c[str1][str2];
int b[str1][str2];
void lcsLength(char X[],char Y[])
{
    int m,n,i,j,k;
    m=strlen(X);
    n=strlen(Y);
    for(i=1; i<=m; i++)
        c[i][0]=0;
    for(j=0; j<=n; j++)
        c[0][j]=0;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(X[i-1]==Y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=NWD;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=upp;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=left;
            }
        }
    }
}
/*
void printLcs(int i,int j,char X[],char Y[])
{
    if(i==0||j==0)
        return;
    if(b[i][j]==NWD)
    {
        printLcs(i-1,j-1,X,Y);
        cout<<X[i-1];
    }
    else if(b[i][j]==upp)
    {
        printLcs(i-1,j,X,Y);
    }
    else
    {
        printLcs(i,j-1,X,Y);
    }
}

void show(char X[],char Y[])
{
    int i,j,p,q;
    p=strlen(X);
    q=strlen(Y);
    for(i=0; i<=p; i++)
    {
        for(j=0; j<=q; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=0; i<=p; i++)
    {
        for(j=0; j<=q; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}*/
int main()
{
    int i,j,k,p,len1,len2,q;
    char st1[1009],st2[1009];
    //getchar();
    while(gets(st1))
    {
        gets(st2);
        p=strlen(st1);
        q=strlen(st2);
        lcsLength(st1,st2);
        //show(st1,st2);
        cout<<c[p][q]<<endl;
    }
    return 0;
}


