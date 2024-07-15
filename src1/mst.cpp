#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
struct sv{
    int u,v,w;
};
const int N = 3e5+5;
int n,m,a,b,c,f[N];
vector <sv> e;
int tim(int u){
    if (u==f[u]) return u;
    return f[u]=tim(f[u]);
}
bool tron(int a, int b){
    a = tim(a); b = tim(b);
    if (a==b) return 0;
    f[b] = a;
    return 1;
}
bool cmd(sv a, sv b){
    return a.w < b.w;
}
int res;
ll kq,d;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        e.pb({a,b,c});
    }
    sort(e.begin(),e.end(),cmd);
    for (int i = 1; i <= n; i++) f[i]=i;

    for (int i = 0; i < e.size(); i++){
        if (d==n-1) break;
        if (tron(e[i].u,e[i].v)){
            kq+=e[i].w;
            res = max(res,e[i].w);
            d++;
        }
    }
    cout << res;
    return 0;
}
