#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
const int maxn=1e5+5;
int n,A,B;
vector<ii> a[maxn];
vector<int> b;
int c[maxn],d[maxn],gt[maxn];
bool visited[maxn],kt[maxn];
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>A>>B;
    for (int i=1;i<=n-1;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    }
    //maxflow
    queue<int> q;
    q.push(A);
    d[A]=1e9;
    visited[A]=true;
    c[A]=A;
    while (q.size()>0)
    {
        int u=q.front();
//        cout << u << ' ';
        q.pop();
        for (ii i: a[u])
        {
            int v=i.fi,w=i.se;
            if (!visited[v])
            {
//                cout << v << ' ';
                c[v]=u;
                gt[v]=w;
                d[v]=min(w,d[u]);
                cout << d[v] << ' ';
                q.push(v);
                visited[v]=true;
            }
        }
    }
    cout << '\n';
    int v=B;
    memset(kt,true,sizeof(kt));
    while (c[v] != v)
    {
        b.push_back(gt[v]);
        v=c[v];
        kt[v]=false;
    }
    int max1=0,max2=0;
    for(ii i: a[A])
    {
        int u=i.fi,v=i.se;
        if (kt[u])
        {
            max1=max(max1,v);
        }
    }
    for(ii i: a[B])
    {
        int u=i.fi,v=i.se;
        if (kt[u])
        {
            max2=max(max2,v);
        }
    }
    int res=d[B]+min(max1,max2);
    cout << d[B] << ' ' << max1 << ' ' << max2 << '\n';
    reverse(b.begin(),b.end());
    if (b.size() >= 3)
    {
        res=max(res,min(b[0],b[b.size()-1]));
    }
    cout << res << ' ';
    for (int i=0;i<=b.size()-1;i++)
    {
        b[i]-=d[B];
    }
    res=max(res,d[B]+min(max1,b[b.size()-1]));
    cout<<res;
    return 0;
}

