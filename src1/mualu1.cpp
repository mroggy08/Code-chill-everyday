// i'm wutan
#include <bits/stdc++.h>
#define EL cout<<endl
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "flood"
using namespace std;
typedef long long ll;
typedef double db;
void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r",stdin);
        freopen(PROB".out", "w",stdout);
    }
}

const int N = 1002;
int n, m, k, a[N][N], b[N][N], d[N][N];
int xH, xG, yH, yG;
int di[] = {0, -1, 0, 1};
int ci[] = {-1, 0, 1, 0};
vector < pii > pos;

void readinp(){
    cin >> n >> m >> k;
    FU(i, 1, n){
        string s; cin >> s;
        FU(j, 1, m){
            if (s[j - 1] == '.') a[i][j] = 0;
            if (s[j - 1] == 'H') a[i][j] = 1;
            if (s[j - 1] == 'G') a[i][j] = 2;
            if (s[j - 1] == 'S') a[i][j] = 3;
        }
    }
}

bool check (int t){
    FU(i, 1, n) FU(j, 1, m) b[i][j] = d[i][j] = 0;
    queue < pii > Q;
    for (auto o : pos){
        Q.push(o);
        b[o.fi][o.se] = 1;
    }
    while (!Q.empty()){
        int u = Q.front().fi;
        int v = Q.front().se;
//        cout << u << ' ' << v << '\n';
        Q.pop();
        if (b[u][v] >= t) break;
        FU(i, 0, 3){
            int x = u + di[i];
            int y = v + ci[i];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (b[x][y]) continue;
            if (a[x][y]) continue;
            b[x][y] = b[u][v] + 1;
            Q.push({x, y});
        }
    }
    #define iii pair < int , pii >
    priority_queue < iii , vector < iii > , greater < iii > > P;
    FU(i, 1, n) FU(j, 1, m) d[i][j] = 1e9;
    d[xH][yH] = 0;
    P.push({0, {xH, yH}});
    while (!P.empty()){
        int w = P.top().fi;
        int u = P.top().se.fi;
        int v = P.top().se.se;
        P.pop();
//        cout << u << ' ' <<v << '\n';
        if (d[u][v] < w) continue;
        FU(i, 0, 3){
            int x = u + di[i];
            int y = v + ci[i];
//            cout <<x << ' ' << y << '\n';
            if (x < 1 || x > n || y < 1 || y > m) continue;
            int c = (b[x][y] != 0);
//            cout << c << '\n';
            if (d[x][y] > w + c && w + c <= k){
                d[x][y] = w + c;
//                cout <<x  << ' ' << y << '\n';
                P.push({d[x][y], {x, y}});
                cout << P.size() << '\n';
            }
        }
    }
    return (d[xG][yG] <= k);
}

void solve(){
    FU(i, 1, n) FU(j, 1, m)
        if (a[i][j] == 1)
            xH = i, yH = j;
        else if (a[i][j] == 2)
            xG = i, yG = j;
        else if (a[i][j] == 3)
            pos.push_back({i, j});

    int l = 0, r = n + m;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
//    if (r != n + m)
//    cout << r;
//    else cout << -1;
}

int main(){
        if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("2.out","w",stdout);}
    setIO();
    int t = 1;
    while (t--){
        readinp();
        solve();
    }
}
