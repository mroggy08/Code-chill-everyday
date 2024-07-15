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
#define inf INT_MAX
using namespace std;
const int N = 1e6+3;
void dfs(int u, int pre)
{
    int c =0;
    low[u] = num[u] = ++d;
    for (auto v : a[u])
    {
        if (v==pre) continue;
        if (num[v]) low[u] = min(low[u],num[v]);
        else {
                dfs(v,u);
            low[u] = min(low[u],low[v]);
            c++;
            if (low[v]==num[v]) cau++;
            if (u==pre)
            {
                if (c>1) khop[u]=1;
            }
            else if (low[v] >= num[u]) khop[u]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    return 0;
}

