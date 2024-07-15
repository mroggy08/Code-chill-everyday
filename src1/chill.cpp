#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
string s;
long long l,c,t;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--){
        cin >> s;
        c=0; l = 0;
        for (char x : s){
            if ((x-'0')%2==1) l+=x-'0';
            else c+=x-'0';
        }
        if (c==l) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
