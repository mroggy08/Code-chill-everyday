#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
string s;
int kq;
int main()
{
    if(fopen("demso.inp","r")){freopen("demso.inp","r",stdin);freopen("demso.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    for (char x : s){
        if (isdigit(x)) kq++;
    }
    cout << kq;


    return 0;
}
