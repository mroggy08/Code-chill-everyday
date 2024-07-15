#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp(int N, int Chuso,bool gh, bool Loaiso, int D){
    if (N==0){
        if (Loaiso==1) return D;
        return 0;
    }
    if (gh==false && f[])
}
void tach(ll x, int type){
    int n = 0;
    while (x){
        A[++n] = x%10;
        x/=10;
    }
    for (int i = 0; i < 10; i++){
        kq[i] += type*dp(n,i,1,i!=0,0);
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(f,-1,sizeof f);
    while (cin >> l >> r){
        if (l==0&&r==0) return 0;
        memset(kq,0,sizeof kq);
        if (l>r) swap(l,r);
        tach(r,1); tach(l-1,-1);
        for (int i = 0; i < 10; i++) cout << kq[i] << ' ';
        cout << '\n';
    }


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
