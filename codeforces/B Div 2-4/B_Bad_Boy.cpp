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
ll n, m, i, j; cin >> n >> m >> i >> j;
pair<ll, ll> c1 = {1,1}, c2 = {1,m}, c3 = {n,m}, c4 = {n, 1};
multimap< ll,pair<ll,ll>> mp;
ll d1 = sqrt(pow(i-c1.first,2) + pow(j-c1.second,2)), d2 = sqrt(pow(i-c2.first,2) + pow(j-c2.second,2)),
 d3 = sqrt(pow(i-c3.first,2) + pow(j-c3.second,2)), d4 = sqrt(pow(i-c4.first,2) + pow(j-c4.second,2));
mp.insert({d1, c1});
mp.insert({d2, c2});
mp.insert({d3, c3});
mp.insert({d4, c4});

auto it = mp.rbegin();
// deb((*it).first);
pair<ll, ll> l_d = {(*it).s.f, (*it).s.s};
if(l_d == c1)
cout << l_d.f << " " << l_d.s << " " << c3.f << " " << c3.s << endl;
else if(l_d == c2)
cout << l_d.f << " " << l_d.s << " " << c4.f << " " << c4.s << endl;
else if(l_d == c3)
cout << l_d.f << " " << l_d.s << " " << c1.f << " " << c1.s << endl;
else if(l_d == c4)
cout << l_d.f << " " << l_d.s << " " << c2.f << " " << c2.s << endl;

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
