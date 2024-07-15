#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+3;
int n,k,a[N],l,r;
ll kq;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> k;
    f1(i,1,n ) cin >> a[i];
    sort(a+1,a+n+1);
    f1(i,1,n-1){
    	l = lower_bound(a+i+1,a+n+1,k-a[i]) - a;
    	r = upper_bound(a+i+1,a+n+1,k-a[i]) - a;
    	if (a[l]==k-a[i]){
    		kq+=r-l;
    	}
    }
    cout << kq;
    return 0;
}
