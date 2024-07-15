#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+6;
ii a[N];
int add=0,q;
unordered_map<int,int> mp;
vector<int> kq;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> q;
    for (int i = 1; i <= q; i++) cin >> a[i].fi >> a[i].se;
   	for (int i = q; i >=1 ; i--){
   		if (a[i].fi==1){
   			if (!mp.count(a[i].se+add)) kq.pb(a[i].se+add);
   			else continue;
   		} else if (a[i].fi==2){
   			add+=a[i].se;
   		} else if (a[i].fi==3){
   			mp[a[i].se + add] = 1;
   		}
   	}
    reverse(kq.begin(),kq.end());
   	cout << kq.size() << '\n';
   	for (int v : kq) cout << v << ' ';
    return 0;
}
