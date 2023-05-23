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
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS

// Read statements slowly if WA
// Check for constraints if TLE
void solve()
{
    ll n, q, tmp; cin >> n >> q;
    vl are, aro;

    F0R(i,n){
     cin >> tmp;
     if(tmp & 1){
        aro.pb(tmp);
     }else are.pb(tmp);
    }

    ll es = accumulate(all(are),0ll),
       os = accumulate(all(aro),0ll);

       bool even1 = true, even2 = false;



    while(q--){
        ll a,b; cin >> a >> b;

        if(a == 0){
            if(even1){
                if(b & 1)  even1 = false;
                es += (are.size() * b);
            }
            if(even2){
                if(b & 1)  even2 = false;
                os += (aro.size() * b);
            } 
        }
        else if(a == 1){
             if(!even1){
                if(b & 1)  even1 = true;
                es += (are.size() * b);
            }
            if(!even2){
                if(b & 1)  even2 = true;
                os += (aro.size() * b);
            } 
        }

        cout << es + os << endl;
    }


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
