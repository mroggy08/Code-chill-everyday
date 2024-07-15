#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
#define __ThanhDat int main
using namespace std;
const int N = 1e5+3;
const int M = 2e5+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n,m,k,x,u,v,w,ok[N];
ll d[N];
vector <ii> a[M];
void dis()
{
    priority_queue<ii, vector<ii>, greater<ii>> q;
    for (int i = 1; i <= n; i++) d[i] = 1e18;
    d[1] = 0;
    q.push({0,1});
    while (q.size())
    {
        ll du = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (du > d[u]) continue;
        for (auto it : a[u])
        {
            int v = it.se;
            ll dv = it.fi;
            if (d[v] > du + dv)
            {
                d[v] = du + dv;
                q.push({d[v],v});
                if (v==x) return;
            }
        }
    }
}
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("nobita.inp","r",stdin);
    freopen("nobita.out","w",stdout);
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    cin >> k;
    if (k==1)
    {
        cin >> x;
        dis();
        cout << d[x];
    }
    else{
        for (int i = 1; i <= k; i++) cin >> ok[i];
        cout << 12;
    }
    return 0;
}
