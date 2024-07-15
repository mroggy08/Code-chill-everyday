#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> num;
ll dp[18][163][2];

ll call(int pos, int sum, int f){
    if (pos == num.size()) return sum;
    ll res = dp[pos][sum][f];
    if (res != -1) return res;
    res = 0;
    int LMT = 9;
    if (!f) LMT = num[pos];
    for (int j=0; j<=LMT; j++){
        int nf = f;
        if (j <LMT) nf = 1;
        res += call(pos+1,sum+j,nf);
    }
    return dp[pos][sum][f] = res;
}

ll solve(ll k){
    num.clear();
    while(k>0){
        num.push_back(k%10);
        k /= 10;
    }
    reverse(num.begin(),num.end());
    memset(dp,-1,sizeof(dp));
    return call(0,0,0);
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; ll l,r;
    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << solve(r) - solve(l-1) << "\n";
    }
}

