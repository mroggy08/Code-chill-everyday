#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+9;
int n,a[N],mx,kq,f[1000003];
void sang(int k){
    for (int i = 2; i<=k; i++){
        if (f[i]==0){
            for (int j = i; j <= k; j+=i)
                f[j] = i;
        }
    }
}
bool nt(int x){
    for (int i = 2; i*i <= x; i++){
        if (x%i==0) return 0;
    }
    return x>1;
}
bool tl(int x){
    int D = 0, C = 0;
    while (x>1){
            C=0;
        int h = f[x];
        while (x%h==0) C++,x/=h;
        if (C>1 && D>1) return 0;
        D++;
    }
    if (D==1 && C>2) return 0;
    return D==1 || D==2;
//    cout << D;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    sang(mx);
    for (int i = 1; i <= n; i++){
        if (nt(a[i])) continue;
        if (tl(a[i])) kq++;
    }
    cout << kq;
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
