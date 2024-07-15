ư#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>i2;
#define fi first
#define se second;
#define pb push_back;
string s;
int e=1e9+7,n,a[1000005],d;
long long dp[100005][4][205];
void tach(string s){
    n=s.size();
    int t=0;
    for (int i=n-1;i>=0;i--){
        t++;
        a[t]=(int) (s[i]-'0');
    }
}
long long thu(int i,bool gh,int tong){
    if (i==0){
        if (tong%d==0) return 1;
        else return 0;
    }
    if (dp[i][gh][tong]!=-1) return dp[i][gh][tong];
    int ma=0;
    if (gh==0) ma=9;
    else ma=a[i];
    long long res=0;
    // gh = 1
    for (int j=0;j<=ma;j++){
        if (gh==1){
            bool ok=0;
            if (j==ma) ok=1;
            res=res+(thu(i-1,ok,(tong+(j%d))%d));
            res%=e;
        }
        else {
            res+=(thu(i-1,0,(tong+(j%d))%d));
            res%=e;
        }
    }
    return dp[i][gh][tong]=res%e;
}
int G(string s){
    tach(s);
    return thu(n,1,0);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//    freopen(" ","r",stdin);
//    freopen(" ","w",stdout);
    cin>>s>>d;
    for (int i=0;i<=100000;i++){
        for (int j=0;j<=105;j++) dp[i][1][j]=dp[i][0][j]=-1;
    }
    cout<<(G(s)-1+e)%e;
    return 0;
}

