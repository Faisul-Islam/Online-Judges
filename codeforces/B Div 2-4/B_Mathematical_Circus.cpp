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
    ll n, k;
    cin >> n >> k;
    map<ll, ll> hsh;
    ll crntIdx = 1;
    if (((crntIdx + k) * (crntIdx + 1)) % 4 != 0 && ((crntIdx + 1 + k) * (crntIdx)) % 4 != 0)
    {
        cout << "NO\n";
        return;
    }
    YES;
    while (1)
    {
        if (crntIdx > n)
            break;
        if (((crntIdx + k) * (crntIdx + 1)) % 4 == 0)
            cout << crntIdx << " " << crntIdx + 1 << endl;
        else if (((crntIdx + 1 + k) * (crntIdx)) % 4 == 0)
            cout << crntIdx + 1 << " " << crntIdx << endl;
    
        crntIdx += 2;
    }
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
