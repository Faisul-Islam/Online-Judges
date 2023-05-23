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
    string s, ans;
    cin >> s;
    for (int i = 0; i < n;)
    {
        if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o' && (s[i] != '\n' || s[i+2] != '\n' || s[i+3] != '\n'))
        {
            if (i + 2 == n - 1)
            {
                ans.push_back('*');
                ans.push_back('*');
                ans.push_back('*');
                break;
            }
            else
            {
                for (int j = i + 3; j < n;)
                {
                    if (s[j] == 'g' && s[j + 1] == 'o' && (s[j] != '\n' || s[j+1] != '\n'))
                    {
                        j += 2;
                    }
                    else
                    {
                        i = j;
                        break;
                    }
                }
                        ans.push_back('*');
                        ans.push_back('*');
                        ans.push_back('*');
            }
        }
        else
        {
            ans.push_back(s[i]);
            i++;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}