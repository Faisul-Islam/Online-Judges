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
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define ins insert
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS

// Read statements slowly if WA
// Check for constraints if TLE
void solve()
{
    ll n;
    cin >> n;
    vl ar(n);
    ll initSum = 0, cnt = 0;
    F0R(i, n)
    {
        cin >> ar[i];
        if (i & 1)
            initSum -= ar[i];
        else
            initSum += ar[i];
    }
    if (initSum == 0)
    {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }
    //  -1 -1+1-1+1
    vector<pair<int, int>> idxs;
    ll lastIdx = 0, tmpSum = 0;
    F0R(i, n)
    {
        if (cnt & 1)
            tmpSum -= ar[i];
        else
            tmpSum += ar[i];
        if (tmpSum == 0)
        {
            idxs.pb({lastIdx + 1, i + 1});
            lastIdx = i;
            cnt = 0;
        }
        if (i == n - 1 and tmpSum != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    F0R(i,sz(idxs)) cout << idxs[i].first <<" " << idxs[i].second << endl;

    
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
