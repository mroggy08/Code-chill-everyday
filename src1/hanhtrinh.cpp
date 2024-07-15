#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int mm=1e5+5;
int cha[mm],lech,n,m,x,y,l,r,mid,v;
vector <int> a[mm];
ll h[mm],maxx;
void dfs(int u)
{
    for (int i=0;i<a[u].size();i++)
    {
        v=a[u][i];
        if (cha[v]==0 && abs(h[v]-h[u])<=lech){
            cha[v]=u;
            dfs(v);
        }
    }
}
bool check(int k)
{
    lech=k;
    for (int i=1;i<=n;i++) cha[i]=0;
    cha[1]=1;
    dfs(1);
    if (cha[n]>0) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//    freopen("HANHTRINH.inp","r",stdin);
//    freopen("HANHTRINH.out","w",stdout);
    cin>>n>>m;
    maxx=0;
    for (int i=1;i<=n;i++)
    {
        cin>>h[i];
        maxx=max(maxx,h[i]);
    }
    for (int i=1;i<=m;i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    l=0;
    r=maxx;

    while (l<=r)
    {
            int mid=(l+r)/2;
        if (check(mid)==true)
        {
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<l;
return 0;
}

