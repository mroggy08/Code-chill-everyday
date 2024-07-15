#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
const int N = 1e6+3;
int n,m,a[10][30],q;
string s;
int tong(string x, string y)
{
    int g1 = a[x[1]-'0'][int(x[0])-64];
    int g2 = a[y[1]-'0'][int(y[0])-64];
    return g1+g2;
}
int sosanh(string x, string y)
{
    int g1 = a[x[1]-'0'][int(x[0])-64];
    int g2 = a[y[1]-'0'][int(y[0])-64];
    return max(g1,g2);
}
void xuli(string s)
{
    string t="";
    for (int i = 0; i < 3; i++)
        t += s[i];
    string h1 = ""; h1+=s[4]; h1 += s[5];
    string h2 = ""; h2+=s[7]; h2+=s[8];
    if (t=="SUM") cout << tong(h1,h2) << '\n';
    else cout << sosanh(h1,h2) << '\n';
}
int sum1(string t)
{
    string h = "",h3="",k="",k1="";
    int g1,g2;
    for (int i = 0; i < 3; i++) h += t[i];
    if (h=="MAX"||h=="SUM")
    {
        string h1 = ""; h1+=t[4]; h1 += t[5];
        string h2 = ""; h2+=t[7]; h2 += t[8];
        if (h=="MAX") g1 = sosanh(h1,h2);
        else g1 = tong(h1,h2);
        for (int i = 11; i < 14; i++)   k += t[i];
        if (k=="MAX"||k=="SUM")
        {
            string h4 = ""; h4 += t[15]; h4 += t[16];
            string h5 = ""; h5 += t[18]; h5 += t[19];
            if (k=="MAX") g2 = sosanh(h4,h5);
            else g2 = tong(h4,h5);
        }
        return g1 + g2;
    }
    else if (h!="MAX"&&h!="SUM"){
        h3+=t[0]; h3+=t[1];
        g1 = a[h3[1]-'0'][int(h3[0])-64];
        for (int i = 3; i <=5; i++) k1+=t[i];
        if (k1=="MAX"||k1=="SUM")
        {
            string h6 = ""; h6+=t[7]; h6+=t[8];
            string h7 = ""; h7+=t[10]; h7+=t[11];
            if (k1=="MAX") g2 = sosanh(h6,h7);
            else g2 = tong(h6,h7);
        }
        return g1+g2;
    }
}
int com(string t)
{
    string h = "",h3="",k="",k1="";
    int g1,g2;
    for (int i = 0; i < 3; i++) h += t[i];
    if (h=="MAX"||h=="SUM")
    {
        string h1 = ""; h1+=t[4]; h1 += t[5];
        string h2 = ""; h2+=t[7]; h2+=t[8];
        if (h=="MAX") g1 = sosanh(h1,h2);
        else g1 = tong(h1,h2);
        for (int i = 11; i < 14; i++)   k+=t[i];
        if (k=="MAX"||k=="SUM")
        {
            string h4 = ""; h4+=t[15]; h4+=t[16];
            string h5 = ""; h5+=t[18]; h5+=t[19];
            if (k=="MAX") g2 = sosanh(h4,h5);
            else g2 = tong(h4,h5);
        }
        return max(g1,g2);
    }
    else if (h!="MAX"&&h!="SUM"){
        h3+=t[0]; h3+=t[1];
        g1 = a[h3[1]-'0'][int(h3[0])-64];
        for (int i = 3; i <=5; i++) k1+=t[i];
        if (k1=="MAX"||k1=="SUM")
        {
            string h6 = ""; h6+=t[7]; h6+=t[8];
            string h7 = ""; h7+=t[10]; h7+=t[11];
            if (k1=="MAX") g2 = sosanh(h6,h7);
            else g2 = tong(h6,h7);
        }
        return max(g1,g2);
    }
}
void sub2(string s)
{
    string t = "",q="";
    for (int i = 0; i < 3; i++) t+=s[i];
    for (int i = 4; i < s.size() - 1; i++) q+=s[i];
    if (t=="SUM") cout << sum1(q) << '\n';
    else cout << com(q) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//        freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> n >> m;
    f1(i,1,n) f1(j,1,m) cin >> a[i][j];
    cin >> q;
    while (q--){
        cin >> s;
        if (s.size() <= 10) xuli(s);
        else {
            sub2(s);
        }
    }
    return 0;
}
