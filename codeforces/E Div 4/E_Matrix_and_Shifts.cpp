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
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ins insert

// Constants
constexpr ll SZ = 2e5 + 7;
constexpr ll inf = 9e18;
constexpr ll mod = 1e9 + 7;

int modpow(int a, int b, int m = mod) {
    a = a % m; int ans = 1;
    while (b) {
        if (b & 1) { ans = (ans * a) % m; }
        b = b >> 1; a = (a * a) % m;
    }
    return ans;
}

// Inverse Mod (1 / a) % mod
int modinv(int a, int m = mod) { return modpow(a, m - 2, m); }

// Modular Arithematic
int modadd(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int modsub(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int modmul(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int moddiv(int a, int b, int m = mod) { a = a % m; b = b % m; return (modmul(a, modinv(b, m), m) + m) % m; }

bool isKthBitSet(ll n, ll k) { return (n & (1ll << k)); }
int msbPosition(int n)
{
    int k = __builtin_clz(n);
    return 1 << (31 - k);
}
int nearest2sPower(int n) {
    return pow(2, ceil(log(n) / log(2)));
}
int nearestSmallerEqual2sPower(int n) {
    return pow(2, floor(log(n) / log(2)));
}

 4 % 2

void solve(ll testCaseChecker)
{
    ll n; cin >> n;
    int ar[n + 1][n + 1];
    vi rowSum(n), colSum(n);
    char c;
    int count = 0;
    F0R(i, n) {
        F0R(j, n) {
            cin >> c;
            ar[i][j] = c - '0';
            if(i == j and !ar[i][j])  count++;
        }
    }
    ll emptyRows = 0, emptyCols = 0;

    F0R(i, n) {
        bool flag = false;
        F0R(j, n) {
            flag |= ar[i][j];
            rowSum[i] += ar[i][j];
        }
        if (!flag) {
            emptyRows++;
        }
        flag = false;
        F0R(j, n) {
            flag |= ar[j][i];
            colSum[i] += ar[j][i];
        }
        if (!flag) {
            emptyCols++;
        }
    }
    int mustXors = max(emptyCols, emptyRows) - min(emptyCols, emptyRows);
    int ans = 0;
    if (emptyCols >= emptyRows) {
        for (auto& v : colSum) {
            ans += max(0, v - 1);
        }
    }
    else {
        for (auto& v : rowSum) {
            ans += max(0, v - 1);
        }
    }
    deb(count);
    cout << ans + mustXors << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    for (ll tcc = 1; tcc <= T; tcc++)
    {
        solve(tcc);
    }
}
