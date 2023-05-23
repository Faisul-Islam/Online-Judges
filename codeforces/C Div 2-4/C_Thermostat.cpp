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
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS

// Read statements slowly if WA
// Check for constraints if TLE
void solve()
{
    ll l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    // abs(-5 - 10);

    ll ans = 0;
    if (abs(a-b) >= x)
        cout << 1 << endl;
    else if (a == b)
        cout << 0 << endl;
    else if (((abs(a - l) < x and abs(r - a) < x) or (abs(b - l) < x and abs(b - r) < x)))
        cout << -1 << endl;
    else
    {
        ll diff = abs((a + x) - b);
         if (x > abs(a - r))
        {
            if (abs(l - b) >= x)
                cout << 2 << endl;
            else
                cout << 3 << endl;
        }
        else if (abs(l - a) < x)
        {
            if (abs(b - r) >= x)
                cout << 2 << endl;
            else
                cout << 3 << endl;
        }
        else
            cout << 2 << endl;
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
