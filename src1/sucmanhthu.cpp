#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
string s1,s2,tam;
bool ok;
int kq;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s1 >> s2;
    int m = s2.size(), n = s1.size();
    s1 = "#" + s1;
//    s2 = "*" + s2;
    for (int i = 1; i <= n; i++){
        if (s1[i]==s2[0]){
                tam = "";
            for (int id = i; id <= i+m-1;id++){
                tam = tam + s1[id];
            }
//            cout << s2 << ' ' << tam << '\n';
            if (tam==s2) kq++, i = i + m-1;
        }
    }
    cout << kq;
    return 0;
}
