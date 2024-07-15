#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define __ThanhDat int main
#define ii pair<int,int>
using namespace std;
const int N = 1e6+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n,m,ha,sa,hb,sb,u,v,w,ok,nut;
std::vector<ii> a[5003];
vector<int> A,B;
ll d1[103],d2[103],mi=1e18;
void dis1(int u, int t){
    priority_queue<ii, vector<ii>, greater<ii>> q;
    for (int i=1; i<=n ;i++) d1[i] = 1e18;
    d1[u]=0;
    q.push({0,u});
    while (q.size()){
        int u = q.top().se;
        ll du = q.top().fi;
        q.pop();
        if (du > d1[u]) continue;
        for (auto it : a[u]){
            int v = it.se;
            ll dv = it.fi;
            if (d1[v]>dv+du){
                d1[v] = dv+du;
                if (v!=t) A.push_back(v);
//                else return;
                q.push({d1[v],v});
            }
        }
    }
}
void dis2(int u, int t){
    priority_queue<ii, vector<ii>, greater<ii>> q;
    for (int i=1; i<=n ;i++) d2[i] = 1e18;
    d2[u]=0;
    q.push({0,u});
    while (q.size()){
        int u = q.top().se;
        ll du = q.top().fi;
        q.pop();
        if (du > d2[u]) continue;
        for (auto it : a[u]){
            int v = it.se;
            ll dv = it.fi;
            if (d2[v]>dv+du){
                d2[v] = dv+du;
                if (v!=t) B.push_back(v);
//                else return;
                q.push({d2[v],v});
            }
        }
    }
}
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
    	freopen(task".inp","r",stdin);
    	freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    cin >> ha >> sa >> hb >> sb;
    while (m--){
    	cin >> u >> v >> w;
    	a[u].push_back({w,v});
    	a[v].push_back({w,u});
    }
    dis1(ha,sa); dis2(hb,sb);
//    cout << d1[sa] << ' ' << d2[sb];
    for (int i=0; i<A.size(); i++){
        for(int j=0; j<B.size(); j++){
            if (A[i]==B[j]){
                if (d1[A[i]]==d2[B[j]]){
                        ok=1;
                        if (d1[A[i]]<mi){
                        mi = d1[A[i]];
                        nut = A[i];
                    }
                }
            }
        }
    }
    if (!ok) cout << "NO";
    else {
        cout << "YES\n" << d1[sa] << '\n' << d2[sb] << '\n' << nut << '\n' << mi;
    }
    return 0;
}
