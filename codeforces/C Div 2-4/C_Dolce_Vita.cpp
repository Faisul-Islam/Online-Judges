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
  ll n, x;
  cin >> n >> x;

  vl ar(n);

  F0R(i, n)
  {
    cin >> ar[i];
  }
  sort(all(ar));

  vl ps(n + 1);

  ps[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    ps[i] = ps[i - 1] + ar[i - 1];
  }

  ll days = 0, ans = 0; // never used int
  for (int i = n; i >= 1; i--)
  {
    ll ds = 0;

    if (ps[i] + (i * days) <= x)
    {
      ds = x - (ps[i] + days * i);  // got WA for this, got precedence related error because of not wrapping up inside brackets correctly:(
      // deb(x - (ps[i] + i * days))
      // deb(x - ps[i] + (i * days))
      if (ds >= 0)
      {
        ds = (ds / i) + 1;
        days += ds;
        ans += (i * ds);
      }
    }
  }
  cout << ans << endl;
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
