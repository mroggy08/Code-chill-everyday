#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int gh = 1000000;
int t,l,r,f[gh+6],g[gh+6],kq[gh+6];
bool sure(int n){
	int h,dem=0,cnt1=0,cnt2=0;
	while (n>1){
		h = f[n];
		dem += 1;
		while (n%h==0){
			if (dem==1) cnt1++;
			else if (dem==2) cnt2++;
			n/=h;
		}
	}
	if (dem>2) return 0;
	if (dem==1 && cnt1==3) return 1;
	if (dem==2){
		if (cnt1==1 && cnt2==1) return 1;
		else return 0;
	} 
	return 0;
}
void create(){
	for (int i = 2; i <= gh; i++){
		if (f[i]==0){
			for (int j = i; j <= gh; j+=i){
				f[j]=i;
			}
		}
	}
}
void sang(){
	for (int i = 4; i <= gh; i++){
		if (sure(i)) g[i]=1;
	}
	for (int i = 4; i <= gh; i++){
		if (g[i]) kq[i]=kq[i-1]+1;
		else kq[i]=kq[i-1];
	}
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    create();
    sang();
    cin >> t;
    while (t--){
    	cin >> l >> r;
    	cout << kq[r] - kq[l-1] << '\n';
    }
    
    
    return 0;
}
