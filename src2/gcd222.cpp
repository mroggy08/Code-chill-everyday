#include <bits/stdc++.h>
#define file(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define fd(i,n) for (int i = n; i > 0; i--)
#define ii pair<int,int>
#define lli pair<ll,int>
#define fi first
#define pb push_back
#define ll long long
#define VI vector<int>
#define VII vector<ii>
#define VLLI vector<lli>
#define ii pair<int,int>
#define lli pair<ll,int>
#define ALL(a) a.begin(),a.end()
using namespace std;
const int N =1e5+5;
int n,t,x;
ii query[N];
VI comp;
struct sv
{
	int val,d;
};
sv T[N*4];
void upd(int id, int l, int r, int pos, int vl){
	if (pos<l||pos>r) return;
	if (pos<=l&&pos>=r){
		T[id].d+=vl;
		if (T[id].d>=1) T[id].val = comp[l-1];
		else T[id].val = 0;
		return;
	}
	int m = (r+l)>>1;
	upd(id*2,l,m,pos,vl);
	upd(id*2+1,m+1,r,pos,vl);
	T[id].val=__gcd(T[id*2].val,T[id*2+1].val);
}
int get(int id, int l, int r, int u, int v){
	if (u>r||v<l) return 0;
	if (u<=l&&v>=r) return T[id].val;
	int m = (r+l)>>1;
	return __gcd(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int compress(){
	f1(i,1,n) comp.push_back(query[i].second);
	sort(ALL(comp));
	comp.resize(unique(ALL(comp)) - comp.begin());
//	for (int gt : comp) cout << gt << ' ';
//        cout << '\n';
	f1(i,1,n){
		query[i].second = lower_bound(ALL(comp),query[i].second) - comp.begin() + 1;
	}
	return comp.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("1");
    cin >> n;
    f1(i,1,n) {
    	cin >> query[i].first >> query[i].second;
    }
    int liem = compress();
//    cout << liem << ' ';

    f1(i,1,n){
    	if (query[i].fi == 1){
            upd(1,1,liem,query[i].second,1);
    	} else upd(1,1,liem,query[i].second,-1);
    	int ans = get(1,1,liem,1,liem);
    	cout << (ans ? ans : 1) << '\n';
    }
    return 0;
}


