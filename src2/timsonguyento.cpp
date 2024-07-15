#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e7+3;
int a,b,f[N];
void sang(int k){
	f[0]=f[1]=1;
	for (int i = 2; i*i <= k; i++){
		if (!f[i]){
			for (int j = i*i; j <= k; j+=i) f[j]=1;
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> a >> b;
    sang(b);
   	for (int i = a; i <= b;i++){
   		if (!f[i]) cout << i << '\n';
   	}
    return 0;
}
