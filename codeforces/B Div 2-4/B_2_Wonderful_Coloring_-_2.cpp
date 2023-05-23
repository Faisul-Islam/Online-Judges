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
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS

// Read statements slowly if WA
// Check for constraints if TLE
ll next(set<ll> &ar,ll k){
    ll val = 1;
    if(ar.size() == k) return 0;
    FOR(i,1,k+1){
        if(ar.find(i) == ar.end()) return i;
    }
    return 0;
}
void solve()
{
    ll n, k, in;
    cin >> n >> k;
    vl ar(n), ans(n);
    set<ll> init;
    F0R(i, n)
    {
        cin >> ar[i];
    }
    map<ll, set<ll>> ms;
    ll prev = 1;
    F0R(i, n)
    {
        if (ms[ar[i]].find(prev) == ms[ar[i]].end() and prev != 0)
        {
            ms[ar[i]].insert(prev);
            ans[i] = prev;
        }
        else
        {
            if (ms[ar[i]].empty() == false)
            {
                // prev = (((*(ms[ar[i]].rbegin())) + 1) > k ? 0 : (*(ms[ar[i]].rbegin())) + 1);
                if(((*(ms[ar[i]].rbegin())) + 1) > k) prev = next(ms[ar[i]],k);
                else prev = (*(ms[ar[i]].rbegin())) + 1;

            }
            else
                prev = 1;

            ans[i] = prev;
            ms[ar[i]].insert(prev);
        }
    }
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
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
