#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define c child
#define vec vector
#define mat matrix
#define ll long long
#define pi pair
using namespace std;
int dp[1000][1000];
int unbounded_knaps(int n, int s, int val[], int w[])
{
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (w[n - 1] <= s)
    {
        int ch1 = val[n - 1] + unbounded_knaps(n, s - w[n - 1], val, w);
        int ch2 = unbounded_knaps(n - 1, s, val, w);
        return dp[n][s] = max(ch1, ch2);
    }
    else
    {
        return unbounded_knaps(n - 1, s, val, w);
    }
}
int main()
{
    int n;
    cin >> n;
    int val[n], w[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        w[i] = i + 1;
    }
    cout << unbounded_knaps(n, n, val, w) << endl;
    return 0;
}