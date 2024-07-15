#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
using namespace std;
const int N = 1e6+3;
const int mm=1e6+5;
vii a[mm];
ll d[mm],m,n,s,t,dv,du,u,v,w;
void dij(int s)
{
    priority_queue<ii,vector<ii>,greater<ii> > q;
    q.push({0,s});
    for (int i=1;i<=n;i++) d[i]=1e18;
    d[s]=0;
        while (q.size())
        {
            du=q.top().fi;
            u=q.top().se;
            q.pop();
            if (du>d[u]) continue;
            for (auto it:a[u])
            {
                dv=it.fi;
                v=it    .se;
                if (d[v]>du+dv){
                    d[v]=du+dv;
                    q.push({d[v],v});
                }
            }
        }
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++){
        cin>>u>>v>>w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    dij(s);
    cout<<d[t];
  return 0;
}

