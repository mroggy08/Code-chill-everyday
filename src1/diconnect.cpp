#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)

using namespace std;

const int N = 1e5+3;
const ll inf = 1e18;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
int n,m,u,v,w,f[N],d,t,ok,tr[N];
vi a[N];
void dfs(int u)
{
    f[u]=1;
    for (int v : a[u])
    {
        if (!f[v]) dfs(v);
    }
}
void dfsc(int s)
{
    f[s]=1;
    if (ok) return;
    for (auto v : a[s])
    {
        if (!f[v])
            {
                tr[v]=s;
                dfsc(v);
            }
        else if (f[v] && v!=tr[s])
        {
            ok=1;
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
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        f1(i,1,n) a[i].clear();
        while (m--)
        {
            cin >> u >> v;
            a[u].pb(v);
        }
        f1(i,1,n) f[i]=0;
        d=0;
        f1(i,1,n)
        {
            if (!f[i]) {
                dfs(i);
                d++;
            }
        }
        if (d==1)
        {
            ok = 0;
            f1(i,1,n) {f[i]=0;tr[i]=0;}
            f1(i,1,n)
            {
                if (!f[i])
                {
                    tr[i]=-1;
                    dfsc(i);
                    if (ok) break;

                }
            }
            if (ok) cout << "YES\n";
            else cout << "NO\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

