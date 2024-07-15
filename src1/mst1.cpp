#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define vi2 vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0)

using namespace std;

const int N = 5007;
int n,m,f[N],s[N];
struct node
{
   int u,v,w;
};
vector <node> a;
bool cmd(node a, node b)
{
    return a.w < b.w;
}

void make_set()
{
   f1(i,1,n) f[i]=i;
}
int Find(int v)
{
    if (v==f[v]) return v;
    return f[v] = Find(f[v]);
}
bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a==b) return 0;
    f[b]=a;
    return 1;
}
void kruskal()
{
    int  d2 = 0,d1=0;
    for (int i = 0; i < a.size(); i++)
    {
        if (d1 == n-1) break;
        node e = a[i];
        if (Union(e.u,e.v))
        {
            cout << e.u << ' ' << e.v << '\n';

            d1++;
            d2+=e.w;
        }
    }
    cout << (d1!=n-1 ? -1 : d2);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("2.out","w",stdout);}
    cin >> n >> m;
    while (m--)
    {
        int U,V,W;
        cin >> U >> V >> W;
        a.pb({U,V,W});
    }
    sort(a.begin(),a.end(),cmd);
//    for (int i = 0; i < a.size(); i++){
//        cout << a[i].u << ' ' << a[i].v << ' ' << a[i].w << '\n';
//    }
    make_set();
    kruskal();
    return 0;
}
