#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+9;
int n,A,B,d[N],tr[N],val[N],check[N],mx1,mx2,f[N],w,u,v,kq;
vector <ii> a[N];
vector <int> Val;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> A >> B;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    queue <int> q;
    q.push(A);
    d[A]=1e9;
    f[A]=1;
    while (q.size()){
        int u = q.front();
//        cout << u << ' ';
        q.pop();
        for (ii e : a[u]){
            int dv = e.first, v = e.second;
            if (!f[v]){
//                cout << v << ' ';
                f[v]=1;
                q.push(v);
                val[v] = dv;
                d[v]=min(d[u],dv);
//                cout << d[v] << ' ';
                tr[v]=u;
            }
        }
    }
    cout << '\n';
    int C=B;
    while (C!=A){
        Val.push_back(val[C]);
//        cout << C << ' ';
        C=tr[C];
        check[C] = 1;
    }
    for (ii e : a[A]){
        int dv = e.first,v = e.second;
        if (!check[v]){
            mx1=max(mx1,dv);
        }
    }
    for (ii e : a[B]){
        int dv = e.first,v = e.second;
        if (!check[v]){
            mx2=max(mx2,dv);
        }
    }
    // mx1,mx2 dinh ke a,b dell nam tren path
    // Val ::: path
    kq = d[B] + min(mx1,mx2);
//    for (int e : Val) cout << e << ' ';
//    cout << d[B] << ' ' << mx1 << ' ' << mx2 << '\n';
    reverse(Val.begin(),Val.end());
    if (Val.size()>=3){
        kq = max(kq,min(Val[0],Val[Val.size()-1]));
    }
//    cout << kq << ' ';
    for (int i = 0; i < Val.size(); i++) Val[i]-=d[B];
    kq = max(kq,d[B]+min(mx1,Val[Val.size()-1]));
    cout << kq;
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
