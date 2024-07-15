//Dai Ca Di Hoc
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 1000005
#define MOD 1000000007
#define ll long long

using namespace std;

string s;
int k, c[maxn], n;
ll m,tam;
ll doi(string s)
{
    ll v = 0;
    for (auto it : s) v = v*10 + (it-'0');
    return v;
}
void Print(string st){
    while(st[0]=='0') st.erase(0,1);
    ll m = doi(st);
    ll kq = m - tam;
    cout << kq;
    exit(0);
}

void Check(int pos){
    int cur = c[pos-1];
    int cur1 = c[pos];
    if (cur1>=k) {
        Print(s);
        return;
    }
//    cout << cur << '\n';
    if (s[pos] == '9' || cur > k)
    {
        return;
    }
    s[pos]++;
    cur += (s[pos] == '6');
    if (n - pos >= k - cur){
        // điền k-cur số 5 vào cuối
        For(i, pos+1, n)
            if (i <= n - k + cur) s[i] = '0';
                else s[i] = '6';
        Print(s);
    } else
    if (s[pos] < '6' && k - cur == n-pos+1){
        For(i, pos, n) s[i] = '6';
        Print(s);
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("so.inp","r",stdin);
    freopen("so.out","w",stdout);
    cin >> s >> k;
    s = "00" + s;
    tam = doi(s);
    if (s.length() <= k+1)
        s = string(k+2-s.length(),'0') + s;
    n = s.length()-1;
    for (int i = 1; i <= n; i++)
        c[i] = c[i-1] + (s[i] == '6');
    for (int i = n; i > 0; i--) Check(i);
    return 0;
}

