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
typedef unsigned long long ull;
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
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS

// Read statements slowly if WA
// Check for constraints if TLE
bool pred(ll mid, ll x)
{
    ull messages = 0;
    messages = (mid * (mid+1))/2;
    return messages < x;
}
// bool poss(ll mid,x){

// }
void solve()
{
    ll k, x;
    cin >> k >> x;
    ll lo = 1, hi = k;

    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        // TTTFFF
    // deb(pred(mid, x));

        if (pred(mid, x))
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    ll ans = 0, sum = 0;
    lo = hi;
    // deb(lo);
    // if((lo * (lo +1))/2 < k){
    //     cout << 2 * lo + 1 << endl;
    //     deb("yo");
    //     return;
    // }
    // for (ll i = 1; i <= lo; i++)
    // {
    //     sum += i;
    //     ans++;
    //     if (sum >= x) break;
            
    // }
    // for (ll i = lo - 1; i >= 1; i--)
    // {
    //     if (sum >= x)
    //         break;
    //     sum += i, ans++;
        
    // }
    ll l = 0, r = 1e18+1;
    while(l < r){
        ll md = (l+r)/2;
        // TTFFF
        if(pred(md,k))
        l = md+1;
        else
        r = md-1;
    }
    cout << l + 1 << endl;
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
