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
    ll n; cin >> n;
    string s; cin >> s;
    ll mid = n / 2;

    ll defVal = 0, maxVal = 0;
    maxVal += ((n - mid) * (n - 1 + mid));

    if (n & 1)
        maxVal -= mid;

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    F0R(i, n)
    {
        if (s[i] == 'L')
            defVal += i;
        else
            defVal += n - i - 1;
    }
    ll curAns = 0, prevDefVal = defVal;

    ll curJ = 0;
    F0R(i, n)
    {
        if (defVal >= maxVal)
            cout << maxVal << " ";
        else
        {
            for (int j = curJ; j < mid;)
            {
                if (s[j] == 'L')
                {
                    defVal -= j;
                    defVal += (n - j - 1);
                    s[j] = 'R';
                }
                else if (s[n - j - 1] == 'R')
                {
                    defVal -= j;
                    defVal += (n - j - 1);
                    s[n - j - 1] = 'L';
                }
                if (prevDefVal != defVal)
                {
                    prevDefVal = defVal;
                    curJ = j;
                    break;
                }
                else
                    j++;
            }
            if (defVal > maxVal)
                cout << maxVal << " ";
            else
                cout << defVal << " ";
        }
    }
    cout << endl;
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
