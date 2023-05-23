#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << endl;
#else
// online submission
#endif

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define YES cout << "YES\n"
#define NO cout << "NO\n"
template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

void solve()
{
    ll n,in, zc = 0, mx = INT_MIN, mn = INT_MAX;
    cin >> n;
    vl ar;
    set<ll> frq;
F0R(i,n){
    cin >> in;
    if(in == 0 and zc < 3) ar.pb(in), zc++;
    else if(in != 0) ar.pb(in);
    frq.insert(in);
}
sort(all(ar));
int len = sz(ar);
if((ar[0] + ar[1] + ar[2]) < ar[0] or (ar[len-1] + ar[len-2] + ar[len-3]) > ar[len-1]){
    NO;
    return;
}else{
    F0R(i,len){
        FOR(j,i+1,len){
            FOR(k,j+1,len){
                if(i == j and j == k) continue;
                else{
                    if(frq.find(ar[i] + ar[j] + ar[k]) == frq.end()){
                        NO;
                        return;
                    }
                }
            }
        }
    }
    YES;
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