#include<bits/stdc++.h>
#define pb push_back
#define vec vector
#define mat matrix
using namespace std;
void convert(int n,vec<int>adj[])
{
    int mat[n][n];
    memset(mat,0,sizeof(mat));
    for(int i=0; i<n; i++)
    {
        for(int child: adj[i])
        {
            mat[i][child]=1;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vec<int> v[n];
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    convert(n,v);
    
    return 0;
}