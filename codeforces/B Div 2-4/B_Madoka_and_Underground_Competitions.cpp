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

// char ar
void solve()
{
    ll n, k, r, c;
    cin >> n >> k >> r >> c;
    r--, c--;
    char ar[n + 1][n + 1];

    ar[r][c] = 'X';

    F0R(i, n)
    {
        F0R(j, n)
        {
            ar[i][j] = '.';
        }
    }

    ll rt = r, rc = c, cntrL = 1, cntrR = 0;

    for (int i = r; i < n; i++)
    {
        for (int j = c - cntrR; j < n; j += k)
                ar[i][j] = 'X';
        

        for (int j = c - cntrR; j >= 0; j -= k)
                ar[i][j] = 'X';
    

        cntrR++;
    }

    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = c + cntrL; j < n; j += k)
            ar[i][j] = 'X';

        for (int j = c + cntrL; j >= 0; j -= k)
                ar[i][j] = 'X';

        cntrL++;
    }

    F0R(i, n)
    {
        F0R(j, n)
            cout << ar[i][j];

        cout << endl;
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
