#include<bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define c child
#define vec vector
#define mat matrix
#define ll long long
#define pi pair
using namespace std;
void divide(int a[], int l, int r)
{
    for(int i=l; i<=r; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    if(l<r)
    {
        int mid=(l+r)/2;
        divide(a,l,mid);
        divide(a,mid+1,r);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
     cin>>a[i];
    }
    divide(a,0,n-1);
    return 0;
}