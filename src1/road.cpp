#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define i2 pair<int,ii>
#define fi first
#define se second
#define vi vector<int>
#define vi2 vector<i2>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
// do dai - gtr - dinh
using namespace std;
const int N = 1e2+3;
int tc,k,n,m,u,v,w,l;
int du,check;
vi2 a[111];
int ok;
void dis()
{
    priority_queue<i2,vi2,greater<i2>> q;
    q.push({0,{1,0}});
    while (q.size())
    {
        du = q.top().fi;
        int u=q.top().se.fi;
        int cost1 = q.top().se.se;
        q.pop();
        if (u==n) {ok=1; return;}
        for (auto e : a[u])
        {{
            int dv = e.fi;
            int v = e.se.fi;
            int cost2 = e.se.se;
            if (cost1+cost2 <= k) {
                q.push({du+dv,{v,cost1+cost2}});
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> tc;
    while (tc--)
    {
        check=0;
        cin >> k >> n >> m;
        while (m--)
        {
            cin >> u >> v >> l >> w;
            a[u].pb({l,{v,w}});
            if (u==n || v==n) check=1;
//            a[v].pb({{l,w},u});
        }
//        cout << check << '\n';
        if (!check){
            cout << -1 << '\n';
            continue;
        }
        dis();
////        cout << d[n][k] << '\n';
//        for (int i = 1; i <= k; i++)
//            cout << d[n][i] << ' ';
//        cout << '\n';
        if (ok) cout << du << '\n'; else cout << -1 << '\n';
        ok=0;
    }
    return 0;
}

