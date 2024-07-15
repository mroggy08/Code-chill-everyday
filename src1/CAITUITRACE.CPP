#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, w, i, j, u, v, res=0, f[100005];
stack<int>s;
int tv[100005], a[105];
int main(){ 
	// freopen("INP.INP","r",stdin);
	// freopen("OUT.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> w;
    for (i=1; i<=n; i++){
        cin >> a[i] >> v;
        for (j=w; j>=a[i]; j--)
            if (f[j]<f[j-a[i]]+v){
                tv[j]=i;
                f[j]=f[j-a[i]]+v;
            }
    }
     
    for (j=1; j<=w; j++)
        if (res<f[j]){
            u=j;
            res=f[j];
        }
    cout << res << '\n';
    while (tv[u]){
        s.push(tv[u]);
        u-=a[tv[u]];
    }
    while (s.size()){
    	cout << s.top() << ' ';
    	s.pop();
    }
 
 
    return 0;
}