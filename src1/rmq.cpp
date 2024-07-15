#include <bits/stdc++.h>
using namespace std;
int n,q,u,v,a[10003],t[10003][17];
void build()
{
    for (int i = 1; i <= n; i++) t[i][0] = a[i];
    for (int j = 1; j < 17; j++)
        for (int i = 1; i + (1<<j) - 1 <= n; i++)
            t[i][j] = t[i][j-1]+t[i+(1<<(j-1))][j-1];
}
int get(int l, int r){
    int k = __lg(r-l+1);
    return min(t[l][k], t[r-(1<<k)+1][k]);
}
int sum(int l, int r)
{
    int m = r-l+1,sum=0;
    for (int j = 0; (1<<j)<=m; j++)
    {
        if (m>>j & 1){
            sum = sum + t[l][j];
            l = l + (1<<j);
        }
    }
    return sum;
}
//void preprocess() {
//    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
//    for (int j = 1; j <= 16; ++j)
//        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
//            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
//}
//int queryMin(int l, int r) {
//    int k = __lg(r - l + 1);
//    return min(st[k][l], st[k][r - (1 << k) + 1]);
//}
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
//    preprocess();
    while (q--)
    {
        cin >> u >> v;
        cout << sum(u,v) << '\n';
    }
    return 0;
}
