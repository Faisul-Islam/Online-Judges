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
    ll n; cin >> n;
    string s; cin >> s;
    int ans = 0;

    F0R(i,n-1){
      if(s[i] == s[i+1]){
        if(i+2 >= n){
            if(s[i] == 'R') s[i+1] = 'G';
            else s[i+1] = 'R';
            ans++;
        }else{
            if(s[i+1] == s[i+2]){
            if(s[i] == 'R') s[i+1] = 'G';
            else s[i+1] = 'R';
            }else{
                if(s[i+2] == 'R') s[i+1] = (s[i] == 'G')? 'B':'G';
                else if(s[i+2] == 'G') s[i+1] = (s[i] == 'R')? 'B':'R';
                else s[i+1] = (s[i] == 'G')? 'R':'G';
            }
            ans++;
        }
      }
    }
    cout << ans << endl;
    cout << s << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}