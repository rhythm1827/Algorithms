#include<bits/stdc++.h>
#define str1 7
#define str2 6
#define left 1
#define upp 2
#define NWD 3

char X[]="ABCBDAB",Y[]="BDCABA";
//char X[]=" ABCBDAB",Y[]=" ABCBDAB";
using namespace std;
int c[str1+1][str2+1];
int b[str1+1][str2+1];
void lcsLength()
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
void printLcs(int i,int j)
{
    if(i==0||j==0)
        return;
    if(b[i][j]==NWD)
    {
        printLcs(i-1,j-1);
        cout<<X[i-1];
    }
    else if(b[i][j]==upp)
    {
        printLcs(i-1,j);
    }
    else
    {
        printLcs(i,j-1);
    }
}
void show()
{
    int i,j;
    for(i=0; i<=str1; i++)
    {
        for(j=0; j<=str2; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=0; i<=str1; i++)
    {
        for(j=0; j<=str2; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    lcsLength();
    int i,j;
    i=strlen(X);
    j=strlen(Y);
    printLcs(i,j);
    cout<<endl<<endl;
    show();
    return 0;
}

