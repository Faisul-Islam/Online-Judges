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
    ll n, cost = INT_MAX;
    cin >> n;
    vl ar(n);
    F0R(i, n)
    {
        cin >> ar[i];
    }
    ll ans = ar[0];
    FOR(i, 1, n)
    {
        ans = __gcd(ar[i], ans);
    }
    // deb(ans);
    if (ans == 1)
        cout << 0 << endl;
    else
    {

        for (int i = n - 1; i >= 0; i--)
        {
            ll tmp = ar[i];
            if (__gcd(ar[i], i + 1ll) == 1ll)
            {
                cost = min(cost, n - i);
            }
            else
            {
                ar[i] = __gcd(ar[i], i + 1ll);
                if (check(ar) == 1)
                {
                    cost = min(cost, n - i);
                }
                ar[i] = tmp;
            }
        }
        F0R(i, n)
        {
            FOR(j, i + 1, n)
            {
                if (i == j)
                    continue;
                ll v1 = ar[i], v2 = ar[j];
                ar[i] = __gcd(ar[i], i + 1ll), ar[j] = __gcd(ar[j], j + 1ll);
                if (check(ar) == 1)
                {
                    cost = min(cost, n - i + n - j);
                }
                ar[i] = v1, ar[j] = v2;
            }
        }
        cout << cost << endl;
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
