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

// Constants
constexpr ll SZ = 2e5 + 7;
constexpr ll inf = 9e18;
constexpr ll mod = 1e9 + 7;

int modpow(int a, int b, int m = mod)
{
    a = a % m;
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % m;
        }
        b = b >> 1;
        a = (a * a) % m;
    }
    return ans;
}

// Inverse Mod (1 / a) % mod
int modinv(int a, int m = mod) { return modpow(a, m - 2, m); }

// Modular Arithematic
int modadd(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int modsub(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
int modmul(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int moddiv(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (modmul(a, modinv(b, m), m) + m) % m;
}

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

map<int, int> mp[16];
void pre()
{
    mp[1][2]++, mp[1][3]++;
    mp[2][4]++, mp[2][5]++;
    mp[3][6]++, mp[3][7]++;
    mp[4][8]++, mp[4][9]++;
    mp[5][10]++, mp[5][11]++;
    mp[6][12]++, mp[6][13]++;
    mp[7][14]++, mp[7][15]++;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    if(mp[a].find(b) != mp[a].end() or mp[b].find(a) != mp[b].end()) cout << "Yes\n";
    else cout << "No\n";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;
    pre();
    while (T--)
    {
        solve();
    }
}
