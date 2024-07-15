#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define __ThanhDat int main

using namespace std;
const int mm=100005;
vector <int> a[100005];
//stack <int> st;
int n,m,x,y,t,s,cha[100005],g[mm],h[mm],p[mm],kq[mm] ;

void dfs1(int u)
{
    g[u]=1;
    for (auto v : a[u])
    {
        if (!g[v])
        {
            p[v]=u;
            dfs1(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      freopen("b1.inp","r",stdin);
    freopen("b1.out","w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    dfs1(s);
    if (g[t])
    {
//        cout << "YES\n";
        int c = t,cnt=0;
        while (c!=s)
        {
            cnt++;
            kq[cnt]=c;
            c=p[c];
        }
        kq[++cnt]=s;
        cout << cnt << '\n';
        for (int i=cnt;i>=1;i--) cout<<kq[i]<<" ";
    }
    else cout  << "-1";
}

