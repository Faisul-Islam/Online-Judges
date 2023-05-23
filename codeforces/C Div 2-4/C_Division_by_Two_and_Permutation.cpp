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
    int n;
    cin >> n;
    set<ll> oc;

    vl ar(n);
    F0R(i, n)
    {
        cin >> ar[i];
        ll tmp = ar[i];
    }
    sort(ar.begin(), ar.end());
    F0R(i, n)
    {
        ll tmp = ar[i];
        while (tmp > 0)
        {
            if(tmp > 0 && tmp <= n && oc.find(tmp) == oc.end()){
                oc.insert(tmp); 
                break;
            }
            if (tmp > 0 && tmp <= n)
            {
                if (oc.find(tmp) == oc.end())
                {
                    if (oc.find(tmp / 2) == oc.end() && tmp/2 > 0)
                        tmp /= 2;
                    else{
                        oc.insert(tmp);
                        break;
                    }
                }else tmp/=2;
            }
            else tmp /= 2;

        }
    }

    if (oc.size() == n)
        cout << "YES\n";
    else
        cout << "NO\n";
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