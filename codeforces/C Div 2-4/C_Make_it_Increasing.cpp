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

void solve()
{
    ll n; cin >> n;
    vl a(n), b(n);

    F0R(i,n) {
        cin >> a[i];
        b[i] = a[i];
    }

    int ans = 0, ans2 = 0;

    // ll mx = *max_element(all(a));

    for(int i = n-1; i >= 1;i--){
        ans++;
        ll tmp = a[i-1];
        while(a[i-1] >= a[i]){
            a[i-1] -= tmp, ans++;
        }
    }

    for(int i = 1; i < n-1;i++){
        ans2++;
        ll tmp = b[i];
        while(b[i] >= b[i+1]){
            b[i] -= tmp, ans2++;
        }
    }
    ans2++;
    ll tmp = b[n-1];
    while( b[n-2] >= b[n-1]){
           b[n-1] += tmp, ans2++;
    }

    for(auto &i : a) cout << i << " ";
    cout << endl  << endl;
        for(auto &i : b) cout << i << " ";
    cout << endl  << endl;
    cout << min(ans, ans2) << endl;

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
