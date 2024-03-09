/**************************************
 https://codeforces.com/problemset/problem/20/C
*************************************/
#include<bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define c child
#define vec vector
#define mat matrix
#define pi pair
#define ll long long 
using namespace std;

const ll N = 1e5 + 5;
vec<pi<ll, ll>> v[N]; 
ll dis[N];
ll par[N];
class cmp {
public:
    bool operator()(pi<ll, ll> a, pi<ll, ll> b) {
        return a.second > b.second;
    }
};

void dijkstra(int s) {
    priority_queue<pi<ll, ll>, vec<pi<ll, ll>>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty()) {
        pi<ll, ll> parent = pq.top();
        pq.pop();
        ll parentNode = parent.first;
        ll parentCost = parent.second;
        for (pi<ll, ll> child : v[parentNode]) {
            ll childNode = child.first;
            ll childCost = child.second;
            if (parentCost + childCost < dis[childNode]) {
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]});
                par[childNode]=parentNode;
            }
        }
    }
}

int main() {
    ll n, e;
    cin >> n >> e;
    while (e--) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b, c});
        v[b].pb({a, c});
    }
    for (ll i = 1; i <= n; i++) {
        dis[i] = 1e18;
        par[i]=-1;
    }
    dijkstra(1);
    if(dis[n]==1e18)
    {
        cout<<-1<<endl;
    }
    else
    {
    ll x=n;
    vec<ll> path;

    while (x!=-1)
    {
        path.pb(x);
        x=par[x];
    }
    reverse(path.begin(),path.end());
    for(ll val: path)
    cout<<val<<" ";
    cout<<endl;
    }
    return 0;
}
