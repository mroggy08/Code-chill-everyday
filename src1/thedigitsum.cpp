#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
ll dp(int id, int tong, int gh){
    if (id>n) {
        if (tong==0) return 1; else return 0;
    }
    if (f[id][tong][gh]!=-1) return f[id][tong][gh];
    int z = 0;
    if (gh==1) z = s[id] - '0' ; else z = 9;
    ll res = 0;
    for (int i = 0; i <= z; i++){
        if (gh==0){
            // z = 9;
            res = (res + )
        }
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s >> k;
    n = s.size();
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            for (int z = 0; z <= 1; z++){
                f[i][j][z] = -1;
            }
        }
    }
    s = "0" + s;
    cout << (md + (dp(1,0,1) - 1))%md;
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
