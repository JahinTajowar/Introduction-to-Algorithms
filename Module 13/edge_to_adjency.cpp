#include<bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define c child
#define vec vector
#define mat matrix
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vec<pair<int,int>> v[n];
    while (e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].pb({b,c});
    }
    for(int i=0; i<n; i++)
    {
        cout<<i<<" -> ";
        for( pair<int,int> c: v[i])
        {
            cout<<"{"<< c.first<<"," << c.second<<"}";
        }
        cout<<endl; 
    }
    
    return 0;
}