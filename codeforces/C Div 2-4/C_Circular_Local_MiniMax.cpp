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
vector<int> arr, ans;

void solve()
{
    int n, tmp, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    if (arr.size() & 1)
        cout << "NO\n";
    else
    {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() / 2;
        bool yes = true;
        for (int i = 0; i < arr.size() / 2; i++)
        {
            ans.push_back(arr[i]);
            ans.push_back(arr[r]);
            r++;
        }
        for (int i = 1; i < ans.size() - 1; i++)
        {
            if (ans[i] > ans[i + 1] && ans[i] > ans[i - 1])
                continue;
            else if (ans[i] < ans[i + 1] && ans[i] < ans[i - 1])
                continue;
            else
            {
                yes = false;
                break;
            }
        }
        if (!yes)
            cout << "NO\n";
        else if (ans.back() > ans[0])
        {
            cout << "YES\n";
            for (auto &i : ans)
                cout << i << " ";
            cout << endl;
        }
        else
            cout << "NO\n";
    }

    arr.clear();
    ans.clear();
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
