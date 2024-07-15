#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair <int,pii>

const int HH = 102;

int k , n , r , ans;
bool l;
vector <piii> ds[HH];

void Dijkstra(){
    priority_queue < piii , vector <piii> , greater<piii> > q;
    q.push ( { 0 , { 1 , 0 } } );
    while (!q.empty()){

        ans = q.top().fi;
        int price = q.top().se.se;
        int u = q.top().se.fi;
        q.pop();

        if (u == n) { l = true; return; }

        for (auto E : ds[u]){
            int v = E.se.fi;
            int cost = E.se.se;
            int w = E.fi;
            if ( cost + price <= k ){
                q.push( { ans + w , { v , cost + price } } );
            }
        }

    }
}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.ans","w",stdout);
    int t; cin >> t;
    while (t--){

        cin >> k >> n >> r;
        for (int i = 1; i <= n; i++) ds[i].clear();
        for (int i = 1; i <= r; i++){
            int S , D , L , T;
            cin >> S >> D >> L >> T;
            ds[S].pb ( { L , { D , T } } );
        }

        l = false;
        Dijkstra();

        if (l) cout << ans;
        else cout << -1;
        cout << '\n';

    }

}

