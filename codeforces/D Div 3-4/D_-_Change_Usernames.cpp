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
vector<ll> g[N];
bool visited[N];
// O(E+V)
bool dfsLoop(ll vertex, ll parent)
{
    visited[vertex] = true;
    bool isLoopExists = false;
    for (auto child : g[vertex])
    {
        if (visited[child] and child == parent)
            continue;
        if (visited[child])
            return true;
        isLoopExists |= dfsLoop(child, vertex);
    }
    return isLoopExists;
}
ll toInt(string s)
{
    ll ans = 0, idx = 0;
    for (int i = sz(s) - 1; i >= 0; i--)
    {
        ans += (10 * idx) + (s[i] - 'a' + 1);
        idx++;
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> mp;
    while (n--)
    {
        string s, t;
        cin >> s >> t;
        ll v = toInt(s), e = toInt(t);
        mp[v]++, mp[e]++;
        g[v].pb(e);
        g[e].pb(v);
    }
    for (auto &i : mp)
    {
        if (visited[i.first])
            continue;
        if (dfsLoop(i.first, 0))
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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
