#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
string s;
ll ma,kq=1;
ll doi(string s){
    ll a = 0;
    for (char x : s) a = a*10+(x-'0');
    return a;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    while (s.size()>1){
        ma = 0;
        for (char x : s){
            ma = max(ma,(ll)x-'0');
        }
        s = to_string(doi(s) - ma);
        kq++;
    }
    cout << kq;


    return 0;
}
