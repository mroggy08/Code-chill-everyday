#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e6+6;
int n,a[N],kq,f[N];
bool check(int n){
    string s = to_string(n);
    int chan = 0, le = 0;
    for (char x : s) {
        if ((x-'0') % 2 == 0) chan++;
        else le++;
    }
    return chan!=le;
}
void sang(int k){S
    f[0]=f[1]=1;
    for (int i = 2; i*i <= k; i++){
        if (f[i]==0){
            for (int j = i*i; j <= k; j+=i){
                f[j]=1;
            }
        }
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    sang(2e6);
    for (int i = 1; i <= n;i++) {
        cin >> a[i];
        if (!f[a[i]]){
            if (check(a[i])) kq++;
        }
    }
    cout << kq;


    return 0;
}
