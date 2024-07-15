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
vector <int> a[100005];
stack <int> st;
ll n,m,x,y,t,s,cha[100005],g[100005];
bool check;
void truyvet(int f,int s)
{
    while (f!=s)
    {
        st.push(f);
        f=cha[f];
    }
    st.push(s);
}
void dfs(int u)
{
    g[u]=1;
    for (int v:a[u])
    {
    if (!g[v]){
        cha[v]=u;
        dfs(v);
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    #define task "inp"
//    if (fopen(task".inp","r")) {
//        freopen(task".inp","r",stdin);
//        freopen(task".out","w",stdout);
//    }
//
    freopen("b1.inp","r",stdin);
    freopen("b1.ans","w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(s);
    if (!g[t]) cout<<-1;
    else {
        truyvet(t,s);
        cout<<st.size()<<'\n';
        while (st.size())
    {
        cout << st.top()<<" ";
        st.pop();
    }
    }
}
