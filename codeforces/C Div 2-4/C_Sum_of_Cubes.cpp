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

map<ll,ll> cubes;

void preCompute(){
    ll counter = 1;
    while(1){
     ll tmp = counter * counter * counter;
     if(tmp > 1e12) break;
     cubes[tmp] = tmp;
     counter++;
    }
}

void solve()
{
    ll x; cin >> x;

    for(ll i = 1; i * i <= x; i++){
        ll rem = x -(i * i * i);
        // deb(rem);
        if(rem <= 0) break;
        if(cubes[rem] > 0 && rem > 0){
            // deb(cubes[rem]);
            YES;
            return;
        }
    }
    NO;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
      preCompute();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
