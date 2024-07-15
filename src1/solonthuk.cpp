#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector <int> a;
    string s;
    int k;
    unordered_map<char,int> mp;
    cin >> s >> k;
    for (char x:  s) {
        mp[x]++;
        if (mp[x]==1) a.pb(x-'0');
    }
    sort(a.begin(),a.end(),greater<int>());
    cout << a[k-1];
    return 0;
}
