/*************************
 * https://www.hackerrank.com/contests/phitron-monthly-programming-contest-a-batch-04-a-feb-2024/challenges/romeo-and-juliet-2
 *************************/
#include<bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define c child
#define vec vector
#define mat matrix
using namespace std;

const int N = 1e5 + 5;
vec<int> v[N];
bool vis[N];
int dis[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!q.empty()) {
        int par = q.front();
        q.pop();
        for (int c : v[par]) {
            if (!vis[c]) {
                vis[c] = true;
                q.push(c);
                dis[c] = dis[par] + 1;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    while (e--) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    int src, d, k;
    cin >> src >> d >> k;
    bfs(src);
    if (dis[d] != -1 && dis[d] <= k * 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
