#include <bits/stdc++.h>
 
using namespace std;
string x, y, kq = "";
int L[2002][2002];
void qhd() {
    memset(L, 0, sizeof(L));
    int m = x.length(), n = y.length();
    x = ' ' + x;
    y = ' ' + y;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (x[i] == y[j])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    int i = m, j = n;
    while (kq.size() != L[m][n]) {
        if (x[i] == y[j]) {
            kq.push_back(x[i]);
            i--;
            j--;
        } else if (L[i][j - 1] == L[i][j])
            j--;
        else
            i--;
    }
    reverse(kq.begin(), kq.end());
    for (auto x : kq) cout << x;
    /*string res;
    int _max = f[n][m];
    FOR2(i, n, 1)
    FOR2(j, m, 1)
    if (f[i][j] == _max && a[i] == b[j]) {
        _max--;
        res.push_back(a[i]);
        break;
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";  */
}
 
int main() {
    ios::sync_with_stdio(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin.tie(0);
    cout.tie(0);
    cin >> x;
    cin >> y;
    qhd();
    return 0;
}