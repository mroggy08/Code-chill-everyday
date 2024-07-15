#include <bits/stdc++.h> // QioCas
using namespace std;
using ll = long long;


int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    freopen("task.inp","r",stdin);
    	freopen("task.ans","w",stdout);
    int n, k;
    cin >> n >> k;
    int a[n + 1] = {};
    ll ps[n + 1] = {};
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }

    ll ans = numeric_limits<ll>::min(), maxz = ps[k], minz = ps[k];
    for(int i = 2 * k; i <= n; ++i) {
        minz = min(minz, ps[i - k] - ps[i - 2 * k]);
        maxz = max(maxz, ps[i - k] - ps[i - 2 * k]);
        ans = max(ans, abs(ps[i] - ps[i - k] - maxz));
        ans = max(ans, abs(ps[i] - ps[i - k] - minz));
    } cout << ans << "\n";
    return 0;
}
