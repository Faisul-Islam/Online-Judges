#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
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
#define ff first
#define ss second
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

ll n, k;
vl ropes(1e4 + 7);

bool cut(ld x)
{
    ld ropesSum = 0;
    F0R(i, n)
        ropesSum += floor(ropes[i] / x);

    return ropesSum >= k;
}

void solve()
{
    cin >> n >> k;

    F0R(i, n)
        cin >> ropes[i];

    // T T T T F F F F F
    ld lo = 0, hi = 1e8;

    for (int t = 0; t < 100; t++)
    {
        ld mid = (lo + hi * 1.0) / 2.0;
        if (cut(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << setprecision(20) << lo << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}
