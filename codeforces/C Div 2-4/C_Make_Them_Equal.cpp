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
const int MX = (3 * 1e5);
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS

// Read statements slowly if WA
// Check for constraints if TLE
bool prime[MX + 1];
vi prs;
void soe()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= MX; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= MX; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= MX; p++)
        if (prime[p])
            prs.pb(p);
}
void solve()
{
    ll n, idx = 0, cnt = 0;
    cin >> n;
    char c, in;
    cin >> c;
    string s;
    bool hasC = false;
    // a bbbbba

    vi ans, ans2;

    F0R(i, n)
    {
        cin >> in;
        if (in == c) idx = i + 1, cnt++;
    }
    if(cnt == n) cout << 0 << endl;
    else{
        if(idx*2 > n) cout << 1 << endl << idx << endl;
        else  cout << 2 << endl << n-1 << " " << n << endl;
    } 
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10);
    cin.exceptions(cin.failbit);
    soe();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
