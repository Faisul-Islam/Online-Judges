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
// Read statements slowly
void solve()
{
    ll n, q, tmp, mx = INT_MIN;
    cin >> n >> q;
    vl ar(n), ps(n);

    F0R(i, n)
    {
        cin >> tmp;
        if (i == 0)
            ps[i] = tmp;
        else
            ps[i] = ps[i - 1] + tmp;

        mx = max(tmp, mx);
        ar[i] = mx;
    }

    while (q--)
    {
        ll tmp;
        cin >> tmp;
        ll idx = -1, i = 0;

        i = distance(ar.begin(),ub(ar.begin(), ar.end(),tmp))-1;

        for (; i < n; i++)
        {
            if (tmp >= ar[i])
                idx = i;
            else
                break;
        }
        if (idx == -1)
            cout << 0 << " ";
        else
            cout << ps[idx] << " ";
    }
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
