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
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ins insert

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS
// Read statements slowly
const double DOUBLE_MAX = 999999.0000;


void solve()
{
        ll n, tmp; cin >> n;

    vl ar(n), v(n);
    ll mx = 0, mn = INT_MAX;
    F0R(i,n){
        cin >> ar[i];
        mx = max(ar[i], mx);
        mn = min(ar[i], mn);
    }
    F0R(i,n) cin >> v[i];
  
    ll l = 0, r = mx;
    double ans = DOUBLE_MAX;
    for(ll i = mn; i <= mx; i++){
        double tmpSec = 0.0;
        for(int j = 0; j < n; j++){
            double tmpDist = abs(ar[j]-i);
            double tmpMnSec = (tmpDist * 1.0) / v[j];
        // deb(tmpMnSec);

           if(tmpMnSec < ans && tmpMnSec != 0) ans = tmpMnSec;
        }
        // deb(ans);
    }
    cout << ans << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}
