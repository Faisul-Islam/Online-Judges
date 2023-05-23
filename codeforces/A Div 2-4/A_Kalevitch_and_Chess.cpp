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
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define ins insert
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
bool isKthBitSet(ll n, ll k) { return (n & (1ll << k)); }
int msbPosition(int n)
{
    int k = __builtin_clz(n);
    return 1 << (31 - k);
}
int nearest2sPower(int n)
{
    return pow(2, ceil(log(n) / log(2)));
}
int nearestSmallerEqual2sPower(int n)
{
    return pow(2, floor(log(n) / log(2)));
}
ll check(vl &ar)
{
    ll ans = ar[0];
    FOR(i, 1, sz(ar))
    {
        ans = __gcd(ar[i], ans);
    }
    return ans;
}
void solve()
{
    char board[8][8];
    F0R(i, 8)
    {
        F0R(j, 8)
        cin >> board[i][j];
    }
    int row = 0, col = 0;
    F0R(i, 8)
    {
        bool flag = true;
        F0R(j, 8)
        {
            if (board[i][j] != 'B')
                flag = 0;
        }
        if (flag)
            row++;
    }

    F0R(i, 8)
    {
        bool flag = true;
        F0R(j, 8)
        {
            if (board[j][i] != 'B')
                flag = 0;
        }
        if (flag)
            col++;
    }
    if (row + col == 16)
        cout << 8 << endl;
    else
        cout << row + col << endl;
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
