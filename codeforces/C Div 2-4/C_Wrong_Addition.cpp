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
    string a, s;
    cin >> a >> s;

    string ans;
    ll crSIdx = (s.length()) - 1;
    for (int i = (a.length()) - 1; i >= 0; i--)
    {
        if (crSIdx == -1)
        {
            cout << -1 << endl;
            return;
        }
        if ((a[i] - '0') > (s[crSIdx] - '0'))
        {
            string tmp = "00";
            tmp[1] = s[crSIdx--];

            if (crSIdx == -1)
            {
                cout << -1 << endl;
                return;
            }
            tmp[0] = s[crSIdx--];
            if ((stoi(tmp) - (a[i] - '0')) > 10 || (stoi(tmp) - (a[i] - '0')) < 0)
            {
                cout << -1 << endl;
                return;
            }
            ans.pb((stoi(tmp) - (a[i] - '0')) + '0');
        }
        else
        {

            ans.pb(((s[crSIdx] - '0') - (a[i] - '0')) + '0');
            crSIdx--;
        }
    }
    for (int i = crSIdx; i >= 0; i--)
    {
        ans.pb(s[i]);
    }
    // reverse(all(ans));
    bool found = false;
    for (ll i = ans.length() - 1; i >= 0; i--)
    {
        if (ans[i] != '0' && !found)
            found = true, cout << ans[i];
        else if (ans[i] != '0' || found)
            cout << ans[i];
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
