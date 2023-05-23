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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define ins insert
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 2 * 1e5 + 5;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS

// Read statements slowly if WA
// Check for constraints if TLE

vl dp[MX];
vl ar;

void l1s(ll i)
{
    // if (dp[i].size() != 0)
    //     return;
    dp[i].pb(i);
    for (int j = i - 1; j >= 0; j--)
    {
        if (ar[j] == ar[dp[i].back()] - 1)
        {
            // deb(ar[dp[i].back()]);
            dp[i].pb(j);
        }
    }
}

void solve()
{
    ll n, in;
    cin >> n;
    F0R(i, n)
        cin >> in,
        ar.pb(in);
    ll mxIdx = -1, mxSize = -1;
    // l1s(n-1);
    FOR(i, 1, n)
    {
        l1s(i);
    }
    F0R(i, n)
    {
        // cout << dp[i].size() << endl;
        if ((ll)dp[i].size() > mxSize){
            mxSize = dp[i].size();
             mxIdx = i;
        }
            
    }
    cout << mxSize << endl;

    for(int i = mxSize - 1; i >= 0;i--)
    {
        cout << dp[mxIdx][i] +1<< " ";
    }
    cout << endl;

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
