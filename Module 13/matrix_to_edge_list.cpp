#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define vec vector
#define mat matrix
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Declare matrix as a 2D vector
    vec<vec<int>> mat(n, vec<int>(n));

    // Input the adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    vec<pair<int, int>> edgeList;

    // Traverse the adjacency matrix to find edges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1 && i != j)
            {
                edgeList.pb({i, j});
            }
        }
    }

    // Print the edge list
    for (pair<int, int> edge : edgeList)
    {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}
