#include<bits/stdc++.h>
using namespace std;
long long n,x,a[100000],dp[501][501],dp1[100000],s,w;
void lis()
{
    int res=0;
    for (int i=1;i<=n;i++)
    {
        dp1[i]=1e5;
        int k=lower_bound(dp1+1,dp1+1+res,a[i])-dp1;
        res=max(res,k);
        dp1[k]=a[i];
    }
    cout<<res;
}
void sub2()


{
    int kq = 0;
    f1(i,1,n) f[i][1] = a[1];
    f1(k,2,n)
    {
        f1(i,1,n)
        {
            f[i][k] = 1e9;
            f1(j,1,i-1)
            {
                if (a[j] < a[i]) f[i][k] = min(f[i][k],f[j][k-1] + a[i]);
            }
        }
    }
}
void daycon()
{
//    int res=0;
    for (int i=1;i<=n;i++) dp[i][1]=a[i];
    for (int k=2;k<=n;k++)
        for (int i=1;i<=n;i++)
        {
            dp[i][k]=1e9;
            {
                for (int j=1;j<i;j++)
                {
                    if (a[j]<a[i]) dp[i][k]=min(dp[i][k],dp[j][k-1]+a[i]);
                }
            }
        }
    for (int k=n;k>=1;k--)
    {
        for (int i=1;i<=n;i++)
        {
            if (dp[i][k]<=w) { cout<<k; return;}
        }
    }
}
int main()
{
    //freopen("daycon.inp","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>w;
    for (int i=1;i<=n;i++) cin>>a[i], s+=a[i];
    if (w==s) lis();else daycon();
return 0;
}
