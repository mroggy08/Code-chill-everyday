#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 5e2+5;
int n,m,a[N][N],q,u,v;
ll hang[N],cot[N];

int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j  = 1; j <= m; j++){
            cin >> a[i][j];
            hang[i]+=a[i][j];
            cot[j]+=a[i][j];
        }
    }
    cin >> q;
    while (q--){
        cin >> u >> v;
//        cout << hang[u] << ' ' << cot[v] << '\n';
        cout << hang[u] + cot[v] - a[u][v] << '\n';
    }

    return 0;
}
