#include <bits/stdc++.h>
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define file(name)  if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
#define pii pair<int,ii>
using namespace std;
const int N = 1e2+2;
const int K = 1e5+5;
const int oo = 1e9+7;
int k,n,m,u,v[K],L[K],T[K],dp[N][K];
vector<int> a[N];
void Dij(){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,{1,k}});
    dp[1][k] = 0;
    while (q.size()){
        int du = q.top().fi, u = q.top().se.fi, fe = q.top().se.se; q.pop();
        if (du > dp[u][fe]) continue;
        if (u==n) return void(cout << du << '\n');
//        for (int e : a[u]){
//            int dv = L[e], vv = v[e], pe = T[e];
//            if (fe>=pe && dp[vv][fe-pe]>du+dv){
//                dp[vv][fe-pe] = du+dv;
//                q.push({dp[vv][fe-pe],{vv,fe-pe}});
//            }
//        }
        for (int i : a[u]){
            if (fe>=T[i] && dp[v[i]][fe-T[i]] > du + L[i]){
                dp[v[i]][fe-T[i]] = du + L[i];
                q.push({dp[v[i]][fe-T[i]],{v[i],fe-T[i]}});
            }
        }
    }
    cout << "-1\n";
}
void solve(int testcase){
    cin >> k >> n >> m;
    f1(i,1,n) f1(j,0,k) dp[i][j] = oo;
    f1(i,1,n) a[i].clear();
    f1(i,1,m){
        cin >> u >> v[i] >> L[i] >> T[i];
        a[u].push_back(i);
    }
    Dij();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("1");
    int t; cin >> t; for (int test = 1; test <= t; test++) solve(test);
    return 0;
}
