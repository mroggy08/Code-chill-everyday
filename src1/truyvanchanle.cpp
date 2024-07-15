#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
ll n,q,x,sl,sc,loai;
ll chan,le;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> x;
        if (x&1) le+=x,sl++;
        else chan+=x,sc++;
    }
    while (q--){
        cin >> loai >> x;
        if (loai==1){
            if (x%2==0){
                chan = chan + x*sc;
                cout << chan + le << '\n';
            } else {
//                cout << chan << ' ';
                chan = chan + x*sc;
                sl += sc;
                le += chan;
                chan = 0;
                cout << le << '\n';
            }
        } else if (loai == 2){ // le
            if (x%2==1){
                le = le + x*sl;
                sc += sl;
                chan += le;
                le = 0;
                cout << chan << '\n';
            } else {
                le = le + x*sl;
                cout << le + chan << '\n';
            }
        }
    }
    return 0;
}
