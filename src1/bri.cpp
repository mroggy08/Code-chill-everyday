#include <bits/stdc++.h>

using namespace std;
long long n,m,cc,i,lab[1000005],a,b,c,d;
long long Findset(long long u)
{
    if(lab[u]<0)return u;
    else return lab[u]=Findset(lab[u]);
}
void Union(long long r,long long s)
{
    if(lab[s]<lab[r])swap(r,s);
    lab[r]+=lab[s];
    lab[s]=r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin>>n>>m;cc=n;
    for(i=0;i<n;i++)lab[i]=-1;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        c=Findset(a);d=Findset(b);
        if(c!=d)
        {
            Union(c,d);
            cc--;
            if(cc==1){cout<<i;return 0;}
        }
    }
    return 0;
}
