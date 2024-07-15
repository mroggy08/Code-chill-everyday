#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
int n,m,a[102],b[102];
ll f[102][100003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            f[i][j] = f[i-1][j];
            if (j >= a[i]) f[i][j] = max(f[i][j],f[i-1][j-a[i]] + b[i]);
        }
    }
    cout << f[n][m] << '\n';
    vector <int> kq;
    int i = n, j = m;
    while (i > 0){
        if (f[i][j]!=f[i-1][j]){
            kq.push_back(i);
            j-=a[i];
        }
        i--;
    }
    reverse(kq.begin(),kq.end());
    cout << kq.size() << '\n'; for (auto it : kq) cout << it << ' ';
    return 0;
}

