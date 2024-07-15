#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 1e5+3;
int n,m,cnt,kq[6];
char a[603][603];
int sol(int d)
{
    if (d==0) return 1;
    if (d==4) return 2;
    if (d==8) return 3;
    if (d==12) return 4;
    return 5;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= 5*n+1; i++) for (int j = 1; j <= 5*m+1; j++) cin >> a[i][j];
    for (int d = 2; d <= 5*n+1; d+=5)
        for (int r = 2; r <= 5*m+1; r+=5)
           {
               cnt = 0;
               for (int i = d; i <= d+3; i++)
                   for (int j = r; j <= r+3; j++)
                       if (a[i][j]=='*') cnt++;
                kq[sol(cnt)]++;
           }

    for (int i = 1; i <= 5; i++)
        cout << kq[i] << ' ';
    return 0;
}


