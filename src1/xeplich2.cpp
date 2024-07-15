#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define li pair<long long,int>

using namespace std;

const int N = 1007;
int n, L, C, a[N];
li f[N][N];

long long cal(int t)
{
    if (!t) return 0;
    return t <= 10 ? -C : (t - 10) * (t - 10);
}

li dp(int id, int k, int gr)
{
    if (id > n) return {0, gr - 1};
    if (f[id][k].fi != 1e15) return f[id][k];
    li ans1 = {1e15, 0}, ans2;
    if (k + a[id + 1] <= L)
        ans1 = dp(id + 1, k + a[id + 1], gr);
    ans2 = dp(id + 1, a[id + 1], gr + 1);
    ans2.fi += cal(L - k);
    return f[id][k] = min(ans1, ans2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
//    if (fopen("task.inp","r")) {
//        freopen("task.inp","r",stdin);
//        freopen("task.out","w",stdout);
//    }
    cin >> n >> L >> C;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= L; j++)
                f[i][j].fi = 1e15;
    a[n + 1] = 1e9;
    li tmp = dp(1, a[1], 1);
    cout << tmp.se << "\n" << tmp.fi;
    return 0;
}
