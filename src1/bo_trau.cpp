#include <bits/stdc++.h>
#define Max 555
#define ll long long
using namespace std;

const int oo = 1e9;

typedef pair<ll,ll> pii;

vector<pii> p[Max];
ll P,n,C,a[Max],d[Max];
bool f[Max],fl[Max];
ll dis[Max][Max];

void dijktra(int x){
    memset(fl,true,sizeof fl);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    for(int i = 1; i <= P; i ++) d[i] = oo;
    d[x] = 0;
    q.push({d[x],x});
    while(!q.empty()){
        pii g = q.top(); q.pop();
        int u = g.second;

        if(!fl[u]) continue;
        fl[u] = false;

        for(auto i : p[u]){
            int v = i.first;
            int kc = i.second;
            if(d[v] > d[u] + kc){
                d[v] = d[u] + kc;
                q.push({d[v],v});
            }
        }

    }
    for(int i = 1; i<= P ; i ++){
        dis[i][x] = d[i];
    }
   // return d[y];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     freopen("task.inp","r",stdin);
    freopen("task.ans","w",stdout);
    memset( f, true, sizeof f);
    cin >> P >> n >> C ;
    for(int i = 1; i <= n ; i ++){
        cin >> a[i];
    }
    for(int i = 1; i <= C; i ++){
        int x,y,ts;
        cin >> x >> y >> ts;
        p[x].push_back({y,ts});
        p[y].push_back({x,ts});
    }

    ll tr = oo;
    int b;

    for(int j = 1; j <= n; j ++){
        dijktra(a[j]);
    }

    for(int i = 1; i <= P ; i++){
        ll o = 0;
        for(int j = 1; j <= n; j ++){
            o += dis[i][a[j]];
        }
        cout << o << ' ';
        if(tr > o){
            b = i;
            tr = o;
        }
    }
    cout << '\n';
    cout << b ;
}

