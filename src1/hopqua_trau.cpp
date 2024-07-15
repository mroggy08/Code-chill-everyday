#include <bits/stdc++.h>
using namespace std;
long long k,l,r,mid,g,c,d,x,y,z,n;
int i,j;
long long a[2000001];
int main()
{
    freopen("task.inp", "r" ,stdin);
    freopen("task.ans", "w" ,stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n-2;i++)
    {
        l=i+2; r=n; g=-1e18;
        while (l<=r)
        {
            mid=(l+r)/2;
            c=a[mid]-a[i];
            if (c<=k)
            {
                if (mid>g) g=mid;
                l=mid+1;
            } else r=mid-1;
        }
        if (g!=-1e18)
        {
            z=g-i-1;
            z=z*(z+1)/2;
            d=d+z;
        }
    }
    cout<<d;
}
