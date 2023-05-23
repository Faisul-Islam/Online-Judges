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
char ar[504][504];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 504; i++)
        for (int j = 0; j < 504; j++)
        {
            ar[i][j] = '0';
        }
    F0R(i, n)
    {
        F0R(j, m)
        {
            cin >> ar[i][j];
        }
    }

    // for(int i = 0; i < )
    int ans = 0, cntrX = 0, cntrY = 0;
    while (1)
    {
        int tmpC = 0;
        tmpC += (ar[cntrX][cntrY] == '1');
        tmpC += (ar[cntrX][cntrY + 1] == '1');
        tmpC += (ar[cntrX + 1][cntrY] == '1');
        tmpC += (ar[cntrX + 1][cntrY + 1] == '1');
        if (tmpC == 3)
        {
            ans += 2;
        }
        else if (tmpC == 4)
            ans += 2;
        else if (tmpC == 1)
            ans += 1;

        ar[cntrX][cntrY] = '0';
        ar[cntrX][cntrY + 1] = '0';
        ar[cntrX + 1][cntrY] = '0';
        ar[cntrX + 1][cntrY + 1] = '0';
               if (cntrY != m)
            cntrY++;

        if (cntrX >= n && cntrY == m)
        {
            cout << ans << endl;
            return;
        }

 

        if (cntrY == m)
        {
            cntrY = 0, cntrX += 2;
            // deb("hey");
        }
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
