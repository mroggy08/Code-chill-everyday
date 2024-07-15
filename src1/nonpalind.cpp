#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int N;
string s;
bool ch(string s){
	string s1 = s;
	reverse(s.begin(),s.end());
	return s==s1;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> s;
    bool ok = 1;
    for (int i = 0; i < s.size(); i++){
    	if (s[i]!=s[0]) ok = 0;
    }
    if (ok){
    	cout << 0;
    	return 0;
    }
    cout << (ch(s) ? N-1 : N);
    
    
    return 0;
}
