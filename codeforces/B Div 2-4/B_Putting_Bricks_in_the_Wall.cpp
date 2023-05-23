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
#define debexec deb("exec")

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

void solve(ll testCaseChecker)
{
    ll n; cin >> n;
    char s[n][n];
    vector<pair<int, int> > pos;
    char c;
    F0R(i, n) {
        F0R(j, n) {
            cin >> s[i][j];
        }
    }
    if (s[0][1] == s[1][0]) {
        c = s[0][1];
        ll cnt = 0;
        if (s[0][2] == c) {
            cnt++;
            pos.pb({ 0,2 });
        }
        if (s[1][1] == c) {
            cnt++;
            pos.pb({ 1,1 });
        }
        if (s[2][0] == c) {
            cnt++;
            pos.pb({ 2,0 });
        }
        if (cnt == 2 or cnt == 1) {
            cout << cnt << endl;
            for(auto &[v, k]: pos){
                cout << v << " " << k << endl;
            }
            return;
        }else[
            pos.clear();
        ]


    }
    if (s[n - 2][n - 2] == s[n - 1][n - 2]) {

    }
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
