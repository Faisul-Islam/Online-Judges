
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define ins insert

void solve()
{
  ll n;
  cin >> n;
  vl ar(n), ans(n);
  map<ll, ll> frq, frq2;
  F0R(i, n)
      cin >> ar[i],
      frq[ar[i]]++;

  if (sz(frq) == n or (sz(frq) == n - 1 and *max_element(all(ar)) == n))
  {
    cout << "YES" << endl;
    ll missing = 0;
    F0R(i, n)
    {
      if (frq[i + 1] == 2)
      {
        missing = i + 1;
        break;
      }
    }
    bool flag = false;
    F0R(i, n)
    {
      if (frq2.find(ar[i]) == frq2.end() and (ar[i] != missing))
      {
        cout << ar[i] << " ";
        frq2[ar[i]]++;
        ans[i] = ar[i];
      }
      else
      {
        if (!flag)
        {
          cout << n - missing + 1 << " ";
          frq2[missing]++;
          ans[i] = missing;
        }
        else
        {
          ll missing2 = 0;
          F0R(i, n)
          {
            if (frq2.find(i + 1) == frq2.end())
            {
              missing2 = i + 1;
              break;
            }
          }
          cout << missing << " ";
          frq2[missing2]++;
          ans[i] = missing2;
        }
        flag = !flag;
      }
    }
    cout << endl;
    for (auto &i : ans)
      cout << i << " ";
    cout << endl;
  }
  else
    cout << "NO" << endl;
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);
  cout << setprecision(10);
  cin.exceptions(cin.failbit);

  int T = 1;
  cin >> T;
  while (T--)
  {
    solve();
  }
}
