#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+6;
string s,a[N];
int n,k,d,b[N];
ll kq;
int ch(string s){
    int a = 0;
    for (char x : s) a = a*10 + (x-'0');
    return a;
}
int make(string s){
    if (s[0]=='-'){
        string v = "";
        for (int i = 1; i < s.size(); i++){
            v+=s[i];
        }
        int kq = -ch(v);
        return kq;
    }
    return ch(s);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cin.ignore();
    getline(cin,s);
    cin >> k;
    stringstream ss(s);
    string word,tu;
    while (ss>>word){
        tu = word + "#";
        string s2 = "";
//        cout << tu << ' ';
//        cout << tu << ' ';
        for (int i = 0; i < tu.size(); i++){
            if (isdigit(tu[i])==1 || tu[i]=='-') {
                s2 += tu[i];
//                cout << s2 << ' ';
            } else if (isdigit(tu[i])==0 && isdigit(tu[i-1])==1){
//                cout << s2 << " ";
                a[++d] = s2;
//                cout << a[d] << ' ';
                s2 = "";
            }
        }
    }
    for (int i = 1; i <= d; i++) b[i]= make(a[i]);
//    for (int i = 1; i <= d; i++) cout << b[i] << ' ';
    sort(b+1,b+d+1);
    for (int i = 1; i <= n; i++){
        int l = lower_bound(b+i+1,b+n+1,k-b[i]) - b;
        int r = upper_bound(b+i+1,b+n+1,k-b[i]) - b;
        if (b[l]==k-b[i]) kq += r-l;
    }
    cout << kq;
    return 0;
}
