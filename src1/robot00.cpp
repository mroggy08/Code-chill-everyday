#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair <int, int> i2;
#define ll long long
ll n, m, tmp, ans=INT_MIN;
vector <vector <ll> > a, f,s;
vector <i2> dxy = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll mx(ll a, ll b)
{
    if (a>b) return a;
    return b;
}
ll work(int i, int j)
{
        if (f[i][j])
                return f[i][j];
        int  x, y;
        ll ans = 0;
        for (i2 id : dxy)
        {
                x = i + id.fi;
                y = j + id.se;
                if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] > a[i][j])
                        ans = mx(ans, work(x, y));
        }
        return f[i][j] = ans + s[i][j];
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin >> n >> m;
        a.resize(n, vector <ll> (m));
        f.resize(n, vector <ll> (m));
        s.resize(n, vector <ll> (m));
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        cin >> a[i][j];
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        cin >> s[i][j];
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        ans = max(ans, work(i, j));
        cout << ans;
        return 0;
}
