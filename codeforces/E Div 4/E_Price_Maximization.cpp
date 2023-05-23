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
void solve()
{
    ll n, k, tmp; cin >> n >> k;
    vl sk, lk;

    F0R(i,n){
        cin >> tmp;
        if(tmp < k) sk.pb(tmp);
        else lk.pb(tmp);
    }

    sort(all(sk), greater<>());
    sort(all(lk), greater<>());

    ll ans = 0;

    ll sc = 0, lc = 0, tmpSum = 0, cntr = 0;

    while(sc != sk.size() || lc != lk.size()){
        if(cntr % 2 == 0){
            ans += tmpSum / k;
            tmpSum = 0;
        }
        if(lc < lk.size()){
           tmpSum += lk[lc], cntr++, lc++;
        }
        if(sc < sk.size()){
           tmpSum += sk[sc], cntr++, sc++;
        }
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
