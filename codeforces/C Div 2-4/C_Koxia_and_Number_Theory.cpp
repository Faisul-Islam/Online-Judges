#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
#define deb(x)
#endif
typedef unsigned long long ll;
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

// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS
// Read statements slowly if WA
// Check for constraints if TLE


void solve()
{
    ll n;
    cin >> n;
    vl ar(n);
    map<ll, int> frq;
    F0R(i, n)
    cin >> ar[i], frq[ar[i]]++;


    FOR(a, 0, 101)
    {
        bool flag = true;
        F0R(i, n)
        {
            FOR(j, i + 1, n)
            {
                if (i == j)
                    continue;
                ll gcd = __gcd(ar[i] + a, ar[j] + a);
                if (gcd != 1)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
        {
            YES;
            return;
        }
    }
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
