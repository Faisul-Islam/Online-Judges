#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
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
#define ff first
#define ss second
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

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    map<ll, int> frq1, frq2, fin1;

    F0R(i, n)
    {
        cin >> a[i];
        frq1[a[i]]++;
    }
    F0R(i, n)
    {
        cin >> b[i];
        frq2[b[i]]++;
    }

    int ans = 0;

    F0R(i, n)
    {
        if (frq2[a[i]] > 0 || a[i] < 10)
            fin1[a[i]]++, frq2[a[i]]--;
        else
        {
            a[i] = to_string(a[i]).length();
            fin1[a[i]]++;
            ans++;
        }

        if (frq1[b[i]] > 0 || b[i] < 10)
            fin1[b[i]]--, frq1[b[i]]--;
        else
        {
            b[i] = to_string(b[i]).length();
            fin1[b[i]]--;
            ans++;
        }
    }

    for (auto &i : fin1)
    {
        if (i.ff != 1)
            ans += abs((i).ss);
    }

    cout << ans << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
