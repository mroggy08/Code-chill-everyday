/*
////////  ଘ(੭*ˊᵕˋ)੭* ̀ˋ////////
////////ଘ(੭ˊᵕˋ)੭* ੈ✩‧˚///////
///////ଘ(🌸o▿o)(≧U≦❁)β///
/////// ଘ(✿˵•́ ᴗ •̀˵)//////
////////ଘ(✿˵•́ ᴗ •̀˵)/////
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200200;
int n,m,h[N],pa[N],p[N],ans;
vector<int>ds[N];
void dfs(int u)
{
    for(int v:ds[u])
    {
        if(v==pa[u])continue;
        h[v]=h[u]+1;
        cout << v << ' ' << h[v] << '\n';
        pa[v]=u;
        dfs(v);
    }
}
int find(int v)
{
    if(p[v]==v)return v;
    return p[v]=find(p[v]);
}
void lca(int A,int B)
{
    int a=A,b=B;
    while(a!=b)
    {
        a=find(a);b=find(b);
        if(a==b)break;
        int ha=h[a],hb=h[b];
//        cout << a << ' ' << ha << ' ' << b << ' ' << hb << '\n';
        if(hb>=ha)
        {
            p[b]=pa[b];
            b=pa[b];
            --ans;
        }
        else
        {
            p[a]=pa[a];
            a=pa[a];
            --ans;
        }
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        ds[a].push_back(b);
        ds[b].push_back(a);
    }
    h[1]=1;pa[1]=1;
    dfs(1);
    ans=n-1;
    for(int i=1;i<=n;++i)p[i]=i;
    cin>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        lca(a,b);
    }
    cout<<ans;
}
