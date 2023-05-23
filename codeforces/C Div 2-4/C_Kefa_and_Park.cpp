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
const int N = 1e5 + 10;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS

// Read statements slowly if WA
// Check for constraints if TLE
vl adj[N];
bool visited[N];
vl ar(N);
ll ans = 0, m;
// O(E+V)
void dfs(ll node, ll parent, vl &ar, ll cats, ll maxCats)
{
    if (visited[node])
        return;
    visited[node] = true;
    if (ar[node])
        cats++;
    else
        cats = 0;
    maxCats = max(cats, maxCats);

    int numOfChild = 0;
    for (auto ir : adj[node])
    {
        if (ir != parent)
        {
            dfs(ir, node, ar, cats, maxCats);
            numOfChild++;
        }
    }
    if (numOfChild == 0 and maxCats <= m)
        ans++;
}

void solve()
{
    ll n;
    cin >> n >> m;
    FOR(i, 1, n + 1)
        cin >> ar[i];
    FOR(i, 1, n)
    {
        ll v1, v2;
        cin >> v1 >> v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
    dfs(1, 0, ar, 0, 0);
    cout << ans << endl;
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
