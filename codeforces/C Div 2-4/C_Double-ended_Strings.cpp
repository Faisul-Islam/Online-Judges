#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
#define deb(x)
#endif
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ins insert
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS
// Read statements slowly

void subString(string &str,string &toMtchStr, int n)
{
    vector<string> substrs;
    for (int len = 1; len <= n; len++)
    {   
        for (int i = 0; i <= n - len; i++)
        {

            int j = i + len - 1;     
            string tmp;      
            for (int k = i; k <= j; k++)
                tmp.pb(str[k]);

            if(toMtchStr.find(tmp) != string::npos){
             substrs.pb(tmp);
            }
             
        }
    }
    sort(all(substrs),[](string &s1,string &s2){return s1.size() < s2.size();});

    if(substrs.size() == 0) cout << str.length() + toMtchStr.length() << endl;
    else{
        string ansSub = substrs[substrs.size()-1];
        cout << str.length() + toMtchStr.length() - 2 * ansSub.length() << endl;
    }
}

void solve()
{
  string s; cin >> s;
  string s2; cin >> s2;
 int ans = 0;
   if(s.length() <= s2.length()){
    subString(s,s2,s.length());
   }else{
    subString(s2,s,s2.length());
   }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
