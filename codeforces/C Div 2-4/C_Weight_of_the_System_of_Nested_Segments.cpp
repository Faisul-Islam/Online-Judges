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

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> ar(m), ans;
    map<ll, ll> frq;
    F0R(i, m)
    {
        ll x, w;
        cin >> x >> w;
        ar[i] = {w, x};
        frq[x] = i + 1;
    }
    sort(all(ar));

    ll sm = 0;


    ll cntr = 0;

    for(int i = 0; i < n * 2; i += 2)
        sm += ar[i].fi + ar[i+1].fi, ans.pb({ar[i].se, frq[ar[i].se]}), ans.pb({ar[i + 1].se, frq[ar[i + 1].se]});

    sort(all(ans));

    int l = 0, r = n * 2 - 1;

    cout << sm << endl;
    for(int i = 0; i < n * 2; i += 2)
        cout << ans[l++].se << " " << ans[r--].se << endl;

    cout << endl;
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
