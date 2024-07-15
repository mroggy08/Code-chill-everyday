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
const int N = 1e5+3;
int n,k,x,g[N],d,u,v,ch[N],m;
vi a[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> n >> k;
    memset(ch,-1,sizeof ch);
    queue <int> q;
    f1(i,1,k) cin >> x,ch[x]=0,q.push(x);
    cin >> m;
    while (m--)
    {
        cin >> u >> v;
        a[v].pb(u);
        a[u].pb(v);
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto it : a[u])
        {
            if (ch[it]==-1)
            {
                ch[it] = ch[u] + 1;
                q.push(it);
            }
        }
    }
    f1(i,1,n) cout << ch[i] << ' ';
    return 0;
}

