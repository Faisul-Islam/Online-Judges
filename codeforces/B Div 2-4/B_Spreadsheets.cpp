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

void solve(ll testCaseChecker)
{
    string s, row, col; cin >> s;
    if (s[0] == 'R') {
        bool flag = true;
        FOR(i, 1, sz(s)) {
            if (s[i] >= '0' and s[i] <= '9' and flag) {
                row.pb(s[i]);
            }
            else if (s[i] == 'C') {
                flag = false;
            }
            else {
                col.pb(s[i]);
            }
        }
        // deb(col);
        ll val = stoi(col);
        ll p = 0;
        string ans;
        ll cVal = val;
        while(cVal)
        {
            ll pl = powl(26, p);
            ll tmp = (val / pl) % 26;
            ans.pb(char(tmp + 'A' - 1));
            p++;
            cVal /= 26;
        }
        reverse(all(ans));
        cout << ans << row << endl;
    }
    else {
        F0R(i, sz(s)) {
            if (s[i] >= 'A' and s[i] <= 'Z') {
                col.pb(s[i]);
            }
            else {
                row.pb(s[i]);
            }
        }
        ll ans = 0, p = 0;
        for (ll i = sz(col) - 1; i >= 0; i--)
        {
            ll c = col[i] - 'A' + 1;
            ll val = (powl(26, p) * c);
            ans += val;
            p++;
        }
        cout << "R" << row << "C" << ans << endl;
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
