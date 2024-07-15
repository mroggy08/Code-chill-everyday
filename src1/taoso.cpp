#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
ll n,id,f[12];
vector <ll> a;
bool cmd(int A, int B){
    string s = to_string(B),s1 = to_string(A);
    return A*f[s.size()]+B > B*f[s1.size()]+A;
}
bool nt(ll n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n%i==0){
            return 0;
        }
    }
    return n>1;
}
int main()
{
//    if(fopen("cau3.inp","r")){freopen("cau3.inp","r",stdin);freopen("cau3.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    if (nt(n)){
        cout << n;
        return 0;
    }
    f[0]=1;
    for (int i = 1; i <= 10; i++){
        f[i] = f[i-1]*10;
    }
    id = 2;
    while (n>1){
        while (n%id==0){
            a.pb(id);
            n/=id;
        }
        id++;
    }
    sort(a.begin(),a.end(),cmd);
    for (ll e : a) cout << e;
    return 0;
}
