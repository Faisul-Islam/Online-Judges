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

// gfg code
const ll N = 2;
void rotate90(ll a[N][N])
{

    for (ll i = 0; i < N / 2; i++)
    {
        for (ll j = i; j < N - i - 1; j++)
        {
            ll tmp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = tmp;
        }
    }
}
void solve()
{
    ll mat[2][2];
    F0R(i, 2)
    {
        F0R(j, 2)
            cin >> mat[i][j];
    }
    if (mat[0][0] < mat[0][1] and mat[1][0] < mat[1][1] and mat[0][0] < mat[1][0] and mat[0][1] < mat[1][1])
    {
        YES;
        return;
    }
    else
    {
        F0R(i, 10)
        {
            rotate90(mat);
            if (mat[0][0] < mat[0][1] and mat[1][0] < mat[1][1] and mat[0][0] < mat[1][0] and mat[0][1] < mat[1][1])
            {
                YES;
                return;
            }
        }
        NO;
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
