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
    int t; ll n;
    cin >> t;
    while (t--){
    	cin >> n;
    	cout << n/3 + n/5 - n/15 << '\n';
    }
    
    return 0;
}
