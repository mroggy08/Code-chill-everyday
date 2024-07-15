#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int gh = 1e6;
int n,val,f[gh+6],kq;
void sang(){
	for (int i = 2; i <= 1e6; i++){
		if (!f[i]){
			for (int j = i; j <= gh; j+=i) f[j]=i;
		}
	}
}
int sol(int k){
	int h,res=1,cnt;
	while (k>1){
		h = f[k];
		cnt=0;
		while (k%h==0){
			cnt++;
			k/=h;
		}
		res*=(cnt+1);
	}
	return res;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sang();
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> val;
    	kq = max(kq,sol(val));
    }
    cout << kq;

    
    
    return 0;
}
