#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

// Read statements slowly if WA
// Check for constraints if TLE
void solve()
{
    ll n;
    cin >> n;
    string s1,s2;
    char c;
    map<char,int> m1,m2;
    F0R(i,n) cin >> c, m1[c]++, s1.pb(c);
    F0R(i,n) cin >> c, m2[c]++, s2.pb(c);

    if(m1['a'] != m2['a'] or m1['b'] != m2['b'] or m1['c'] != m2['c']) NO;
    else{
        if(s1 == s2) YES;
        else{
            if((s1[0] == 'c' and s1[0] != s2[0]) or (s1[n-1] == 'a' and s1[n-1] != s2[n-1])){
                NO;
                return;
            }

         F0R(i,n-1){
            if(s1[i] != s2[i]){
                if(s2[i] == 'b' )
                FOR(j,i+1,n-1){
                    
                }
            }
         }
         YES;
        }
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
