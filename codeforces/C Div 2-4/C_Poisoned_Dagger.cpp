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

ll n;

bool lowest(vl &ar, ll m, ll h)
{
    ll needed = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (ar[i + 1] - ar[i] < m)
            needed += (ar[i + 1] - ar[i]);
        else
            needed += m;
    }
    needed += m;
    return needed >= h;
}

void solve()
{
    ll h;
    cin >> n >> h;

    vl ar(n);
    F0R(i, n)
        cin >> ar[i];

    ll maxDif = 0;

    ll lo = 0, hi = h;
    //   F F F T T T T
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (lowest(ar, mid, h))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << hi << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
