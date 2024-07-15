#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int tc;
void solve(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    s = "#"+s;
    ll kq=0;
    int r=2;
    unordered_map <char,int> mp;
    for (int i = 1; i <= n; i++){
        mp[s[i]]++;
        r = i + 1;
        while (r<=n){
            mp[s[r]]++;
            if (mp[s[r]]<=k){
                r++;
            }
            else {
                break;
            }
        }
        cout << r << ' ' << i << '\n';
        kq+=r-i;
    }
    cout << kq << '\n';
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--){
        solve();
    }
    return 0;
}
