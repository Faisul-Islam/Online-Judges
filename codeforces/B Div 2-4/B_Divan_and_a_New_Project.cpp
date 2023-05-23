#pragma GCC optimize("O3")
#pragma GCC target("sse4")
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
bool sortbysec(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
    return (a.second > b.second);
}

void solve()
{
    ll n, tmp;
    cin >> n;

    vpl ar(n);
    vl ansAr(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        ar[i] = {tmp, i};
    }

    sort(ar.begin(), ar.end(), greater<>());

    ll ans = 0, cntr = 0, l = 0, r = 0;

    cntr = (n + 1) / 2;
    l = cntr - 1, r = cntr + 1;
    ansAr[0] = cntr;

    F0R(i, n)
    {
        if (i & 1)
        {
            ans += 2 * abs(cntr - l) * ar[i].fi;
            ansAr[ar[i].se + 1] = l--;
        }
        else
        {
            ans += 2 * abs(cntr - r) * ar[i].fi;
            ansAr[ar[i].se + 1] = r++;
        }
    }

    cout << ans << endl;
    for (auto &i : ansAr)
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
