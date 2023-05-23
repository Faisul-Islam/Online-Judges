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

// O(E+V)
void gridTravel(vector<vector<char>> &grid, ll x, ll n, ll &ans)
{
    // ll i = 0;
    F0R(i, n)
    {
        if (grid[x][i] == 'B') ans++;
        else
            return;
        if (x)
        {
            if (grid[0][i] == 'B') x = 0, ans++;
        }
        else
        {
            if (grid[1][i] == 'B') x = 1, ans++;
        }
    }
}
void solve()
{
    ll n, bCount = 0;
    cin >> n;
    char c;
    vector<vector<char>> grid(2);
    string s;
    cin >> s;
    F0R(i, n)
    {
        grid[0].pb(s[i]);
        if (s[i] == 'B')
            bCount++;
    }
    cin >> s;
    F0R(i, n)
    {
        grid[1].pb(s[i]);
        if (s[i] == 'B')
            bCount++;
    }
    ll ans1 = 0, ans2 = 0;
    gridTravel(grid, 0, n, ans1);
    gridTravel(grid, 1, n, ans2);

    if (ans1 == bCount or ans2 == bCount)
        YES;
    else
        NO;
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
