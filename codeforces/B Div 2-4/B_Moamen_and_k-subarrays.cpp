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

void solve(ll testCaseChecker)
{
    ll n, k;
    cin >> n >> k;
    vl ar(n);
    set<ll> oc;
    F0R(i, n)
    {
        cin >> ar[i];
    }

    vl suff(n, 1e9);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            suff[i] = ar[i];
        else
        {
            suff[i] = min(ar[i], suff[i + 1]);
        }
    }
    ll subArrs = 1;
    FOR(i, 0, n - 1)
    {
        if(ar[i] < ar[i+1] and (suff[i+1] < ar[i] or suff[i+1] >= ar[i+1])){
        }
        else if (ar[i] > suff[i + 1] or (ar[i] < suff[i+1] and suff[i+1] < ar[i+1]))
            subArrs++;
    }
    if (subArrs > k)
        cout << "No\n";
    else
        cout << "Yes\n";
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