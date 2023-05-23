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
    string s;
    cin >> s;
    vl A[28], ans;
    ll cost = 0, prev = s[0] - 'a' + 1;
    F0R(i, sz(s))
    {
        A[s[i] - 'a' + 1].pb(i + 1);
    }
    char first = s[0], last = s.back();
    if (first <= last)
    {
        for (int i = first - 'a' + 1; i <= last - 'a' + 1; i++)
        {
            for (auto &j : A[i])
            {
                ans.pb(j);
                cost += abs(i - prev);
                prev = i;
            }
        }
    }
    else
    {
        for (int i = first - 'a' + 1; i >= last - 'a' + 1; i--)
        {
            for (auto &j : A[i])
            {
                ans.pb(j);
                cost += abs(i - prev);
                prev = i;
            }
        }
    }
    cout << cost << " " << sz(ans) << endl;
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
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
