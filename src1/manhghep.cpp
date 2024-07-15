#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAN = 1e6;
int n, a, b, t, d = 0;
ll res = 0;
int f[MAN + 7];
int ck(int n){
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    int s = sqrt(n), k = -1;
    do {
        k += 6;
        if (n % k == 0 || n % (k + 2) == 0)
            break;
    } while (k <= s);
    return (k > s);
}
void ds(int n){
    t = 0;
    while (n > 0){
        t += n % 10;
        n /= 10;
    }
}
void sang(){
    f[0] = f[1] = 1;
    for (int i = 2; i * i <= MAN; i++)
        if (!f[i])
            for (int j = i * i; j <= MAN; j += i)
                f[j] = 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("task.INP", "r", stdin);
    freopen("task.ans", "w", stdout);
    cin >> a >> b;
    sang();
    for (int i = a; i <= b; i++){
        ds(i);
        if (t <= MAN)
            res += (!f[t]);
        else {
            res += ck(t);
            d++;
        }
    }
    cout << res;
    cerr << "Time: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
    return 0;
}
