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
    ll n; cin >> n;
    string s; cin >> s;
    vector<bool> won(n, false);
    char arr[n][n];
    // 1 zero loss 2 atleast 1 win

    F0R(i, n) {
        F0R(j, n) {
            arr[i][j] = '=';
        }
    }
    F0R(i, n) {
        F0R(j, n) {
            if (i == j) arr[i][j] = 'X';
            else {
                if (s[i] == '1') {
                    arr[i][j] = '=';
                    arr[j][i] = '=';
                }
                else {
                    //  2
                    if (s[j] == '1') {
                        arr[i][j] = '=';
                        arr[j][i] = '=';
                    }
                    else {

                        if (!won[i] and arr[j][i] == '=') {
                            arr[i][j] = '+';
                            arr[j][i] = '-';
                            won[i] = true;
                        }
                        else if (!won[j] and arr[i][j] == '=') {
                            arr[j][i] = '+';
                            arr[i][j] = '-';
                            won[j] = true;
                        }
                    }
                }
            }
        }
        if (s[i] == '2') {
            bool flag = false;
            for (auto& v : arr[i]) {
                if (v == '+') {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                NO;
                return;
            }
        }
    }
    YES;
    F0R(i, n) {
        F0R(j, n) {
            cout << arr[i][j];
        }
        cout << endl;
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
