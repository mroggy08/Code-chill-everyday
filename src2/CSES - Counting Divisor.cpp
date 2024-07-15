#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+3;
int f[N];
void sang(){
	for (int i = 2; i <= N; i++){
		if (!f[i]){
			for (int j = i; j <= N; j+=i)
				f[j]=i;
		}
	}
}
int calc(int n){
	int cnt,h;
	int ans=1;
	while (n>1){
		 h = f[n];
		 cnt = 0;
		while (n%h==0){
			cnt++;
			n/=h;
		}
		ans *= (cnt+1);
	}
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    sang();
    int tc; cin >> tc; while (tc--){
    	int x; cin >> x;
    	cout << calc(x) << '\n';
    }
    return 0;
}
