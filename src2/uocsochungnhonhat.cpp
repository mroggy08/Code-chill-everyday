#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+3;
int n,a[N],kq;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n;
    f1(i,1,n) cin>>a[i];kq=a[1]; f1(i,2,n) kq=__gcd(kq,a[i]);
    if (kq==1) cout << -1;
    else {
    	if (kq%2==0){
    		cout << 2;
    		return 0;
    	}
    	for (int i = 3; i <= kq; i+=2){
    		if (kq%i==0)
    		{
    			return cout << i,0;
    		}
    	}
    }
    return 0;
}
