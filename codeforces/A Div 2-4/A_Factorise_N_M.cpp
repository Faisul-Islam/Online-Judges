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
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ins insert
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 1e5;
    bool prime[MX + 1];

void soe()
{

    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= MX; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= MX; i += p)
                prime[i] = false;
        }
    }
 
}

void solve()
{
    ll n; cin >> n;
    if(!prime[n+2] and n!= 2) cout << 2 << endl;
    else if(!prime[n+3]) cout << 3 << endl;
    else if(!prime[n+5]) cout << 5 << endl;
    else cout << 7 << endl;
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
