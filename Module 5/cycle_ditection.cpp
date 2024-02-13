#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vist[N];
vector<int> adj[N];
int parentArray[N];
bool ans;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vist[src]=true;
    while (!q.empty())
    {
        int parent=q.front();
        //cout<<parent<<endl;
        q.pop();
        for(int child : adj[parent]){
            if(!vist[child]==true && parentArray[parent]!=child)
            {
                ans=true;
            }
            if(vist[child]==false)
            {
                vist[child]=true;
                parentArray [child]=parent;
                q.push(child);
            }
        }
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin >>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vist,false,sizeof(vist));
    memset(parentArray,-1,sizeof(parentArray));
    ans=false;
    for (int i = 0; i < n; i++)
    {
        if(!vist[i])
        {
            bfs(i);
        }
    }
    if(ans)
    {
        cout<<"cycle Found";
    }
    else
    {
        cout<<"Cycle Not Found";
    }
    return 0;
}