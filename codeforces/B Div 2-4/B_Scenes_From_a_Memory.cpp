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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define ins insert

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
// ALWAYS SIMULATE FULL TEST CASE
// DO CUSTOM TEST CASE CHECK, MIN & MAX CONSTRAINTS, 0,1 CONSTRAINTS
map<ll, bool> primes;
ll prAr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void preCompute()
{
    for (int i = 0; i < 25; i++)
        primes[prAr[i]] = 1;
}
void solve()
{
    ll n; cin >> n;

    char c;
    ll cntr = 0;
    string s, ps;

    F0R(i, n)
    {
        cin >> c;
        if (c - '0' != 7 && c - '0' != 2 && c - '0' != 3 && c - '0' != 5)
            s.pb(c);
        else
            ps.pb(c), cntr++;
    }

    if (s.length() == 0)
    {
        int len = ps.length();
        string ans;

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (i != j)
                {
                    string tmp;
                    tmp.pb(ps[i]);
                    tmp.pb(ps[j]);

                    if (primes[stoi(tmp)] == 0)
                    {
                        cout << min(len, 2) << "\n"
                             << stoi(tmp) << endl;
                        return;
                    }
                }
            }
        }
    }
    else
        cout << 1 << "\n"
             << s[0] << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    preCompute();
    cin >> T;
    while (T--)
    {
        solve();
    }
}
