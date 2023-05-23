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

void solve()
{
    int n;
    cin >> n;
    map<string, int> all;
    string tmp;
    vector<string> ar1, ar2, ar3;

    int a = 0, b = 0, c = 0;

    F0R(i, 3)
    {
        F0R(j, n)
        {
            cin >> tmp;
            all[tmp]++;
            if (i == 0)
                ar1.pb(tmp);
            else if (i == 1)
                ar2.pb(tmp);
            else if (i == 2)
                ar3.pb(tmp);
        }
    }

    F0R(i, n)
    {
        if (all[ar1[i]] == 1)
            a += 3;
        else if (all[ar1[i]] == 2)
            a += 1;
    }
    F0R(i, n)
    {
        if (all[ar2[i]] == 1)
            b += 3;
        else if (all[ar2[i]] == 2)
            b += 1;
    }
    F0R(i, n)
    {
        if (all[ar3[i]] == 1)
            c += 3;
        else if (all[ar3[i]] == 2)
            c += 1;
    }
    cout << a << " " << b << " " << c << endl;
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
